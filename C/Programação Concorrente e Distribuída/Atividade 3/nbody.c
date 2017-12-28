#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

/*
 * pRNG based on http://www.cs.wm.edu/~va/software/park/park.html
 */
#define MODULUS    2147483647

//Calculo do tempo
double inicioSerial, finalSerial;
double inicioParalelo, finalParalelo;
//Tempos
double tSerial = 0;
double tParalelo = 0;

double Random(void)
/* ------------------------------------------------------------------------------
 * Random returns a random real number uniformly distributed between 0.0 and 1.0.
 * ------------------------------------------------------------------------------
 */
{
  return ((double) rand() / MODULUS);
}

/*
 * End of the pRNG algorithm
 */

typedef struct {
  double x, y, z;
  double mass;
} Particle;
typedef struct {
  double xold, yold, zold;
  double fx, fy, fz;
} ParticleV;

void InitParticles( Particle[], ParticleV [], int );
double ComputeForces( Particle [], Particle [], ParticleV [], int );
double ComputeNewPos( Particle [], ParticleV [], int, double);

int main(int argc, char *argv[])
{
  inicioSerial = omp_get_wtime();
  Particle  * particles;   /* Particulas */
  ParticleV * pv;          /* Velocidade da Particula */
  int         npart;
  double      sim_t;       /* Tempo de Simulacao */
  srand(time(NULL));
  if(argc != 3){
     printf("Indique o número de threads e o tamanho do vetor, nesta ordem\n");
     exit(1);
  }
  omp_set_num_threads(atoi(argv[1]));
  //scanf("%d",&npart);
  //npart = 25000;
  npart = atoi(argv[2]);
  /* Allocate memory for particles */
  particles = (Particle *) malloc(sizeof(Particle)*npart);
  pv = (ParticleV *) malloc(sizeof(ParticleV)*npart);
  /* Generate the initial values */
  finalSerial = omp_get_wtime();
  tSerial += finalSerial - inicioSerial;

  InitParticles( particles, pv, npart);

  inicioSerial = omp_get_wtime();
  sim_t = 0.0;
  int tid;
  double max_f;
  finalSerial = omp_get_wtime();
  tSerial += finalSerial - inicioSerial;

  /* Compute forces (2D only) */
  max_f = ComputeForces(particles, particles, pv, npart);
  /* Once we have the forces, we compute the changes in position */
  sim_t = ComputeNewPos(particles, pv, npart, max_f);
  

  //for (i=0; i<npart; i++)
  //fprintf(stdout,"%.5lf %.5lf %.5lf\n", particles[i].x, particles[i].y, particles[i].z);

  printf("%g\n", max_f);
  printf("%g\n", sim_t);

  printf("Tempo Serial: %.10lf s\n", tSerial);
  printf("Tempo Paralelo: %.10lf s\n", tParalelo);
  printf("Tempo Total: %.10lf s\n", tSerial + tParalelo);
  printf("Fração serial: %.10lf\n", tSerial/(tSerial + tParalelo));

  return 0;
}

void InitParticles( Particle particles[], ParticleV pv[], int npart )
{
  int i;
  inicioParalelo = omp_get_wtime();
  #pragma omp parallel for default(none) private(i) shared(particles, pv, npart)
  for (i=0; i<npart; i++) {
    particles[i].x = Random();
    particles[i].y = Random();
    particles[i].z = Random();
    particles[i].mass = 1.0;
    pv[i].xold	  = particles[i].x;
    pv[i].yold	  = particles[i].y;
    pv[i].zold	  = particles[i].z;
    pv[i].fx	  = 0;
    pv[i].fy	  = 0;
    pv[i].fz	  = 0;
  }
  finalParalelo = omp_get_wtime();
  tParalelo += finalParalelo - inicioParalelo;
}

double ComputeForces( Particle myparticles[], Particle others[], ParticleV pv[], int npart )
{
  inicioSerial = omp_get_wtime();
  double max_f;
  int i;
  max_f = 0.0;
  int j;
  double xi, yi, rx, ry, mj, r, fx, fy, rmin;
  finalSerial = omp_get_wtime();
  tSerial += finalSerial - inicioSerial;

  inicioParalelo = omp_get_wtime();
  #pragma omp parallel for default(none) private(rmin, i, j, xi, yi, fx, fy, rx, ry, mj, r) shared(npart, myparticles, others, pv, max_f)
  for (i=0; i<npart; i++) {
    rmin = 100.0;
    xi   = myparticles[i].x;
    yi   = myparticles[i].y;
    fx   = 0.0;
    fy   = 0.0;
    for (j=0; j<npart; j++) {
      rx = xi - others[j].x;
      ry = yi - others[j].y;
      mj = others[j].mass;
      r  = rx * rx + ry * ry;
      /* ignore overlap and same particle */
      if (r == 0.0) continue;
      if (r < rmin) rmin = r;
      r  = r * sqrt(r);
      fx -= mj * rx / r;
      fy -= mj * ry / r;
    }
    pv[i].fx += fx;
    pv[i].fy += fy;
    fx = sqrt(fx*fx + fy*fy)/rmin;
    if (fx > max_f) max_f = fx;
  }
  finalParalelo = omp_get_wtime();
  tParalelo += finalParalelo - inicioParalelo;
  return max_f;
}

double ComputeNewPos( Particle particles[], ParticleV pv[], int npart, double max_f)
{
  inicioSerial = omp_get_wtime();
  int i;
  double a0, a1, a2;
  static double dt_old = 0.001, dt = 0.001;
  double dt_new;
  double xi, yi;
  a0	 = 2.0 / (dt * (dt + dt_old));
  a2	 = 2.0 / (dt_old * (dt + dt_old));
  a1	 = -(a0 + a2);
  finalSerial = omp_get_wtime();
  tSerial += finalSerial - inicioSerial;

  inicioParalelo = omp_get_wtime();
  #pragma omp parallel for default(none) private(i, xi, yi) shared(a0, a1, a2, particles, pv, npart)
  for (i=0; i<npart; i++) {
    xi	           = particles[i].x;
    yi	           = particles[i].y;
    particles[i].x = (pv[i].fx - a1 * xi - a2 * pv[i].xold) / a0;
    particles[i].y = (pv[i].fy - a1 * yi - a2 * pv[i].yold) / a0;
    pv[i].xold     = xi;
    pv[i].yold     = yi;
    pv[i].fx       = 0;
    pv[i].fy       = 0;
  }
  finalParalelo = omp_get_wtime();
  tParalelo += finalParalelo - inicioParalelo;

  inicioSerial = omp_get_wtime();
  dt_new = 1.0/sqrt(max_f);
  /* Set a minimum: */
  if (dt_new < 1.0e-6) dt_new = 1.0e-6;
  /* Modify time step */
  if (dt_new < dt) {
    dt_old = dt;
    dt     = dt_new;
  }
  else if (dt_new > 4.0 * dt) {
    dt_old = dt;
    dt    *= 2.0;
  }
  finalSerial = omp_get_wtime();
  tSerial += finalSerial - inicioSerial;

  return dt_old;
}


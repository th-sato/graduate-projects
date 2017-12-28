import java.util.Arrays;
import java.util.Random;

public class Main {
	private static final int numberOfElements = 10;

	public static void main(String[] args) {
		double responseS = 0, turnaroundS = 0, waitS = 0;
		CFS_task [] input = new CFS_task[numberOfElements];
		CFS_task t;
		int [] vetor_chegada = new int[numberOfElements];
		int [] vetor_burst = new int[numberOfElements];
		int [] niceness = new int[numberOfElements];
		int q = 1;
		Random gerador = new Random();
		
		for (int i=0; i<input.length; i++){
			vetor_chegada[i] = gerador.nextInt(20);
			//vetor_burst[i] = gerador.nextInt(99)+1;
			niceness[i] = 0;
		}
		
		vetor_chegada[0] = 0;
		Arrays.sort(vetor_chegada);
		vetor_burst[0] = 100;
		vetor_burst[1] = 1;
		vetor_burst[2] = 60;
		vetor_burst[3] = 93;
		vetor_burst[4] = 37;
		vetor_burst[5] = 48;
		vetor_burst[6] = 17;
		vetor_burst[7] = 56;
		vetor_burst[8] = 24;
		vetor_burst[9] = 1;
		
		System.out.println("Vetor burst:");
		for (int i=0; i<input.length; i++){
			System.out.println(vetor_burst[i]);
		}
		
		System.out.println("Vetor chegada:");
		for (int i=0; i<input.length; i++){
			System.out.println(vetor_chegada[i]);
		}
		
		System.out.println();
		System.out.println("Niceness:");
		for (int i=0; i<input.length; i++){
			System.out.println(niceness[i]);
		}

		System.out.println();

		for (int i=0; i<input.length; i++){
			input[i] = new CFS_task ("P"+Integer.toString(i),niceness[i], vetor_chegada[i], vetor_burst[i]);
		}

		System.out.println();

		CFS_RQ rq = new CFS_RQ(input);
		rq.startScheduler();
		System.out.println(rq.getThroughput());
		System.out.println();
		input = rq.returnTasks();
		for (int i=0; i<input.length; i++){
			System.out.println("Processo: "+input[i].getName());
			System.out.println("Resposta: "+input[i].getTimeResponse());
			System.out.println("Turnaround: "+input[i].getTurnaround());
			System.out.println("Wait: "+input[i].getWaitTime());
			responseS += input[i].getTimeResponse();
			turnaroundS += input[i].getTurnaround();
			waitS += input[i].getWaitTime();
			System.out.println();
		}
		System.out.println("Média resposta: " + responseS/input.length);
		System.out.println("Média turnaround: " + turnaroundS/input.length);
		System.out.println("Média espera: " + waitS/input.length);
		System.out.println();		
		
		/*FCFS fcfs = new FCFS();
		RR rr = new RR();
		fcfs.run_FCFS(vetor_burst);
		System.out.println();*/
		SJF sjf = new SJF();
		sjf.run_SJF(vetor_chegada, vetor_burst);
		System.out.println();
		/*rr.run_RR(vetor_burst,q);*/

	}
}


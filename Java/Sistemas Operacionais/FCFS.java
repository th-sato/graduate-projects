
public class FCFS {
 
public void run_FCFS(int [] tempo_de_burst)	{
				
		int j = 0, n, contador_tempo = 0;
		float tempo_medio_de_espera = 0, tempo_medio_de_turnaround = 0;
		
		n=tempo_de_burst.length;
        
     //   int tempo_de_chegada[] = new int[n];
        int tempo_de_espera[] = new int[n];
        int tempo_de_turnaround[] = new int[n];
        int tempo_de_resposta[] = new int[n];
        
     /*   System.out.println("Insira os tempos de chegada em ordem: ");
        for (int i = 0; i < n; i++)
        {
        	tempo_de_chegada[i]=ler.nextInt();
        }	
    */
        
        for (int i = 0; i < n; i++)
        {
        	tempo_de_resposta[i] = -1;
        }
        
        while (j < n)
        {
        	if (j == 0)
        	{
        		tempo_de_espera[j] = 0;
        		tempo_de_resposta[j] = tempo_de_espera[j];
        	}
        	else if (j >=1)
        	{
        		tempo_de_espera[j] = tempo_de_burst[j - 1] + tempo_de_espera[j-1];
        		tempo_de_resposta[j] = tempo_de_espera[j];
        	}
        	contador_tempo = contador_tempo + tempo_de_burst[j];
        	tempo_medio_de_espera = tempo_medio_de_espera + tempo_de_espera[j];  
        	tempo_de_turnaround[j] =  tempo_de_espera[j] + tempo_de_burst[j];
        	tempo_medio_de_turnaround = tempo_medio_de_turnaround + tempo_de_turnaround[j];
        	j++;
        }        
        tempo_medio_de_espera = tempo_medio_de_espera / n;
        tempo_medio_de_turnaround = tempo_medio_de_turnaround / n;

        System.out.println("FCFS:");
        System.out.println("O tempo medio de espera: " + tempo_medio_de_espera);
        System.out.println("O tempo medio de turnaround: " + tempo_medio_de_turnaround);
        //System.out.println("O tempo total de execução é: " + contador_tempo);
        for (int i = 0; i < n; i++)
        {
        		System.out.println("Resposta P" + (i+1) + ": " + tempo_de_resposta[i]);
        }    
        for (int i = 0; i < n; i++)
        {
        		System.out.println("Espera P" + (i+1) + ": " + tempo_de_espera[i]);       		
        }
        for (int i = 0; i < n; i++)
        {
        		System.out.println("Turnaround P" + (i+1) + ": " + tempo_de_turnaround[i]);
        }  
	}	
}


public class SJF {

	public void run_SJF (int[] tempo_de_chegada, int [] vetor_de_burst) {
				
		int j = 0, processos = 0, n, contador_tempo = 0, menor = 99999, tempo_total = 0;
		float tempo_medio_de_espera = 0, tempo_medio_de_turnaround = 0;
		
        n=tempo_de_chegada.length;
        
        int tempo_de_burst[] = new int[n];
        int tempo_de_espera[] = new int[n];
        int tempo_de_turnaround[] = new int[n];
        int tempo_de_resposta[] = new int[n];
        
        for (int i = 0; i < n; i++)
        {
        	tempo_de_burst[i] = vetor_de_burst[i];
        	tempo_de_resposta[i] = -1;
        	tempo_total = tempo_total + tempo_de_burst[i];
        }	
                        
       int aux_espera = 0;
        
       while (processos < n)
       {
        	for (int k = 0; k < n; k++)
        	{
        		if (tempo_de_chegada[k] <= contador_tempo)
        		{
        			if (tempo_de_burst[k] < menor && tempo_de_burst[k]!= -1)
        			{
        				menor = tempo_de_burst[k];
        				j = k;
        			}
        		}        		 
        	}
        	if (tempo_de_resposta[j] == -1)
        		tempo_de_resposta[j] = aux_espera - tempo_de_chegada[j];
        	processos++;
        	menor = 99999;
        	tempo_de_espera [j] = aux_espera - tempo_de_chegada[j];
        	tempo_medio_de_espera = tempo_medio_de_espera + tempo_de_espera[j];  
        	tempo_de_turnaround[j] =  tempo_de_espera[j] + tempo_de_burst[j];
        	tempo_medio_de_turnaround = tempo_medio_de_turnaround + tempo_de_turnaround[j];
        	contador_tempo = contador_tempo + tempo_de_burst[j];
        	aux_espera = aux_espera + tempo_de_burst[j];
        	tempo_de_burst[j] = -1;
        }
        	
        tempo_medio_de_espera = tempo_medio_de_espera / n;
        tempo_medio_de_turnaround = tempo_medio_de_turnaround / n;        
        
        System.out.println("SJF:");
        System.out.println("O tempo medio de espera : " + tempo_medio_de_espera);
        System.out.println("O tempo medio de turnaround : " + tempo_medio_de_turnaround);
      //  System.out.println("O tempo total de execução é: " + contador_tempo);
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

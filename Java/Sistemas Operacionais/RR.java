
public class RR {

	public void run_RR (int [] tempo_de_burst, int q) {
				
		int j = 0, n, contador_tempo = 0, tempo_total = 0;
		float tempo_medio_de_espera = 0, tempo_medio_de_turnaround = 0, tempo_medio_de_resposta = 0;
		
		n=tempo_de_burst.length;
        
 
        
        //int tempo_de_chegada[] = new int[n];
        
        int tempo_de_espera[] = new int[n];
        int tempo_de_turnaround[] = new int[n];
        int tempo_de_resposta[] = new int[n];
        
      /*  System.out.println("Insira os tempos de chegada em ordem: ");
        for (int i = 0; i < n; i++)
        {
        	tempo_de_chegada[i]=ler.nextInt();
        }	
        */
        
        for (int i = 0; i < n; i++)
        {
        	tempo_total = tempo_total + tempo_de_burst[i];
        	tempo_de_turnaround[i] = tempo_de_burst[i];
        	tempo_de_resposta[i] = -1;
        }
                
       int aux_espera = 0;
       int ultimo = 0;
        
      while (contador_tempo < tempo_total)
      {	  
    	  if (tempo_de_burst[j] >= q)
    	  {
    		  if (j != ultimo)
    			  tempo_de_espera[j] = aux_espera - (tempo_de_turnaround[j] - tempo_de_burst[j]);
    		  if (tempo_de_resposta[j] == -1)
          		tempo_de_resposta[j] = aux_espera;
    		  tempo_de_burst[j] = tempo_de_burst[j] - q;
    		  contador_tempo = contador_tempo + q;
    		  aux_espera = q + aux_espera;
    		  ultimo = j;
    	  }
    	  else if (tempo_de_burst[j] > 0)
    	  {    
    		  if (j != ultimo)
    			  tempo_de_espera[j] = aux_espera - (tempo_de_turnaround[j] - tempo_de_burst[j]);
    		  if (tempo_de_resposta[j] == -1)
          		tempo_de_resposta[j] = aux_espera;
    		  contador_tempo = contador_tempo + tempo_de_burst[j];
    		  aux_espera = tempo_de_burst[j] + aux_espera;
    		  tempo_de_burst[j] = 0;
    		  ultimo = j;
    	  }    	      	      	  
    	  if (j+1 == n)
    		  j = 0;
    	  else
    		  j++;    	 
      }

      for (int i = 0; i < n; i++)
      {	  
    	  tempo_de_turnaround[i] = tempo_de_turnaround[i] + tempo_de_espera[i];
    	  tempo_medio_de_espera = tempo_medio_de_espera + tempo_de_espera[i];
    	  tempo_medio_de_turnaround = tempo_medio_de_turnaround + tempo_de_turnaround[i];
    	  tempo_medio_de_resposta = tempo_medio_de_resposta + tempo_de_resposta[i];
      }       
      tempo_medio_de_espera = tempo_medio_de_espera / n;
      tempo_medio_de_turnaround = tempo_medio_de_turnaround / n;
      tempo_medio_de_resposta = tempo_medio_de_resposta / n;
      System.out.println("RR: q = " + q);
      System.out.println("O tempo medio de resposta: " + tempo_medio_de_resposta);
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

Programme Algorithme_s�quentiel

Debut 
	t=clock();// calculer le temps 

	pour(cpt=0;cpt<=N;cpt++){
		trouve=0;
		tant que(!trouve){
				
			pour(j=2;j*j<=i;j++){
                               si(i%j==0){break;}
		        }//fin pour 

		        si(j*j>i){
                            trouve = 1;
                            ecrire("%d\n",i);
                        }
		        i+=2;
	       }//fin tant que
	}//fin pour 
		
	tseq = clock() - t ;
        ecrire("\n Le nombre de cycles d'horloge en execution s�quentielle : %d\n",tseq );	

	//Fin code s�quentiel	

Fin 
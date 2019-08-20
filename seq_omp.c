#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#define N 1000 //Changer ici le nombre de nombres premiers
#define Nthread 4

void main(void){

  int i=3,t,cpt,j,trouve,tseq,tpara;

	//Debut code séquentiel
	t=clock();
	for(cpt=0;cpt<=N;cpt++){
		trouve=0;
		while(!trouve){
			for(j=2;j*j<=i;j++){
                               if(i%j==0){break;}
		        }//end for

		        if(j*j>i){
                            trouve = 1;
                            printf("%d\n",i);
                        }
		        i+=2;
	       }//end while
	}//end for

	tseq = clock() - t ;
        printf("\n Temps d'execution séquentielle : %f (ms)\n",((float)tseq/CLOCKS_PER_SEC)*1000);

	//Fin code séquentiel


	//Debut code parallél
	t=clock();

   #pragma omp parallel num_threads(Nthread) private(trouve,j,i)
   {
	i = 3 + omp_get_thread_num()*2;

	#pragma omp for private(cpt) 
	for(cpt=0;cpt<=N;cpt++){
			trouve=0;
			while(!trouve){

				for(j=2;j*j<=i;j++){
				      if(i%j==0){break;}

				}//end for

				if(j*j>i){trouve = 1;/*printf("%d -> %d\n",omp_get_thread_num(),i);*/}
				i+=Nthread*2;
			}//end while
	}//end for


   }//end parallel

   tpara = clock() - t ;
   printf("\n Temps d'execution parallèle: %f (ms)\n",((float)tpara/CLOCKS_PER_SEC)*1000 );

//Fin code parallél
printf("Acceleration = %f\n",(float)tseq/tpara );
}

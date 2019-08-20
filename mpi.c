#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>
#define N 1000


void main(void){
	int i=3,t,cpt,j,trouve,tseq,tpara,rank,premier[N],index=0;

	MPI_Status status;
	MPI_Init(NULL,NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

if(rank==0)t=clock();

   
	i = 3 + rank*2;
	

	for(cpt=rank;cpt<=N;cpt+=2){
			trouve=0;
			while(!trouve){
				
					for(j=2;j*j<=i;j++){
						if(i%j==0){break;}
						
					}//end for
				if(j*j>i && rank==1){trouve = 1;
							/*printf("%d ",i);*/  //afficher les nombres premiers 
							premier[index++]=i;
							}
				if(j*j>i && rank==0)trouve = 1;
				i+=4;
			}//end while
	}//end for



	
 
	if(rank==1){
MPI_Send(&index,1,MPI_INT,0,1,MPI_COMM_WORLD); 
MPI_Send(premier,index,MPI_INT,0,2,MPI_COMM_WORLD); 
}

		

if(rank==0) {
	MPI_Recv(&index,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
	MPI_Recv(premier,index,MPI_INT,1,2,MPI_COMM_WORLD,&status);

	//for(i=0;i<index;i++) printf("%d recived\n ",premier[i]);
	int time = (clock() - t);
	printf("\n Temps d'execution : %f (ms) \n ",((float)time/CLOCKS_PER_SEC)*1000);	

}

	//Fin code parallél

	MPI_Finalize();

}

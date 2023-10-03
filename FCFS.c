#include<stdio.h>

int main(){

	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0},prc[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;
	printf("Enter number of processes	");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	    prc[i]=i;
		printf("Arrival time of process[%d]	",i+1);
		scanf("%d",&at[i]);
		printf("Burst time of process[%d]	",i+1);
		scanf("%d",&bt[i]);

		printf("\n");
	}




	for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                int temp1,temp2,temp3;
                temp1 = at[j];
                temp2 = bt[j];
                temp3 = prc[j];

                at[j] = at[j+1];
                bt[j] = bt[j+1];
                prc[j] = prc[j+1];

                at[j+1] =temp1;
                bt[j+1]=temp2;
                prc[j+1]=temp3;

            }
        }
	}



	for(int j=0;j<n;j++)
	{
	    if(sum<at[j]){
            sum=at[j];
		}
		sum+=bt[j];

		ct[j]+=sum;
	}
	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}
	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(prc[j]>prc[j+1]){
                int temp1,temp2,temp3,temp4,temp5,temp6;
                temp1 = at[j];
                temp2 = bt[j];
                temp3 = prc[j];
                temp4 = ct[j];
                temp5 = tat[j];
                temp6 = wt[j];

                at[j] = at[j+1];
                bt[j] = bt[j+1];
                prc[j] = prc[j+1];
                ct[j] = ct[j+1];
                tat[j] = tat[j+1];
                wt[j] = wt[j+1];

                at[j+1] =temp1;
                bt[j+1]=temp2;
                prc[j+1]=temp3;
                ct[j+1] = temp4;
                tat[j+1]= temp5;
                wt[j+1] = temp6;

            }
        }
	}
	printf("Solution: \n\n");
	printf("P_id\t AT\t BT\t CT\t TAT\t WT\t\n\n");

	for(int i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",prc[i]+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	return 0;
}

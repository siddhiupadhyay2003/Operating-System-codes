#include<stdio.h>

int main()
{
      int at[20]={0};
      int bt[20]={0};
      int wt=0;
      int tat=0;
      int n, q, i;
      int count = 0;
      int sum=0;
      int y;
      int temp[20]={0};
      printf("Enter the no. of processes: ");
      scanf("%d", &n);
      y=n;
      for(int i=0;i<n;i++)
      {
            printf("Enter the arrival and burst time for process %d: ", i+1);
            scanf("%d", &at[i]);
            scanf("%d", &bt[i]);
            temp[i]=bt[i];
      }

      printf("Enter the quantum size: ");
      scanf("%d", &q);
      printf("\n Process No \t Arrival time \t Burst Time \t TAT \t Waiting Time\n");  
      for(i=0, sum=0; y!=0; )
      {
            if(temp[i]<=q && temp[i]>0)
            {
                  sum = sum+temp[i];
                  temp[i]=0;
                  count = 1;
            }
            else if(temp[i]>0)
            {
                  sum =sum+q;
                  temp[i]=temp[i]-q;
            }
            if(temp[i]==0 && count==1)
            {
                  y--;
                  printf("     %d             %d               %d                 %d                %d\n", i+1,at[i], bt[i], sum-at[i], sum-at[i]-bt[i]);
                  wt = wt+ sum-at[i]-bt[i];
                  tat = tat + sum - at[i];
                  count =0;
            }
            if(i==n-1)
            {
                  i=0;
            }
            else if(at[i+1]<=sum)
            {
                  i++;
            }
            else
            {
                  i=0;
            }


      }
      return 0;
}

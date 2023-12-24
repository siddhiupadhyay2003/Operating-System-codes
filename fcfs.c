#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b = temp;

}

int main(){
    int wt[20], bt[20], tat[20],  avwt, avtat, n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("%d\n", n);
    for(int i = 0; i<n; i++)
    {
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    for(int i = 0; i<n; i++)
    {
        wt[i] = 0;
        tat[i] =0;
    }
    wt[0] = 0;
    for(int i = 1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            wt[i] = wt[i] + bt[j];
        }
    }
    for(int i = 0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
    }

    printf("Process ID    Burst Time    Waiting Time    Turn-around Time\n");
    for(int i = 0;i<n;i++)
    {
        printf("    %d          %d             %d             %d", i+1, bt[i], wt[i], tat[i]);
        printf("\n");
    }

    return 0;
}

#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a=*b;
    *b = temp;
}

int main()
{
    int wt[20] = {0};
    int bt[20] = {0};
    int tat[20] = {0};
    int p[20] = {0};
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
        p[i] = i+1;
    }

    for(int i = 0;i<n;i++)
    {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(&bt[j], &bt[j+1]);
                swap(&p[j], &p[j+1]);
            }
        }
    }
    
    wt[0] = 0;
    for(int i = 1;i<n;i++)
    {
        for(int j =0;j<i;j++)
        {
            wt[i] = wt[i]+bt[j];
        }
    }
    for(int i =0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
    }
    printf("Process ID    Burst Time    Waiting Time    Turn-around Time\n");

    for(int i = 0;i<n;i++)
    {
        printf("  %d             %d              %d                 %d", p[i], bt[i], wt[i], tat[i]);
        printf("\n");
    }

    

    return 0;
}

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
    int prio[20]={0}, p[20]={0}, bt[20]={0}, wt[20]={0}, tat[20]={0}, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(int i = 0;i<n;i++)
    {
        p[i] = i+1;
    }
    for(int i = 0;i<n;i++)
    {
        printf("Enter the priority value and burst time for process %d: ", i+1);
        scanf("%d", &prio[i]);
        scanf("%d", &bt[i]);
    }
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            if(prio[j]>prio[j+1])
            {
                swap(&p[j], &p[j+1]);
                swap(&bt[j], &bt[j+1]);
                swap(&prio[j], &prio[j+1]);
            }
        }
    }
    wt[0] = 0;
    for(int i = 1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            wt[i] = wt[i] + bt[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    printf("Process ID     priority      Burst Time    Waiting Time    Turn-around Time\n");
    for(int i = 0;i<n;i++)
    {
        printf("    %d            %d               %d             %d             %d", p[i], prio[i], bt[i], wt[i], tat[i]);
        printf("\n");
    }


    return 0;
}

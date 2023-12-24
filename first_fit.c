#include<stdio.h>

int main()
{
    int highest;
    int p[20] = {212, 417, 112, 426};
    int b[20]={100,500,200,300,600};
    int borig[20];
    int bf[20];
    int np=4;
    int nb=5;
    int remain;
    int k=0;
    int flag;
    for(int i=0;i<np;i++)
    {
        flag = 0;
        for(int j=0;j<nb;j++)
        {
            remain = b[j]-p[i];
            if(p[i]<b[j])
            {
                bf[k]=j+1;
                k++;
                b[j]=b[j]-p[i];
                break;
            }
            else
            {
                flag++;
            }
        }
        if(flag==nb)
        {
            bf[k]= -1;
            k++;
        }
    }
    printf("\n");
    printf("Process  process_size   Block_no. \n");

    for(int i=0;i<np;i++)
    {
        printf("%d           %d               %d\n", i+1, p[i], bf[i]);
    }

    return 0;
}

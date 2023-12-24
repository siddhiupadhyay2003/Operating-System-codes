#include<stdio.h>

int main()
{
    int highest;
    int p[20] = {212, 417, 112, 426};
    int b[20]={100,500,200,300,600};
    int bf[20];
    int np=4;
    int nb=5;

   
    int remain, block, flag;
    for(int i=0;i<np;i++)
    {
        highest = -255635;
        flag = 0;
        for(int j=0;j<nb;j++)
        {
            remain = b[j] - p[i];
            if(remain>0)
            {
                if(remain>=highest)
                {
                    highest = remain;
                    block = j;
                }

            }
            else
            {
                flag++;
            }
        }
        if(flag!=nb)
        {
            b[block] = b[block] - p[i];
            bf[i] = block+1;

        }
        else
        {
            bf[i] = -1;
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

#include<stdio.h>

int main()
{
    int lowest;
    int borig[10];
    int np=4,nb=5;
    int p[10]={212,417,112,650};
    int b[10]={100,500,200,300,600};
    int bf[10];
    int remain, block,flag;
    
    for(int i=0;i<np;i++)
    {
        
        lowest = 255364;
        flag=0;
        for(int j=0;j<nb;j++)
        {
            remain = b[j] - p[i];
            if(p[i]<=b[j])
            {
                if(remain<=lowest)
                {
                    lowest = remain;
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
            bf[i]=-1;

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

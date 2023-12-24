#include<stdio.h>

int main()
{
  int n;
  int m;
  n=5; //no. of processes
  m=3; // no. of different types of processes
  int alloc[5][3] =   { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
 
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4
 
    int avail[3] = { 3, 3, 2 }; // Available Resources
    int p[5] = {0};
    int totalalloc[3] = {0};
    printf("Total allocated resources: \n");
    for(int j = 0;j<m;j++)
    {
      for(int i =0;i<n;i++)
      {
        totalalloc[j] = totalalloc[j]+alloc[i][j];

      }
      
      printf("%d ", totalalloc[j]);
    }
    printf("\n");
    int total[3]={0};
    for(int i=0;i<m;i++)
    {
      total[i] = totalalloc[i]+avail[i];
      
    }
    printf("total resources: \n");
    for(int i=0;i<m;i++)
    {
      
      printf("%d ", total[i]);
      
    }
    printf("\n");

    int remain[5][3];
    printf("\nRemaining need: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            remain[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", remain[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\n");
    printf("\n");
    int flag;
    for(int k=0;k<n;k++)
    {
        int temp;
        for(int i=0;i<n;i++)
        {
            flag=0;
            for(int j=0;j<m;j++)
            {
                if(remain[i][j]>avail[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                temp = i;
                for(int j=0;j<m;j++)
                {
                    avail[j] = avail[j]+alloc[i][j];
                    remain[i][j] = 255366;
                    printf("%d ", avail[j]);
                    
                }
                printf("\n");
                p[k] = i+1;
                break;
            }
            else{
              printf("There is no safe sequence \n");
            }
        }
    }
    printf("\n");
    printf("the escape sequence is: \n");
    for(int i=0;i<n;i++)
    {
      printf("P%d ", p[i]);
    }


  return 0;
}

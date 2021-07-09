#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a;
    int N,i;
    scanf("%d", &N);
    a = (int *) malloc(N * sizeof(int) );

    if(a != NULL)
    {
        for(i=0; i<N; i++)
        {   
        
            scanf ("%d", &a[i]);
        }
        int smallest;
        smallest = a[0];
 
        for (i = 0; i < N; i++) 
        {
            if (a[i] < smallest) 
            {
                smallest = a[i];
            }
        }

        printf("smallest: %d \n", smallest);

        int largest;
        largest = a[0];

        for (i = 0; i < N; ++i) 
        {
            if (largest < a[i])
            {
                largest = a[i];
            }
        }

        printf("largest: %d \n", largest);

        int sum = 0;
        for (i = 0; i < N; ++i) 
        {
            sum += a[i];
        }
        printf("sum: %d \n", sum);

    }

}
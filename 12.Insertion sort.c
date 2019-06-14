#include<stdio.h>

int  main()
{
    int n,i,x,j;

    int a[100];

    printf("Enter how many numbers U want to sort:");

    scanf("%d",&n);

    printf("Enter the elements:");

    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    for(i=1;i<n;i++)
    {
        x=a[i];

        j=i-1;

        while(j>=0&&a[j]>x)
        {
            a[j+1]=a[j];

            j=j-1;
        }

        a[j+1]=x;
    }


   printf("After sorting: ");

    for(i=0;i<n;i++)
    {
        printf("%d  ", a[i]);
    }


    return 0;
}

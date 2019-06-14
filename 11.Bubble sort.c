// Bubble sort Propgram
#include<stdio.h>
int main()
{
    int size,step,i,j,temp;

    printf("Enter the no of elements: ");
    scanf("%d",&size);

    int input[size];


    for(i=0;i<size;i++)
    {
        scanf("%d",&input[i]);
    }

    //Bubble sort begins here
    //for loop to control the steps
    for(step=0;step<size-1;step++)
    {
        for(j=0;j<size-step-1;j++)
        {
            if(input[j]>input[j+1])
            {
                swap(&input[j],&input[j+1]);

            } // if ends
        } // for loop ends for j

    } //for loop ends for step

    printf("Printing the Data in ascending order\n");

    for(i=0;i<size;i++)
    {
        printf("%4d",input[i]);
    }

    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

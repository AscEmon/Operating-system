# include<stdio.h>

int main()

{
    int a[100],l,r,n,x,i,mid,c=0;

    printf("Enter the array size: ");
    scanf("%d",&n);

   // for(i=0;i<n;i++)
       i=0;
   do
    {
        printf("a[%d]:",i);
        scanf("%d",&a[i]);

        if(i>0&&a[i]<a[i-1]){
            printf("Wrong input please try again.");
            continue;
        }
        i++;
    }while(i<n);

    printf("Which element do you want to search: ");
    scanf("%d",&x);

    l=0;
    r=n-1;

    while(l<=r)
    {
        mid=(l+r)/2;

        if(a[mid]==x){
            c=1;

            break;
        }
        else if(a[mid]>x)
            r=mid-1;

        else
            l=mid+1;
    }

    if(c==1)

    {
        printf("%d is found at %d position.",x,mid+1);
    }

    else{

        printf("%d is not found",x);
    }
}

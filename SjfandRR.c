#include<stdio.h>
#include<stdlib.h>

struct process{
    char process_name;
    int s_t,start_time,finish_time,count,turnaround;
};
void sjf(struct process *a,int x);
int main()
{
    int quantum,c=0;
    float wtr=0,wts=0;
    printf("How many Process???\n");
    int n;
    scanf("%d",&n);
    struct process rr[n],ss[n],bb[n],s[n];
    int st[n];
    int i,et=0;
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        scanf("%c %d",&rr[i].process_name,&rr[i].s_t);
        st[i]=rr[i].s_t;
        rr[i].count=0;
        ss[i]=rr[i];
        bb[i]=rr[i];
        s[i]=rr[i];
    }
    printf("Enter quantum \n");
    scanf("%d",&quantum);
    sjf(s,n);
    int strt=0;
    for(i=0;i<n;i++)
    {
        s[i].start_time=strt;
        s[i].finish_time=strt+s[i].s_t;
        strt=s[i].finish_time;
        wts=wts+s[i].start_time;
    }
    printf("Grand Chart->   Shortest Job First-:\n");
    printf("%2s","");
    for(i=0;i<n;i++)
    {
        printf("%4c",s[i].process_name);
    }
    puts("");
    for(i=0;i<n;i++)
    {
        printf("%4d",s[i].start_time);
    }
    printf("%4d\n\n",s[n-1].finish_time);
    printf("Grand Chart -> Round Robin-:\n");
    et=0;
    c=0;
    printf("%2s","");
    for(i=0;c<n;i++)
    {
        i=i%n;
        if(bb[i].count!=-1)
        {
            printf("%4c",bb[i].process_name);
        }
        if(bb[i].count==0)
        {
            bb[i].start_time=et;
            bb[i].count++;
            wtr=wtr+et;
        }
        if(bb[i].s_t<=quantum&&bb[i].count!=-1)
        {
            et=et+bb[i].s_t;
            bb[i].s_t=0;
            bb[i].finish_time=et;
            c=c++;
        }
        else if(bb[i].s_t>quantum)
        {
            bb[i].s_t=bb[i].s_t-quantum;
            et=et+quantum;
        }
        if(bb[i].s_t!=0)
        {
            printf("");
        }
        else if(bb[i].s_t==0&&bb[i].count!=-1)
        {
            bb[i].count=-1;
        }
    }
    puts("");
    et=0;
    c=0;
    for(i=0;c<n;i++)
    {
        i=i%n;
        if(ss[i].count!=-1)
        {
            printf("%4d",et);
        }
        if(ss[i].count==0)
        {
            ss[i].start_time=et;
            ss[i].count++;
        }
        if(ss[i].s_t<=quantum&&ss[i].count!=-1)
        {
            et=et+ss[i].s_t;
            ss[i].s_t=0;
            ss[i].finish_time=et;
            c=c++;
        }
        else if(ss[i].s_t>quantum)
        {
            ss[i].s_t=ss[i].s_t-quantum;
            et=et+quantum;
        }
        if(ss[i].s_t==0&&ss[i].count!=-1)
        {
            ss[i].count=-1;
        }
    }
    printf("%4d \n",et);
    puts("Comparison: Average to Wait for Response:");
    printf("SJF-> %f",wts/n);
    printf("RR -> %f",wtr/n);
    if(wts>wtr)
    {
        puts("RR is more Efficient");
    }
    else if(wts<wtr)
    {
        puts("SJF is more Efficient");
    }
    else
    {
        puts("Both the Algorithms are equally efficient for this set of process");
    }
    return 0;
}
void sjf(struct process *a,int x)
{
    int i,j;
    struct process temp;
    for(i=x-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {
            if(a[j].s_t>a[j+1].s_t)
               {
                   temp=a[j+1];
                   a[j+1]=a[j];
                   a[j]=temp;
               }
        }
    }
}


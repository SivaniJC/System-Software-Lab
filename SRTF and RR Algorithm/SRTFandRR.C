#include<stdio.h>
int n,qtum,pid[10],a[10],b[10],tt[10],avg[10];
int swt=0,stat=0;
float f_atat=0.0,f_awt=0.0;
int rr()
{
    int ch,st[10],i,count=0,temp,sq=0,totalburst=0;
    printf("\nEnter the no. of process\n");
    scanf("%d",&n);
    printf("Enter burst time\n");
    for(i=0; i<n; i++)
    {
        pid[i]=i+1;
        scanf("%d",&b[i]);
        totalburst+=b[i];
    }
    printf("Enter the quantum: ");
    scanf("%d",&qtum);
    for(i=0; i<n; i++)
    {
        st[i]=b[i];
    }
    while(1)
    {
        for(i=0; i<n; i++)
        {
            temp=qtum;
            if(st[i]==0)
            {
                count++;
                continue;
            }
            if(st[i]>qtum)
                st[i]=st[i]-qtum;
            else if(st[i]>=0)
            {
                temp=st[i];
                st[i]=0;
            }
            sq+=temp;
            tt[i]=sq;
        }
        if(sq==totalburst)
            break;
    }
    printf("\nProcess id burst time wait time turnaround time\n");
    for(i=0; i<n; i++)
    {
        avg[i]=tt[i]-b[i];
        printf("%d\t\t%d\t\t%d\t\t%d",i+1,b[i],avg[i],tt[i]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        swt+=avg[i];
        stat+=tt[i];
    }
    f_awt=(float)swt/n;
    f_atat=(float)stat/n;
    printf("\n\nAverage waiting time is %f\nAverage turnaround time is %f",f_awt,f_atat);
    return 1;
}
int srtf()
{
    int ch,a[10],b[10],x[10],i,smallest,count=0,time=0,n;
    double avg=0,tt=0,end;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    printf("Enter arrival time\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter the burst time\n");
    for(i=0; i<n; i++)
        scanf("%d",&b[i]);
    for(i=0; i<n; i++)
        x[i]=b[i];
    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time &&b[i]<b[smallest] &&b[i]>0)
                smallest=i;
        }
        b[smallest]--;
        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            avg=avg+end-a[smallest]-x[smallest];
            tt=tt+end-a[smallest];
        }
    }
    printf("\nAverage waiting time =%lf\n",avg/n);
    printf("Average turnaround time %lf",tt/n);
    return 0;
}
int main()
{
    int i,ch;
    printf("1:SRTF\n2:RR\n3:exit\n");
    printf("Enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        srtf();
        break;
    case 2:
        rr();
        break;
    case 3:
        return 1;
    }
    return 1;
}
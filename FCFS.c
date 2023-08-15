#include <stdio.h>
struct process{
    int pid;
    int atime;
    int btime;
    int ctime;
    int wtime;
    int tat;
} p[10];

void main(){
    int n,i,ttat=0, twt=0, crtime=0;
    struct process temp;
    printf("enter number of processes:\n");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        p[i].pid = i;
        printf("enter arrival time of process %d: ", i);
        scanf("%d", &p[i].atime);
        printf("enter burst time of process %d: ", i);
        scanf("%d", &p[i].btime);
        p[i].ctime=0;p[i].wtime=0;
    }
    for(int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if(p[i].atime>p[j].atime){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nP\tATime\tBTime\tCTime\tTAT\tWT"); 
    for(i=1;i<=n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t", (i), p[i].atime, p[i].btime, p[i].ctime, p[i].tat, p[i].wtime);
    }

    for(i=1;i<=n;i++){
        if(crtime<p[i].atime){
            crtime=p[i].atime; 
        }
        p[i].ctime = crtime + p[i].btime;
        p[i].tat = p[i].ctime - p[i].atime;
        p[i].wtime = p[i].tat - p[i].btime;
        ttat+=p[i].tat;
        twt+=p[i].wtime;
        crtime=p[i].ctime;
    }
    ttat=ttat/n;
    twt=twt/n;
    printf("\nThe result:");
    printf("\nP\tATime\tBTime\tCTime\tTAT\tWT"); 
    for(i=1;i<=n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t", (i), p[i].atime, p[i].btime, p[i].ctime, p[i].tat, p[i].wtime);
    }
    printf("\nCompleted!");   
    printf("\nTotal TAT: %d, Totat Waiting Time: %d", ttat, twt);   
}

// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.

#include<stdio.h>
#include<stdlib.h>

struct car{
    int pos;
    double time;
};

int cmp(const void* a,const void* b){
    struct car* x=(struct car*)a;
    struct car* y=(struct car*)b;
    return y->pos - x->pos;
}

int main(){
    int n,target;
    scanf("%d%d",&n,&target);
    int position[1000],speed[1000];
    for(int i=0;i<n;i++) scanf("%d",&position[i]);
    for(int i=0;i<n;i++) scanf("%d",&speed[i]);
    struct car c[1000];
    for(int i=0;i<n;i++){
        c[i].pos=position[i];
        c[i].time=(double)(target-position[i])/speed[i];
    }
    qsort(c,n,sizeof(struct car),cmp);
    int fleets=0;
    double maxTime=0;
    for(int i=0;i<n;i++){
        if(c[i].time > maxTime){
            fleets++;
            maxTime=c[i].time;
        }
    }
    printf("%d",fleets);
    return 0;
}
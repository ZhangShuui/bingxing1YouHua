#include <time.h>
#include <iostream>
using namespace std;
double a[1000];
double b[1000][1000];
double sum[1000];
void countit(int n){
    for (int i = 0; i < n; ++i) {
        sum[i]=0.0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum[j]+=b[i][j]*a[i];
        }
    }
}
int main()
{

    for(int i=0;i<1000;i++){
        a[i]=double (i);
        for(int j=0;j<1000;j++){
            b[i][j]=double (i*j);
        }
    }
    int step=10;
    for(int i=10;i<1000;i+=step){
        int freq=CLOCKS_PER_SEC,start=clock(),end=clock();
        int counter=0;

        while(end-start<10){
            counter++;
            countit(i);
            end=clock();
        }
        double sec=double (end-start)/double (freq);
        cout<<i<<","<<counter<<","<<sec<<","<<sec/float (counter)<<endl;
        if (i==100)
            step=100;
    }
    return 0;
}
#include<stdio.h>

/* for interger i to n-3
    for interger j ti n-2
        for integerk to n-1
            if arr[i]^2+a[j]^2==a[k]^2 
            or arr[i]^2+a[k]^2==a[j]^2 
            or arr[k]^2+a[j]^2==a[i]^2
                print a[i] and a[j] and a[k] is the Pythagorean triple*/


void Iterationway(int a[], int n){
    for(int i=0;i<n-2;i++)
    {                 //n
        for(int j=i+1;j<n-1;j++)
        {           //n(n-1)/2
            for(int k=j+1;k<n;k++)
            {         //n(n-1)(n-2)/6

                int d=a[i];
                int b=a[j];
                int c=a[k];

                if((d*d+b*b==c*c)|| d*d+c*c==b*b|| b*b+c*c==d*d){
                    printf("%d %d %d\n",a,b,c);
                }    
            }
        }
    }
}
//-> O(n^3)



int main(){
    int arr[]={3, 12, 5, 5, 4, 10, 6, 13};
    int size=sizeof(arr)/sizeof(arr[0]);
    Iterationway(arr,size);
}
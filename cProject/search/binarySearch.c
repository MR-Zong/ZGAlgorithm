#include<stdio.h>
#include<stdlib.h>

int main(){

    int a[] = {2};//{1,2,3,5,8,9,15,38,44};
    int len = 1;
    int target = 3;
    int low=0,h=len-1,m;
    while(low<=h){
        m = low+(h-low)/2;
        printf("low %d, h %d, m %d\n",low,h,m);
        if(a[m]==target){
            printf("target %d\n",m);
            break;
        }else if(a[m] > target){
            h = m-1;
        }else {
            low = m+1;
        }
    }
    return 0;
}

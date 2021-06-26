#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    long long a[100000], i, j, n, s[100000] = {0}, jj, ii;
    //while there are days to be investigated
    while (cin>>n) {
        
        long long max = 0;//initialize highest emotiona value to zero
        ii=0;
        jj=0;
        for (i = 1; i <= n; i++) {//start populating from day 1 not 0
            cin>>a[i];//enter emotional value
            s[i] = s[i - 1] + a[i];//accumulate sum of values
        }
        for (i = 1; i <= n; i++){
            for (j = i; j <= n; j++) {
                long long min = 9223372036854775807; // maximum size of a 64bit signed integer as minimum value
                //find the lowest by assigning the lowest value with the highest possible first
                for (long long k = i ; k <= j; k++){
                    if (a[k] < min){//if found value is less than min
                        min = a[k];//min is now that value
                    }
                }
                //find the maximum emotional value and max period
                if ((s[j] - s[i-1]) * min > max) {
                //sum of the emotional values of the days in the given period * the smallest emotional value of the day in it
                    max = (s[j] - s[i-1]) * min;
                    jj = j; //start period
                    ii = i; //end period of maximum period
                  

                }
            }
        }
        if(n>0){
            cout<< max<<endl;//print max value
            cout<< ((ii==0)?ii+1:ii) <<" "<< ((jj==0)?jj+1:jj)<<endl;       
        }else if(n==0) {
           cout<<"0\n"<<"0 1\n\n";// print max period
        }
        
    }
}
#include<iostream>
#include"fft.h"
#include"transform.h"
using namespace std;
int main(){
    int len = 16,l=4;
    int *rev = new int[len];
    GetReverse(len,l,rev);
    for(int i=1;i<len;i++)
        {
            cout<<"origin ("<<i<<")  ";
            printBinary(rev[i]);
        }
    cout<<"finish"<<endl;
    delete []rev;
    return 0;
}
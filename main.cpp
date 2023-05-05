#include <iostream>
#include <cmath>
#include <complex>
#include"./include/fft.h"
using namespace std;
// 主函数测试

complex<double> A1[N], A2[N]; // 相乘的多项式
complex<double> C[N]; // 相乘结果
int main(){

    // 两个相乘多项式的初始化。注意：两个相乘多项式和最后的乘积多项式需要有相同的项数

    for(int i = 0; i < N; i ++){
        A1[i] = A2[i] = 0;
    }

    A1[0] = 1, A1[1] = 1, A1[2] = 3, A1[3] = 2; // A1(x) = 2x3 + 3x2 +  x + 1
    A2[0] = 4, A2[1] = 3, A2[2] = 5, A2[3] = 1; // A2(x) =  x3 + 5x2 + 3x + 4

    // F，乘，F逆

    fft(A1, N);
    fft(A2, N);

    for(int i=0;i<N;i++)
    {
        cout<<"A1["<<i<<"]: "<<A1[i]<<"A2["<<i<<"]: "<<A2[i]<<endl;
    }
    for(int i = 0; i < N; i ++) 
        C[i] = A1[i] * A2[i];

    ifft(C, N);

    // 输出

    cout<<"-------------------------------"<<endl;
    for(int i = 0; i < N; i ++) 
        cout << C[i] << endl;

    

    return 0;
}

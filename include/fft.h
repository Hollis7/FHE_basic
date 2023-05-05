#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
#ifndef FFT_H
#define FFT_H
const double pi = 3.14159265358979323846;
const int N = 8; // 多项式的最大支持位数
complex<double> b[N]; // 用来充当临时调整空间的数组

void fft_logic(complex<double> *a, int n, int inv){

    // 参数：
    // 当inv = 1时，a是系数多项式，n是当前数组长度（2的幂次），函数效果是原地变成点值多项式
    // 当inv = -1时，a是点值多项式，n是当前数组长度（2的幂次），函数效果是原地变成系数多项式，但是所得的系数是n倍，需要在包装的函数中进行调整

    if (n == 1) return; // 为什么？因为omega_1^0=1，点值多项式和系数多项式的表示完全一致。

    // 利用B暂存和写回，把a的顺序调整为 a[0] a[2] .. a[n-2] a[1] a[3] .. a[n-1]，前后两半

    for(int i = 0; i < n/2; i ++){
        b[i]       = a[i * 2];
        b[i + n/2] = a[i * 2 + 1];
    }
    for(int i = 0; i < n; i ++)
        a[i] = b[i];

    // 分治求A1和A2

    fft_logic(a, n/2, inv);
    fft_logic(a + n/2, n/2, inv);

    // 通过A1和A2，计算A

    double unit_rad = 2 * pi / n; // 单位角幅度值

    for(int i = 0; i < n/2; i ++){
        complex<double> x(cos(i * unit_rad), inv*sin(i * unit_rad)); // x = omega_n^i 
        complex<double> tmp1 = a[i];
        complex<double> tmp2 = x * a[i + n/2];
        a[i]       = tmp1 + tmp2;
        a[i + n/2] = tmp1 - tmp2;
    }

}

void fft(complex<double> *a, int n){
    // 输入系数多项式及其长度，原地转换为点值多项式
    fft_logic(a, n, 1);
}

void ifft(complex<double> *a, int n){
    // 输入点值多项式及其长度，原地转换为系数多项式
    fft_logic(a, n, -1);
    for(int i = 0; i < n; i ++) 
        a[i] /= n;
}
#endif
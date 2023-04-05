#include <iostream>
using namespace std;
// Function to get the reverse order of indices
void GetReverse(int len, int l, int *rev)
{
    // Initialize the array to 0
    for (int i = 0; i < len; i++)
        rev[i] = 0;
    // Calculate the reverse order of indices
    for (int i = 0; i < len; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
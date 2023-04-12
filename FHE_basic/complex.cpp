// Define the constant PI
const double PI = 3.1415926535;

// Define a complex number struct
struct Complex
{
    double a, b;
    // Constructor with default values of 0
    Complex(double x = 0, double y = 0) { a = x, b = y; }
    // Overload the + operator for complex numbers
    Complex operator+(const Complex &rhs) const { return Complex(a + rhs.a, b + rhs.b); }
    // Overload the - operator for complex numbers
    Complex operator-(const Complex &rhs) const { return Complex(a - rhs.a, b - rhs.b); }
    // Overload the * operator for complex numbers
    Complex operator*(const Complex &rhs) const { return Complex(a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a); }
};

// Define an array to store the reverse order of indices
int rev[Maxsize + 5];

// Function to get the reverse order of indices
void GetReverse(int len, int l)
{
    // Initialize the array to 0
    for (int i = 0; i < len; i++)
        rev[i] = 0;
    // Calculate the reverse order of indices
    for (int i = 0; i < len; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
}

// Function to calculate the exponential of a complex number
inline Complex EXP(double theta)
{
    return Complex(cos(theta), sin(theta));
}
// Function to perform the Fast Fourier Transform
void FFT(vector<Complex> &a, int dir) {
                int len = a.size();
                // Rearrange the elements in bit-reversed order
                for (int i = 0; i < len; i++)
                    if (i < rev[i])
                        swap(a[i], a[rev[i]]);
                // Perform the FFT
                for (int stp = 1; stp < len; stp <<= 1)
                    for (int k = 0; k < stp; k++)
                    {
                        Complex wk = EXP(dir * k * PI / stp);
                        for (int even = k; even < len; even += stp << 1)
                        {
                            int odd = even + stp;
                            Complex tmp = a[odd] * wk;
                            a[odd] = a[even] - tmp;
                            a[even] = a[even] + tmp;
                        }
                    }
                // If performing the inverse FFT, divide each element by the length of the array
                if (dir == -1)
                    for (int i = 0; i < len; i++)
                        a[i].a /= len;
}
    /*
    The FFT function performs the Fast Fourier Transform on a vector of complex numbers a.
    The dir parameter specifies the direction of the transform,
    with dir = 1 for the forward transform and dir = -1 for the inverse transform.
    The function first rearranges the elements of a in bit-reversed order using the rev array,
    which is calculated by the GetReverse function.
    It then performs the FFT using a nested loop structure.
    The outer loop iterates over the different stages of the FFT, with stp representing the stage size.
    The inner loop iterates over the different groups within each stage,
    with k representing the group index. Within each group, the function calculates the twiddle factor wk and
    applies it to the elements in the group using a butterfly operation.
    If performing the inverse FFT, the function divides each element of a by the length of the array to normalize the result.
    */
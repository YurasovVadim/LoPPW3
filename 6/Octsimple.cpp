#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool TrialDivision (uint32_t n)
{
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint32_t i = 3; i <= (uint32_t) sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}
uint32_t BitCount (uint32_t input)
{
    uint32_t res = 0;
    static const unsigned shift_size = ((sizeof(uint32_t) * 8) - 1);
    if(input < 0)
        {
        res ++;
        input &= ( (1 << shift_size) - 1 );
    }
    while(input)
    {
        res += (input & 1);
        input >>= 1;
    }
    return res;
}
int main ()
{
    uint32_t f;
    for (f = 0x80000001; f <= 0xFFFFFFFF; f++)
    {
        if (TrialDivision(f) && BitCount(f) == 3)
        {
            cout << dec << f << "\t" << hex << f << endl;
        }
    }
    return 0;
}
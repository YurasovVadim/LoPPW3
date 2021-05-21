#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
 
 bool TrialDivision(uint64_t n)
{
if (n<2)
return false;
if (n<4)
return true;
if ((n & 1) == 0)
return false;
for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i+=2)
if (n % i == 0)
return false;
return true;
}
 
int main(int argc, char* argv[])
{
    int n=100000;
    uint64_t min = 1ULL<<(n-3);
    uint64_t max = (min << 2) + 2;
    uint64_t r;
    bool result;
    uint64_t a[3];
    mt19937_64 gen(clock());
    uniform_int_distribution<uint64_t> rnd(min,max);
    for (int i = 0; i < 3; i++) {
         system_clock::time_point begin = system_clock::now();
        result = true;
        while(result) {
            r = rnd(gen);
            if (TrialDivision(r)) {
                result = false;
            }
            a[i] = r;
        }
        system_clock::time_point end = system_clock::now();
        duration <double> delta = end-begin;
        cout << a[i] << endl;
        cout << delta.count() << "sec" << endl;
    }
    return 0;
}
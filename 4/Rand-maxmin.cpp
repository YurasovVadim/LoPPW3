#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
 
 bool TrialDivision(uint32_t n)
{
if (n<2)
return false;
if (n<4)
return true;
if ((n & 1) == 0)
return false;
for (uint32_t i = 3; i <= (uint32_t) sqrt(n); i+=2)
if (n % i == 0)
return false;
return true;
}
 
int main(int argc, char* argv[])
{
     int n=10000;
    uint32_t min = 1ULL<<(n-3);
    uint32_t max = (min << 2) + 2;
    uint32_t r;
    vector <int> v;
    v.resize(1000,0);
    bool result;
    mt19937 gen(clock());
    uniform_int_distribution<uint32_t> rnd(min,max);
    for (int i = 0; i < 1000; i++)
    {
        result = true;
        while(result)
        {
            r = rnd(gen);
            if (TrialDivision(r))
            {
                result = false;
            }
        }
        v.at(i) = r;
        cout << v.at(i) << endl;
    }
    int point;
    for (int i = 0; i < 998; i++)
    {
        for (int j = i + 1; j < 1000; j++)
            if(v.at(i) > v.at(j))
            {
                point = v.at(i);
                v.at(i)= v.at(j);
                v.at(j) = point;
            }
    }
    cout << "min number = " << v.front() << endl;
    cout << "max number = " << v.back() << endl;
    return 0;
}
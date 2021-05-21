#include <iostream> 
#include <ctime> 
using namespace std; 

int main ()

{

    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    time_t t = time(NULL);
    tm * ptm;
    char time [100];
    ptm = localtime(&t);
    strftime(time, 100, "В настоящий момент время: %c", ptm);
    cout << time << endl;

    return 0;

}
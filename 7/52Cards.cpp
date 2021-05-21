#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

string number[13] {"Двойка" , "Тройка" , "Четверка" , "Пятерка" ,"Шестерка", "Семерка", "Восьмерка", "Девятка","Десятка","Валет", "Дама", "Король", "Туз"};
string mast[4] {"Крести", "Черви", "Буби", "Пики"};
struct karta {
    int real_mast;
    int real_number;
};
void koloda(vector<karta>& t);
void mix_koloda(vector<karta>& t);
void find_color(vector<karta>& t);
void find_nom(vector<karta>& t);
void find_dama(vector<karta>& t);
void print_ace(vector<karta>& t);
void print_koloda(vector<karta>& t);
int main()
{
    vector<karta> koloda52(52);
    cout << "Колода:" << endl;
    koloda(koloda52);
    print_koloda(koloda52);
    cout << endl;
    cout << "Перемешивание колоды:" << endl;
    mix_koloda(koloda52);
    print_koloda(koloda52);
    cout << endl;
    cout << "Поиск в колоде двух подряд карт одного цвета:" << endl;
    find_color(koloda52);
    cout << endl;
    cout << "Поиск в колоде двух подряд карт одного номинала:" << endl;
    find_nom(koloda52);
    cout << endl;
    cout << "Поиск в колоде дамы пик:" << endl;
    find_dama(koloda52);
    cout << endl;
    cout << "Поиск в колоде всех тузов:" << endl;
    print_ace(koloda52);
    return 0;
}

void koloda(vector<karta>& t)
{
    int i;
    int mast1 = 1;
    int number1 = 2;
    for(i = 0; i < 52; i++) {
        t[i].real_number = number1;
        t[i].real_mast = mast1;
        if (mast1 == 3) {
            mast1 = 0;
            number1++;
        } else
            mast1++;
    }
}

void mix_koloda(vector<karta>& t)
{
    static mt19937 rnd((uint64_t)&rnd);
    shuffle(t.begin(),t.end(),rnd);
}

void find_color(vector<karta>& t)
{
    int i;
    for(i = 1; i < 52; i++) {
        if ((t[i].real_mast == 1 && t[i - 1].real_mast == 2) || (t[i].real_mast == 4 && t[i -1].real_mast == 3) || (t[i].real_mast == 1 && t[i-1].real_mast== 1) || (t[i].real_mast == 2 && t[i - 1].real_mast == 2) || (t[i].real_mast== 3 && t[i - 1].real_mast == 3) || (t[i].real_mast == 4 && t[i - 1].real_mast == 4)) {
            cout << number[t[i - 1].real_number - 2] << " " << mast[t[i - 1].real_mast] << endl;
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] << endl;
            cout << endl;
        }
    }
}

void find_nom(vector<karta>& t)
{
    int i;
    for(i = 1; i < 52; i++) {
        if (t[i].real_number == t[i-1].real_number) {
            cout << number[t[i - 1].real_number - 2] << " " << mast[t[i - 1].real_mast] << endl;
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] << endl;
            cout << endl;
        }
    }
}

void find_dama(vector<karta>& t)
{
    int i;
    for(i = 0; i < 52; i++) {
        if (t[i].real_number == 12 && t[i].real_mast == 3) {
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] <<" находится в колоде на " << i + 1 << "-ом месте" << endl;
            break;
        }
    }
}

void print_ace(vector<karta>& t)
{
    int i;
    for(i = 0; i < 52; i++) {
        if (t[i].real_number == 14 && t[i].real_mast == 0) {
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] <<" находится в колоде на " << i + 1 << "-ом месте" << endl;
        }
        if (t[i].real_number == 14 && t[i].real_mast == 1) {
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] <<" находится в колоде на " << i + 1 << "-ом месте" << endl;
        }
        if (t[i].real_number == 14 && t[i].real_mast == 2) {
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] <<" находится в колоде на " << i + 1 << "-ом месте" << endl;
        }
        if (t[i].real_number == 14 && t[i].real_mast == 3) {
            cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] <<" находится в колоде на " << i + 1 << "-ом месте" << endl;
        }
    }
}

void print_koloda(vector<karta>& t)
{
    int i;
    for(i = 0; i < 52; i++) {
        cout << number[t[i].real_number - 2] << " " << mast[t[i].real_mast] << endl;;
    }
}
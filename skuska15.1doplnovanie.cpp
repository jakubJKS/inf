// skuska15.1doplnovanie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Pole {
private:
    int* data = nullptr;
    int pocet = 0;
public:
    Pole(int poc)
        :pocet(poc), data(pocet > 0 ? new int[pocet] : nullptr)
    {
        if (pocet>0)
        {
            for (int i = 0; i < pocet; i++)
                data[i] = 0;
        }
    }
    ~Pole() { delete[] data; }

    friend ostream& operator<<(ostream& os, Pole& p) 
    {
        for (int i = 0; i < p.pocet; i++)
            os << p.data[i] << endl;
        return os;
    }
};

int main()
{
    Pole p(5);
    cout << p;
    return 0;
}
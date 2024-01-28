#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>    // std::shuffle
//#include <random>       // std::default_random_engine
//#include <chrono>       // std::chrono::system_clock
#include <iterator>
#include <tuple>

int main()
{
    std::tuple<int, char> karta;
    std::vector<std::tuple<int, char>> balik;

    std::string hraci[4]{ "Peter", "Pavol", "Jozef", "Milan" };
    int skore[4]{ 0,0,0,0 };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            karta = std::make_pair(j + 1, i + 65);
            balik.push_back(karta);
        }
    }
    std::cout <<" povodny " << std::endl;
    int oddelovac = 0;
    for (int i = 0; i < 32; i++)
    {
        if (oddelovac != 8)
        {
            std::cout << std::get<0>(balik.at(i)) << std::get<1>(balik.at(i)) << " ";
            oddelovac++;
        }
        else
        {
            std::cout << std::endl;
            std::cout << std::get<0>(balik.at(i)) << std::get<1>(balik.at(i)) << " ";
            oddelovac = 1;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    srand(time(0));

    std::random_shuffle(balik.begin(), balik.end());

    std::cout << " pomiesany " << std::endl;
    int oddelovac1 = 0;
    for (int i = 0; i < 32; i++)
    {
        if (oddelovac1 != 8)
        {
            std::cout << std::get<0>(balik.at(i)) << std::get<1>(balik.at(i)) << " ";
            oddelovac1++;
        }
        else
        {
            std::cout << std::endl;
            std::cout << std::get<0>(balik.at(i)) << std::get<1>(balik.at(i)) << " ";
            oddelovac1 = 1;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << " zrebovanie " << std::endl;


    std::vector<std::tuple<int, char>> kolo;

    for (int kola = 0; kola < 8; kola++)
    {

        for (int i = 0; i < 4; i++)
        {
            std::cout << std::get<0>(balik.at(i)) << std::get<1>(balik.at(i)) << " ";
            kolo.push_back(balik.at(i));
        }

        std::sort(kolo.begin(), kolo.end(), [](const auto& a, const auto& b) {
            if (std::get<0>(a) == std::get<0>(b)) {
                return std::get<1>(a) < std::get<1>(b); // Porovnávanie písmen v abecede
            }
            return std::get<0>(a) > std::get<0>(b); // Inak zoraï pod¾a èísel od najväèšieho po najmenšie
            });

        auto it = std::find(balik.begin(), balik.end(), kolo.at(0));
        std::cout << "Obsah iterátora it: " << "(" << std::get<0>(*it) << ", " << std::get<1>(*it) << ")" << std::endl;
        int index = 0;
        
        
        // If element was found 
        if (it != balik.end())
        {
            index = it - balik.begin();
        }
        else {
            std::cout << "chyba" << std::endl;
        }
        

        std::cout << ": " << hraci[std::get<1>(kolo.at(0)) - 'A'] << " " << std::get<0>(balik.at(index)) << std::get<1>(balik.at(index)) << std::endl;

        skore[index]++;

        for (int i = 0; i < 4; i++)
        {
            balik.erase(balik.begin());
        }

        kolo.clear();

    }

    std::cout << std::endl << "Vysledok:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << hraci[i] << ": " << skore[i] << std::endl;
    }

}

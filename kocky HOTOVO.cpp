#include <iostream>
#include <string>
#include <tuple>
#include <ctime>
#include <limits>
#include <map> // P�id�na hlavi�ka pro pou�it� std::map

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::tuple<std::string, std::string, int> hrac;
    std::string hraci[4]{ "Peter", "Pavol", "Jozef", "Milan" };
    std::string farba[4]{ "biela", "modra", "hneda", "zlata" };
    int priorita[4]{ 1,2,3,4 };

    // Mapa pro sledov�n� po�tu v�her ka�d�ho hr��e
    std::map<std::string, int> vitezstvi;

    for (int i = 0; i < 4; i++)
    {
        std::cout << hraci[i] << "                   ";
    }
    std::cout << std::endl;

    for (int kolo = 0; kolo < 10; kolo++)
    {
        int nejvyssiCislo = std::numeric_limits<int>::min();
        std::string vitaz;
        int hodnotaVitaze = 0;
        int prioritaVitaze = 0;
        std::cout << std::endl;

        bool existujeVetsiHodnota = false; // P�id�na prom�nn� pro kontrolu
        bool tie = false;  // P�id�na prom�nn� pro kontrolu rem�zy

        for (int i = 0; i < 4; i++)
        {
            int index = std::rand() % 4;
            hrac = std::make_tuple(hraci[i], farba[index], priorita[index]);
            int nahodnaHodnota = (std::rand() % 6) + 1;

            std::cout << nahodnaHodnota << " " << farba[index] << "                ";

            if (nahodnaHodnota > nejvyssiCislo || (nahodnaHodnota == nejvyssiCislo && priorita[index] < prioritaVitaze))
            {
                nejvyssiCislo = nahodnaHodnota;
                vitaz = hraci[i];
                hodnotaVitaze = nahodnaHodnota;
                prioritaVitaze = priorita[index];
                existujeVetsiHodnota = true; // Nastav�me na true, pokud najdeme v�t�� hodnotu
                tie = false; // Pokud najdeme v�t�� hodnotu, nem�me rem�zu
            }
            else if (nahodnaHodnota == nejvyssiCislo && priorita[index] == prioritaVitaze)
            {
                tie = true;  // Pokud hodnoty jsou stejn�, m�me rem�zu
            }
        }

        // Vyp�e v�t�ze nebo slovo TIE po ka�d�m kole
        if (existujeVetsiHodnota && !tie) {
            std::cout << "Vitaz kola " << kolo + 1 << ": " << vitaz << " s hodnotou: " << hodnotaVitaze << " a prioritou: " << prioritaVitaze << std::endl;
            // Zaznamen�me v�t�zstv� pro hr��e
            vitezstvi[vitaz]++;
        }
        else {
            std::cout << "Kolo " << kolo + 1 << " sa nevyhodnotilo (TIE)" << std::endl;
        }
    }

    std::cout << "\nStatistiky vitezstvi po 10 kolech:\n";

    // Vyp�e statistiky v�her pro ka�d�ho hr��e
    for (const auto& pair : vitezstvi) {
        std::cout << pair.first << ": " << pair.second << " vitezstvi\n";
    }

    _CrtDumpMemoryLeaks();
}

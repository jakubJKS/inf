#include <iostream>
#include <string>
#include <tuple>
#include <limits>  // pre std::numeric_limits

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(static_cast<unsigned int>(time(0)));
    std::tuple<std::string, int> hrac;
    std::string hraci[5]{ "Peter", "Milan", "Jozef", "Pavol", "Boris" };
    int kvalifikacia[5]{ 1,2,3,4,5 };
    int body[5]{ 0,0,0,0,0 };

    for (int i = 0; i < 5; i++)
    {
        hrac = std::make_tuple(hraci[i], kvalifikacia[i]);
        std::cout << std::get<0>(hrac) << " " << std::get<1>(hrac) << std::endl;
    }


    for (int kolo = 0; kolo < 4; kolo++)
    {
        std::cout << std::endl;
        std::cout << kolo + 1 << ". kolo: " << std::endl;

        int najmenejBody = std::numeric_limits<int>::max();
        std::string vyhernyHrac;
        int kvalifikaciaVyherneho = 0;  // Ukladá hodnotu kvalifikácie víťaza

        for (int i = 0; i < 5; i++)
        {
            if (hraci[i] != "") {  // Kontrola, či hráč ešte nevypadol
                int nahodnaHodnota1 = std::rand() % 21;
                int nahodnaHodnota2 = std::rand() % 21;
                int nahodnaHodnota3 = std::rand() % 21;
                body[i] = nahodnaHodnota1 + nahodnaHodnota2 + nahodnaHodnota3;

                // Vypísať meno hráča a hodnoty po každom hode
                std::cout << hraci[i] << ": " << nahodnaHodnota1 << " " << nahodnaHodnota2 << " " << nahodnaHodnota3 << " (Celkovo: " << body[i] << ")" << std::endl;

                // Aktualizovať najmenej bodového hráča
                if (body[i] < najmenejBody || (body[i] == najmenejBody && kvalifikacia[i] > kvalifikaciaVyherneho)) {
                    najmenejBody = body[i];
                    vyhernyHrac = hraci[i];
                    kvalifikaciaVyherneho = kvalifikacia[i];
                }
            }
        }

        // Vypísať hráča s najmenej bodmi v danom kole a označiť ho ako vypadnutého
        std::cout << "Vypadol hrac: " << vyhernyHrac << " s najmenej bodmi: " << najmenejBody << std::endl;

        // Označiť vypadnutého hráča
        for (int i = 0; i < 5; i++) {
            if (hraci[i] == vyhernyHrac) {
                hraci[i] = "";  // Označiť hráča ako vypadnutého
            }
        }
    }

    // Nájsť a vypísať víťaza na konci štvrtého kola
    int najviacCelkovo = 0;
    std::string vitaz;

    for (int i = 0; i < 5; i++) {
        if (hraci[i] != "" && body[i] > najviacCelkovo) {
            najviacCelkovo = body[i];
            vitaz = hraci[i];
        }
    }

    std::cout << "Vitaz sutaze po 4. kole: " << vitaz << " s celkovym poctom bodov: " << najviacCelkovo << std::endl;


    // Volání _CrtDumpMemoryLeaks() na konci programu
    _CrtDumpMemoryLeaks();

    return 0;
}

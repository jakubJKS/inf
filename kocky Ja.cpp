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
        int kvalifikaciaVyherneho = 0;  // Uklad� hodnotu kvalifik�cie v�aza

        for (int i = 0; i < 5; i++)
        {
            if (hraci[i] != "") {  // Kontrola, �i hr�� e�te nevypadol
                int nahodnaHodnota1 = std::rand() % 21;
                int nahodnaHodnota2 = std::rand() % 21;
                int nahodnaHodnota3 = std::rand() % 21;
                body[i] = nahodnaHodnota1 + nahodnaHodnota2 + nahodnaHodnota3;

                // Vyp�sa� meno hr��a a hodnoty po ka�dom hode
                std::cout << hraci[i] << ": " << nahodnaHodnota1 << " " << nahodnaHodnota2 << " " << nahodnaHodnota3 << " (Celkovo: " << body[i] << ")" << std::endl;

                // Aktualizova� najmenej bodov�ho hr��a
                if (body[i] < najmenejBody || (body[i] == najmenejBody && kvalifikacia[i] > kvalifikaciaVyherneho)) {
                    najmenejBody = body[i];
                    vyhernyHrac = hraci[i];
                    kvalifikaciaVyherneho = kvalifikacia[i];
                }
            }
        }

        // Vyp�sa� hr��a s najmenej bodmi v danom kole a ozna�i� ho ako vypadnut�ho
        std::cout << "Vypadol hrac: " << vyhernyHrac << " s najmenej bodmi: " << najmenejBody << std::endl;

        // Ozna�i� vypadnut�ho hr��a
        for (int i = 0; i < 5; i++) {
            if (hraci[i] == vyhernyHrac) {
                hraci[i] = "";  // Ozna�i� hr��a ako vypadnut�ho
            }
        }
    }

    // N�js� a vyp�sa� v�aza na konci �tvrt�ho kola
    int najviacCelkovo = 0;
    std::string vitaz;

    for (int i = 0; i < 5; i++) {
        if (hraci[i] != "" && body[i] > najviacCelkovo) {
            najviacCelkovo = body[i];
            vitaz = hraci[i];
        }
    }

    std::cout << "Vitaz sutaze po 4. kole: " << vitaz << " s celkovym poctom bodov: " << najviacCelkovo << std::endl;


    // Vol�n� _CrtDumpMemoryLeaks() na konci programu
    _CrtDumpMemoryLeaks();

    return 0;
}

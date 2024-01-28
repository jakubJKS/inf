// Vytvor program na sutaz v strelbe v ktorom hra vygeneruje 5-30 strelcov s oznacenim "P1,P2,P3,..."
// Sutaz bude fungovat tak ze v kazdom kole strelec vystreli 5 vystrelov (vygeneruje nahodne cislo, a ak je parne tak trafil ak neparne netrafil)
// Za kazde trafenie prida strelcovi bod a potom to vsetkych zoradi podla bodov, a ak maju viaceri strelci rovnako bodov prioritizuje to toho co ma vacsie poradove cislo
// Potom to nasledne na obrazovku vypise vsetkych sutaziacich ktory postupuju (v prvom kole 5, v dalsich vzdy o 1 menej az kym neostane len vitaz) a oddelene vypise aj vsetkych co nepostupili
// Vypis je vo forme "P1: 1 0 0 1 0: 2" takze to vypise oznacenie, kazdu strelu s tym ze jednotky oznacuju trafene strely, a celkovy pocet bodov co zatial ziskali (body sa nepremazavaju po kolach)


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

struct Strelec {
	int cisloOznacenia;
	string oznacenie;
	int body;
	string kolo;
	Strelec(int cisloOznacenia) {
		this->cisloOznacenia = cisloOznacenia;
		this->oznacenie = "P" + to_string(cisloOznacenia);
		this->body = 0;
	}
	void zahrajKolo() {
		this->kolo = "";
		for (int i = 0; i < 5; i++) {
			int vystrel = rand() % 2;
			if (vystrel == 0) {
				this->body++;
				this->kolo += " 1";
			}
			else if (vystrel == 1) {
				this->kolo += " 0";
			}
		}
	}
	void vypisKolo() {
		cout << this->oznacenie << ":" << this->kolo << ": " << this->body << endl;
	}
};

bool porovnaj(Strelec a, Strelec b) {
	if (a.body == b.body) {
		return a.cisloOznacenia > b.cisloOznacenia;
	}
	return a.body > b.body;
}

vector<Strelec> zahrajKola(vector<Strelec> sutaziaci, int kolo) {
	for (int i = 0; i < sutaziaci.size(); i++) {
		sutaziaci.at(i).zahrajKolo();
	}
	sort(sutaziaci.begin(), sutaziaci.end(), porovnaj);
	for (int i = 0; i < sutaziaci.size(); i++) {
		sutaziaci.at(i).vypisKolo();
	}
	cout << endl;
	int vyhodit = sutaziaci.size() - kolo;
	for (int i = 0; i < vyhodit; i++) {
		sutaziaci.pop_back();
	}
	return sutaziaci;
}

int main() {
	srand(time(nullptr));
	vector<Strelec> sutaziaci;
	int pocetSutaziacich = rand() % 26 + 5;
	for (int i = 0; i < pocetSutaziacich; i++) {
		sutaziaci.push_back(Strelec(i + 1));
	}
	for (int i = 5; i > 0; i--) {
		sutaziaci = zahrajKola(sutaziaci, i);
	}
	cout << "Vytazom sa stava: " << sutaziaci.at(0).oznacenie << " " << sutaziaci.at(0).body;
	return 0;
}
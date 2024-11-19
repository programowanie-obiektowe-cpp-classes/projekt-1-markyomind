#pragma once
#include <iostream>
#include <string>

string losowy_wydzial() {
	int numer = rand() % 13;
	string wydzialy[] = {
		" Chemiczny",
		" Elektroniki i Technik Informacyjnych",
		" Elektryczny",
		" Fizyki",
		" Geodezji i Kartografii",
		" Inzynierii Ladowej",
		" Inzynierii Materialowej",
		" Mechaniczny Energetyki i Lotnictwa",
		" Matematyki i Nauk Informacyjnych",
		" Samochodow i Maszyn Roboczych",
		" Mechatroniki",
		" Transportu",
		" Zarzadzania" };

	return wydzialy[numer];
}

string losowe_imie() {
    std::string imie[] = {
        "Ann",
        "Andrew",
        "John",
        "Jane",
        "Bob",
        "Alice",
        "Bertram",
        "Monica",
        "Laura",
        "Eric",
        "Richard",
        "Karen",
        "Clara",
        "Rupert",
        "Bruce",
        "Martha",
        "Elizabeth",
        "Corey",
        "Nancy",
        "Joe",
        "Amy",
        "Mike",
    };

    std::string nazwisko[] = {
        "Hendricks",
        "Smith",
        "Gates",
        "Stein",
        "Warren",
        "Booker",
        "Williamson",
        "Walters",
        "Dunn",
        "Swanson",
        "Knope",
        "Haverford",
        "Ludgate",
        "Meagle",
        "Favreau",
        "Vietor",
        "Lovett",
        "Pfeifer",
        "Rhodes",
        "Abrams",
        "McFaul",
        "Stone",
        "Sisley",
        "Hanneman",
    };
    string rand_name = imie[rand() % 22] + " " + nazwisko[rand() % 24];

    return rand_name;
}

double losowy_rozmiar_buta() {
	double but = 3600 + rand() % (1200 + 1);
	return but / 100;
}

int losowa_ilosc_obser() {
	int fol = rand() % (100000 + 1);
	return fol;
}
bool losowe_uprawnienia() {
	bool woz = rand() % 2;
	return woz;
}
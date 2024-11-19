#include "pracownik.hpp"
#include "kredyt.hpp"
#include "firma.hpp"
#include <string>
	
class Gra {
    public:
		
		Gra(){tura=1;}
		~Gra(){cout << "--Gra" << endl;}
  
	void graj() 
	{
		
		Firma fabryka;
		fabryka.wyczysc_k();
		fabryka.wyczysc_h();
		for(int i=0; i<4; ++i){fabryka.zatrudnij(i);}
		fabryka.set_stan_konta(konto_start);
		fabryka.print_pracownicy();
		fabryka.print_stan_konta();

		
		while(fabryka.get_stan_konta()>0&&fabryka.get_wartosc_firmy()<=cel)
		{
		cout<<endl<<"Tura: "<<tura<<endl;
		cout<<endl<<"Wybierz opcje:"<<endl;
		cout<<"lp - Wypisz pracownikow"<<endl<<"kred - Wypisz kredyty"<<endl<<"wart - Podaj wartosc spolki"<<endl<<"saldo - Podaj stan konta"<<endl;
		cout<<"zinz - Zatrudnij Inzyniera"<<endl<<"zmag - Zatrudnij Magazyniera"<<endl<<"zmkt - Zatrudnij Marketera"<<endl<<"zrob - Zatrudnij Robotnika"<<endl;
		cout<<"wkred - Wez kredyt"<<endl<<"kt - Zakoncz ture"<<endl;
		
		std::string command;
        std::cin >> command;

        if (command == "lp") {
            fabryka.print_pracownicy();
        } else if (command == "zinz") {
            if(fabryka.getn_prac()>=fabryka.getmax_prac()){cout<<endl<<"Maksymalna ilosc pracownikow"<<endl<<endl;}
			else{fabryka.zatrudnij(0);cout<<endl<<"Zatrudniono Inzyniera"<<endl<<endl;}
        } else if (command == "zmag") {
            if(fabryka.getn_prac()>=fabryka.getmax_prac()){cout<<endl<<"Maksymalna ilosc pracownikow"<<endl<<endl;}
			else{fabryka.zatrudnij(1);cout<<endl<<"Zatrudniono Magazyniera"<<endl<<endl;}
        } else if (command == "zmkt") {
            if(fabryka.getn_prac()>=fabryka.getmax_prac()){cout<<endl<<"Maksymalna ilosc pracownikow"<<endl<<endl;}
			else{fabryka.zatrudnij(2);cout<<endl<<"zatrudniono Marketera"<<endl<<endl;}
        } else if (command == "zrob") {
            if(fabryka.getn_prac()>=fabryka.getmax_prac()){cout<<endl<<"Maksymalna ilosc pracownikow"<<endl<<endl;}
			else{fabryka.zatrudnij(3);cout<<endl<<"zatrudniono Robotnika"<<endl<<endl;}
        } else if (command == "saldo") {
            cout<<endl;cout<<"Stan konta: "<<fabryka.get_stan_konta()<<endl<<endl;
        } else if (command == "kt") {
            fabryka.otrzymaj_dochod();tura++;
		} else if (command == "kred") {
            cout<<endl;fabryka.print_kredyt(); cout<<endl;
		} else if (command == "wart") {
            cout<<endl;cout<<"Wartosc firmy: "<<fabryka.get_wartosc_firmy()<<endl<<endl;
		} else if (command == "wkred") {
            if(fabryka.getn_kredyt()>=fabryka.getmax_kredyt()){cout<<endl<<"Maksymalna ilosc kredytow"<<endl<<endl;}
			else{double kwota; int czas; 
				cout<<endl<<"Podaj kwote kredytu: "; cin>>kwota; 
				while(kwota<=0){cout<<"Niepoprawna kwota"<<endl; cin>>kwota;}
				cout<<"Podaj ilosc rat "; cin>>czas; 
				while(czas<=0){cout<<"Niepoprawna ilosc rat"<<endl; cin>>czas;}
				fabryka.wez_kredyt(kwota, czas);cout<<endl<<"Wzieto "<<kwota<<" kredytu / ilosc rat: "<<czas<<" / wartosc raty: "<<kwota/czas<<endl<<endl;}
        } else {
             std::cout << "Nieznana komenda. Sprobuj ponownie.\n";
        }

		}

		if(fabryka.get_wartosc_firmy()>=cel)cout<<endl<<endl<<"WYGRALES - KONIEC GRY"<<endl<<endl;
		else if(fabryka.get_stan_konta()<=0)cout<<endl<<endl<<"FIRMA ZBANKRUTOWALA - KONIEC GRY"<<endl<<endl;
		fabryka.wyczysc_koniec();
	}

	private:
		int tura;
		static const int konto_start=60000;
		static const int cel=150000;
};

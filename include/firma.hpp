#pragma once
#include "pracownik.hpp"
#include "kredyt.hpp"
#include "los.hpp"

class Firma {
    public:
		Firma(){stan_konta=0; n_prac=0; n_kredyt=0; n_inz=0; n_mag=0; n_mkt=0; n_rob=0; wartosc_firmy=0; his_przych_i=0;}
		~Firma(){cout << "--Firma" << endl;}

		double get_stan_konta(){
			return stan_konta;}
		void set_stan_konta(double sk){
			stan_konta=sk;}

		
		void print_stan_konta(){
			cout<<"Stan konta: "<<stan_konta<<endl;}

		
		void print_pracownicy() {cout<< "Lista pracownikow"<<endl; for(int i=0; i<n_prac; i++){cout<<i+1<<" "; prac_tab[i]->print();}}

		
		int getn_prac(){
			return n_prac;}
		int getmax_prac(){
			return max_prac;}
	
		void zatrudnij (int typ){
				if(typ==0){prac_tab[n_prac]=new Inz(losowe_imie(),losowy_wydzial());n_inz++;}
				if(typ==1){prac_tab[n_prac]=new Mag(losowe_imie(),losowe_uprawnienia());n_mag++;}
				if(typ==2){prac_tab[n_prac]=new Mkt(losowe_imie(),losowa_ilosc_obser());n_mkt++;}
				if(typ==3){prac_tab[n_prac]=new Rob(losowe_imie(),losowy_rozmiar_buta());n_rob++;}
				n_prac++;}

		
		double oblicz_przych(){
			
			int liczba_produktow = n_rob*prac_tab[3]->get_wyd();
			cout<<"Potencjalna liczba produktow:		"<<liczba_produktow<<endl;

			
			int pojemnosc_magazynu = n_mag*prac_tab[1]->get_wyd();
			cout<<"Pojemnosc magazynu:			"<<pojemnosc_magazynu<<endl;

		
			if (pojemnosc_magazynu < liczba_produktow) {
				liczba_produktow = pojemnosc_magazynu;
			}
			cout<<"Liczba produktow w magazynie:		"<<liczba_produktow<<endl;

			
			int popyt = n_mkt*prac_tab[2]->get_wyd();
			cout<<"Popyt:					"<<popyt<<endl;

			
			if (liczba_produktow > popyt) {
				liczba_produktow = popyt;
			}
			cout<<"Liczba sprzedanych produktow:		"<<liczba_produktow<<endl;

			
			int cena_produktu = n_inz*prac_tab[0]->get_wyd();
			cout<<"Cena produktu:				"<<cena_produktu<<endl;

			
			cout<<"PRZYCHOD:				"<<cena_produktu*liczba_produktow<<endl;
			return cena_produktu*liczba_produktow;
		}

		/////////////KREDYTY////////////

		int getn_kredyt(){ return n_kredyt; }
		int getmax_kredyt(){ return max_kredyt; }

		void wez_kredyt(double kwota, int raty){
				stan_konta=stan_konta+kwota;
				int i=0;
				while(dost_kredyt[i]!=0)i++;
				kredyt_tab[i]=new Kredyt(kwota, raty);
				dost_kredyt[i]=1;
				n_kredyt++;
			}

		void print_kredyt() {for(int i=0; i<max_kredyt; i++){if(dost_kredyt[i]==1)kredyt_tab[i]->print_kredyt();}}

		void wyczysc_k(){for(int i=0;i<max_kredyt;i++)dost_kredyt[i]=0;}

		void zaplac_raty(){double suma_rat=0;
			for(int i=0; i<max_kredyt; i++){
			if(dost_kredyt[i]==1){
				suma_rat=suma_rat+kredyt_tab[i]->rata();
				if(kredyt_tab[i]->get_raty()==0){dost_kredyt[i]=0;delete kredyt_tab[i];n_kredyt--;}}}
			stan_konta=stan_konta-suma_rat;  cout<<endl<<"Raty kredytu: "<<suma_rat<<endl;}
		
		
		void zaplac_wyn(){double suma_wyn=0;
			for(int i=0; i<n_prac; i++){suma_wyn=suma_wyn+prac_tab[i]->get_wyn();}
			stan_konta=stan_konta-suma_wyn;  cout<<endl<<"Wynagrodzenia:	"<<suma_wyn<<endl;}
		
		
		void otrzymaj_dochod(){
			double przych=oblicz_przych();
			his_przych[his_przych_i]=przych; his_przych_i++; if(his_przych_i==historia)his_przych_i=0;
			stan_konta=stan_konta+przych;zaplac_raty();zaplac_wyn();
			cout<<endl; print_stan_konta(); cout<<"Wartosc firmy:	"<<get_wartosc_firmy()<<endl<<endl;}

		
		void wyczysc_h(){for(int i=0;i<historia;i++)his_przych[i]=0;}

		
		void policz_wartosc_firmy(){double suma=0;for(int i=0;i<historia;i++)suma=suma+his_przych[i];wartosc_firmy=suma/historia;}
		double	get_wartosc_firmy() { policz_wartosc_firmy(); return wartosc_firmy; }

		
		void wyczysc_koniec(){
			for(int i=0; i<max_kredyt; i++){
				if(dost_kredyt[i]==1){delete kredyt_tab[i];}
			}
			for(int i=0; i<n_prac; i++){delete prac_tab[i];}
		}
										
		

    private:
		double stan_konta;

		static const int historia=6;
		int his_przych_i;
		double his_przych[historia];

		double wartosc_firmy;
	
		int n_kredyt;
		static const int max_kredyt = 50000;
		bool dost_kredyt[max_kredyt];
		Kredyt *kredyt_tab[max_kredyt];

		int n_prac;
		int n_inz, n_mag, n_mkt, n_rob;
		static const int max_prac = 1000;
		Pracownik *prac_tab[max_prac];
};

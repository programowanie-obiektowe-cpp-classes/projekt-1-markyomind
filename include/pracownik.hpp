#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pracownik{
    public:
		Pracownik(string imie){imie=imie;}
		Pracownik(){ imie="0";}
		virtual ~Pracownik() {cout << "--Pracownik" << endl;}
		
		string	get_imie(){
			return imie;}

		virtual int get_wyn()=0;
		virtual int get_wyd()=0;
		virtual void print()=0;


    protected:
		string imie;
};

////////////////////////////////////////////

class Inz : public Pracownik{
    public:
		Inz(string im, string cecha){imie=im; cecha_Inz=cecha;}
		Inz(){ imie="0"; cecha_Inz="0";}
		~Inz(){cout << "--Inz" << endl;}

		string get_cecha(){
			return cecha_Inz;}
		virtual int	get_wyn(){
			return wyn_Inz;}
		virtual int get_wyd(){
			return CI;}
		virtual void print(){
			cout<<"Inz - "<<imie<<" / wynagrodzenie: "<<wyn_Inz<<" / wydzial:"<<cecha_Inz<<endl;}
		
    private:
		string cecha_Inz;
		static const int CI = 3000;			
		static const int wyn_Inz = 8000;	
};

//////////////////////////////

class Mag : public Pracownik{
    public:
		Mag(string im, bool cecha){imie=im; cecha_Mag=cecha;}
		Mag(){ imie="0"; cecha_Mag="0";}
		~Mag(){cout << "--Mag" << endl;}

		bool get_cecha(){
			return cecha_Mag;}
		virtual int get_wyn(){
			return wyn_Mag;}
		virtual int get_wyd(){
			return CMag;}
		virtual void print(){
			cout<<"Mag - "<<imie<<" / wynagrodzenie: "<<wyn_Mag<<" / wozek: ";if(cecha_Mag==false)cout<<"nie"<<endl; else cout<<"tak"<<endl;}
		
    private:
		bool cecha_Mag;
		static const int CMag = 4;			
		static const int wyn_Mag = 4500;	
};

//////////////////////////////////

class Mkt : public Pracownik{
    public:
		Mkt(string im, int cecha){imie=im; cecha_Mkt=cecha;}
		Mkt(){ imie="0"; cecha_Mkt=0;}
		~Mkt() {cout << "--Mkt" << endl;}

		int	get_cecha(){
			return cecha_Mkt;}
		virtual int get_wyn(){
			return wyn_Mkt;}
		virtual int get_wyd(){
			return CMkt;} 
		virtual void print(){
			cout<<"Mkt - "<<imie<<" / wynagrodzenie: "<<wyn_Mkt<<" / obserwujacy: " <<cecha_Mkt<<endl;}

    private:
		int cecha_Mkt;
		static const int CMkt = 4;		
		static const int wyn_Mkt=6000;	
};

/////////////////////////////////

class Rob : public Pracownik{
    public:
		Rob(string im, double cecha){imie=im; cecha_Rob=cecha;}
		Rob(){ imie="0"; cecha_Rob=0;}
		~Rob() {cout << "--Rob" << endl;}

		double get_cecha(){
			return cecha_Rob;}
		virtual int get_wyn(){
			return wyn_Rob;}
		virtual int get_wyd(){
			return CRob;}
		virtual void print(){
			cout<<"Rob - "<<imie<<" / wynagrodzenie: "<<wyn_Rob<<" / rozmiar buta: " <<cecha_Rob<<endl;}
		
    private:
		double cecha_Rob;
		static const int CRob = 2;		
		static const int wyn_Rob=4000;	
};

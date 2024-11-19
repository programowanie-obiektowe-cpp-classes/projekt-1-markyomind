#pragma once
#include <iostream>
#include <string>

class Kredyt{
    public:
		Kredyt(double dl, int po_ra){dlug=dl; pozostale_raty=po_ra;}
		~Kredyt() {cout << "--Kredyt" << endl;}

		int	get_raty(){
			return pozostale_raty;}
		double rata(){
			double zap=dlug/pozostale_raty;
			dlug=dlug-zap;
			pozostale_raty--;
			if (pozostale_raty == 0) {
				dlug = 0; return zap;
			}
			else{return 0;}
		}
		virtual void print_kredyt(){
			cout<<"Dlug: "<<dlug<<"Pozostale raty: "<<pozostale_raty<<endl;}
		
    protected:
	double dlug;
    int	pozostale_raty;
};
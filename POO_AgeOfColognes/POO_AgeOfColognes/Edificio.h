#pragma once
#include <iostream>
#include <string>
using namespace std;

class Edificio{
	int custo, saude, defesa;
	const int id;
	static int idtotal;
public:
	Edificio();

	void setCusto(int c);
	void setSaude(int s);
	void setDefesa(int d);

	string getInfo();

	~Edificio();
};
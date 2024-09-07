#pragma once
#include <string>

enum Typebaum { Laub, Nadelbaum };


class Baum
{

public:
	//
	Baum();

	Baum(int alter, int hohe, std::string Typebaum);

	~Baum();
	

	void  printWerteBaum();
	void  zufaeling();
	void zufaelingb();
	void setalter(int i);
	int getAlter() { return alter; }
	int getHoehe() { return hohe; }
	

private:
	int alter;  
	int hohe;
	std::string Typebaum;

};


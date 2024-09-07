#pragma once
#include <vector>
#include "baum.h"

class Wald
{
public:
	Wald();
	~Wald();
		
	void fuellen();
	void printWald();
	void wachsenWald();
	float  maxalter();
	float maxhohe();


private:
	// vektor von Typ Baume
	//Enthalt 
	std::vector<Baum> baeume;
	


};

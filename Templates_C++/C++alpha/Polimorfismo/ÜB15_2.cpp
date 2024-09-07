// ÜB15_2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

class Person {
private:
	std::string vorname;
	std::string nachname;
public:
	Person(std::string nn, std::string vn) : nachname(nn) , vorname(vn) {}
	virtual ~Person() {
		std::cout << "Person Destruktor" << std::endl;
	}
	const std::string& getVorname() const { return vorname; }
	std::string getNachname() const { return nachname; }

	virtual std::string toString() = 0;
};

std::string Person::toString() {
	return vorname + " " + nachname;
}

class StudentIn : public Person{
private:
	std::string matNr;
public:
	StudentIn(std::string nn, std::string vn, std::string mn) : Person(nn,vn), matNr(mn) {}
	~StudentIn() {
		{
			std::cout << "StudentIn Destruktor" << std::endl;
		}
	}
	std::string getMatNr() const { return matNr; }

	std::string toString() override {
		return "StudentIn: " + Person::toString() + " " + getMatNr();
	}
};


class ProfessorIn : public Person {
private:
	std::string lehrgebiet;
public:
	ProfessorIn(std::string nn, std::string vn, std::string l) : Person(nn, vn), lehrgebiet(l) {}
	~ProfessorIn() {
		{
			std::cout << "ProfessorIn Destruktor" << std::endl;
		}
	}
	std::string getlehrgebiet() const { return lehrgebiet; }

	std::string toString() override {
		return "ProfessorIn: " + Person::toString() + " " + getlehrgebiet();
	}
};



int main()
{
	std::vector<Person*> diePersonen;

	diePersonen.push_back(new StudentIn("Herder", "Johann Gottfried", "635374"));
	diePersonen.push_back(new ProfessorIn("Kant", "Immanuel", "Philosophie"));
	diePersonen.push_back(new StudentIn("von Schön", "Theodor", "123429"));
	
	for (auto personPtr : diePersonen) {
		std::cout << personPtr->getVorname() << std::endl;
	}

	for (auto personPtr : diePersonen) {
		std::cout << personPtr->toString() << std::endl;
	}

	for (auto personPtr : diePersonen) {
		delete personPtr;
	}


	system("pause");
    return 0;
}


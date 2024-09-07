// UB13_1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string vorname;
	string nachname;

public:
	//Oberklassenkonstruktor mit defaultwerten (deshalb braucht man an dieser Stelle keinen Standardkosntruktor)
	Person(string v = "keinName", string n = "keinName") :vorname(v), nachname(n) {}
	
	std::string out() {
		return vorname + " " + nachname + " ";
	}

	void setNachname(const string& n) {
		nachname = n;
	}

	
};

//Ausgabeoperator gibt ausgabestrom zurück, der p.out, also Methode out() der Klasse Person enthält
//Siehe unten analog zu den anderen Klassen und Ausgabeoperatoren
ostream& operator << (ostream& ausgabestream, Person& p) {
	
	return ausgabestream << p.out();

}



//Erbt von Person (Unterklasse von Person)
class Unimitarbeiter : public Person {

private:
	unsigned personalnr;
public:
	//Durch Oberklassenkonstruktor Aufruf ist es möglich auch vorname und nachname als Parameter zu üerbegeben, da
	//vor und nachname in Person zugeweisen werden
	//Kein Standardkonstruktor notwendig, da default Wert in der Parameterliste (unsigned p = 0)
	//ACHTUNG!! NUR ALS INITIALISIERERLISTE IST ES ERLAUBT EINEN OBERKLASSENKONSTRUKTOR AUFZURUFEN
	Unimitarbeiter(string v, string n, unsigned p = 0) : Person(v, n), personalnr(p) {}
	

	//Überschreibt die Methode out() von Person
		string out() {
			//Ruft explizit die Methode out() von der Oberklasse Person  
			return Person::out() + to_string(personalnr);
			//zusätzlich wird die Personalnr aus dieser Klasse ausgegeben
		
	}
};


ostream& operator << (ostream& ausgabestream, Unimitarbeiter& u) {
	return ausgabestream << u.out();
}


//Unterklasse von PErson
class Student : public Person {
private:
	unsigned matrikelnr;
	string studiengang;

public:
	//Durch Oberklassenkonstruktor Aufruf ist es möglich auch vorname und nachname als Parameter zu üerbegeben, da
	//vor und nachname in Person zugeweisen werden
	//Kein Standardkonstruktor notwendig, da default Wert in der Parameterliste (unsigned m = 0)
	//ACHTUNG!! NUR ALS INITIALISIERERLISTE IST ES ERLAUBT EINEN OBERKLASSENKONSTRUKTOR AUFZURUFEN
	Student(string v, string n, string s= "kein Studiengang", unsigned m=0 ) : Person(v,n), studiengang(s), matrikelnr(m) {}
	
	string out() {
		//Ruft explizit die Methode out() von der Oberklasse Person auf
		return Person::out() + ", " + studiengang + ", " + to_string(matrikelnr) + '\n';
		//zusätzlich wird der Studiengang aus dieser Klasse ausgegeben
		
	}

};
ostream& operator << (ostream& ausgabestream, Student& s) {
	return ausgabestream << s.out();
}


//Unterklasse von Unimitarbeiter --> autom. Unterklasse von Person
class Professor : public Unimitarbeiter {
private:
	
	string fachgebiet;

public:
	//Durch Oberklassenkonstruktor Aufruf ist es möglich auch vorname, nachname und Personalnr als Parameter zu üerbegeben, da
	//vor und nachname in Person zugeweisen werden und Personalnr in Unimitarbeiter
	//Kein Standardkonstruktor notwendig, da default Wert in der Parameterliste (string f ="kein Fachgebiet")
	//ACHTUNG!! NUR ALS INITIALISIERERLISTE IST ES ERLAUBT EINEN OBERKLASSENKONSTRUKTOR AUFZURUFEN
	Professor(string v, string n, unsigned p, string f ="kein Fachgebiet") : Unimitarbeiter(v,n,p), fachgebiet(f) {}

	string out() {
		//Ruft explizit die Methode out() von der Oberklasse Unimitarbeiter auf, die wiederum
		//die Methode out() von der Oberklasse Person aufruft (zusätzlich wird in Unimitarbeiter die personalnr ausgegeben)
		return Unimitarbeiter::out() + ", " + fachgebiet;
		//zusätzlich wird das Fachgebiet aus dieser Klasse ausgegeben	
	}
};

ostream& operator << (ostream& ausgabestream, Professor& p) {
	return ausgabestream << p.out();
}

class Doktorand : public Unimitarbeiter {
private:
	string seminarthema;
public:
	//Durch Oberklassenkonstruktor Aufruf ist es möglich auch vorname, nachname und Personalnr als Parameter zu üerbegeben, da
	//vor und nachname in Person zugeweisen werden und Personalnr in Unimitarbeiter
	//Kein Standardkonstruktor notwendig, da default Wert in der Parameterliste (string s ="kein Thema")
	//ACHTUNG!! NUR ALS INITIALISIERERLISTE IST ES ERLAUBT EINEN OBERKLASSENKONSTRUKTOR AUFZURUFEN
	Doktorand(string v, string n, unsigned p, string s ="kein Thema") : Unimitarbeiter(v, n, p), seminarthema(s) {}

	string out() {
		//Ruft explizit die Methode out() von der Oberklasse Unimitarbeiter auf, die wiederum
		//die Methode out() von der Oberklasse Person aufruft (zusätzlich wird in Unimitarbeiter die personalnr ausgegeben)
		return Unimitarbeiter::out() + ", " + seminarthema;
		//zusätzlich wird das Seminarthema aus dieser Klasse ausgegeben
	}
};

	ostream& operator << (ostream& ausgabestream, Doktorand & d) {
		return ausgabestream << d.out();
	}

int main()
{
	
	Student st("Leonardo", "da Pisa", "Master Mathematik", 11235813);
	
	
	Person pe;
	pe = st;			//Objekt von Student wird dem Objekt von Person zugeweisen -->Datenverlust, aber zuweisungskompatibel
	
	st.setNachname("Fibonacci");
	Professor pr("Albert", "Einstein", 69776750, "Theoretische Physik");
	

	Doktorand dr("Alan", "Turing", 10010110, "Berechenbarkeit und das Halteproblem ");
	
	Unimitarbeiter um(dr);
	Person p;
	cout << p << endl;
	
	cout << pe << endl;
	cout << st << endl;
	cout << pr << endl;
	cout << dr << endl;
	cout << um << endl;

	system("pause");
	return 0;
}

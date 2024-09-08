// template.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include <iostream>
#include <vector>

using namespace std;

// funktion
template<typename T >
T min(T  a, T b)
{

	return a < b ? a : b;

}

template<typename T >
void tausche(vector <T>& v)
{
	T a = v[0];
	v[0] = v[1];
	v[1] = a;

}


double  addiere(int x, double y)

{
	double erg = 0;
	erg = x + y;
	return erg;
}

template <typename T1, typename  T2>
T2 addiere(T1 x, T2 y)
{
	T2 erg = 0;
	erg = x + y;
	return erg;
}


int main()
{
	std::vector<int> vI;
	vector<double>vD;
	vector<char> vC;
	
	for (size_t i = 0; i < 2; i++)
	{
		vI[i]=i;
	}
	
	



	



	


	int a = 3; int  b = 4;
	float d1 = 3.5, d2 = 5.9;
	//char c1 = 'g', char c2 = 'u';
	cout << " Minimun von " << a << b << "  is "  <<std::min(a, b) << endl;

	cout << " addiction mit 2 verschidene " << addiere(a, d1) << endl;


	cout << "  " << vI[0] << vI[1] << endl;
	cout << "  " << vD[0] << vD[1] << endl;
	cout << "  " << vC[0] << vC[1] << endl;

	tausche(vI);
	tausche(vD);
	tausche(vC);

	cout << "  " << vI[0] << vI[1] << endl;
	cout << "  " << vD[0] << vD[1] << endl;
	cout << "  " << vC[0] << vC[1] << endl;
	cout << " adresse" << &a << endl;

	return 0;
}
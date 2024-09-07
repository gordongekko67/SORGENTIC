#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

void Cubi(double lato, double &perimetro, double &supLat, double &vol)
{
   perimetro=4*lato;
   supLat=6*pow(lato,2);
   vol = pow(lato,3);
}


int main(int argc, char *argv[])
{
    double somma=0;
    double lato=0, perimetro=0, supLat=0, volume=0;

    do
    {
      cout<<"Inserire la misura del lato: ";
      cin>>lato;

      Cubi(lato, perimetro, supLat, volume);

      if (supLat<200)
      {
        somma+=supLat;
        cout<<"Superficie laterale di questo cubo: "<<supLat<<". Totale ad ora: "
            <<somma<<endl;
      }
      else
        cout<<"Cubo scartato (superficie "<<supLat<<")"<<endl;

    } while (somma<=1000);

    system("PAUSE");
    return EXIT_SUCCESS;
}

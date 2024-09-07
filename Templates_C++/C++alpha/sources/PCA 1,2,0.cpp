
// Pgm di simulazione quotazioni titoli in Borsa
// SISTEMA.CPP 
//
//  Questo pgm applica il principio della PCA
//  vendendo  POCO PER VOLTA appena il prezzo di vendita e' superiore al prezzo
//  medio di carico 

///////////////////////////////////////////////////////////////////////////
//          include
//////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Scrivifile.cpp"  

int ricalcolo(void);     // funzione di ricalcolo
int parzi(void);         // funzione di ricalcolo quantità parziale 
int numerocasuale(void); // funzione di calcolo numero casuale
int spazio(void)       ; // funzione per spaziare

using std::cout;
using std::cin;
using std::endl;
using std::setw;

///////////////////////////////////////////////////////////////////////////
//          dichiaro variabili
///////////////////////////////////////////////////////////////////////////

double media_qta;
double cap_iniziale;
double parzi_qta;
double total_val;
double valore_acq;
double valore_ven;
double qta_acq;
double qta_ven;
double total_qta;
double Valore;
double Valore_fin;
double guadagno_patrim;
double guadagno_fin;
double guadagno_totale;
double guadagno_totale_tot;
double media_array80;
double media_array120;
double perdita_totale;
double perdita_singola;
double total_val_cash;
double total_val_cash_iniziale;
double total_val_par;
double perce_vendita;
double perce_acquisto;
double valore_cash_netto;
double coefficiente_acquisto;
double coefficiente_vendita;
int numgiorni;
int  z; 
int  i;
int  j;
long int guadagno_tot;
long int gua_sing;
int      flagac ;
int      operazioni_vincita;
int      operazioni_perdita;
int      numero_simulazioni;
int      numero_operazioni;
int      aa0;
int      aa1;
float    aa1doub;
float    aa2;
int      aa3;

/////////////////////////////////////////////////////////////////////////
//          MAIN LINE
/////////////////////////////////////////////////////////////////////////

int main()
{

	//    azzeramento variabili iniziale

	operazioni_vincita = 0;
	operazioni_perdita = 0;
	numero_simulazioni = 1;
	numero_operazioni  = 700;
	coefficiente_acquisto = 0.8;
	coefficiente_vendita = 1.2;


	for ( int z = 1; z <= numero_simulazioni;  z++  )
	{
		// inizializzo le variabili
		Valore    = 100;      
		media_qta = 100;
		total_val = 10000;
		total_val_cash_iniziale = 200000;
		total_qta = 100;
		guadagno_tot = 0;
		flagac = 0;
		perce_vendita  = 0.2; // percentuale di patrimonio da vendere  
		perce_acquisto = 0.2; // percentuale di patrimonio da acquistare
		srand( time(0));      // randomizzazione tramite l'ora 
		cap_iniziale = total_val;	
		total_val_cash = total_val_cash_iniziale;

		// ricalcolo
		ricalcolo();

		for ( int i = 1; i <= numero_operazioni; i++ )
		{
			//richiamo la routine di generazione numero casuale 
			numerocasuale();
			//  cout << Valore << " " << aa2 << endl;

			numgiorni = numgiorni + 1;

			// determino la quantità parziale per vedere se ho abbastanza cash disponibile
			parzi();

			if (Valore < media_array80  && total_val_cash > total_val_par) {
				// spaziatura 
				spazio();
				cout <<  "   Titolo da acquistare a " << Valore  << " num giorni " << numgiorni << endl; 

				// determino di quanto devo comprare
				valore_acq = total_val*perce_acquisto;
				// determino la quantità
				qta_acq = valore_acq/Valore;
				// sommo al totale quantità
				total_qta = total_qta + qta_acq;

				// sommo il totale del valore
				total_val = total_val + valore_acq;
				// ricalcolo il prezzo medio		
				media_qta = total_val / total_qta;
				// sottraggo la quantità di cash
				total_val_cash = total_val_cash - valore_acq;

				// ricalcolo
				ricalcolo();

				//     std::cin.get();
				flagac = 0;

			}
			// controllo se opportuno vendere      
			if (Valore > media_array120 && (flagac == 0 || numgiorni > 100))  {
				spazio();
				cout <<  "   Titolo da vendere a " << Valore  << "   " << numgiorni << endl;

				// determino quanto vendere
				valore_ven = total_val*perce_vendita;

				// determino la quantità
				qta_ven = valore_ven/Valore;

				// guadagno da singola operazione 		
				gua_sing = (Valore-media_qta)*qta_ven;

				cout <<  " quantità in vendita   " <<  qta_ven  << endl;
				cout <<  "   guadagno operazione SINGOLA " <<  gua_sing << endl;

				// sommo al guadagno totale		
				guadagno_tot = guadagno_tot + gua_sing;

				// diminuisco il valore 
				total_val = total_val - valore_ven;
				// diminuisco la quantità
				total_qta = total_qta - qta_ven;
				// ricalcolo la media	
				media_qta = total_val / total_qta;
				// aggiungo al cash il valore venduto
				total_val_cash = total_val_cash + valore_ven;

				// ricalcolo
				ricalcolo();

				//   std::cin.get();
				numgiorni = 0;
				flagac = 1;
			}



		}

		//     Report finale
		spazio();
		cout <<  " Prezzo finale  " << Valore << endl;
		Valore_fin = total_qta * Valore;
		cout <<  " Valore finale patrimonio " << Valore_fin << endl;
		cout <<  " Totale investito storico " << cap_iniziale << endl;
		guadagno_patrim = Valore_fin - cap_iniziale;
		cout <<  " Guadagno/perdita relativa alla singola simulazione !!!! " << guadagno_patrim << endl;
		cout <<  " valore cash finale "<< total_val_cash << endl;
		cout <<  " valore cash iniziale " << total_val_cash_iniziale << endl;
		valore_cash_netto = total_val_cash - total_val_cash_iniziale;
		cout <<  " valore cash netto    "  << valore_cash_netto << endl;
		guadagno_totale = guadagno_patrim+ valore_cash_netto ; 
		guadagno_totale_tot= guadagno_totale_tot + guadagno_totale;
		cout <<  " guadagno totale     "  << guadagno_totale << endl;
		if (guadagno_totale > 0)
			operazioni_vincita = operazioni_vincita + 1;                                                  
		else
			operazioni_perdita = operazioni_perdita + 1; 
		std::cin.get();          
	}

	spazio();
	cout <<  " Operazioni VINCITA!!!! " << operazioni_vincita << endl;
	cout <<  " Operazioni PERDITA!!!! " << operazioni_perdita << endl;
	cout <<  " FINALE        !!!!!!!! " << guadagno_totale_tot   << endl; 
	Scrivifile x;
	x.numgiorni= numgiorni;
	x.operazioni_vincita= operazioni_vincita;
	x.operazioni_perdita= operazioni_perdita;
	x.Scrivi();


	std::cin.get();


	return 0;

}

int ricalcolo(void)
{
	media_array80 = media_qta * coefficiente_acquisto;
	media_array120 = media_qta  * coefficiente_vendita;         
	cout << "-- quote -- patrim ----- PMC  ----- Sogl.acq ---- Sogl.vendita ---" << endl;
	cout << "* "<< total_qta << "   " << total_val << "          "   << media_qta << "       " << media_array80 <<  "           "  << media_array120 << "" <<  endl;
	cout << " cash $  "<< total_val_cash  << " valore della operazione " << total_val_par << endl; 
	return 0;

}

int parzi(void)
{
	parzi_qta =(total_val*perce_vendita)/Valore;
	total_val_par = parzi_qta *Valore;

	return 0;


}

int numerocasuale(void)
{

	// random della casistica
	aa0 = rand() % 100;

	if (aa0 >= 0  && aa0 <= 49)
		aa1 = 1  + rand() % 100;
	if (aa0 >= 50 && aa0 <= 82)
		aa1 = 100 + rand() % 100;
	if (aa0 >= 83 && aa0 <= 96)
		aa1 = 200 + rand() % 100; 
	if (aa0 >= 97 && aa0 <= 98)
		aa1 = 300 + rand() % 200;
	if (aa0 >= 99 && aa0 <= 99)
		aa1 = 500 + rand() % 400;

	// il valore ottenuto viene diviso * 100 per avere la percentuale

	aa1doub = aa1;
	aa2 =  aa1doub/100;

	// si decide se la percentuale ha segno positivo o negativo

	aa3 = rand() % 10;
	if ( aa3 < 5 )
		aa2 = aa2 * (-1);

	//ricalcolo del valore 

	Valore = Valore + ( Valore *aa2/100);


	return 0;


}

int spazio(void)
{                                                                                      
	cout << "--------------------------------------------------------------------------" << endl;


	return 0;



}

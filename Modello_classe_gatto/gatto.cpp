#include <iostream>
#include <string>
#include <algorithm>
#include "gatto.h"

using namespace std;


int main() {
    // Creazione di un oggetto di tipo Gatto
    Gatto g1("Micio", 4, 2);
    g1.miagola();

    Gatto g2;
    g2.setName("Birba");
    g2.miagola();

    return 0;
}

/* cppbuch/k23/textverarbeitung/csvauswerten.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 4. Aufl., korr. Nachdruck 2016
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib> // für exit( )
#include <fstream>
#include <iostream>

std::vector<int> splitInt(char *buf, const char *trennzeichen) {
  std::vector<int> vec;
  char *str = std::strtok(buf, trennzeichen);
  while (str) {
    vec.push_back(atoi(str));
    str = strtok(NULL, trennzeichen);
  }
  return vec;
}

using namespace std;

int main() {
  string csvDateiname;
  cout << "CsvDatei? ";
  cin >> csvDateiname;
  ifstream quelle(csvDateiname); // Dateiobjekt anlegen
  if (!quelle) {                 // Fehlerabfrage
    cerr << csvDateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }
  vector<vector<int>> tabelle;
  constexpr size_t N{1000};
  char buf[N]; // Muss groß genug für eine Zeile sein
  while (quelle.good()) {
    quelle.getline(buf, N);
    if (!quelle.fail()) {
      tabelle.push_back(splitInt(buf, ","));
    }
  }

  quelle.close();
  // Tabelle ausgeben
  for (const auto &zeile : tabelle) {
    for (auto zahl : zeile) {
      cout << zahl << "  ";
    }
    cout << '\n';
  }
}

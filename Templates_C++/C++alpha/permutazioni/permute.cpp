/* cppbuch/k23/folgen/permute.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 4. Aufl., korr. Nachdruck 2016
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <vector>
#include <showContainer.h>
using namespace std;

unsigned long fakultaet(unsigned n) { // Fakultät $n!$ berechnen
  unsigned long fac = 1;
  while (n > 1) {
    fac *= n--;
  }
  return fac;
}

int main() {
  vector<int> v{0, 1, 2, 3};
  unsigned long anzahl =
      fakultaet(v.size()); // Anzahl der Permutationen
  for (unsigned long i = 0; i < anzahl; ++i) {
    if (!prev_permutation(v.begin(), v.end())) {
      cout << "Zyklusbeginn:\n"; // siehe Text
    }
    showContainer(v);
  }
}

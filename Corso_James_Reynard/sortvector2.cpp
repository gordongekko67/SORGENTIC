#include <iostream>
#include <string>
#include <vector>

class isshorter{

    public:
        bool operator() (const std::string & ls, const std::string& rs){
        return ls.size() < rs.size();
        }

};

int main(){

    std::vector<std::string> v;
    v.push_back("ZZZAAAAA");
    v.push_back("BBBBBBB");
    v.push_back("AAAACC");
    v.push_back("ZC");

    sort(begin(v), end(v), isshorter());
    
    for (auto i : v){

        std::cout << i <<  std::endl;
    }




    std::vector<std::string> v2;
    v2.push_back("AA");
    v2.push_back("BBBBB");
    v2.push_back("CC");

    for (auto i : v2){

        if (i.size()> 4){

            std::cout << "trovato l'elemento " <<   i << std::endl;
            break;
        }

    }










    return 0;
}
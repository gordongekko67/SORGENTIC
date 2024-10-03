#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main(){

    std::string s1="Hello world";
    s1[2]='a';
    std::string s2=s1.substr(6);
    std::string s3=s1.substr(6,2);

    //std::string hi ={"Hello"};

    std::string s4 = s2;
    std::string s5 = s1+=s2;
    std::string s6 = s1+s2;

    bool comp = s5.compare(s6);

    std :: cout << " s4 " <<  s4 << std::endl;
    std :: cout << " s5"  << s5 << std::endl;
    std :: cout << " s6 " << s6 << std::endl;
    std :: cout << " comp " <<  comp << std::endl;
    
    
    std::cout << "   "  <<  s1 << "   "  << s2 << "  " << s3 <<  std::endl;

    int pos = s6.find("ld");
    // std::cout << "   "  <<  pos << "   "  <<  std::endl;

    // different member versions of find in the same order as above:
    std::size_t found = s6.find("dfrld");
    if (found != std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';
    else
        std::cout << "Not found " << found << '\n';

    int pos1 = s6.rfind("ld");
    // std::cout << "   "  <<  pos << "   "  <<  std::endl;

    // different member versions of find in the same order as above:
    std::size_t found1 = s6.rfind("ld");
    if (found1 != std::string::npos)
        std::cout << "first 'needle' found at: " << found1 << '\n';
    else
        std::cout << "Not found " << found1 << '\n';



    std::string hello= "Hello world";
    std::size_t poso = hello.find("ero");
    if (poso != std::string::npos)
        std::cout << "first 'needle' found at: " << poso << '\n';
    else
        std::cout << "Not found poso " << found1 << '\n';


    std::string vowels= "aeiou";
    std::cout << hello.find_first_of(vowels) << std::endl;
    std::cout << hello.find_last_of(vowels) << std::endl;
    std::cout << hello.find_first_not_of(vowels) << std::endl;
    std::cout << hello.find_last_not_of(vowels) << std::endl;


    std::string stringa1= "Hello";
    stringa1.append("world");
    std::cout << stringa1 << '\n';

    std::string figa ="fig";
    std::string figa1= figa.insert(3, "one");
    std::cout << figa1 << '\n';


    std::string str5="world";
    auto last = str5.end() -1;
    auto it = str5.insert(str5.begin() + 3, 'G');    
    std::cout << str5 << '\n';
 
    std::string stringa2="Hello world";
    std::string stringa4;
    
    stringa4.erase(4, 3); 
    std::cout << stringa4 << '\n';

    std::string converti= "42";
    int num= stoi(converti);
    std::cout << num << '\n';

    int numll= stoll(converti);
    std::cout << numll << '\n';

    std::string pi="3.143566";
    float numfloat=stof(pi);
    std::cout << numfloat << '\n';


    return 0;
}
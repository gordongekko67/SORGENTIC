#include <iostream>
#include <string>

class refrigerator
{

private:
        int temperature;
        bool door_open;
        bool power_on;
        std::string marca;

public:

        void init(int vtemperature, bool vdoor_open, bool vpower_on, std::string vmarca)
        {
                temperature = vtemperature;
                door_open = vdoor_open;
                power_on = vpower_on;
                marca = vmarca;
        }

        // costruttore di default
        refrigerator()
        {
               init(2,true, false, "Marca anonima");
        }

        // costruttore standard
        refrigerator(int vtemperature, bool vdoor_open, bool vpower_on, std::string vmarca)
        {
                init(vtemperature,vdoor_open,vpower_on, vmarca); 
        }

        // costruttore standard aggiuntivo in overload 
        refrigerator(std::string vmarca)
        {
                init(5,false,false, marca=vmarca);
        }
  
        void stampa_frigo()
        {
                std::cout << "la temperature e' " << temperature << std::endl;
                std::cout << "door  " << door_open << std::endl;
                std::cout << "acceso  " << power_on << std::endl;
                std::cout << "marca   " <<  marca <<  std::endl;
        }
};

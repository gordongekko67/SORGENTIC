// #include "refrigerator.h"

#pragma once

class frigosuper : public refrigerator

{

private:
    int temperature_super;

public:
    frigosuper(int t, bool d, bool p, std::string m, int tt) : refrigerator(t, d, p, m)
    {

        temperature_super = tt;
    }

    frigosuper(int tt)
    {

        refrigerator();
        temperature_super = tt;
    }

    void stampafrigosuper()
    {

        stampa_frigo();
        std::cout << "la temperature super e' " << temperature_super << std::endl;
    }
};

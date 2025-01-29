#include <iostream>
#include <vector>

// Classe base
class Animale {
public:
    virtual void verso() const {
        std::cout << "Un animale fa un verso generico." << std::endl;
    }

    // Distruttore virtuale per garantire corretta distruzione
    virtual ~Animale() = default;
};

// Classe derivata Cane
class Cane : public Animale {
public:
    void verso() const override {
        std::cout << "Il cane abbaia: Bau bau!" << std::endl;
    }
};

// Classe derivata Gatto
class Gatto : public Animale {
public:
    void verso() const override {
        std::cout << "Il gatto miagola: Miao miao!" << std::endl;
    }
};

int main() {
    // Vettore di puntatori alla classe base
    std::vector<Animale*> animali;

    // Creazione dinamica degli oggetti
    animali.push_back(new Cane());
    animali.push_back(new Gatto());
    animali.push_back(new Animale());

    // Chiamata polimorfica al metodo verso()
    for (const auto& animale : animali) {
        animale->verso();
    }

    // Liberazione della memoria
    for (auto& animale : animali) {
        delete animale;
    }

    return 0;
}


#ifndef AMBIENT_HPP
#define	AMBIENT_HPP
#include <armadillo>

using namespace arma;
using namespace std;

class Ambient{
    
private:
    vec ka;
    double Ia;

public:  
    
    Ambient();
    
    Ambient(vec ka, double Ia);

    void SetIa(double Ia) {
        this->Ia = Ia;
    }

    double GetIa() const {
        return Ia;
    }

    void SetKa(vec ka) {
        this->ka = ka;
    }

    vec GetKa() const {
        return ka;
    }
    
};

#endif	/* AMBIENT_HPP */


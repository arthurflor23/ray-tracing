
#ifndef LIGHT_HPP
#define	LIGHT_HPP
#include <armadillo>

using namespace arma;
using namespace std;

class Light{
    
private:
    vec posicao, I;
    
public:
    
    Light();
    
    Light(vec luz){
	this->posicao << luz(0) << luz(1) << luz(2);
	this->I << luz(3) << luz(4) << luz(5);
    }

    void SetI(vec I) {
        this->I = I;
    }

    vec GetI() const {
        return I;
    }

    void SetPosicao(vec posicao) {
        this->posicao = posicao;
    }

    vec GetPosicao() const {
        return posicao;
    }

};


#endif	/* LIGHT_HPP */



#ifndef OBJECT_HPP
#define	OBJECT_HPP
#include <armadillo>

#include "Ambient.hpp"
#include "Light.hpp"
#include "Hittable.hpp"

using namespace arma;
using namespace std;

class Object :public Hittable {

private:
    vec kd, ks, normal;
    mat transf;
    double p;
    int tipo;  
    
public:
    
    Object();
    
    void setTipo(int tipo) {
        this->tipo = tipo;
    }

    int getTipo() const {
        return tipo;
    }

    void setP(double p) {
        this->p = p;
    }

    double getP() const {
        return p;
    }

    void setTransf(mat transf) {
        this->transf = transf;
    }

    mat getTransf() const {
        return transf;
    }

    void setNormal(vec normal) {
        this->normal = normal;
    }
    
    vec getNormal() const {
        return normal;
    }

    void setKs(vec ks) {
        this->ks = ks;
    }

    vec getKs() const {
        return ks;
    }

    void setKd(vec kd) {
        this->kd = kd;
    }

    vec getKd() const {
        return kd;
    }
    
    virtual bool colide(const vec &d, double &T2, const vec &origem){ 
        return false; 
    }
    
    virtual vec getA(){ 
        return 0; 
    }
    
    virtual vec getB(){ 
        return 0; 
    }
    
    virtual vec getC(){ 
        return 0; 
    }
    
    vec cor(const vec &d, const vector<Light> &luz, const vector<Object *> objetos, const Ambient ambiente, const vec &vetor, const unsigned int &indice);

};

#endif	/* OBJECT_HPP */


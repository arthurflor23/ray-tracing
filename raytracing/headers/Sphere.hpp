
#ifndef SPHERE_HPP
#define	SPHERE_HPP

#include "Object.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

class Sphere :public Object {

private:
    double raio;
    vec centro, min, max; 
    
public:
    
    Sphere();
    Sphere(vec esfera);
    
    bool colide(const vec &d, double &T, const vec &origem);
    
    void setMax(vec max) {
        this->max = max;
    }

    vec getMax() {
        return max;
    }

    void setMin(vec min) {
        this->min = min;
    }

    vec getMin()  {
        return min;
    }

    void setCentro(vec centro) {
        this->centro = centro;
    }

    vec getCentro() {
        return centro;
    }

    void setRaio(double raio) {
        this->raio = raio;
    }

    double getRaio(){
        return raio;
    }

};

#endif	/* SPHERE_HPP */


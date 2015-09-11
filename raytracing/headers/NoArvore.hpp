/* 
 * File:   NoArvore.hpp
 * Author: arthur
 *
 * Created on 11 de Setembro de 2015, 09:30
 */

#ifndef NOARVORE_HPP
#define	NOARVORE_HPP

#include <armadillo>

#include "Ambient.hpp"
#include "Light.hpp"
#include "Hittable.hpp"
#include "Box.hpp"
#include "Object.hpp"

using namespace arma;
using namespace std;

class NoArvore :public Hittable {
    
private:
    Box bounds;
    NoArvore *esq, *dir;
    int eixo;
    double split;
    vector<Object *> objetos;
    
public:
    vec getCentro() { 
        return 0; 
    }
    
    vec getMin() { 
        return 0; 
    }
    
    vec getMax() { 
        return 0; 
    }

    static NoArvore * construirArvore(vector <Object *> &objetos, unsigned int &porc, int nivel=0);
    static NoArvore * percorrerArvore(NoArvore * &No, Ray &r, bool &colide, double &Tmin, double &T, int &indice);
    
    static bool Folha(NoArvore * &No);

    void setObjetos(vector<Object*> objetos) {
        this->objetos = objetos;
    }

    vector<Object*> getObjetos() const {
        return objetos;
    }

    void setSplit(double split) {
        this->split = split;
    }

    double getSplit() const {
        return split;
    }

    void setEixo(int eixo) {
        this->eixo = eixo;
    }

    int getEixo() const {
        return eixo;
    }

    void setDir(NoArvore* dir) {
        this->dir = dir;
    }

    NoArvore* getDir() const {
        return dir;
    }

    void setEsq(NoArvore* esq) {
        this->esq = esq;
    }

    NoArvore* getEsq() const {
        return esq;
    }

    void setBounds(Box bounds) {
        this->bounds = bounds;
    }

    Box getBounds() const {
        return bounds;
    }
};

#endif	/* NOARVORE_HPP */


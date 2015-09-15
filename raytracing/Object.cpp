
#include "headers/Object.hpp"
#include "headers/Sphere.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

Object::Object() {
}

vec Object::cor(const vec &d, const vector<Light> &luz, const vector<Object *> objetos, const Ambient ambiente, const vec &vetor, const unsigned int &indice){ 
    
    vec Ca, Co, Cs, V, L, H, cor_final;
    double T2;
    cor_final << 0 << 0 << 0;
    unsigned int ind=0;
	
    for (unsigned int i=0; i<luz.size(); i++){
        bool sombra=false;
            
	for (unsigned int j=0; j<objetos.size(); j++){
            
            if (j!=indice && objetos[j]->colide(d, T2, luz[i].GetPosicao())){
		if ((T2 > 0) && (T2 <= 1)) { 
                    sombra=true;
                    ind = j;
                }
            }
	}
	      
	if (!sombra){
            V = luz[i].GetPosicao()-d;
            L = normalise(luz[i].GetPosicao()-d);
            H = (L+V)/2;
            H = H / norm(H,2);
		
            if (this->getTipo() == 0){ 
                
                this->setNormal(d - this->getCentro());
                this->setNormal(normalise(this->getNormal()));
            }
		
            Co = this->getKd() % luz[i].GetI() * max(0.0, dot(this->getNormal(), L));
            Cs = this->getKs() % luz[i].GetI() * pow(max(0.0, dot(this->getNormal(), H)), this->getP());
            cor_final += Co + Cs;
	} 
    }
    
    Ca = ambiente.GetIa() * ambiente.GetKa();
    cor_final += Ca;
 
    for (int i=0; i<3; i++){
	if (cor_final(i) > 255){
            cor_final(i) = 255;
        }
    
	else if (cor_final(i) < 0){ 
            cor_final(i) = 0; 
        }
    }
	  
    return cor_final;
    
}




#include "headers/Heapsort.hpp"
#include "headers/Object.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

Heapsort::Heapsort() {
}

vector<Object*> Heapsort::heapsort(vector <Object *> &objetos, int n, int eixo){
    
    int i = (n/2)+1, pai, filho;
    Object * t;
   
    for (;;){
        
        if (i > 0){
            i--;
            t = objetos[i];
        }
      
        else{
            n--;
        
            if (n == 0)  { 
                return objetos; 
            } 
            
            t = objetos[n];
            objetos[n] = objetos[0];
        }
      
        pai = i; 
        filho = i*2;
 
        while (filho < n){
          
            if ((filho + 1 < n)  &&  (objetos[filho + 1]->getCentro()(eixo) > objetos[filho]->getCentro()(eixo))) { 
                filho++; 
            }

            if (objetos[filho]->getCentro()(eixo) > t->getCentro()(eixo)){

                objetos[pai] = objetos[filho];
                pai = filho;
                filho = pai*2 + 1;
            }

            else { 
                break; 
            }
        }
    
        objetos[pai] = t;
    }    
    
}


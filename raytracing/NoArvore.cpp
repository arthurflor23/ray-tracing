/* 
 * File:   NoArvore.cpp
 * Author: arthur
 * 
 * Created on 11 de Setembro de 2015, 09:30
 */

#include "headers/NoArvore.hpp"
#include "headers/Heapsort.hpp"
#include "headers/Box.hpp"

#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

bool NoArvore::Folha(NoArvore * &No){
    if (No->getEsq() == NULL && No->getDir() == NULL){
	return true;
    }
    
    return false;
}

NoArvore * NoArvore::construirArvore(vector <Object *> &objetos, unsigned int &porc, int nivel){
    
  NoArvore * No = new NoArvore();
  vector<Object *> esq, dir;
  vec min, max;
  Box bounds;
  
  max = objetos[0]->getMax();
  min = objetos[0]->getMin();

    for (unsigned int i=1;i<objetos.size();i++)
      {
	if (objetos[i]->getMin()(0) < min(0)) { min(0) = objetos[i]->getMin()(0); }
	if (objetos[i]->getMin()(1) < min(1)) { min(1) = objetos[i]->getMin()(1); }
	if (objetos[i]->getMin()(2) < min(2)) { min(2) = objetos[i]->getMin()(2); }
	
	if (objetos[i]->getMax()(0) > max(0)) { max(0) = objetos[i]->getMax()(0); }
	if (objetos[i]->getMax()(1) > max(1)) { max(1) = objetos[i]->getMax()(1); }
	if (objetos[i]->getMax()(2) > max(2)) { max(2) = objetos[i]->getMax()(2); }
      }

  No->setBounds(Box(min, max));
  No->setObjetos(objetos);
  No->setEixo(nivel % 3);
  
    if (nivel >= 20 || objetos.size() <= porc)
      {
	No->setEsq(NULL);
	No->setDir(NULL);
	return No;
      }  
      
  Heapsort::heapsort(objetos, objetos.size(), No->getEixo());
   
  No->setSplit (objetos[objetos.size()/2]->getCentro()(No->getEixo()));
    if (objetos.size()%2==0) { 
        No->setSplit(No->getSplit() + objetos[(objetos.size()/2)-1]->getCentro()(No->getEixo())); 
        No->setSplit(No->getSplit()/2);  
    }
      
    for (unsigned int w=0;w<objetos.size();w++)
    {
	if ((objetos[w]->getMin()(No->getEixo()) <= No->getSplit()) && (objetos[w]->getMax()(No->getEixo()) <= No->getSplit())){
	    esq.push_back(objetos[w]);
	}
        
	else if ((objetos[w]->getMin()(No->getEixo()) > No->getSplit()) && (objetos[w]->getMax()(No->getEixo()) > No->getSplit())){
	    dir.push_back(objetos[w]);
	}
        
	else{
	    esq.push_back(objetos[w]);
	    dir.push_back(objetos[w]);
	}
      }
    
      No->setEsq(NoArvore::construirArvore(esq, porc, nivel+1));
      No->setDir(NoArvore::construirArvore(dir, porc, nivel+1));
      
return No;
}

NoArvore * NoArvore::percorrerArvore(NoArvore * &No, Ray &r, bool &colide, double &Tmin, double &T, int &indice){
    
  NoArvore * NoAtual = No;
  vector <NoArvore *> pilha;
  int nivelDaPilha=0;
  
  while(nivelDaPilha!=-1){
      
      if (!Folha(NoAtual)){
          
	  Ray r0=r, r1=r;
          
	  bool intersecta0 = NoAtual->getEsq()->getBounds().intersect(r0);
	  bool intersecta1 = NoAtual->getDir()->getBounds().intersect(r1);
	  
	  if (intersecta0 && intersecta1){
          
	      if (r1.GetTmin() < r0.GetTmin()){
                  
                pilha.push_back(NoAtual->getEsq());
                NoAtual=NoAtual->getDir();  
              }
		
	      else{
                  
		pilha.push_back(NoAtual->getDir());
  		NoAtual=NoAtual->getEsq(); 
              }
		
	    nivelDaPilha++;
	  }
          
	  else{
	    if (intersecta0){
		NoAtual=NoAtual->getEsq();
            }
            
	    else if (intersecta1){
                NoAtual=NoAtual->getDir();
            }
            
	    else{ 
		nivelDaPilha--;
		
                if (nivelDaPilha!=-1){
                    NoAtual=pilha[nivelDaPilha];
                    pilha.resize(nivelDaPilha);
		}    
            }
	}  
    }
	  
    else{
	for(unsigned int i=0; i<NoAtual->getObjetos().size(); i++){
            
            if(NoAtual->getObjetos()[i]->colide(r.GetD(), T, r.GetOrigem())) {
                colide=true;
		
                if (T>=0 && T<=Tmin){
                    Tmin = T;
                    indice = i;
		}
            }
	}
	    
	if (colide==true) return NoAtual;
	
	  nivelDaPilha--;
	  
          if (nivelDaPilha!=-1){    
	      NoAtual=pilha[nivelDaPilha];
	      pilha.resize(nivelDaPilha);
	    }
	}
    }
  
return NoAtual;
}
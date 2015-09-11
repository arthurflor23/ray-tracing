/* 
 * File:   Read.cpp
 * Author: arthur
 * 
 * Created on 11 de Setembro de 2015, 10:54
 */

#include "headers/Read.hpp"
#include "headers/Ambient.hpp"
#include "headers/Object.hpp"
#include "headers/Sphere.hpp"
#include "headers/Triangle.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

int Read::leitura(const char *txt, vector<Object *> &objetos, vector<Light> &luz, Ambient &ambiente, mat &keye, int &cont_tri){
    
  double cont, k, j, z[3], cont_obj=0;
  vec aux1, aux2;
  mat vertice, face;
  char tipo_objeto[2], tmp[32];
  float valor, valor1, valor2, valor3;
  char barra1[16], barra2[16], barra3[16];
  vector<Sphere *> bola;
  
  ifstream arq (txt, ios_base::in);
  
  if (!arq) { 
    return 1; 
  }
 
  arq >> cont;
 
  for (k=0; k<cont; k++){
      
      arq >> tipo_objeto;
     
      if (strcmp(tipo_objeto, "t")==0){
          
	  for (j=0;j<28;j++){
              
	    arq >> valor;
	    aux1 << valor;
	    aux2 = join_cols(aux2,aux1);
	  }
          
	  objetos.push_back(new Triangle(aux2)); 
	  aux2.reset(); cont_tri++;
	}
 
      else if (strcmp(tipo_objeto, "s")==0){
          
	  for (j=0;j<23;j++){
              
	    arq >> valor;
	    aux1 << valor;
	    aux2 = join_cols(aux2,aux1);
	  }
          
	  bola.push_back(new Sphere(aux2));
	  aux2.reset();   
	}
    }
    
    arq >> cont;

    for (k=0; k<cont; k++){
        
	arq >> tipo_objeto;

	if (strcmp(tipo_objeto, "o")==0){
            
	    arq >> tmp;
	    
	    for (j=0;j<19;j++){
		arq >> valor;
		aux1 << valor;
		aux2 = join_cols(aux2,aux1);
	    }
	  
	    ifstream obj (tmp, ios_base::in);
	    
            if (!obj) { 
                return 1; 
            }
	    
	    while (obj){
		obj >> tipo_objeto;

		if (strcmp(tipo_objeto,"v")==0){
		    obj >> valor1 >> valor2 >> valor3;
		    
		    aux1 << valor1 << valor2 << valor3; 
		    vertice = join_cols(vertice,aux1.t());
		}
     
		else if (strcmp(tipo_objeto,"f")==0){
		    obj >> barra1 >> barra2 >> barra3;
		    
		    z[0]=(atoi(barra1));  z[1]=(atoi(barra2));  z[2]=(atoi(barra3));
		    if (z[0]<0) { z[0] = z[0] * -1; }
		    if (z[1]<0) { z[1] = z[1] * -1; }
		    if (z[2]<0) { z[2] = z[2] * -1; }
	 
		    aux1 << z[0] << z[1] << z[2];
		    face = join_cols(face,aux1.t()); cont_obj++;
		}
	      }
	    obj.close();
	    
	    for (j=0;j<cont_obj;j++){ 
		aux1 << vertice(face(j,0)-1,0) << vertice(face(j,0)-1,1) << vertice(face(j,0)-1,2) 
		     << vertice(face(j,1)-1,0) << vertice(face(j,1)-1,1) << vertice(face(j,1)-1,2) 
		     << vertice(face(j,2)-1,0) << vertice(face(j,2)-1,1) << vertice(face(j,2)-1,2);
		aux1 = join_cols(aux1,aux2);

		objetos.push_back(new Triangle(aux1));
		cont_tri++;
	    }
	      vertice.reset(); face.reset(); cont_obj=0;
	}
	aux2.reset();
     }
     
  for(unsigned int a=0;a<bola.size();a++){
    objetos.push_back(bola[a]);
  }   
     
  arq >> cont;

  for (k=0; k<cont; k++){
      for (j=0;j<18;j++){
	  arq >> valor;
	  aux1 << valor;
	  aux2 = join_cols(aux2,aux1);
      }
      
    luz.push_back(aux2);
    aux2.reset();
  }
  
  for (j=0;j<4;j++){
      arq >> valor;
      aux1 << valor;
      aux2 = join_cols(aux2,aux1);
  }
  
  ambiente.SetKa(aux2(0) << aux2(1) << aux2(2));
  ambiente.SetIa(aux2(3));
  aux2.reset();
  
  for (j=0;j<9;j++){
      arq >> valor;
      aux1 << valor;
      aux2 = join_cols(aux2,aux1);
  }
  
  keye << aux2(2)/aux2(0) << aux2(1) 	     << aux2(2)/2 << endr
       << aux2(3) 	  << aux2(5)/aux2(4) << aux2(5)/2 << endr
       << aux2(6) 	  << aux2(7)         << aux2(8)   << endr;
  
  arq.close(); 
  return 0;
}

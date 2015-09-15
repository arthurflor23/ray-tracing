
#include "headers/Writer.hpp"
#include "headers/NoArvore.hpp"
#include "headers/Object.hpp"
#include "headers/Triangle.hpp"

using namespace arma;
using namespace std;

Writer::Writer(const char *txt, const vector<Light> luz, const mat keye, const Ambient ambiente, NoArvore * No){
    
  int resolucao[2];
  vector<Pixels *> pixel;
  vec origem;

  origem << 0 << 0 << 0;
  resolucao[0] = keye(0,2)*2;
  resolucao[1] = keye(1,2)*2;
  
  for (int w=0;w<resolucao[1];w++){
      for (int z=0;z<resolucao[0];z++){
	  pixel.push_back(new Pixels(z, w));
	} 
    }  
  
  #pragma omp parallel for
  for (int j=0; j<resolucao[0]*resolucao[1]; j++){
      
      double Tmin=numeric_limits<double>::max(), T=numeric_limits<double>::min();
      int indice=0;
      vec d, vetor; 
      bool colide=false;
      NoArvore * NoAtual;
      
	vetor << (int)pixel[j]->getXY()(0) << (int)pixel[j]->getXY()(1) << 1;
        d = keye.i() * vetor;
	  
	Ray r = Ray(origem, d);
	NoAtual = NoArvore::percorrerArvore(No, r, colide, Tmin, T, indice);
	  
	if (colide && luz.size()!=0){
            pixel[j]->color(NoAtual->getObjetos()[indice]->cor(d*Tmin, luz, NoAtual->getObjetos(), ambiente, vetor, indice));
	}
          
	else{ 
            pixel[j]->color(ambiente.GetKa());
	}
    }
    
  ofstream arq (txt, ios_base::out);
  arq << "P3" << endl << resolucao[0] << " " << resolucao[1] << endl << 255 << endl;  

  for (unsigned int i=0;i<pixel.size();i++){
    arq << pixel[i]->getR() << " " << pixel[i]->getG() << " " << pixel[i]->getB() << endl;
  }  

  arq.close();

}


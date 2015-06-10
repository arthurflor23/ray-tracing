
#include <armadillo>
#ifndef RAY_HPP
#define	RAY_HPP

using namespace arma;

class Ray {

private:
    vec origem, d, inv_d;
    double tmin, tmax;
    int sign[3];    
    
public:
    Ray();
    
    Ray(vec origem, vec d){
        
	this->origem = origem;
	this->d = d;
        this->inv_d = 1/d;
	this->tmin = std::numeric_limits<double>::min();
	this->tmax = std::numeric_limits<double>::max();
        this->sign[0] = (inv_d(0) < 0);
        this->sign[1] = (inv_d(1) < 0);
        this->sign[2] = (inv_d(2) < 0);
      }

    void SetTmax(double tmax) {
        this->tmax = tmax;
    }

    double GetTmax() const {
        return tmax;
    }

    void SetTmin(double tmin) {
        this->tmin = tmin;
    }

    double GetTmin() const {
        return tmin;
    }

    void SetInv_d(vec inv_d) {
        this->inv_d = inv_d;
    }

    vec GetInv_d() const {
        return inv_d;
    }

    void SetD(vec d) {
        this->d = d;
    }

    vec GetD() const {
        return d;
    }

    void SetOrigem(vec origem) {
        this->origem = origem;
    }

    vec GetOrigem() const {
        return origem;
    }

    void SetSign(int sign[3]) {
        this->sign[0] = sign[0];
        this->sign[1] = sign[1];
        this->sign[2] = sign[2];
    }

    int* GetSign() {
        return sign;
    }

};

#endif	/* RAY_HPP */
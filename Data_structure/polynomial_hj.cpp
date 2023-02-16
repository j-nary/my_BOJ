#include <iostream>
#include <fstream>
#include "polynomial_hj.h"
void Polynomial::LoadPolynomial(std::string& filename){
    std::ifstream ifs(filename);
    ifs >> n;
    for(int i=0;i<n;i++){
        ifs>>tempa>>tempb;
        arr[tempb]=tempa;
    }
}
void Polynomial::PrintPolynomial(void){
    for(int i=99;i>=0;i--){
        if (arr[i]!=0) std::cout << arr[i] << " " << i << std::endl; 
    }
}
void Polynomial::add(Polynomial a, Polynomial b){
    for(int i=0;i<=99;i++){
        arr[i]=a.arr[i]+b.arr[i];
    }
}


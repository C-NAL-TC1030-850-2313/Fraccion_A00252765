#include <stdexcept>
#include "Fraccion.hpp"

Fraccion::Fraccion(){
    num=0;
    den=1;
}

Fraccion::Fraccion(int n, int d){
    num=n;
    setDen(d);
}

int Fraccion::getNum() const{
    return num;
}

int Fraccion::getDen() const{
    return den;
}

void Fraccion::setNum(int n) {
    num=n;
    int mcdiv=mcd(num,den);
    num=num/mcdiv;
    den=den/mcdiv;
}

void Fraccion::setDen(int d) {
    if (d > 0){
        int mcdiv=mcd(num,d);
        num=num/mcdiv;
        den=d/mcdiv;
    } else {
        throw  std::invalid_argument("El denominador debe ser mayor a cero");
    }
}

//método privado de la clase para calcular minimo comun denominador
int Fraccion::mcd(int n, int d){
    int num1, num2, residuo;
    num1=abs(n);
    num2=abs(d);
    while (num2 > 0){
        residuo=num1 % num2;
        num1=num2;
        num2=residuo;
        
    }
    return num1;
}

//Sobrecarga como función miembro de un operador binario
Fraccion Fraccion::operator+(const Fraccion &f){
    Fraccion aux;
    aux.setNum(num*f.den+f.num*den);
    aux.setDen(den*f.den);
    return aux;
}

Fraccion operator-(const Fraccion& f1, const Fraccion& f2){
    Fraccion aux;
    aux.setNum(f1.num*f2.den-f2.num*f1.den);
    aux.setDen(f1.den*f2.den);
    return aux;
}

std::ostream& operator<< (std::ostream& salida, const Fraccion& f1){
    salida << f1.num << "/" << f1.den;
    return salida;
}

std::istream &operator>> (std::istream& entrada, Fraccion& f1){
    int n, d;
    entrada >> n >> d;
    f1.setNum(n);
    f1.setDen(d);
    return entrada;
}

//Sobrecarga de preincremento
Fraccion Fraccion::operator++ (){
    setNum(++num);
    *this;
}

//Sobrecarga de postincremento
Fraccion Fraccion::operator++ (int){
    Fraccion anterior(num, den);
    setNum(++num);
    return anterior;
}
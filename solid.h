#include <iostream>
#include <string>

using namespace std;

class Base{
    private:
        int medida;
    public:
        Base (int _medida){
            this->medida = _medida;
        }
        ~Base(){}
        int getMedida(){return this->medida;}
};

class Altura{
    private:
        int medida;
    public:
        Altura (int _medida){
            this->medida= _medida;
        }
        ~Altura(){}
        int getMedida(){return this->medida;}
};

class Lado{
    private:
        int medida;
    public:
        Lado (int _medida){
            this->medida = _medida;
        }
        ~Lado(){}
        int getMedida(){return this->medida;}
};


class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;
    public:
        Triangulo (Base _base, Altura _altura, Lado _ladoA, Lado _ladoB, Lado _ladoC) : base(0), altura(0), ladoA(0), ladoB(0), ladoC(0){
            this->base = _base;
            this->altura = _altura;
            this->ladoA = _ladoA;
            this->ladoB = _ladoB;
            this->ladoC = _ladoC;
        }
        ~Triangulo (){}
};

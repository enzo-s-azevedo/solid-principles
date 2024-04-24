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
        Lado(int _medida){
            this->medida = _medida;
        }
        ~Lado(){}
        int getMedida(){return this->medida;}
};


class Triangulo{
    private:
        Base base = 0;
        Altura altura = 0;
        Lado ladoA = 0;
        Lado ladoB = 0;
        Lado ladoC = 0;
        int area = 0;
    public:
        Triangulo () {}
        ~Triangulo (){}

        void construirBase(Base b){
            this->base = b;
        }

        void construirAltura(Altura h){
            this->altura = h;
        }

        void construirLados(Lado a, Lado b, Lado c){
            this->ladoA = ladoA;
            this->ladoB = ladoB;
            this->ladoC = ladoC;
        }
        
        int getBaseTriangulo(){
            return this->base.getMedida();
        }
        
        int getAlturaTriangulo(){
            return this->altura.getMedida();
        }

        void calcularArea(){
            this->area = this->getAlturaTriangulo() * this->getBaseTriangulo() / 2;
        }

        void imprimirArea(){
            cout << "Área = " << this->area << endl;
        }
        
};

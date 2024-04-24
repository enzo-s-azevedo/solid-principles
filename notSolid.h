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

class Triangulo : public Lado, public Base, public Altura{
    private:
        int area = 0;
    public:
        Triangulo(int medidaBase = 0, int medidaLado = 0, int medidaAltura = 0) : Base(medidaBase), Altura(medidaAltura), Lado(medidaLado), area(0) {}
        ~Triangulo(){}

        void calcularArea(){
            this->area = this->Base::getMedida() * this->Altura::getMedida()/2;
            cout << "Área = " << this->area << endl;
        }        
};

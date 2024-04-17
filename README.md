# Princípios SOLID
Este é um código que serve para criar um triângulo e calcular sua área através de classes. O código foi construído respeitando os princípios SOLID: Princípio da Responsabilidade Única e Princípio de Inversão de Dependências e os princípios: Prefira Composição a Herança e Princípio de Demeter.

## Princípios da Responsabilidade Única
As classes `Base`, `Altura`, `Lado` e `Triangulo` possuem apenas uma funcionalidade, seus papéis são respectivamente: 
- Guardar o valor da medida da base de um triângulo;
```c++
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

- Guardar o valor da medida da altura de um triângulo;
```c++
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

- Guardar o valor da medida do lado de um triângulo;
```c++
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

calcular a área de um triângulo;
```c++
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
        int area(){
            this->area = base.getMedida() * altura.getMedida()/2;
        }
};

## Princípio de Inversão de Dependências
Este princípio prioriza interfaces a classes, então como `Triangulo` atende a todos os tipos de triângulo (contém todas as informações presentes em um triângulo), caso seja necessário implementar outro tipo de triângulo a implementação de `Triangulo` permanecerá válida.
```c++
class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;

## Prefira Composição a Herança
Como `Base`, `Lado` e `Altura` fazem parte de `Triangulo` (composições), nesse código foi optado utilizar composição em vez de herança. Abaixo há um trecho do código em que é possível visualizar que a classe `Triangulo` é composta por outras classes.
```c++
class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;

## Princípio de Demeter
No código os métodos apenas invocam os atributos da sua própria classe.
```c++
int getMedida(){return this->medida;}


int area(){
    this->area = base.getMedida() * altura.getMedida()/2;
        }
   

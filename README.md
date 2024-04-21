# Princípios SOLID
Este é um código que serve para construir um triângulo através de classes. O código foi construído respeitando os princípios SOLID: Princípio da Responsabilidade Única e Princípio de Inversão de Dependências e os princípios: Prefira Composição a Herança e Princípio de Demeter.

## Princípio da Responsabilidade Única
Esse princípio evita que as classes possuam múltiplas responsabilidades, portanto as classes `Base`, `Altura`, `Lado` e `Triangulo` possuem apenas uma funcionalidade, seus papéis são respectivamente: 
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
```

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
```

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
```

- Construir um triângulo;
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
};
```

## Princípio de Inversão de Dependências
Este princípio prioriza interfaces a classes, então como `Triangulo` atende a todos os tipos de triângulo (`private` contém todas as informações presentes em qualquer triângulo, ou seja, é uma abstração de triângulo), caso seja necessário implementar outro tipo de triângulo a implementação de `Triangulo` permanecerá válida.
```c++
class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;
```

## Prefira Composição a Herança
Sabendo que herança tende a introduzir problemas na manutenção e evolução das classes de um sistema, esse código optou por `Triangulo` utilizar instâncias das classes `Base`, `Lado` e `Altura`, assim se mantem a flexibilidade para adicionar ou remover funcionalidades.
```c++
class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;
```

## Princípio de Demeter
Para não ter que quebrar o encapsulamento dos objetos quando uma classe exigir alterações, no código os métodos apenas invocam os atributos da sua própria classe.
```c++
int getMedida(){return this->medida;}
```


### Referências:
Engenharia de Software Moderna - Marco Tulio Valente

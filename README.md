# Princípios SOLID
Este é um código que serve para construir um triângulo através de classes. O código foi construído respeitando os princípios: Princípio da Responsabilidade Única, Princípio Aberto/Fechado, Prefira Composição a Herança e Princípio de Demeter.

## Princípio da Responsabilidade Única
Esse princípio evita que as classes possuam múltiplas responsabilidades, portanto as classes `Base`, `Altura`, `Lado` e `Triangulo` possuem métodos com apenas uma funcionalidade, seus papéis são respectivamente:
 
- Retornar o valor da medida de uma base;
```c++
class Base{
    [...]
        int getMedida(){return this->medida;}
};
```

- Retornar o valor da medida de uma altura;
```c++
class Altura{
    [...]
        int getMedida(){return this->medida;}
};
```

- Retornar o valor da medida de um lado;
```c++
class Lado{
    [...]
        int getMedida(){return this->medida;}
};
```

- Construir a base de um triângulo;
```c++
class Triangulo{
    [...]
            void construirBase(Base b){
            this->base = b;
        }
};
```
- Construir a altura de um triângulo;
```c++
class Triangulo{
    [...]
            void construirAltura(Altura h){
            this->altura = h;
        }
};
```

- Construir os lados de um triângulo;
```c++
class Triangulo{
    [...]
        void construirLados(Lado a, Lado b, Lado c){
            this->ladoA = ladoA;
            this->ladoB = ladoB;
            this->ladoC = ladoC;
        }
};
```

- Retornar a base do triângulo;
```c++
class Triangulo{
    [...]
        int getBaseTriangulo(){
            return this->base.getMedida();
        }
};
```

- Retornar a altura do triângulo;
```c++
class Triangulo{
    [...]
        int getAlturaTriangulo(){
            return this->altura.getMedida();
        }
};
```
- Calcular a área do triângulo;
```c++
class Triangulo{
    [...]
        void calcularArea(){
            this->area = this->getAlturaTriangulo() * this->getBaseTriangulo() / 2;
        }
};
```
- Imprimir a área do triângulo;
```c++
class Triangulo{
    [...]
        void imprimirArea(){
            cout << "Área = " << this->area << endl;
        }
};
```

Isso resolve o problema do código errôneo, em que o método `calcularÁrea()` possuia duas funções: calcular e imprimir a área do triângulo.
```c++
class Triangulo{
    [...]
        void calcularArea(){
            this->area = this->Base::getMedida() * this->Altura::getMedida()/2;
            cout << "Área = " << this->area << endl;
        }
```


## Princípio Aberto/Fechado
Este princípio afirma que classes devem estar abertas para extensões e fechadas para modificações, nesse código a classe `Triangulo` respeita isso, já que pode ser extendida para qualquer tipo de triângulo, pois ela contém todos os atributos que um triângulo necessita.
```c++
class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;
    [...]
```
Isso corrige o problema do código errôneo, no qual `Triangulo` só poderia ser utilizado para triângulos equiláteros, já que permite a atribuição de valor para apenas um lado.
```c++
class Triangulo : public Lado, public Base, public Altura{
    private:
        int area = 0;
    public:
        Triangulo(int medidaBase = 0, int medidaLado = 0, int medidaAltura = 0) : Base(medidaBase), Altura(medidaAltura), Lado(medidaLado), area(0) {}
    [...]
```

## Prefira Composição a Herança
Esse código optou por `Triangulo` utilizar instâncias das classes `Base`, `Lado` e `Altura`.
```c++
class Triangulo{
    private:
        Base base;
        Altura altura;
        Lado ladoA;
        Lado ladoB;
        Lado ladoC;
        int area;
    [...]
```
Como herança tende a introduzir problemas na manutenção e evolução das classes de um sistema, esse código corrige o problema de usar herança de forma errônea, já que `Triangulo` não respeita o "é-um" `Base`, `Lado` e `Altura` , e sim "tem-um".
```c++
class Triangulo : public Lado, public Base, public Altura{
    private:
        int area = 0;
    public:
        Triangulo(int medidaBase = 0, int medidaLado = 0, int medidaAltura = 0) : Base(medidaBase), Altura(medidaAltura), Lado(medidaLado), area(0) {}
    [...]
```

## Princípio de Demeter
Para respeitar o princípio de Demeter esse código optou por utilizar apenas acessos de métodos da sua própria classes.
```c++
        int getBaseTriangulo(){
            return this->base.getMedida();
        }
        
        int getAlturaTriangulo(){
            return this->altura.getMedida();
        }

        void calcularArea(){
            this->area = this->getAlturaTriangulo() * this->getBaseTriangulo() / 2;
        }
        [...]
```
Para isso, os métodos `getBaseTriangulo()` e `getAlturaTriangulo()` foram criados a fim de corrigir o problema de ter que acessar métodos de outras classes quando se cálcula a área do triângulo.
```c++
        void calcularArea(){
            this->area = this->Base::getMedida() * this->Altura::getMedida()/2;
            cout << "Área = " << this->area << endl;
        }        
        [...]
```

### Referências:
Engenharia de Software Moderna - Marco Tulio Valente

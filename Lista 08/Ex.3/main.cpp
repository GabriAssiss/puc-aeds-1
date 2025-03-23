#include <iostream>

using namespace std;

class Produto{
protected:
    string nome;
    double valor;
public:
    void definir(const string & nome, double valor){
    this->nome = nome;
    this->valor = valor;
    }
    void exibir(){
        cout<<nome<<endl;
        cout<<valor<<endl;
    }

};

class Bebida:public Produto{
private:
    double volume;
public:
    void definir(const string & nome, double valor, double volume){
    Produto::definir(nome, valor);

    this->volume = volume;
    }
    void exibir(){
    Produto::exibir();
    cout<<volume<<endl;
    }
};

class Alimento:public Produto{
private:
    double peso;
public:
    void definir(const string & nome, double valor, double peso){
        Produto::definir(nome, valor);

        this->peso = peso;
    }
    void exibir(){
        Produto::exibir();
        cout<<peso<<endl;
    }
};

int main()
{
    string nome;
    double valor;
    double volume;
    double peso;


    cout<<"Digite o nome do produto:"<<endl;
    getline(cin, nome);
    cout<<"Digite o valor do produto:"<<endl;
    cin>>valor;

    Produto prod1;
    prod1.definir(nome, valor);
    prod1.exibir();

    cout<<"Digite o nome da bebida:"<<endl;
    cin>>nome;
    cout<<"Digite o valor da bebida:"<<endl;
    cin>>valor;
    cout<<"Digite o volume da bebida, em ml:"<<endl;
    cin>>volume;

    Bebida bebida1;
    bebida1.definir(nome, valor, volume);
    bebida1.exibir();

    cout<<"Digite o nome do alimento:"<<endl;
    cin>>nome;
    cout<<"Digite o valor do alimento:"<<endl;
    cin>>valor;
    cout<<"Digite o peso o alimento, em gramas:"<<endl;
    cin>>peso;

    Alimento alimento1;

    alimento1.definir(nome, valor, peso);
    alimento1.exibir();

    return 0;
}

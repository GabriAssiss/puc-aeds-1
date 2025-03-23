#include <iostream>
#include <string>

using namespace std;


class Ingrediente{
private:
    string nome_;
    double quantidade_;
    string unidade_;
public:
    void setNome(string &nome){
        cout<<"Insira o nome:"<<endl;
        getline(cin, nome);
        nome_ = nome;
    }
    void setQuant(double quantidade){
        cout<<"Insira a quantidade:"<<endl;
        cin>>quantidade;
        if(quantidade <= 0){
            exit(1);
        }
        quantidade_ = quantidade;
    }
    void setUni(string &unidade){
        cout<<"Insira a unidade:"<<endl;
        cin>>unidade;
        unidade_ = unidade;
        if(unidade != "kg" && unidade != "litros" && unidade != "unidades"){
            exit(1);
        }
    }
    string getNome(){
        return nome_;
    }
    double getQuant(){
        return quantidade_;
    }
    string getUni(){
        return unidade_;
    }


    Ingrediente(const string &nome, double quantidade, const string &unidade);
    Ingrediente();
    Ingrediente(const Ingrediente &copia);
    ~Ingrediente();
};

Ingrediente::Ingrediente(const string &nome, double quantidade, const string &unidade){
    cout<<"Construindo Objeto"<<endl;
    nome_ = nome;
    quantidade_ = quantidade;
    unidade_ = unidade;

    cout<<nome_<<endl;
    cout<<quantidade_<<endl;
    cout<<unidade_<<endl;
}
Ingrediente::Ingrediente(){
    cout<<"Construindo Objeto padrao"<<endl;
    nome_ = "";
    quantidade_ = 0;
    unidade_ = "";
    cout<<nome_<<endl;
    cout<<quantidade_<<endl;
    cout<<unidade_<<endl;
}
Ingrediente::~Ingrediente(){
 cout<<"Destruindo Objetos"<<endl;
}
Ingrediente::Ingrediente(const Ingrediente &copia){
    cout<<"Construindo Objeto copia"<<endl;
    this->nome_ = copia.nome_;
    this->quantidade_ = copia.quantidade_;
    this->unidade_ = copia.unidade_;

    cout<<nome_<<endl;
    cout<<quantidade_<<endl;
    cout<<unidade_<<endl;
}
int main()
{


    string nome_ing, unid_ing;
    double quant_ing;

    Ingrediente ing0;
    ing0.setNome(nome_ing);
    ing0.setQuant(quant_ing);
    ing0.setUni(unid_ing);

    Ingrediente ing1 = Ingrediente(ing0.getNome(), ing0.getQuant(), ing0.getUni());
    Ingrediente ing2 = Ingrediente();
    Ingrediente ing_copia = Ingrediente(ing1);

    return 0;
}

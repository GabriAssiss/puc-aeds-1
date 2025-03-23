#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ingrediente{
private:
    string nome;
    float preco;
public:
    void setNome(const string &nome){
        this->nome = nome;
    }
    void setPreco(float preco){
        this->preco = preco;
    }
    string getNome(){
        return nome;
    }
    float getPreco(){
        return preco;
    }
};
class Receita{
    public:
        vector<Ingrediente> ingredientes;
        void add_ingrediente(const Ingrediente ingrediente);
        void lista_ingredientes();
        void remover(int indice);
};
void Receita::add_ingrediente(const Ingrediente ingrediente) {
    ingredientes.push_back(ingrediente);
}
void Receita::lista_ingredientes(){
    for(Ingrediente ing : ingredientes){
        cout<< ing.getNome() <<endl;
    }
}
void Receita::remover(int indice){
    ingredientes.erase(indice+ingredientes.begin());
}
class ReceitaEspecial: public Receita{
public:
    float total = 0;
    void calcular(){
        for(Ingrediente ing : ingredientes){
            total = total + ing.getPreco();
        }
        cout<<total<<endl;
    }
};
int main()
{

    string nome;
    float preco;

    cout<<"Digite o nome do ingrediente:"<<endl;
    cin>>nome;
    cout<<"Digite o preco do ingrediente:"<<endl;
    cin>> preco;
    try{
        if (preco <= 0)
            throw 0;
    }
    catch(int erro){
        cout<<"Preco invalido!"<<endl;
    }

    Ingrediente ing;
    ing.setNome(nome);
    ing.setPreco(preco);

    Receita rec;

    rec.add_ingrediente(ing);
    rec.lista_ingredientes();
    rec.remover(1);
    rec.lista_ingredientes();

    ReceitaEspecial re;
    re.add_ingrediente(ing);
    re.calcular();

    return 0;
}

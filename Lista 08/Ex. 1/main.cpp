#include <iostream>
#include <string>

using namespace std;

class Ingrediente{
private:
    string nome_;
    double quantidade_;
    string unidade_;
public:
    void produto(const string& pegar_nome, const string& pegar_unidade, double pegar_quantidade);
    void compras();
};

void Ingrediente::produto(const string& pegar_nome, const string& pegar_unidade, double pegar_quantidade){
    nome_ = pegar_nome;
    quantidade_ = pegar_quantidade;
    unidade_ = pegar_unidade;
}
void Ingrediente::compras(){
    cout<<nome_<<endl;
    cout<<quantidade_<<endl;
    cout<<unidade_<<endl;
}

int main()
{
    Ingrediente info_ingrediente;
    string pegar_nome, pegar_unidade;
    double pegar_quantidade;

    cout<<"Digite o nome do que deseja comprar:"<<endl;
    getline(cin, pegar_nome);

    cout<<"Digite a quantidade do que deseja comprar:"<<endl;
    cin>>pegar_quantidade;

    cout<<"Digite a unidade do que deseja comprar:"<<endl;
    getline(cin, pegar_unidade);

    info_ingrediente.produto(pegar_nome, pegar_unidade, pegar_quantidade);
    info_ingrediente.compras();


    return 0;
}

/*
* ATIVIDADE 3 - SI300/A
* DEMONSTRAÇÃO DE USO DO SHARED_PTR
* UNICAMP - FACULDADE DE TECNOLOGIA* 2016
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Inteiros{
public:
    vector <shared_ptr<int>> setNumero();
    /*
    * PONTEIRO SHARED_PTR PERMITE CÓPIA E PODE SER USADO COMO PARÂMETRO
    * PARA FUNÇÕES; SEGUE ABAIXO:
    */
    void getNumero(vector <shared_ptr<int>>);
    void Clear(vector <shared_ptr<int>>);
};
void Inteiros::Clear(vector <shared_ptr<int>> inteiros){
    cout << endl;
    cout << "Limpando lista" << endl;
    //PARA AS LINHAS DE CÓDIGO ABAXIO, VALE A MESMA OBSERVAÇÃO FEITA NOS
    //COMENTARIOS DO CÓDIGO DE EXEMPLO DE USO DO unique_ptr
    /*while (scan != inteiros.end())
    {
    delete (*scan);
    (*scan) = NULL;
    scan++;
    }*/
    inteiros.clear();
    cout << "Finalizando" << endl;
}
void Inteiros::getNumero(vector <shared_ptr<int>> inteiros){
    vector<shared_ptr<int>>::iterator scan = inteiros.begin();
    cout << endl << "Imprimindo vetor:" << endl;
    while (scan != inteiros.end()){
        cout << **scan << endl;
        scan++;
    }
}
vector <shared_ptr<int>> Inteiros::setNumero(){
    vector <shared_ptr<int>> inteiros;
    for (int i = 1; i < 5; i++){
        shared_ptr <int> x(new int);
        cout << "Digite o " << i << "o número" << endl;
        cin >> *x;
        if (*x != 0){
            inteiros.insert(inteiros.end(), x); //PONTEIRO SHARED_PTR PERMITE CÓPIA. NÃO NECESSITA move
        }
        else{
            cout << "Número zero não permitido. Tente outro número." << endl;
            i--;
        }
    }
    return inteiros;
}
int main(int argc, char** argv){
    Inteiros numeros;
    vector <shared_ptr<int>> inteiros;
    cout << "Digite 4 números" << endl;
    inteiros = numeros.setNumero();
    numeros.getNumero(inteiros); //RECURSO COMPARTILHADO
    numeros.Clear(inteiros); //RECURSO COMPARTILHADO
    return 0;
}

/*
* ATIVIDADE 3 - SI300/A
* DEMONSTRAÇÃO DE USO DO PONTEIRO INTELIGENTE UNIQUE_PTR
* UNICAMP - FACULDADE DE TECNOLOGIA
* 2016
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Inteiros{
public:
    void setNumero();
    void getNumero();
    ~Inteiros();
private:
    vector <unique_ptr<int>> inteiros;
};
Inteiros::~Inteiros(){
    cout << endl;
    cout << "Limpando lista" << endl;
    /*
    * COM USO DO PONTEIRO INTELIGENTE UNIQUE_PTR, TORNA-SE
    * DESNECESSÁRIO AS LINHAS DE CÓDIGO COMENTADAS ABAIXO
    * QUE LIBERAM AS OS ESPAÇOS DE MEMÓRIAS ALOCADAS DINAMICAMENTE.
    * COM O USO DO PONTEIRO UNIQUE_PTR, OS ESPAÇOS SERÃO LIBERADOS
    * AUTOMATICAMENTE QUANDO NÃO FOREM MAIS USADOS (SAIREM FORA DO ESCOPO).
    *
    while (scan != inteiros.end()){
    delete (*scan);
    (*scan) = NULL;
    scan++;
    }
    */
    inteiros.clear();
    cout << "Finalizando" << endl;
}
void Inteiros::getNumero(){
    vector<unique_ptr<int>>::iterator scan = inteiros.begin();
    cout << endl << "Imprimindo vetor:" << endl;
    while (scan != inteiros.end())
    {
        cout << **scan << endl;
        scan++;
    }
}
void Inteiros::setNumero(){
    for (int i = 1; i < 5; i++){
        unique_ptr <int> x(new int);
        cout << "Digite o " << i << "o número" << endl;
        cin >> *x;
        if (*x != 0){
            inteiros.insert(inteiros.end(), (move(x)));
            /*
            * OBSERVE QUE FOI USADO O COMANDO "move" PARA A OPERAÇÃO DE INSERÇÃO
            * ACIMA. ISTO PORQUE, O PONTEIRO UNIQUE_PTR NÃO PERMITE CÓPIA.
            *
            * OBSERVE TAMBÉM, O PROBLEMA QUANDO É INSERIDO UM NÚMERO IGUAL A ZERO.
            * UM ESPAÇO DE MEMÓRIA FOI ALOCADO, PORÉM, NÃO FOI INSERIDO NO VETOR
            * FICANDO TAMBÉM, SEM REFERÊNCIA DE ACESSO. ESTE ESPAÇO DE MEMÓRIA,
            * FICARIA ALOCADO E SEM USO DURANTE TODA A EXECUÇÃO DO PROGRAMA.
            * ESTE É UM CASO DE VAZAMENTO DE MEMÓRIA (memory leak).
            * DEVIDO AO USO DO UNIQUE_PTR, ESSES ESPAÇOS SERÃO LIBERADOS ASSIM QUE
            * ESTIVEREM FORA DO ESCOPO.
            */
        }
        else{
            cout << "Número zero não permitido. Tente outro número." << endl;
            i--;
        }
    }
}
int main(int argc, char** argv){
    Inteiros numeros;
    cout << "Digite 4 números" << endl;
    numeros.setNumero();
    numeros.getNumero();
    return 0;
}

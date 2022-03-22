#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int* tamanhoVetor = new int;
    int* qtdIteracao = new int;
    bool* troca = new bool;

    cout << "Digite o tamanho do vetor: ";
    cin >> *tamanhoVetor;
    int* vetor = new int[*tamanhoVetor];
    
    //Armazenando Valores:
    for (int i = 0; i < *tamanhoVetor; i++){
        cout << "Digite o valor do vetor da posicao "<<i+1<<":";
        cin >> vetor[i];
    }

    //BubbleSort:
    *troca = true;
    *qtdIteracao = 0;
    for (int i = 0; i < *tamanhoVetor && *troca; i++){
        if(*troca)(*qtdIteracao)++;
        *troca = false;
        for (int j = *tamanhoVetor-1; j > i; j--){
            if(vetor[j]<vetor[j-1]){
                swap(vetor[j],vetor[j-1]);
                *troca = true;
            }
        }
    }

/*
    for (int i = 0; i < *tamanhoVetor; i++){
        cout << "\n SAID: "<< vetor[i]<<"\n ";
    }
*/

/* EM TODOS ESSES CASOS MEU CÓDIGO FUNCIONOU:

    1° Caso:
            1 3 2 5 4
        1°: 1 2 3 4 5 *TROCOU
        2°: 1 2 3 4 5 *N TROCOU

    2° Caso:
            6 5 2 1
        1°: 5 6 1 2 *TROCOU
        2°: 1 5 6 2 *TROCOU
        3°: 1 2 5 6 *TROCOU
        4°: 1 2 5 6 *N TROCOU

    3° Caso:
            3 5 7 8
        1°: 3 5 7 8 *N TROCOU
    
    4° Caso:
        9 2 3 7 8
    1°: 2 9 3 7 8 *TROCOU
    2°: 2 3 9 7 8 *TROCOU
    3°: 2 3 7 9 8 *TROCOU
    4°: 2 3 7 8 9 *TROCOU
    5°: 2 3 7 8 9 *N TROCOU
*/
    cout <<*qtdIteracao;
    delete tamanhoVetor;
    delete qtdIteracao;
    delete troca;
    delete [] vetor;

    return 0;
}

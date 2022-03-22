#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int* tamanhoVetor = new int;
    cin >> *tamanhoVetor;
    int* vetor = new int[*tamanhoVetor];

    for (int i = 0; i < *tamanhoVetor; i++){
        cin >> vetor[i];
    }

    int* qtdRepet = new int;
    *qtdRepet = 0 ;
    for (int i = 0; i < *tamanhoVetor; i++){
        for (int j = *tamanhoVetor-1; j >i; j--){
            if( vetor[i]==vetor[j] && (vetor[j],vetor[i]!=0)){
                vetor[j]=0;
                (*qtdRepet)++;
            }
        }
    }
    cout << *qtdRepet <<"\n";
    delete qtdRepet;
    delete tamanhoVetor;
    delete [] vetor;

    return 0;
}

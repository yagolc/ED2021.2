#include <iostream>
using namespace std;
int main(int argc, char const *argv[]){
    int* tamanhoVetor = new int;
    cout << "Digite o tamanho do vetor: ";
    cin >> *tamanhoVetor;
    int* vetor = new int[*tamanhoVetor];
    int* nRepetido = new int;
    int* qtdvzs = new int;

    for (int i = 0; i < *tamanhoVetor; i++){
        cout<< "\nDigite o valor do vetor "<<i+1<<" :";
        cin >> vetor[i];
    }
    int *temp = new int;
    *qtdvzs = 0;
    for (int i=0; i < *tamanhoVetor; i++){
        *temp = 0;
        for (int j = *tamanhoVetor; j >= 0; j--){
            if(vetor[i]==vetor[j] ){
                (*temp)++;
                if(*temp>*qtdvzs){
                    *qtdvzs = *temp;
                    *nRepetido = vetor[i];
                }
            }
        }
    }
    cout << *nRepetido << " ";
    cout << *qtdvzs << "\n";
    
    delete qtdvzs;
    delete nRepetido;
    delete [] vetor;
    delete temp;
    delete tamanhoVetor;

    return 0;
}

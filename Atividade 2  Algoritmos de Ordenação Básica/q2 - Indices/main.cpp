#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int* tamanhoVetor = new int;
    bool* troca = new bool;
    cout << "Digite o tamanho do vetor: ";
    cin >> *tamanhoVetor;
    int* vetor = new int[*tamanhoVetor];
    int* ordemIndice = new int[*tamanhoVetor];

    for (int i = 0; i < *tamanhoVetor; i++){
        cout<< "\nDigite o valor do vetor "<<i+1<<" :";
        cin >> vetor[i];
        ordemIndice[i]=i;
    }

    //BubbleSort:
    *troca = true;
    for (int i = 0; i < *tamanhoVetor && *troca; i++){
        *troca = false;
        for (int j = *tamanhoVetor-1; j > i; j--){
            if(vetor[j]<vetor[j-1]){
                swap(vetor[j],vetor[j-1]);
                swap(ordemIndice[j],ordemIndice[j-1]);
                *troca = true;
            }
        }
    }
    for (int i = 0; i < *tamanhoVetor; i++){
        if(i == (*tamanhoVetor-1)) cout << ordemIndice[i]<<"\n";
        else cout << ordemIndice[i]<<" ";
    }
    delete tamanhoVetor;
    delete troca;
    delete [] vetor;
    delete [] ordemIndice;
    
    return 0;
}

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[]){


//VETOR DE CONSULTA:
    int *tcons =  new int;
    cin >> *tcons;
    string vcons[*tcons];

    for (int i = 0; i < *tcons; i++){
        cin >> vcons[i];
    }

//VETOR DE BUSCA
    int *tbusc =  new int;
    cin >> *tbusc;
    string vbusc[*tbusc];

    for (int i = 0; i < *tbusc; i++){
        cin >> vbusc[i];
    }



//LÓGICA:
    int *aux = new int;
    *aux = 0;
    for (int i = 0; i < *tbusc; i++){
        for (int j = 0; j < (*tcons); j++){
            if(vbusc[i]==vcons[j]) (*aux)++;
        }
        if(i==*tbusc-1)cout << *aux <<"\n";
        else cout << *aux <<" ";
        *aux = 0;
    }
    

    return 0;
}

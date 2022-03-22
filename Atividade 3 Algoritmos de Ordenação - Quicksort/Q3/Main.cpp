#include <iostream>
using namespace std;


void remover_pessoas_da_fila(int *vP,int *vS,int E,int N){
    for (int i = 0; i < E; i++){
        for (int j = 0; j < N; j++){
            if(vS[i]==vP[j]){ 
                vP[j]=0;
                j=N+1;
            }
        }
    }  
}

void organizar_fila(int *vP,int N){
    int *VAUX = new int[N];
    for (int i = 0,j = 0; i < N; i++){
        if(vP[i]!=0){
            VAUX[j]=vP[i];
            j++;
        }
    }
    vP = VAUX;

    for (int i = 0; i < N; i++){
        if(vP[i]!=0){
            if(vP[i+1]==0) cout << vP[i] << " \n";
            else cout << vP[i] << " ";
        }
    }
    delete []VAUX;
}


int main(int argc, char const *argv[]){
     
    int *n = new int;
    cin >> *n;
    int *vPessoas = new int[*n];

    for (int i = 0; i < *n; i++){
        cin >> vPessoas[i];
    }

    int *e = new int;
    cin >> *e;
    int *vSairam = new int[*e];

    for (int i = 0; i < *e; i++){
        cin >> vSairam[i];
    }

    remover_pessoas_da_fila(vPessoas,vSairam,*e,*n);
    organizar_fila(vPessoas,*n);

    delete n;
    delete e;
    delete []vPessoas;
    delete []vSairam;
    return 0;
}

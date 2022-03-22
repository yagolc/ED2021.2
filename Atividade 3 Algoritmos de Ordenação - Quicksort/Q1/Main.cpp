#include <iostream>
using namespace std;

void rotacao(int *V, int R, int T){
    int *VAUX = new int[T];
    for (int i = 0; i < R; i++){
        for (int j = 0,k = 0; j < T || k < T; j++){
            if(j>=T){
                V[k]=VAUX[k];
                k++;
           }else{
           if(j==0) VAUX[j]=V[T-1];
           else VAUX[j]=V[j-1];
            }  
        }
    }
    delete VAUX;
}


int main(int argc, char const *argv[]){
    int *t = new int;
    int *r = new int;
    cin >> *t;
    cin >> *r;
    int *v = new int[*t];

    for (int i = 0; i < *t; i++){
        cin >> v[i];
    }

    rotacao(v,*r,*t);
    
    cout << "["<<" ";
    for (int i = 0; i < *t; i++){
        cout << v[i] <<" ";
    }
    cout << "]"<<"\n";
    delete t;
    delete []v;
    delete r;

    return 0;
}

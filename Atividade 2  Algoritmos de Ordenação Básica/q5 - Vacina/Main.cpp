#include <iostream>
using namespace std;
int main(int argc, char const *argv[]){
    bool* troca = new bool;
    int* t = new int;
    //cout<<"Digite o valor do numero de Pessoas e Vacinas: ";
    cin >> *t;
    int* v = new int[*t];
    int* p = new int[*t];
    for (int i = 0,j=0; i < *t || j < *t; i++){
       // cout << "Digite a força da vacina "<<i+1<<": ";
        if(i<*t)cin >> v[i];
        if(i>*t-1){
            //cout << "Digite a força do paciente "<<j+1<<": ";
            cin >> p[j];
            j++;
        }
    }

    //BubbleSort para organizar em ordem crescente: 
    *troca = true;
    for (int i = 0; i < *t; i++){
        *troca=false;
        for (int j = *t-1; j > i; j--){
            if(v[j]<v[j-1]){
                swap(v[j],v[j-1]);
                *troca = true;
            }
            if(p[j]<p[j-1]){
                swap(p[j],p[j-1]);
                *troca = true;
            }
        }
    }

    *troca= true;
    for (int i = 0; i < *t && *troca!=false; i++){
        if(v[i]>p[i]) *troca=true;
        else *troca=false;
    }

    if(*troca==true) cout << "Yes\n";
    else cout << "No\n";

    delete troca;
    delete [] v;
    delete [] p;
    delete t;

    return 0;
}

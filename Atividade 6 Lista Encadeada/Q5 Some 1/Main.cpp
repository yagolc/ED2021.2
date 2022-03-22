#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

 
ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;

}

void print_list(ListNode * head){

    for(auto ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }

}


//************************************
bool someAuxAux(ListNode * head){
        
}

ListNode* someUm(ListNode *head){
   vector<int> v;
   vector<int> v2;

   for(ListNode * sum = head; sum != nullptr; sum = sum->next){
        v.push_back(sum->val);
   }

   
    int concatenando = 0;
    if(v.size()>1){
        for (int i = 0; i < v.size(); i++){
            if(i==0)  concatenando = v[i];
            else concatenando = (concatenando * 10) + v[i];
        }
        concatenando++;
    }

    
    int concatenando_newSize = concatenando;
    int new_size=0;
    while(true){
        if(concatenando_newSize==0) break;
        else concatenando_newSize = concatenando_newSize / 10;
        new_size++;
    }


    for (int i = 0; i < new_size; i++){
            v2.emplace(v2.begin(),concatenando % 10);
            concatenando = concatenando / 10;
        }
    // v2.push_back(concatenando/100);
    // v2.push_back( (concatenando/10) % 10);
    // v2.push_back(concatenando % 10);


    ListNode * new_head= nullptr;
   for (int i = 0; i < v2.size(); i++){
    ListNode * p;
    if( i == 0){
        new_head = new ListNode(v2[i]);
        p = new_head;
        
    }else{
        p->next = new ListNode(v2[i], nullptr);
        p = p->next;
    }
   }

    return new_head;
} 

//************************************



int main(){
    
    ListNode * head = readList();
    head = someUm(head);
    print_list(head);
    return 0;    
}

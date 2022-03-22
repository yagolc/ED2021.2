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



//***************************************


vector<int> bubbleSort(vector<int> vet){

    bool troca = true;
    int qtdIteracao = 0;

    while (troca){
        troca = false;
        qtdIteracao++;
        for (int i = 0; i < vet.size()-1; i++){
            if(vet[i]>vet[i+1]){
                swap(vet[i],vet[i+1]);
                troca = true;
            }
        }
    }

    return vet;
    
}




ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
   vector<int> v;
   for(ListNode * del = l1; del != nullptr; del = del->next){
        v.push_back(del->val);
   }
   for(ListNode * del = l2; del != nullptr; del = del->next){
        v.push_back(del->val);
   }

   v = bubbleSort(v);




   ListNode * new_head= nullptr;
   for (int i = 0; i < v.size(); i++){
    ListNode * p;
    if( i == 0){
        new_head = new ListNode(v[i]);
        p = new_head;
        
    }else{
        p->next = new ListNode(v[i], nullptr);
        p = p->next;
    }
   }

   

    return new_head; 
}

//***********************************************************





ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head = nullptr;
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


int main(){
    
    ListNode * list1 = readList();
    ListNode * list2 = readList();
    ListNode * head = mergeTwoLists(list1, list2);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}

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
    int n, x;
    cin >> n >> x;
    ListNode * head;
    ListNode * tmp = nullptr;

    ListNode * ptr;
        
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        if( i == 1){
            head = new ListNode(v);
            ptr = head;
        }else{
            ptr->next = new ListNode(v, nullptr);
            ptr = ptr->next;
        }

        if(i == x){
            tmp = ptr;
        }

    }

    
    ptr->next = tmp;
    return head;
}


/******************************/
bool detectLoop(ListNode* head){

    ListNode * fast = head;
    ListNode * slow = head;
    ListNode * verifica_fast = head;
    int i = 0;
    while(true){
        //cout << i << " <-i "<< fast->val <<" <- FAST "<< slow->val <<" <- SLOW"<<endl;
        verifica_fast=fast->next;
        if(verifica_fast == nullptr) return false;
        if(fast->val  ==  slow->val && i!=0) return true;
        fast = fast->next->next;
        slow = slow->next;
        i++;
    }
    
}
/********************************/



int main(){
    
    ListNode * head = readList();
    cout << detectLoop(head) << endl;

    return 0;    
}

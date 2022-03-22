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

/**********************************/
ListNode* oddEvenList(ListNode* head) {
   vector<int> v;
   vector<int> v2;
   int i =0 ;
   for(ListNode * del = head; del != nullptr; del = del->next){
       if(i%2==0) v.push_back(del->val);
       else v2.push_back(del->val);
       i++;
   }

    for ( i = 0; i < v2.size(); i++){
        v.push_back(v2[i]);
    }
    
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

/**********************************/


int main(){
    int n;
    ListNode * head= nullptr;
    cin >> n;
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

    head = oddEvenList(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}
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

/*********************/
int getMiddle(ListNode *head){

    int i =0;
    int n =0;
    for(ListNode * tamanho = head; tamanho != nullptr; tamanho = tamanho->next){
        i++;
    }

    i = (i/2)+1;

    for(ListNode * final = head; n<=i; final = final->next){
        n++;
        if(n==i) return final->val;
    }
}
/**************************/




int main(){
    
    ListNode * head = readList();
    
    cout << getMiddle(head) << endl;

    
    return 0;    
}
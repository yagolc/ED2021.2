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


ListNode * intersectionList(ListNode * head1, ListNode * head2){
    vector<int> v;
    vector<int> v2;
    vector<int> vfinal;

    int i = 0;

    for(ListNode * l1 = head1; l1 != nullptr; l1 = l1->next){
        v.push_back(l1->val);
    }

    for(ListNode * l2 = head2; l2 != nullptr; l2 = l2->next){
        v2.push_back(l2->val);
    }
    int n = 0;
    for(int i = 0; i< v.size(); i++){
        if(v[i]==n)i++;
        else{
            n=0;
            for (int j = 0; j < v2.size(); j++){
                if(v[i]==v2[j]){
                    if(n==0)vfinal.push_back(v[i]);
                    n=v[i];
                }
            }
        }
        
    }

    // for (int i = 0; i < vfinal.size(); i++){
    //     cout << vfinal[i] << " <- VETOR"<<endl << endl;
    // }
    

    ListNode * final= nullptr;
   for (int i = 0; i < vfinal.size(); i++){
    ListNode * p;
    if( i == 0){
        final = new ListNode(vfinal[i]);
        p = final;
        
    }else{
        p->next = new ListNode(vfinal[i], nullptr);
        p = p->next;
    }
   }

   return final;
}


void printList(ListNode * head){
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}



int main(){
    
    ListNode * head1 = readList();
    ListNode * head2 = readList();
     
    ListNode * res = intersectionList(head1, head2);


    printList(res);

    return 0;    
}

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *readList()
{
    int n;
    cin >> n;
    ListNode *head;
    for (int i = 0; i < n; i++)
    {
        ListNode *ptr;
        int x;
        cin >> x;
        if (i == 0)
        {
            head = new ListNode(x);
            ptr = head;
        }
        else
        {
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;
}

vector<int> intersecao(int x, vector<int> result)
{
    for (int i = 0; i < result.size(); i++)
    {
        if (x == result[i])
            return result;
    }
    result.push_back(x);
    return result;
}

ListNode *add(vector<int> result)
{
    ListNode *head;
    for (int i = 0; i < result.size(); i++)
    {
        ListNode *ptr;
        if (i == 0)
        {
            head = new ListNode(result[i]);
            ptr = head;
        }
        else
        {
            ptr->next = new ListNode(result[i], nullptr);
            ptr = ptr->next;
        }
    }

    return head;
}

ListNode *intersectionList(ListNode *head1, ListNode *head2)
{
    vector<int> result;
    for (ListNode *l1 = head1; l1 != nullptr; l1 = l1->next)
    {
        for (ListNode *l2 = head2; l2 != nullptr; l2 = l2->next)
        {
            if (l1->val == l2->val)
                result = intersecao(l1->val, result);
        }
    }
    return add(result);
}

void printList(ListNode *head)
{
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}

int main()
{

    ListNode *head1 = readList();
    ListNode *head2 = readList();

    ListNode *res = intersectionList(head1, head2);

    printList(res);

    return 0;
}
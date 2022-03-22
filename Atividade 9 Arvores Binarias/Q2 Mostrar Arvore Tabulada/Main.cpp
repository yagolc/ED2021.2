#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int value = 0, Node *left = nullptr, Node *right = nullptr)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree
{
    Node *root{nullptr};
    BTree()
    {
    }

    void cl(stringstream &string_stream, Node **n)
    {
        string value;
        string_stream >> value;
        if (value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *n = new Node(num);
        cl(string_stream, &(*n)->left);
        cl(string_stream, &(*n)->right);
    }

    BTree(string serial)
    {
        stringstream string_stream(serial);
        cl(string_stream, &root);
    }

    void __destroy(Node *node)
    {
        if (node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree()
    {
        __destroy(this->root);
    }

    void show()
    {
        __bshow(this->root);
    }
    void __bshow(Node *node, string heranca = "")
    {
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->left, heranca + "l");
        for (int i = 0; i < (int)heranca.size() - 1; i++)
            cout << (heranca[i] != heranca[i + 1] ? "...." : "....");
        if (heranca != "")
            cout << (heranca.back() == 'l' ? "...." : "....");
        if (node == nullptr)
        {
            cout << "#" << endl;
            return;
        }
        cout << node->value << endl;
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->right, heranca + "r");
    }
};

int main()
{
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show();
}
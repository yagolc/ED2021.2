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
    Node *root;
    BTree()
    {
        this->root = nullptr;
    }

    void clone(stringstream &ss, Node **elo)
    {
        string value;
        ss >> value;
        if (value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *elo = new Node(num);
        clone(ss, &(*elo)->left);
        clone(ss, &(*elo)->right);
    }

    BTree(string serial)
    {
        stringstream ss(serial);
        clone(ss, &root);
    }

    void __destroy(Node *node)
    {
        if (node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    string final = "";

    void bshow()
    {
        __bshow(this->root);
    }

    void __bshow(Node *node, string heranca = "")
    {
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->left, heranca + "l");
        for (int i = 0; i < (int)heranca.size() - 1; i++)
            cout << (heranca[i] != heranca[i + 1] ? "_" : "");
        if (heranca != "")
        {
            cout << (heranca.back() == 'l' ? "L" : "R");
        }
        if (node == nullptr)
        {
            cout << "#" << endl;
            return;
        }
        cout << node->value;
        final += node->value;
        if (node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->right, heranca + "r");
    }

    ~BTree()
    {
        __destroy(this->root);
    }

    string find_path(Node *node, int value)
    {
        for (int i = 0; i < final.size(); i++)
        {
            int token = 0;
            string result = "";
            if (final[0] == value)
                return r;
            else
            {
                if (i == 0)
                    result += "r";

                else if (final[i] == '_')
                {
                    token++;
                }
                else if (final[i] == value)
                    result += 'x';

                else
                {
                    result += final[i];
                }
            }
        }
    }
};

int main()
{
    string line;
    getline(cin, line);
    BTree bt(line);
    int value;
    cin >> value;
    string path = bt.find_path(bt.root, value);
    cout << path << "\n";
    bt.bshow();
}
#include <iostream>
#include <vector>
#include <iomanip> // std::setw

using namespace std;

template <typename T>
class NodeTree
{
public:
    T key;
    int size;
    NodeTree<T> *left;
    NodeTree<T> *right;
    NodeTree(T key) : key(key), left(nullptr), right(nullptr){};
    NodeTree(T key, NodeTree *l, NodeTree *r) : key(key), left(l), right(r){};
};

template <typename T>
NodeTree<T> *insert(NodeTree<T> *root, T key)
{
    if (root == nullptr)
        return new NodeTree<T>(key);
    else
    {
        if (key < root->key)
        {
            root->left = insert(root->left, key);
        }
        else
        {
            root->right = insert(root->right, key);
        }
        return root;
    }
}

template <typename T>
NodeTree<T> *createTree(vector<T> keys)
{
    NodeTree<T> *root = nullptr;
    for (auto key : keys)
    {
        root = insert(root, key);
    }
    return root;
}

template <typename T>
bool find(NodeTree<T> *root, int l, int r)
{
    if (root->left == nullptr and root->right == nullptr)
    {
        if (l <= root->key and root->key <= r)
        {
            cout << root << "\n======\n";
            return true;
        }
        return false;
    }
    bool resLeft = find(root->left, l, r);
    bool resRight = find(root->right, l, r);
    if (resLeft and resRight)
    {
        cout << root << "\n======\n";
        return true;
    }
    return false;
}

template <typename T>
ostream &operator<<(ostream &output, const NodeTree<T> *ptr)
{
    static int offset = 0;

    if (ptr == nullptr)
    {
        output << " " << setw(offset);
        output << "-\n";
    }
    else
    {
        offset += 3;
        output << ptr->left;
        offset -= 3;

        output << " " << setw(offset);
        output << ptr->key << endl;

        offset += 3;
        output << ptr->right;
        offset -= 3;
    }
    return output;
}

int main()
{

    int n;
    int l, r;
    vector<int> keys;

    cin >> n >> l >> r;

    keys.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }

    NodeTree<int> *root = createTree(keys);

    find(root, l, r);
}
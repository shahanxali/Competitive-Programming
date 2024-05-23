// Question: https://codeforces.com/problemset/problem/913/B
// Level: 1200

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct node
{
    int data;
    vector<node *> children;
};

// Function to check if the tree is a spruce
bool isSpruce(node *root)
{
    if (root->children.empty())
    {
        // Leaf node, always considered part of a spruce tree
        return true;
    }

    int leafChildren = 0;
    for (node *child : root->children)
    {
        if (!isSpruce(child))
        {
            return false; // If any subtree is not a spruce, the whole tree isn't
        }
        if (child->children.empty())
        {
            leafChildren++;
        }
    }

    // Check the condition for non-leaf nodes
    return leafChildren >= 3;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 2; i <= n; i++)
    {
        int parent;
        cin >> parent;
        arr[i - 1] = parent;
    }

    unordered_map<int, node *> nodes;

    for (int i = 1; i <= n; i++)
    {
        node *newnode = new node();
        newnode->data = i;
        nodes[i] = newnode;
    }

    node *root = nodes[1];

    for (int i = 2; i <= n; i++)
    {
        int parent = arr[i - 1];
        nodes[parent]->children.push_back(nodes[i]);
    }

    if (isSpruce(root))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}

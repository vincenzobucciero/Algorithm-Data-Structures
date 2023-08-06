/**
 * Progettare ed implementare un algoritmo ricorsivo che dato un albero binario calcoli la profondità di un nodo 
 * 
 * Profondità -> lunghezza del cammino semplice dalla radice al nodo 𝑥
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) { }
};

int depthNode(TreeNode* node, int x) {
    if(node == nullptr) {
        return -1;
    }

    if(node->val == x) {
        return 0;
    }

    int leftDepth = depthNode(node->left, x);
    int rightDepth = depthNode(node->right, x);

    if (leftDepth == -1 && rightDepth == -1) {
        return -1;
    }

    return max(leftDepth, rightDepth) + 1;
}

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode *nodeX = root->left->left;    //x = 5

    int depthXNode = depthNode(root, nodeX->val);

    cout << "La profondità del nodo x = " << nodeX->val << " è : " << depthXNode << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

//how can return x node's depth in Binary tree?
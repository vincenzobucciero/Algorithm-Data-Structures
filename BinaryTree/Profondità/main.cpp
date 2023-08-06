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

int depthNode(TreeNode* node, TreeNode* root, int depth) {
    if (!node) {
        return -1; // Albero vuoto, quindi il nodo non è presente
    }

    if (node == root) {
        return depth; // Nodo trovato, ritorna la profondità corrente
    }

    int leftDepth = depthNode(root->left, node, depth + 1);
    if (leftDepth != -1) {
        return leftDepth; // Il nodo è stato trovato nel sottoalbero sinistro
    }

    int rightDepth = depthNode(root->right, node, depth + 1);
    if (rightDepth != -1) {
        return rightDepth; // Il nodo è stato trovato nel sottoalbero sinistro
    }

    //return depthNode(root->right, node, depth + 1); // Cerca nel sottoalbero destro

    return -1;
}

int main() {
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode *nodeX = root->left;    //x = 5

    int depthXNode = depthNode(nodeX, root, 0);

    cout << "La profondità del nodo x = " << nodeX->val << " è : " << depthXNode << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
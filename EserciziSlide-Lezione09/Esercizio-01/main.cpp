/**
 * Progettare ed implementare un algoritmo ricorsivo che dato un albero binario calcoli l'altezza di un nodo x
 * 
 * altezza -> numero di archi nel più lungo cammino semplice dal nodo x ad una foglia
 * 
 *                          // Esempio di costruzione di un albero binario:
                            //       1                 altezza 1: 0
                            //      / \                 
                            //     2   3               altezza 2 - 3 : 1
                            //    / \
                            //   4   5                 altezza 4 - 5 : 2
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;    //valore int del nodo
    TreeNode *left;     //puntatore al sottoalbero sx del nodo
    TreeNode *right;    //puntatore al sottoalbero dx del nodo

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) { }
};

int altezzaNodo(TreeNode *node) {
    if(!node) {
        return -1;      //se non esiste nodo ritorna -1
    }

    int leftHeight = altezzaNodo(node->left);
    int rightHeight = altezzaNodo(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    TreeNode *root = new TreeNode(1);  //radice con valore 1

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode *nodeX = root->left->right;    //node x = 5

    int nodeXHeight = altezzaNodo(nodeX);

    cout << "Altezza del nodo x = " << nodeX->val << " è: " << nodeXHeight << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}


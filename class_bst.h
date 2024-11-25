#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int v) : data(v), weight(1), lchild(nullptr), rchild(nullptr) {}

    //inserimento ricorsivo
    Node* insertR(int k) {
        if (this == nullptr) {
            return new Node(k);
        }
        if (k == data) {
            weight++;
            return this;
        }
        if (k < data) {
            if (lchild == nullptr) {
                lchild = new Node(k);
            } else {
                lchild = lchild->insertR(k);
            }
        } else {
            if (rchild == nullptr) {
                rchild = new Node(k);
            } else {
                rchild = rchild->insertR(k);
            }
        }
        return this;
    }

    //attraversamento inOrder
    void inOrder() {
        if (lchild != nullptr) {
            lchild->inOrder();
        }
        cout << data << " ";
        if (rchild != nullptr) {
            rchild->inOrder();
        }
    }

    int getData() { return data; }
    int getWeight() { return weight; }
    Node* getLeftChild() { return lchild; }
    Node* getRightChild() { return rchild; }

    void setLeftChild(Node* child) { lchild = child; }
    void setRightChild(Node* child) { rchild = child; }
};
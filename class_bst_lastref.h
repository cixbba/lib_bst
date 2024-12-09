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
    Node *insertR(int k) {
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

    // ricerca ricorsiva

    bool searchR(int k) {                     
        bool check;
        if (this == NULL) {
            check = false;
            return check;
        }
        if (this->data == k) {
            check = true;
            return check;
        }
        if (k < this->data) {
            check = this->lchild->searchR(k);
        }
        else if (k > this->data) {
            check = this->rchild->searchR(k);
        }
        return check;
    }

    //inserimento iterativo

    Node *insertI(Node *r, int k){
        bool check {true};
        Node *current {r};
        Node *father {r};
        do{
            if(current==NULL){
                if(k<father->data){
                    father->lchild = new Node(k);
                    check = false;
                    return r;
                } else {
                    father->rchild = new Node(k);
                    check = false;
                    return r;
                }
                check = false;
            }
            if(current->data==k){
                check = false;
                return r;
            }
            if(k<current->data){
                father = current;
                current = current->lchild;
            } else {
                father = current;
                current = current->rchild;
            }
        }while(check);
    }

    // ricerca iterativa

    bool searchI(Node *r, int k){
        bool check {true};
        Node *current {r};
        Node *father {r};
        do{
            if(current==nullptr){
                cout << "Non trovato" << endl;
                return 0;
                check = false;
            }
            if(current->data==k){
                cout << "Trovato" << endl;
                return 0;
                check = false;
            }

            if(k<current->data){
                father = current;
                current = current->lchild;
            } else {
                father = current;
                current = current->rchild;
            }
        }while(check);
    }

    void preOrder(Node *r){
        if(r!=nullptr){
            cout << r->data << " ";
            preOrder(r->lchild);
            preOrder(r->rchild);
        }
    }

    void postOrder(Node *r){
        if(r!=nullptr){
            postOrder(r->lchild);
            postOrder(r->rchild);
            cout << r->data << " ";
        }
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

    Node* Eliminate_R(Node *r, int k){
        if(r==nullptr){
            cout << "nodo non trovato";
            return r;
        }
        if(r->data==k){
            if(r->rchild==nullptr && r->lchild==nullptr){
                delete r;
                return r;
            }
            if(r->rchild!=nullptr){
                Node* temp=r;
                r->data=r->rchild->data;
                r->rchild->data=temp->data;
                r->rchild->data=0;
                delete r->rchild;
                return r;
            }
            if(r->lchild!=nullptr){
                Node* temp=r;
                r->data=r->lchild->data;
                r->lchild->data=temp->data;
                r->lchild->data=0;
                delete r->lchild;
                return r;
            }
        }
        if(r->data>k){
            Eliminate_R(r->lchild, k);
        } else{
            Eliminate_R(r->rchild, k);
        }
    }

    int getData() { return data; }
    int getWeight() { return weight; }
    Node* getLeftChild() { return lchild; }
    Node* getRightChild() { return rchild; }

    void setLeftChild(Node* child) { lchild = child; }
    void setRightChild(Node* child) { rchild = child; }
};
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *rchild;
    Node *lchild;
    int weight;
    Node(int v){
        data = v;
        weight = 1;
        rchild = nullptr;
        lchild = nullptr;
    }
};

//ricorsivo
Node *Insert_R(Node *r, int k){
    if(r == nullptr){
        return new Node(k);
        return r;
    }
    if(r->data == k){
        r->weight++;
        return r;
    }
    if(r->data < k){
        r->lchild = Insert(r->lchild,k);
    }else{
        r->rchild = Insert(r->rchild,k);
    }
    
    return r;
    
}

Node *Search_R(Node *r, int N){
    if(r == nullptr){
        cout << r->weight;
        return r;
    }
    if(r->data == N){
        cout << "il numero è presente con un peso di: " << r->weight;
        return 0;
    }
    if(r->data < N){
        r->lchild = Search(r->lchild, N);
    }else{
        r->rchild = Search(r->rchild, N);
    }
    
    return r;
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

Node* Inorder(Node *r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        if(r->lchild!=NULL){
            Inorder(r->lchild );
        }
        cout<<r->data<<" ";
        if(r->rchild!=NULL){
            Inorder(r->rchild );
        }
    }
    return r;
}

Node* Postorder(Node *r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    } else{
        if(r->lchild!=NULL){
            Postorder(r->lchild );
        }
        if(r->rchild!=NULL){
            Postorder(r->rchild );
        }
        cout<<r->data<<" ";
    }
    return r;
}

int max(int L,int R){
    if (L>R){
        return L;
    } else
    return R;
}

int LevelBST(Node *r){
    if(r == nullptr) return 0;

    int L = LevelBST(r->lchild);
    int R = LevelBST(r->rchild);
    return max(L, R) + 1;
    
}

Node* Preorder_Traversal_Test(Node* r){
    if(r==nullptr){
        cout << "l'albero e vuoto";
        return r;
    }
    cout << r->data << " ";
    if(r->lchild!=nullptr && r->lchild->data<r->data){
        Preorder_Traversal_Test(r->lchild);
    }else if(r->lchild!=nullptr && r->lchild->data>r->data){
        cout << "non e un BST";
    }
    if(r->rchild!=nullptr && r->rchild->data>r->data){
        Preorder_Traversal_Test(r->rchild);
    }else if(r->rchild!=nullptr && r->rchild->data<r->data){
        cout << "non e un BST";
    }
    return r;
}

//iterattivo
bool Search_I(Node *r, int k){
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

Node *Insert_I(Node *r, int k){
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

Node* Eliminate_I(Node* r, int k){
    bool check{true};
    do{
    if(r==nullptr){
        cout << "nodo non trovato";
    }
    if(r->data==k){
        if(r->rchild!=nullptr && r->lchild!=nullptr){
            r->data=0;
            delete r;
        }
        if(r->rchild!=nullptr){
            node*temp=r;
            r->data = r->rchild->data;
            r->rchild->data=temp->data;
            r->rchild->data=0;
            delete r->rchild;
            check=false;
            return r;
        }
        if(r->lchild!=nullptr){
            node*temp=r;
            r->data = r->lchild->data;
            r->lchild->data=temp->data;
            r->lchild->data=0;
            delete r->lchild;
            check=false;
            return r;
        }
    }
    }while(check);
}
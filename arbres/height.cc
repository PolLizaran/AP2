#include <iostream>

using namespace std;

struct Node;

using Arbre = Node*;

struct Node{
    int x;
    Arbre fe;
    Arbre fd;
    ~Node(){
        delete fe;
        delete fd;
    }
};

Arbre read_tree(){ //we read it in preorder
    int x;
    cin >> x;
    if(x == -1) return nullptr;
    else{
        Arbre fe = read_tree();
        Arbre fd = read_tree();
        return new Node{x, fe, fd};
    }
}

int height(Arbre A){
    if(A == nullptr) return 0;
    return max(height(A->fe), height(A->fd)) + 1; //incrememtem l'altura per 1 a cada crida recursiva en la qual pujem de nivell
}

int main(){
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        Arbre A = read_tree();
        cout << height(A) << endl;
        delete A;
    }
}

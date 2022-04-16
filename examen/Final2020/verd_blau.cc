#include <iostream>

using namespace std;

struct Node;

using Tree = Node*;

struct Node{
    char color;
    Tree l_tree;
    Tree r_tree;
    ~Node(){
        delete(l_tree);
        delete(r_tree);
    }
};

Tree read_tree_preorder(){
    char c;
    cin >> c;
    if(c == '-') return nullptr;
    else{
        Tree left = read_tree_preorder();
        Tree right = read_tree_preorder();
        return new Node{c, left, right};
    }
}

//given a green color it checks if all his sons are blue
bool check_sons_blue(Arbre A){
    if(A -> color == 'G') return false;
    check_sons_blue(A->l_tree);
    check_sons_blue(A->r_tree);
    return true;
}

int check_height_preorder(Arbre A, int blue_counter, vector ){
    if(A){
        if(A -> color == 'B') blue_counter += 1;
        if(not(A -> l_tree or A -> r_tree)) blue_counter -= 
    }
}

int main(){
    int n;
    cin >> n;
    while(n > 0){
        Arbre A = read_tree_preorder();
        if
        --n;
        delete A;
    }
}

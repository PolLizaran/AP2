#include <iostream>

using namespace std;

struct Node;

using Tree = Node*;

struct Node{
    string word;
    Tree lt;
    Tree rt;
    ~Node(){
        delete(lt);
        delete(rt);
    }
};

Tree read_tree_preorder(){
    string x;
    cin >> x;
    if(x == "-1") return nullptr;
    else{
        Tree left = read_tree_preorder();
        Tree right = read_tree_preorder();
        return new Node{x, left, right};
    }
}

void printing (Tree T, int depth){
    if(T){
        printing(T->rt, depth + 1);
        cout << string(10*depth - T->word.size(), ' ') << T->word << endl;
        printing(T->lt, depth + 1);
    }
}


int main(){
    Tree T = read_tree_preorder();
    printing(T, 1);
    //it has to be 1, if not we would have a negative size of the string containing
    //the word and spaces
}

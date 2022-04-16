#include <iostream>

using namespace std;

struct Node;

using Tree = Node*;

struct Node{
    int x;
    Tree left;
    Tree right;
    ~Node(){
        delete left;
        delete right;
    }
};

Tree read_tree(){
    int value;
    cin >> value;
    if(value == -1) return nullptr;
    else{
        Tree lft_tree = read_tree();
        Tree right_tree = read_tree();
        return new Node{value, lft_tree, right_tree};
    }
}

bool searcher(Tree T, int value){
    if(not T) return false;
    int digit = T -> x;
    if(value == digit) return true;
    if(value < digit) return searcher(T -> left, value);//we have to move left to search for more little numbers
    if(value > digit) return searcher(T -> right, value); //we have to move right to search for bigger numbers
    return false;
}

//WRONG AS WE DON'T CHECK THE FIRST CASE, PREVIOUS ONE BETTER
/*bool searcher(Tree T, int value){
    int digit = T -> x;
    if(value == digit) return true;
    if(value < digit){
        if(T -> left) return searcher(T -> left, value);//we have to move left to search for more little numbers
    }
    if(value > digit){
        if(T -> right) return searcher(T -> right, value); //we have to move right to search for bigger numbers
    }
    return false;
}*/


int main(){
    int no_importance;
    cin >> no_importance; //we don't have to pay attention
    Tree T = read_tree();
    int value;
    while(cin >> value){
        cout << value << ' ' << searcher(T, value) << endl;
    }
    delete T; 
}

#include <iostream>
#include <queue>

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

Arbre read_tree_preorder(){
    int x;
    cin >> x;
    if(x == -1) return nullptr;
    else{
        Arbre esq = read_tree_preorder(); //as the input is given in postorder, we have to go accross firstly to the left sided trees
        Arbre dre = read_tree_preorder();
        return new Node{x, esq, dre};
    }
}

//si no em queda clar mirar arbre final llibreta blava
int width(Arbre M){//to know the max width we have to do a search by level
    if(not M) return 0; // in case we don't do this assertion the program would be wrong (segmentation fault) as we would add to the queue a tree that is a nullptr
    queue<Arbre> qn;
    qn.push(M);
    int max_width = 0;
    while(not qn.empty()){
        int nodes_per_level = qn.size(); //qn.size() indicated the number of elements in the cue, which are the same as the tree width in that level,
        //this is because when we are in a concrete level, we make a pop of all elements of the queue and add the following elements of 1 level less (in case their exist)
        max_width = max(nodes_per_level, max_width);
        while(nodes_per_level > 0){
            //by doing this condition we avoid to look at leafs at an undesires iteration, meaning that we will just visit the number of nodes per level
            M = qn.front(); //store the root of the subtree
            qn.pop();
            if(M -> fe) qn.push(M -> fe); //this if means that the root is pointing at an element and isn't a nullptr
            if(M -> fd) qn.push(M -> fd);
            --nodes_per_level;
        }
    }
    return max_width;
}

int main(){
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        Arbre M = read_tree_preorder();
        cout << width(M) << endl;
        delete M;
    }
}

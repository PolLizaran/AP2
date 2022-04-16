#include <iostream>

using namespace std;

struct Node;

using Tree = Node*;

struct Node{
    int x;
    Tree lt;
    Tree rt;
    ~Node(){
        delete(lt);
        delete(rt);
    }
};

void printPreorder(Tree T){
    if(T){ //ens assegurem que l'element que volem escriure no sigui un punter nul
        cout << T -> x << endl;
        printPreorder(T-> lt);
        printPreorder(T-> rt);
    }
}

//tenim una refència a un arbre pq d'aquesta manera podem assignar un nou arbre
//al punter que l'arbre anterior estava apuntant. Quan fem el new estem creant una
//fulla de l'arbre, de tal manera que estarà apuntada per l'element de baix.
void SearchAndInsert(Tree& T, int value){
    if(not T) T = new Node{value, nullptr, nullptr};
    else if(value > T -> x) SearchAndInsert(T->rt, value);
    else if(value < T -> x) SearchAndInsert(T->lt, value);
//com que en cap moment hem posat la condicio que el value sigui igual a un element
//qeu ja existeix en l'arbre el void no farà res i passarà d'ell
}


int main(){
    Tree T = nullptr;
    int value;
    while (cin >> value){
        SearchAndInsert(T, value);
    }
    printPreorder(T);
    delete(T);
}

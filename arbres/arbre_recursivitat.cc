#include <iostream>
using namespace std;

struct Node; //declaració avançada per poder utilitzar estrcutura

using Arbre = Node*; // cada node de l'arbre el podem pensar com un arbre

//en comptes de definir els arbres directament recorrerem als nodes per definir-ho
struct Node{
    int x;
    Arbre fill_esq; //punter que referencia a un altre element següent de l'arbre
    Arbre fill_dret;
    ~Node(){
        delete fill_esq;
        delete fill_dret;
    }
};

//el que ens ve amb la sequencia de nombres és la descripcio en preordre d'un arbre.
//Si ens ve un nombre -1 el que hem de retornar és un arbre buit
Arbre llegir_arbre_preordre(){
    int x;
    cin >> x;
    if(x == -1) return nullptr;
    else {
        Arbre fe = llegir_arbre_preordre();
        Arbre fd = llegir_arbre_preordre();
        return new Node{x, fe, fd}; //demanem memòria per guardar la info a través d'una adreça de memòria que és un punter
        //ens retorna un punter al nour arbre creat, on s'inicialitza el primer camp amb x, el segon amb fe...
    }
}

void escriure_arbre_postordre(Arbre a){
    if(a != nullptr){
        escriure_arbre_postordre(a -> fill_esq); //posem una fletxa pq passem a través del punter
        escriure_arbre_postordre(a -> fill_dret); //posem una fletxa pq passem a través del punter
        cout << ' ' << a -> x; ///escrivim el valor de l'arrel
    }
}

void escriure_arbre_inordre(Arbre a){
    if(a != nullptr){
        escriure_arbre_inordre(a -> fill_esq); //posem una fletxa pq passem a través del punter
        cout << ' ' << a -> x; ///escrivim el valor de l'arrel
        escriure_arbre_inordre(a -> fill_dret); //posem una fletxa pq passem a través del punter

    }
}

//per identificar si tenim una fuita de memòria hem d'afegir un -fsanitize=address
int main(){
    Arbre a = llegir_arbre_preordre();
    cout << "pos:";
    escriure_arbre_postordre(a);
    cout << endl
         << "ino:";;
    escriure_arbre_inordre(a);
    cout << endl;
    delete a;
}

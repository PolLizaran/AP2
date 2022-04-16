#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int n;

double huffman(){
    priority_queue<double, vector<double>, greater<double>> pq; //priority_queue containing pairs with the
        //probability of an element and the amount of digits used to codificate it
    for(int i = 0; i < n; ++i){
        double prob;
        cin >> prob;
        pq.push(prob);
    }
    double Average = 0.0;
    while(pq.size() > 1){
        double lowest_1 = pq.top();
        pq.pop();
        double lowest_2 = pq.top();
        pq.pop();
        Average += (lowest_1 + lowest_2) / 100;
        pq.push(lowest_1 + lowest_2);

    }
    return Average; //This pair will be the result of associating a codification
    //to each element, so it will contain the expected lenght to code the entire sequence
}

int main(){
    cout << setprecision(4) << fixed;
    cin >> n;
    cout << "expected number of bits per letter: " << huffman() << endl;
    /*
    for(int j = 0; j < n; ++j){
        cout << pq.top().first << " , ";
        pq.pop();
    }
    cout << endl;*/
}

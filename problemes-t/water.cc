#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
    int BigBottle;
    int MediumBottle;
    int LittleBottle;
};


// Initial: initial configuration from which reachability must be calculated
// Capaxcity: maximum capacity of the containers
// reached: Boolean variables indicating which configurations have already been reached/
// The algorithm uses a DFS strategy to calculate the reachable configurations from Initial.
// At the end of the function, the matrix reached represents all reachable configurations.
void Reachability(const Node& Initial, const Node& Capacity, unordered_set<Node>& pq) {

    // Avoid revisiting configurations
    if (pq.count({Initial.BigBottle, Initial.MediumBottle, Initial.LittleBottle})) return;
    pq.insert({Initial.BigBottle, Initial.MediumBottle, Initial.LittleBottle});

    // Simulates DFS with six possible neighbours. The variable transfers represents the
    // amount of water than can be transferred from one container to another.
    // The first parameter of Reachability is modified according to the transferred water

    // BigBottle -> MediumBottle

    int transfer = min(Capacity.MediumBottle - Initial.MediumBottle, Initial.BigBottle);
    if (transfer > 0) Reachability({Initial.BigBottle-transfer, Initial.MediumBottle+transfer, Initial.LittleBottle}, Capacity, pq);

    // BigBottle -> LittleBottle
    transfer = min(Capacity.LittleBottle - Initial.LittleBottle, Initial.BigBottle);
    if (transfer > 0) Reachability({Initial.BigBottle-transfer, Initial.MediumBottle, Initial.LittleBottle+transfer}, Capacity, pq);


    // MediumBottle -> BigBottle
    transfer = min(Capacity.BigBottle - Initial.BigBottle, Initial.MediumBottle);
    if (transfer > 0) Reachability({Initial.BigBottle+transfer, Initial.MediumBottle-transfer, Initial.LittleBottle}, Capacity, pq);


    // MediumBottle -> LittleBottle
    transfer = min(Capacity.LittleBottle - Initial.LittleBottle, Initial.MediumBottle);
    if (transfer > 0) Reachability({Initial.BigBottle, Initial.MediumBottle-transfer, Initial.LittleBottle+transfer}, Capacity, pq);


    // LittleBottle -> BigBottle
    transfer = min(Capacity.BigBottle - Initial.BigBottle, Initial.LittleBottle);
    if (transfer > 0) Reachability({Initial.BigBottle+transfer, Initial.MediumBottle, Initial.LittleBottle-transfer}, Capacity, pq);


    // LittleBottle -> MediumBottle
    transfer = min(Capacity.MediumBottle - Initial.MediumBottle, Initial.LittleBottle);
    if (transfer > 0) Reachability({Initial.BigBottle, Initial.MediumBottle+transfer, Initial.LittleBottle-transfer}, Capacity, pq);
}

// Reads the maximum capacity of three containers (e.g., 10 7 4).
// Reads the initial configuration of the containers (e.g., 0 7 4).
// Writes all reachable configurations (triplets) from the initial configuration
int main() {

    Node Capacity, Initial;
    // Reads the maximum capacity and the initial configuration
    cin >> Capacity.BigBottle >> Capacity.MediumBottle >> Capacity.LittleBottle;
    cin >> Initial.BigBottle >> Initial.MediumBottle >> Initial.LittleBottle;

    // Boolean variables representing the reached configurations
    // It is a 3D matrix, where each dimension represents the configuration of one container

    unordered_set<Node> pq;
    // DFS to calculate reachability


    Reachability(Initial, Capacity, pq);

    // Print the reached configurations

}

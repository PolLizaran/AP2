#include <iostream>
#include <vector>

using namespace std;

// Triple to store information about the capacity of the containers
struct Containers {
    int big, med, small;
};

// Matrix to represent the reached triples
using Matrix3D = vector<vector<vector<bool>>>;


// Initial: initial configuration from which reachability must be calculated
// Capaxcity: maximum capacity of the containers
// reached: Boolean variables indicating which configurations have already been reached/
// The algorithm uses a DFS strategy to calculate the reachable configurations from Initial.
// At the end of the function, the matrix reached represents all reachable configurations.
void Reachability(const Containers& Initial, const Containers& Capacity, Matrix3D& reached) {

    // Avoid revisiting configurations
    if (reached[Initial.big][Initial.med][Initial.small]) return;

    reached[Initial.big][Initial.med][Initial.small] = true;

    // Simulates DFS with six possible neighbours. The variable transfers represents the
    // amount of water than can be transferred from one container to another.
    // The first parameter of Reachability is modified according to the transferred water

    // big -> med
    int transfer = min(Capacity.med - Initial.med, Initial.big);
    if (transfer > 0) Reachability({Initial.big-transfer, Initial.med+transfer, Initial.small}, Capacity, reached);

    // big -> small
    transfer = min(Capacity.small - Initial.small, Initial.big);
    if (transfer > 0) Reachability({Initial.big-transfer, Initial.med, Initial.small+transfer}, Capacity, reached);

    // med -> big
    transfer = min(Capacity.big - Initial.big, Initial.med);
    if (transfer > 0) Reachability({Initial.big+transfer, Initial.med-transfer, Initial.small}, Capacity, reached);

    // med -> small
    transfer = min(Capacity.small - Initial.small, Initial.med);
    if (transfer > 0) Reachability({Initial.big, Initial.med-transfer, Initial.small+transfer}, Capacity, reached);

    // small -> big
    transfer = min(Capacity.big - Initial.big, Initial.small);
    if (transfer > 0) Reachability({Initial.big+transfer, Initial.med, Initial.small-transfer}, Capacity, reached);

    // small -> med
    transfer = min(Capacity.med - Initial.med, Initial.small);
    if (transfer > 0) Reachability({Initial.big, Initial.med+transfer, Initial.small-transfer}, Capacity, reached);
}

// Reads the maximum capacity of three containers (e.g., 10 7 4).
// Reads the initial configuration of the containers (e.g., 0 7 4).
// Writes all reachable configurations (triplets) from the initial configuration
int main() {

    Containers Capacity, Initial;
    // Reads the maximum capacity and the initial configuration
    cin >> Capacity.big >> Capacity.med >> Capacity.small;
    cin >> Initial.big >> Initial.med >> Initial.small;

    // Boolean variables representing the reached configurations
    // It is a 3D matrix, where each dimension represents the configuration of one container
    Matrix3D reached(Capacity.big+1, vector<vector<bool>>(Capacity.med+1, vector<bool>(Capacity.small+1, false)));

    // DFS to calculate reachability
    Reachability(Initial, Capacity, reached);

    // Print the reached configurations
    for (int b = 0; b < reached.size(); ++b) {
        for (int m = 0; m < reached[0].size(); ++m) {
            for (int s = 0; s < reached[0][0].size(); ++s) {
                if (reached[b][m][s])cout << b << " " << m << " " << s << endl;
            }
        }
    }
}

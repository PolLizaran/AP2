#include <iostream>
#include <vector>


using namespace std;

struct Node {
    int BigBottle;
    int MediumBottle;
    int LittleBottle;
};

using Graph = vector<vector<vector<bool>>>;

void pouring_water(const Node& Initial, const Node& Size, Graph& visited, Node& Final) {

    //means we jump to the next recursion call as the vertex already exists
    if (visited[Initial.BigBottle][Initial.MediumBottle][Initial.LittleBottle]) return;

    visited[Initial.BigBottle][Initial.MediumBottle][Initial.LittleBottle] = true;

    if (Initial.LittleBottle == 2) Final = {Initial.BigBottle, Initial.MediumBottle, Initial.LittleBottle};

    //simulates the dropping of water from LittleBottle to BigBottle
    //Size.BigBottle - Initial.BigBottle is the free space remaining in the container
    int water_to_drop = min(Size.BigBottle - Initial.BigBottle, Initial.LittleBottle);
    if (water_to_drop != 0) pouring_water({Initial.BigBottle + water_to_drop, Initial.MediumBottle,
        Initial.LittleBottle - water_to_drop}, Size, visited, Final);


    //recursion done 6 times, one for each possible drop.
    //.
    //.
    //.

}

int main() {

    Node Size, Initial;
    //read the size of containers and it's initial state
    cin >> Size.BigBottle >> Size.MediumBottle >> Size.LittleBottle;
    cin >> Initial.BigBottle >> Initial.MediumBottle >> Initial.LittleBottle;

    Graph visited(Size.BigBottle+1, vector<vector<bool>>(Size.MediumBottle+1, vector<bool>(Size.LittleBottle+1, false)));
    Node Final;
    pouring_water(Initial, Size, visited, Final);

    // Print the visited configurations
    for (int b = 0; b < visited.size(); ++b) {
        for (int m = 0; m < visited[0].size(); ++m) {
            for (int s = 0; s < visited[0][0].size(); ++s) {
                if (visited[b][m][s])cout << b << " " << m << " " << s << "   "  << endl;
            }
        }
    }

}

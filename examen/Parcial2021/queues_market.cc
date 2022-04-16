#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Customer {
    string name;
    string graduation;
    long time;
};

//this operator has the needed criterials in order to store the clients in the correct order

bool operator<(const Customer& p, const Customer& q)
{
    if (p.graduation == q.graduation) //tie case
        return p.time > q.time;
    string grad1 = p.graduation;
    string grad2 = q.graduation;
    if (grad1 == "colonel")
        grad1 = "a"; //will be the bigger string
    else if (grad1 == "captain")
        grad1 = "b"; //will be the second string
    if (grad2 == "colonel")
        grad2 = "a";
    else if (grad2 == "captain")
        grad2 = "b";
    //as grad1 and grad2 now contain a string in lexicographical order, we can just make a return
    return grad1 > grad2;
}

//given a vector, this action reads all the clients from the input with it's correspondant graduation range
void read_queues(vector<priority_queue<Customer>>& v, long& time)
{
    int n = v.size();
    string client, line;
    getline(cin, line);
    //We read the first line where the number of queues was given, even though we'll ignore it,
    //if not we have problems when reading the input
    for (int i = 0; i < n; ++i) {
        string client, line;
        getline(cin, line);
        istringstream in(line);
        while (in >> client) {
            string grad; //store the graduation of the client
            in >> grad;
            v[i].push({ client, grad, time });
            ++time;
        }
    }
}

/*action that adds a client to the asked queue*/
void enters(vector<priority_queue<Customer>>& v, long& time)
{
    string client, grad;
    cin >> client >> grad;
    int queue;
    cin >> queue;
    int n = v.size();
    if (queue >= 1 and queue <= n) { //means the queue given is legal
        v[queue - 1].push({ client, grad, time });
        //we have to take into account the positions of a vector go from 0 to v.size()-1
        ++time;
    }
}

/*this action is used to remove a person from the asked queue. It also checks if the given
queue is legal*/
void leaves(vector<priority_queue<Customer>>& v, bool& first)
{
    int queue;
    cin >> queue;
    int n = v.size();
    if (queue >= 1 and queue <= n and not v[queue - 1].empty()) {
        //means the queue given is legal and the queue isn't empty
        if (first) {
            cout << "DEPARTS" << endl
                 << "-------" << endl;
            first = false; //we don't want to write "DEPARTS" anymore
        }
        Customer s = v[queue - 1].top();
        cout << s.name << endl; //print the client that goes out of the queue
        v[queue - 1].pop(); //susbtract the client in the asked order
    }
}

/*action that given a vector and an instruction, calls two external actions in order to modify
the customers that are waiting in each queue. The parameter time is used to compare the clients
in case of tie in their graduations*/
void update_info(vector<priority_queue<Customer>>& v, const string& order, bool& first, long& time)
{
    if (order == "ENTERS") {
        enters(v, time);
    } else if (order == "LEAVES") {
        leaves(v, first);
    }
}

//action that is just used at the end of the program to print the elements that remain in each queue
void write_final_contents(vector<priority_queue<Customer>>& v, bool& first)
{
    if (first) {
      cout << "DEPARTS" << endl
           << "-------" << endl;
      first = false; //we don't want to write "DEPARTS" anymore
    }
    cout << endl
         << "FINAL CONTENTS" << endl
         << "--------------" << endl;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        cout << "queue " << i + 1 << ':';
        while (not v[i].empty()) {
            Customer s = v[i].top();
            cout << ' ' << s.name;
            v[i].pop();
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n; //number of queues
    vector<priority_queue<Customer>> v(n);
    long time = 1; //variable used to know which customes has arrived first
    read_queues(v, time); //store the input in the queues
    string order;
    bool first = true; //Boolean that aids us to write the output correctly
    while (cin >> order) {
        update_info(v, order, first, time);
    }
    write_final_contents(v, first); //print the queues
}

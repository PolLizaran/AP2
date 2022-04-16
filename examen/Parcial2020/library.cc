#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void read_stacks(vector<stack<string>>& books){
  int n = books.size();
  string title, line;
  getline(cin, line); //to read the line where the number was, if not, we could have errors
  for(int i = 0; i < n; ++i){
    getline(cin, line);
    istringstream in(line);
    while(in >> title) books[i].push(title);
  }
}

//action that prints all the stacks and reverse them in order to write them in order
void write_stacks(vector<stack<string>>& books){
  int x = 1;
  for(stack s : books){
    cout << "Stack " << x << ":";
    stack<string> reverse;
    while(not s.empty()){
      reverse.push(s.top());
      s.pop();
    }
    while(not reverse.empty()){
      cout << ' '<< reverse.top();
      reverse.pop();
    }
    cout << endl;
    ++x;
  }
}

void update_stacks(vector<stack<string>>& books, string order){
  int n_stack;
  if(order == "LOAN"){
    cin >> n_stack;
    if(n_stack >= 1 and n_stack <= books.size() and
      not books[n_stack - 1].empty()) books[n_stack - 1].pop(); //lend a book to the reader
  }else if(order == "RETURN"){
    string ret_book;
    cin >> ret_book >> n_stack;
    if(n_stack >= 1 and n_stack <= books.size()) books[n_stack - 1].push(ret_book);
  }
}


int main(){
  int n;
  cin >> n;
  vector<stack<string>> books(n);
  read_stacks(books);
  string order;
  while (cin >> order){
    update_stacks(books, order);
  }
  write_stacks(books);
}

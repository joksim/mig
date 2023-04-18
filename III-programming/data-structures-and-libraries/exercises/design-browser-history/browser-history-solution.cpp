#include <iostream>
#include <stack>
#include <string>
using std::stack;
using std::string;
using std::cout;


class BrowserHistory {
    stack<string> history, future;
    string current;
public:
    BrowserHistory(string homepage) {
        // 'homepage' is the first visited URL.
        current = homepage;
    }

    void visit(string url) {
        // Push 'current' in 'history' stack and mark 'url' as 'current'.
        history.push(current);
        current = url;
        // We need to delete all entries from 'future' stack.
        future = stack<string>();
    }

    string back(int steps) {
        // Pop elements from 'history' stack, and push elements in 'future' stack.
        while(steps > 0 && !history.empty()) {
            future.push(current);
            current = history.top();
            history.pop();
            steps--;
        }
        return current;
    }

    string forward(int steps) {
        // Pop elements from 'future' stack, and push elements in 'history' stack.
        while(steps > 0 && !future.empty()) {
            history.push(current);
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};
using std::string;

int main(){
  BrowserHistory history ("https://www.google.com");

  // User visits a few pages
  history.visit("https://www.google.com/search?q=java");
  history.visit("https://www.wikipedia.org/");
  history.visit("https://www.amazon.com/");

  // User clicks back button once
  string previousPage = history.back(1);
  cout << "\nUser is now on page: " << previousPage;

  // User clicks forward button twice
  string nextPage = history.forward(2);
  cout << "\nUser is now on page: ",  nextPage;
}

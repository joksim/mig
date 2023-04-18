/*
You have a browser of one tab where you start on the homepage and you can visit another url,
 get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:
 - BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
 - void visit(string url) Visits url from the current page. It clears up all the forward history.
    string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
        string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

 */


#include <stack>
#include <string>

using std::stack, std::string;

class BrowserHistory {
private:
  stack<string> history; // Stack to store past pages
  stack<string> future; // Stack to store future pages
public:
  // Constructor that takes the starting page URL and adds it to the history
  BrowserHistory(string homepage) {
    visit(homepage);
  }

  // Adds a new page to the history and clears the future stack
  void visit(string url) {
    history.push(url);
    future = stack<string>(); // Clear the future stack
  }

  // Moves the user back a certain number of pages in the history
  string back(int steps) {
    while (history.size() > 1 && steps-- > 0)
      future.push(history.top()), history.pop(); // Move pages from history to future stack
    return history.top(); // Return the current page after navigation
  }

  // Moves the user forward a certain number of pages in the future
  string forward(int steps) {
    while (!future.empty() && steps-- > 0)
      history.push(future.top()), future.pop(); // Move pages from future to history stack
    return history.top(); // Return the current page after navigation
  }
};
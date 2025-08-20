// #include <bits/stdc++.h>
// using namespace std;

// class BrowserHistory {
//     stack<string> stk1, stk2;
// public:
    
//     BrowserHistory(string homepage) {
//         visit(homepage);
//     }

//     void visit(string url) {
//         stk1.push(url);
//         stk2 = stack<string>();
//     }

//     string back(int steps) {
//         while(stk1.size()>1 && steps>0){
//             steps--;
//             stk2.push(stk1.top());
//             stk1.pop();
//         }
//         return stk1.top();
//     }

//     string forward(int steps) {
//         while(!stk2.empty() && steps>0){
//             steps--;
//             stk1.push(stk2.top());
//             stk2.pop();
//         }
//         return stk1.top();
//     }
// };

// /**
//  * Your BrowserHistory object will be instantiated and called as such:
//  * BrowserHistory* obj = new BrowserHistory(homepage);
//  * obj->visit(url);
//  * string param_2 = obj->back(steps);
//  * string param_3 = obj->forward(steps);
//  */
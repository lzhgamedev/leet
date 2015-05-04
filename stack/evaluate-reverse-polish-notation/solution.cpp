class Solution {
public:
    stack<int> p;
    int evalRPN(vector<string>& tokens) {
        int i = 0;
        int ans;
        int a, b;
        char sig;
        while(i < tokens.size()) {
            if(tokens[i] != "+" &&
               tokens[i] != "-" &&
               tokens[i] != "*" &&
               tokens[i] != "/") {
                   p.push(atoi(tokens[i].c_str()));
               }
            else {
                b = p.top();
                p.pop();
                a = p.top();
                p.pop();
                sig = tokens[i][0];
                switch(sig) {
                case '+':
                    p.push(a + b);
                    break;
                case '-':
                    p.push(a - b);
                    break;
                case '*':
                    p.push(a * b);
                    break;
                case '/':
                    p.push(a / b);
                    break;
                default:
                    break;
                }
            }
            ++i;
        }
        return p.top();
    }
};
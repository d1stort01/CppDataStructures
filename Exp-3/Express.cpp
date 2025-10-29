#include "Express.hpp"

void Express::Trans()
{
    if (!this->isValid()) {
        return;
    }
    stack<char> opor;
    int i = 0;
    char ch, e;
    while (i < exp.length()) {
        ch = exp[i];
        if (ch == '(') {
            opor.push(ch);
        }
        else if (ch == ')') {
            while (!opor.empty() && opor.top() != '(') {
                e = opor.top();
                opor.pop();
                post_exp += e;
            }
            opor.pop();
        }
        else if (ch == '+' || ch == '-') {
            while (!opor.empty() && opor.top() != '(') {
                e = opor.top();
                opor.pop();
                post_exp += e;
            }
            opor.push(ch);
        }
        else if (ch == '*' || ch == '/') {
            while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/')) {
                e = opor.top();
                opor.pop();
                post_exp += e;
            }
            opor.push(ch);
        }
        else {
            string d = "";
            while (ch >= '0' && ch <= '9') {
                d += ch;
                i++;
                if (i < exp.length()) {
                    ch = exp[i];
                }
                else {
                    break;
                }
            }
            i--;
            post_exp += d;
            post_exp += "#";
        }
        i++;
    }
    while (!opor.empty()) {
        e = opor.top();
        opor.pop();
        post_exp += e;
    }
}

double Express::GetValue()
{
    if (!this->isValid()) {
        return NULL;
    }
    stack<double> opand;
    double a, b, c, d;
    char ch;
    int i = 0;
    while (i < post_exp.length()) {
        ch = post_exp[i];
        switch (ch) {
        case '+':
            a = opand.top();
            opand.pop();
            b = opand.top();
            opand.pop();
            c = b + a;
            opand.push(c);
            break;
        case '-':
            a = opand.top();
            opand.pop();
            b = opand.top();
            opand.pop();
            c = b - a;
            opand.push(c);
            break;
        case '*':
            a = opand.top();
            opand.pop();
            b = opand.top();
            opand.pop();
            c = b * a;
            opand.push(c);
            break;
        case '/':
            a = opand.top();
            opand.pop();
            b = opand.top();
            opand.pop();
            c = b / a;
            opand.push(c);
            break;
        default:
            d = 0;
            while (ch >= '0' && ch <= '9') {
                d = d * 10 + (ch - '0');
                i++;
                ch = post_exp[i];
            }
            opand.push(d);
            break;
        }
        i++;
    }
    return opand.top();
}

bool Express::isValid()
{
    int bal = 0;
    for (char ch : exp) {
        if (ch == '(') {
            bal++;
        }
        if (ch == ')') {
            bal--;
        }
        if (bal < 0) {
            return false;
        }
    }
    if (bal != 0) {
        return false;
    }
    return true;
}

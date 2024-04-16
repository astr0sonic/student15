#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>


std::string N2(std::istream&);
std::string checkCorrect(std::istream&);

unsigned getPriority(char c)
{
    switch (c)
    {
    case '^':
        return 0;
    case '~':
        return 1;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 3;
    case '(':
        return 4;
    default:
        throw std::invalid_argument("Wrong char");
    }
}



std::string checkCorrect(std::istream& in) {
    bool flag = false;
    std::stringstream expression;
    std::stack<char> s;
    while (in.peek() != EOF && in.peek() != '\n') {
        char c = in.peek();
        if (isdigit(c)) {
            if (flag) {
                return "invalid";
            }
            double l;
            in >> l;
            expression << l << ' ';
            flag = true;
        }
        else {
            in.get();
            switch (c) {
            case ' ':
                break;
            case '^':
            case '*':
            case '/':
            case '+':
                if (!flag) {
                    return "invalid";
                }
                while (!s.empty() && getPriority(s.top()) <= getPriority(c)) {
                    expression << s.top() << ' ';
                    s.pop();
                }
                s.push(c);
                flag = false;
                break;
            case '(':
                if (flag) return "invalid";
                s.push(c);
                break;
            case ')':
                if (!flag) return "invalid";
                while (!s.empty() && s.top() != '(') {
                    expression << s.top() << ' ';                    s.pop();
                }
                if (s.empty()) return "invalid";
                s.pop();
                break;
            case '-':
                if (!flag) c = '~';
                while (!s.empty() && getPriority(s.top()) <= getPriority(c)) {
                    expression << s.top() << ' ';
                    s.pop();
                }
                s.push(c);
                flag = false;
                break;
            default:
                return "invalid";
            }
        }
    }
    if (!flag) return "invalid";
    while (!s.empty()) {
        if (s.top() == '(') return "invalid";
        expression << s.top() << ' ';
        s.pop();
    }
    return N2(expression);
}


double calculate(std::string const& in)
{
    std::stringstream str(in);
    std::string s = checkCorrect(std);
    if (s == "invalid") {
        throw std::exception();
    }
    else {
        return std::stod(s);
    }
}



std::string N2(std::istream& in)
{
    std::stack<double> s;
    while (in.peek() != EOF && in.peek() != '\n')
    {
        char c = in.peek();
        if (isdigit(c))
        {
            double d;
            in >> d;
            s.push(d);
        }
        else
        {
            double a, b;
            in.get();
            switch (c)
            {
            case '+':
                if (s.size() < 2)
                    return "invalid";
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a + b);
                break;
            case '-':
                if (s.size() < 2)
                    return "invalid";
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a - b);
                break;
            case '*':
                if (s.size() < 2)
                    return "invalid";
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a * b);
                break;
            case '/':
                if (s.size() < 2)
                    return "invalid";
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a / b);
                break;
            case '^':
                if (s.size() < 2)
                    return "invalid";
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(std::pow(a, b));
                break;
            case '~':
                if (s.size() < 1)
                    return "invalid";
                a = s.top();
                s.pop();
                s.push(-a);
                break;
            case ' ':
                break;
            default:
                return "invalid";
            }
        }
    }
    if (s.size() > 1)
        return "invalid";
    return std::to_string(s.top());
}

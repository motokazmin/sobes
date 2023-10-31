/*

������ �������� ���������. ���������� ��������� ��� �������� ��� ����������, ��� ��� �������� ������. 
� ��������� ����� ����������� ����� ��������, ���������, ���������, ������ � ������� (�������� ������ ����� ���� �� ������). 
��������� �������� �����������. ��� ����� � ��������� �����

��������

��� ���������� ��������� ��������� � ������ ���������� ��������, �� ������ ������������ �������� �������� 
�������� ������ (Reverse Polish Notation, RPN), ����� ��������� ��� ����������� �������. ���� �������� 
��������� ��������� ���������� ��������� � ������ � ���������.

��� ���������� ������� ������� ��������� �� ������ (�����, ���������, ������), ������������� ��� � RPN � ����� ��������� �������� RPN.
*/

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int calculateRPN(string& rpn) {
    stack<int> operands;
    for (char c : rpn) {
        if (isdigit(c)) {
            int num = c - '0';
            while (isdigit(rpn[1])) {
                num = num * 10 + (rpn[1] - '0');
                rpn.erase(0, 1);
            }
            operands.push(num);
        } else if (c == '+' && !operands.empty()) {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a + b);
        } else if (c == '-' && !operands.empty()) {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a - b);
        } else if (c == '*' && !operands.empty()) {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            operands.push(a * b);
        }
    }
    if (!operands.empty()) {
        return operands.top();
    }
    return 0;
}

int main() {
    string expression;
    getline(cin, expression);

    // ��������� ��������� � ����������� ������� (RPN)
    string rpn;
    stack<char> operators;
    for (char c : expression) {
        if (isdigit(c)) {
            rpn += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn += operators.top();
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop();
            }
        } else {
            while (!operators.empty() && operators.top() != '(' && (c == '+' || c == '-' || (c == '*' && (operators.top() == '*' || operators.top() == '+' || operators.top() == '-')))) {
                rpn += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        rpn += operators.top();
        operators.pop();
    }

    int result = calculateRPN(rpn);
    cout << result << endl;

    return 0;
}

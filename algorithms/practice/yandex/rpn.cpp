/*

Задано числовое выражение. Необходимо вычислить его значение или установить, что оно содержит ошибку. 
В выражении могут встречаться знаки сложения, вычитания, умножения, скобки и пробелы (пробелов внутри чисел быть не должно). 
Приоритет операций стандартный. Все числа в выражении целые

Алгоритм

Для вычисления числового выражения с учетом приоритета операций, вы можете использовать алгоритм обратной 
польской записи (Reverse Polish Notation, RPN), также известный как постфиксная нотация. Этот алгоритм 
позволяет правильно обработать операторы и скобки в выражении.

Вам необходимо разбить входное выражение на токены (цифры, операторы, скобки), преобразовать его в RPN и затем вычислить значение RPN.
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

    // Переводим выражение в постфиксную нотацию (RPN)
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

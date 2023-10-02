#include <Windows.h>
#include <conio.h>
#include <string>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <math.h>

using namespace std;

void setTextColor(int textColorIndex) { // Смена цвета текста
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (0 << 4) + textColorIndex);
}

string toLowerCase(string s) {
    string c = "";
    for (int i = 0; i < s.length(); i++)
        c += tolower(s[i]);
    return c;
}

unsigned priority(string c) {
    switch (c[0]) {
    case '(': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    case '^': return 4;
    default: return 0;
    }
}

bool isFunction(string s) {
    if (toLowerCase(s) == "sin" or toLowerCase(s) == "cos")
        return 1;
    return 0;
}

string* tokenizer(string expression, unsigned& counter) {
    size_t arrSize = 100;
    string* exprArr = new string[arrSize];
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i]) or expression[i] == '-') {
            if (isdigit(expression[i]))
                temp += expression[i];
            else {
                if (temp != "") {
                    exprArr[counter] = temp;
                    counter++;
                    temp = "";
                }
                if (counter > 0 and (isdigit(exprArr[counter - 1][0]) or (exprArr[counter - 1][0] == '-' and exprArr[counter - 1].length() > 1 and isdigit(exprArr[counter - 1][1])))) {
                    exprArr[counter] = "-";
                    counter++;
                }
                else
                    temp += '-';
            }
        }
        else {
            if (temp != "") {
                exprArr[counter] = temp;
                counter++;
                temp = "";
            }
            if (expression[i] != ' ' and expression[i] != '\t') {
                string func = "";
                if (i + 2 < expression.length())
                    func = func + expression[i] + expression[i + 1] + expression[i + 2];
                if (isFunction(func)) {
                    i += 2;
                }
                else {
                    func = "";
                    func += expression[i];
                }
                exprArr[counter] = func;
                counter++;
            }
        }
    }
    if (temp != "") {
        exprArr[counter] = temp;
        counter++;
        temp = "";
    }
    return exprArr;
}

string* tokenizerCalc(string expression, unsigned& counter) {
    string temp = "";
    int arrSize = 100;
    string* exprArr = new string[arrSize];
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ' and temp != "") {
            exprArr[counter] = temp;
            temp = "";
            counter++;
        }
        else
            temp += expression[i];
    }
    if (temp != "") {
        exprArr[counter] = temp;
    }
    return exprArr;
}

void creationOutput(int current) {
    setTextColor(15);
    cout << "\tВыберите действие.\n";
    setTextColor(6 - (current == 1 ? 5 : 0));
    cout << "[1] ";
    setTextColor(15);
    cout << "Поиграть с двусвязным списком." << '\n';
    setTextColor(6 - (current == 2 ? 5 : 0));
    cout << "[2] ";
    setTextColor(15);
    cout << "Поиграть со стеком." << '\n';
    setTextColor(6 - (current == 3 ? 5 : 0));
    cout << "[3] ";
    setTextColor(15);
    cout << "Поиграть с очередью." << '\n';
    setTextColor(6 - (current == 4 ? 5 : 0));
    cout << "[4] ";
    setTextColor(15);
    cout << "Прямая польская нотация." << '\n';
    setTextColor(4 - (current == 5 ? 3 : 0));
    cout << "[ESC] ";
    setTextColor(15);
    cout << "Выход из программы." << '\n';
}

void linkedListOutput(int current) {
    setTextColor(15);
    cout << "\tВыберите действие.\n";
    setTextColor(6 - (current == 1 ? 5 : 0));
    cout << "[1] ";
    setTextColor(15);
    cout << "Создать новый список." << '\n';
    setTextColor(6 - (current == 2 ? 5 : 0));
    cout << "[2] ";
    setTextColor(15);
    cout << "Добавить элемент в список." << '\n';
    setTextColor(6 - (current == 3 ? 5 : 0));
    cout << "[3] ";
    setTextColor(15);
    cout << "Удалить элемент из списка." << '\n';
    setTextColor(6 - (current == 4 ? 5 : 0));
    cout << "[4] ";
    setTextColor(15);
    cout << "Удалить список." << '\n';
    setTextColor(6 - (current == 5 ? 5 : 0));
    cout << "[5] ";
    setTextColor(15);
    cout << "Вывести список." << '\n';
    setTextColor(4 - (current == 6 ? 3 : 0));
    cout << "[ESC] ";
    setTextColor(15);
    cout << "Выход из программы." << '\n';
}

void stackOutput(int current) {
    setTextColor(15);
    cout << "\tВыберите действие.\n";
    setTextColor(6 - (current == 1 ? 5 : 0));
    cout << "[1] ";
    setTextColor(15);
    cout << "Создать новый стэк." << '\n';
    setTextColor(6 - (current == 2 ? 5 : 0));
    cout << "[2] ";
    setTextColor(15);
    cout << "Добавить элемент в стэк." << '\n';
    setTextColor(6 - (current == 3 ? 5 : 0));
    cout << "[3] ";
    setTextColor(15);
    cout << "Удалить элемент из стэка." << '\n';
    setTextColor(6 - (current == 4 ? 5 : 0));
    cout << "[4] ";
    setTextColor(15);
    cout << "Удалить стэк." << '\n';
    setTextColor(6 - (current == 5 ? 5 : 0));
    cout << "[5] ";
    setTextColor(15);
    cout << "Вывести стэк." << '\n';
    setTextColor(4 - (current == 6 ? 3 : 0));
    cout << "[ESC] ";
    setTextColor(15);
    cout << "Выход из программы." << '\n';
}

void queueOutput(int current) {
    setTextColor(15);
    cout << "\tВыберите действие.\n";
    setTextColor(6 - (current == 1 ? 5 : 0));
    cout << "[1] ";
    setTextColor(15);
    cout << "Создать новую очередь." << '\n';
    setTextColor(6 - (current == 2 ? 5 : 0));
    cout << "[2] ";
    setTextColor(15);
    cout << "Добавить элемент в очередь." << '\n';
    setTextColor(6 - (current == 3 ? 5 : 0));
    cout << "[3] ";
    setTextColor(15);
    cout << "Удалить элемент из очереди." << '\n';
    setTextColor(6 - (current == 4 ? 5 : 0));
    cout << "[4] ";
    setTextColor(15);
    cout << "Удалить очередь." << '\n';
    setTextColor(6 - (current == 5 ? 5 : 0));
    cout << "[5] ";
    setTextColor(15);
    cout << "Вывести очередь." << '\n';
    setTextColor(4 - (current == 6 ? 3 : 0));
    cout << "[ESC] ";
    setTextColor(15);
    cout << "Выход из программы." << '\n';
}

string stdToRpn(string expression) {
    unsigned counter = 0;
    string* exprArr = tokenizer(expression, counter);
    Stack stack;
    Queue queue;
    for (int i = 0; i < counter; i++) {
        if (isdigit(exprArr[i][0]) or (exprArr[i].length() > 1 and isdigit(exprArr[i][1])))
            queue.push(exprArr[i]);
        else if (isFunction(exprArr[i]) or exprArr[i] == "(")
            stack.push(exprArr[i]);
        else if (exprArr[i] != ")") {
            while (stack.getLength() > 0 and priority(stack.peek()) >= priority(exprArr[i])) {
                queue.push(stack.peek());
                stack.pop();
            }
            stack.push(exprArr[i]);
        }
        else if (exprArr[i] == ")") {
            while (stack.peek() != "(") {
                if (stack.getLength()) {
                    queue.push(stack.peek());
                    stack.pop();
                }
                else
                    return "";
            }
            stack.pop();
            if (stack.getLength() and isFunction(stack.peek())) {
                queue.push(stack.peek());
                stack.pop();
            }
        }
    }
    while (stack.getLength()) {
        if (stack.peek() == "(")
            return "";
        queue.push(stack.peek());
        stack.pop();
    }
    string answer = "";
    while (queue.getLength()) {
        answer += queue.peek() + " ";
        queue.pop();
    }
    delete[] exprArr;
    return answer;
}

string operation(string val1, string val2, string op) {
    if (op == "-")
        return to_string(stod(val1) - stod(val2));
    if (op == "+")
        return to_string(stod(val1) + stod(val2));
    if (op == "*")
        return to_string(stod(val1) * stod(val2));
    if (op == "/")
        return to_string(stod(val1) / stod(val2));
    if (op == "^")
        return to_string(pow(stod(val1), stod(val2)));
}

string function(string value, string func) {
    if (toLowerCase(func) == "sin")
        return to_string(sin(stod(value)));
    return to_string(cos(stod(value)));
}

string calcRpn(string expression) {
    Stack stack;
    unsigned counter = 0;
    string* rpn = tokenizerCalc(expression, counter);
    for (int i = 0; i < counter; i++) {
        if (isdigit(rpn[i][0]) or (rpn[i].length() > 1 and isdigit(rpn[i][1]))) {
            stack.push(rpn[i]);
        }
        else if (isFunction(rpn[i])) {
            string value = stack.peek();
            stack.pop();
            stack.push(function(value, rpn[i]));
        }
        else {
            string value2 = stack.peek();
            stack.pop();
            string value1 = stack.peek();
            stack.pop();
            stack.push(operation(value1, value2, rpn[i]));
        }
    }
    string answer = stack.peek();
    stack.pop();
    delete[] rpn;
    return answer;
}

int output(void outputType(int), unsigned max) {
    int currentNum = 1;
    unsigned button;
    outputType(currentNum);
    while (TRUE) {
        button = _getch();
        button = (button == 224) ? _getch() : button;
        if (button == 80 || button == 77) {           // Управление стрелками движения вниз
            system("cls");
            currentNum += 1;
            currentNum = currentNum == max + 1 ? 1 : currentNum;
            outputType(currentNum);
        }
        else if (button == 72 || button == 75) {      // Управление стрелками движения вверх
            system("cls");
            currentNum -= 1;
            currentNum = currentNum == 0 ? max : currentNum;
            outputType(currentNum);

        }
        else if (button >= 49 && button <= 48 + max) {      // Управление цифрами
            system("cls");
            currentNum = button - 48;
            outputType(currentNum);
            system("cls");
            return currentNum;
        }
        else if (button == 13) {   // Нажат enter
            if (currentNum != max)   // Нажат не enter+[esc]
            {
                system("cls");
                return currentNum;
            }
            else                   // Нажат enter+[esc]
            {
                system("cls");
                return 0;
            }
        }
        else if (button == 27)  // Нажат esc
        {
            system("cls");
            return 0;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int currentNum = output(creationOutput, 5);
    while (currentNum) {
        switch (currentNum) {
        case 1:
        {
            Number defaultValues[] = { "1", "2", "3", "4" };
            LinkedList* a = new LinkedList(4, defaultValues);
            currentNum = output(linkedListOutput, 6);
            while (currentNum) {
                switch (currentNum) {
                case 1:
                {
                    delete a;
                    unsigned length;
                    cout << "Введите длину списка: ";
                    cin >> length;
                    while (!length) {
                        cout << "Длина списка должна быть больше 0!\n\n";
                        cout << "Введите длину списка: ";
                        cin >> length;
                    }
                    cout << "Введите " << length << " значений: ";
                    Number* values = new Number[length];
                    for (int i = 0; i < length; i++) {
                        cin >> values[i];
                    }
                    a = new LinkedList(length, values);
                    cout << "Новый список успешно создан!\n";
                    break;
                }
                case 2:
                {
                    int index;
                    cout << "Введите индекс элемента, перед которым хотите добавить новый: ";
                    cin >> index;
                    while (index < 0 or index > a->getLength()) {
                        cout << "Неверный индекс\n\n";
                        cout << "Введите индекс элемента, перед которым хотите добавить новый: ";
                        cin >> index;
                    }
                    Number value;
                    cout << "Введите значение нового элемента: ";
                    cin >> value;
                    a->push(index, value);
                    cout << "Элемент успешно добавлен!\n";
                    break;
                }
                case 3:
                {
                    if (a->getLength() == 0) {
                        cout << "В списке нет элементов!\n";
                        break;
                    }
                    int index;
                    cout << "Введите индекс элемента, который хотите удалить: ";
                    cin >> index;
                    while (index < 0 or index > a->getLength() - 1) {
                        cout << "Неверный индекс\n\n";
                        cout << "Введите индекс элемента, который хотите удалить: ";
                        cin >> index;
                    }
                    a->pop(index);
                    cout << "Элемент успешно удалён!\n";
                    break;
                }
                case 4:
                {
                    delete a;
                    a = new LinkedList;
                    cout << "Список успешно удалён!\n";
                    break;
                }
                case 5:
                {
                    cout << '\n' << *a << '\n';
                    break;
                }
                }
                system("pause");
                system("cls");
                currentNum = output(linkedListOutput, 6);
            }
            delete a;
            break;
        }
        case 2:
        {
            Number defaultValues[] = { "1", "2", "3", "4" };
            Stack* a = new Stack(4, defaultValues);
            currentNum = output(stackOutput, 6);
            while (currentNum) {
                switch (currentNum) {
                case 1:
                {
                    delete a;
                    unsigned length;
                    cout << "Введите длину стэка: ";
                    cin >> length;
                    while (!length) {
                        cout << "Длина стэка должна быть больше 0!\n\n";
                        cout << "Введите длину стэка: ";
                        cin >> length;
                    }
                    cout << "Введите " << length << " значений: ";
                    Number* values = new Number[length];
                    for (int i = 0; i < length; i++) {
                        cin >> values[i];
                    }
                    a = new Stack(length, values);
                    cout << "Новый стэк успешно создан!\n";
                    break;
                }
                case 2:
                {
                    Number value;
                    cout << "Введите значение нового элемента: ";
                    cin >> value;
                    a->push(value);
                    cout << "Элемент успешно добавлен!\n";
                    break;
                }
                case 3:
                {
                    if (a->getLength() == 0) {
                        cout << "В стэке нет элементов!\n";
                        break;
                    }
                    a->pop();
                    cout << "Элемент успешно удалён!\n";
                    break;
                }
                case 4:
                {
                    delete a;
                    a = new Stack;
                    cout << "Стэк успешно удалён!\n";
                    break;
                }
                case 5:
                {
                    cout << '\n' << *a << '\n';
                    break;
                }
                }
                system("pause");
                system("cls");
                currentNum = output(stackOutput, 6);
            }
            delete a;
            break;
        }
        case 3:
        {
            Number defaultValues[] = { "1", "2", "3", "4" };
            Queue* a = new Queue(4, defaultValues);
            currentNum = output(queueOutput, 6);
            while (currentNum) {
                switch (currentNum) {
                case 1:
                {
                    delete a;
                    unsigned length;
                    cout << "Введите длину очереди: ";
                    cin >> length;
                    while (!length) {
                        cout << "Длина очереди должна быть больше 0!\n\n";
                        cout << "Введите длину очереди: ";
                        cin >> length;
                    }
                    cout << "Введите " << length << " значений: ";
                    Number* values = new Number[length];
                    for (int i = 0; i < length; i++) {
                        cin >> values[i];
                    }
                    a = new Queue(length, values);
                    cout << "Новая очередь успешно создана!\n";
                    break;
                }
                case 2:
                {
                    Number value;
                    cout << "Введите значение нового элемента: ";
                    cin >> value;
                    a->push(value);
                    cout << "Элемент успешно добавлен!\n";
                    break;
                }
                case 3:
                {
                    if (a->getLength() == 0) {
                        cout << "В очереди нет элементов!\n";
                        break;
                    }
                    a->pop();
                    cout << "Элемент успешно удалён!\n";
                    break;
                }
                case 4:
                {
                    delete a;
                    a = new Queue;
                    cout << "Очередь успешно удалена!\n";
                    break;
                }
                case 5:
                {
                    cout << '\n' << *a << '\n';
                    break;
                }
                }
                system("pause");
                system("cls");
                currentNum = output(queueOutput, 6);
            }
            delete a;
            break;
        }
        case 4:
        {
            string expr = "";
            cout << "Введите выражение:\n";
            char c;
            cin.get(c);
            while (c != '\n') {
                expr += c;
                cin.get(c);
            }
            expr = stdToRpn(expr);
            cout << expr << '\n' << '\n';
            expr = calcRpn(expr);
            cout << expr << '\n';
            system("pause");
            system("cls");
            break;
        }
        }
        currentNum = output(creationOutput, 5);
    }
    return 0;
}
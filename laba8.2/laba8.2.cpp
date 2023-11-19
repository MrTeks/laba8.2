#include <iostream>
#include <string>
using namespace std;

/*Дана строка, состоящая из слов, набранных заглавными буквами и
разделенных пробелами(одним или несколькими).Преобразовать каждое
слово в строке заменив в нем все последующие вхождения его первой буквы
на символ «.»(точка).*/
// Функция для обработки одного слова
string processWord(string word) {
    string result;
    if (word.length() > 0) {
        result += word[0]; // Первую букву оставляем без изменений
        for (int i = 1; i < word.length(); ++i) {
            if (word[i] == word[0]) {
                result += '.'; // Заменяем символы, совпадающие с первой буквой, на точки
            }
            else {
                result += word[i]; // Оставляем остальные символы без изменений
            }
        }
    }
    return result;
}

// Функция для обработки всей строки
string processString(string input) {
    string result;
    string word;
    for (char ch : input) {
        if (ch == ' ') {
            result += processWord(word); // Обрабатываем текущее слово и добавляем его к результату
            result += ' '; // Добавляем пробел к результату
            word.clear(); // Очищаем текущее слово для обработки следующего
        }
        else {
            word += ch; // Собираем текущее слово
        }
    }
    result += processWord(word); // Обрабатываем последнее слово после последнего пробела
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    string result = processString(input); // Обрабатываем строку и получаем результат

    cout << "Результат: " << result << endl;
    return 0;
}
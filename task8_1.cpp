#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


bool compare(string& a, string& b) { // функция сравнения по убыванию длины слова  // если не измен констант ссылка
    return a.length() > b.length();
}


void to_lower(string& word) { // делаем слово в нижнем регистре
    for (unsigned short i = 0; i < word.length(); i++) {
        char in = word.data()[i];
        if (in <= 'Z' && in >= 'A')
            word.data()[i] = in - ('Z' - 'z');
    }
}


int main() {
    // записываем имя файла
    string filename;
    cout << "file: ";
    cin >> filename;

    // записываем букву(по условию)
    string letter;
    cout << "letter: ";
    cin >> letter;
    to_lower(letter);

    ifstream file(filename);

    if (!file) {
        cout << "file doesn't exist!" << endl;
        return 1;
    }

    // объявляем поток стринга и записываем в него содержание файла для разбития по пробелам
    stringstream ss;
    ss << file.rdbuf();

    vector<string> words;
    string word;

    while (ss >> word) {
        to_lower(word);
        if (find(words.begin(), words.end(), word) == words.end()) { // если слова ещё нет в словах
            words.push_back(word);
        }
    }

    file.close();

    sort(words.begin(), words.end(), compare); // сортируем по функции

    ofstream file_sorted(filename + "_sorted");
    if (!file_sorted) {
        cout << "error creating file!" << endl;
        return 1;
    }

    try{
        file_sorted.clear();
        for (string& word : words)
            if (word.at(0) == letter.at(0)) // если первая буква совпадает с введёной
                file_sorted << word << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    file_sorted.close();
}

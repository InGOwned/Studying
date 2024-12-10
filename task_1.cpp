#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool check_word(const string& word, const string& given_word);
bool compare_length(const string& a, const string& b);

int main() {
    string given_word;
    cout << "Enter word: ";
    cin >> given_word;

    int n;
    cout << "Enter N: ";
    cin >> n;

    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cerr << "Wrong input file" << endl;
        return 1;
    }

    set<string> longest_words;
    string word;

    while (input_file >> word) {
        if (check_word(word, given_word)) {
            longest_words.insert(word);
        }
    }

    input_file.close();


    vector<string> sorted_words(longest_words.begin(), longest_words.end());
    sort(sorted_words.begin(), sorted_words.end(), compare_length);

    ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        cerr << "Wrong open output file!" << endl;
        return 1;
    }

    for (int i = 0; i < min((int)sorted_words.size(), n); ++i) {
        output_file << sorted_words[i] << endl;
    }
    output_file.close();

    cout << "Result in output.txt" << endl;

    return 0;
}

bool check_word(const string& word, const string& given_word) {
    string sorted_word = word;
    string sorted_given_word = given_word;
    
    sort(sorted_word.begin(), sorted_word.end());
    sort(sorted_given_word.begin(), sorted_given_word.end());

    if (sorted_word.length() != sorted_given_word.length() + 1) {
        return false;
    }

    string diff;
    set_difference(sorted_word.begin(), sorted_word.end(),
                   sorted_given_word.begin(), sorted_given_word.end(),
                   back_inserter(diff));

    return diff.length() == 1;
}


bool compare_length(const string& a, const string& b) {
    return a.length() > b.length();
}

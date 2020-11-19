#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Find(string str, string templ);

int SubFind(string main_str, string find_str);

int main()
{
    setlocale(LC_ALL, "rus");

    string source, pattern;

    cout << "Введите ФИО: ";
    getline(cin, source);

    cout << "Введите шаблон: ";
    getline(cin, pattern);

    cout << Find(source, pattern) << endl;
    cout << SubFind(source, pattern) << endl;
}


int Find(string str, string templ)
{
    int  i, j, strlen, templlen;

    strlen = str.length();
    templlen = templ.length();
    int* d = new int[templlen];

    i = 0;
    j = -1;
    d[0] = -1;
    while (i < templlen - 1)
    {
        while ((j >= 0) && (templ[j] != templ[i])) 
        {
            j = d[j];
        }
        ++i;
        ++j;
        d[i] = (templ[i] == templ[j]) ? d[j] : j;
    }

    for (i = 0, j = 0; (i <= strlen - 1) && (j <= templlen - 1); ++i, ++j)
    {
        while ((j >= 0) && (templ[j] != str[i])) 
        {
            j = d[j];
        }
    }
    delete[] d;

    return (j == templlen) ? i - j : -1;
}

int SubFind(string main_string, string find_string) {
    int result = -1;
    const char* find_str = find_string.c_str();
    const char* main_str = main_string.c_str();
    if (strlen(find_str) > strlen(main_str)) {
        return result;
    }
    bool isFindResult = false;
    for (int i = 0; i <= strlen(main_str) - strlen(find_str) && !isFindResult; i++) {
        char* save_str = new char[strlen(find_str) + 1]{};
        for (int j = 0; j < strlen(find_str); j++) {
            save_str[j] = main_str[i + j];
        }

        if (!strcmp(save_str, find_str)) {
            result = i;
            isFindResult = true;
        }
        delete[] save_str;
    }
    return result;
}
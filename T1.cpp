//Developed by Danilo Silveira Ramos
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool InsertWord(vector<string> &ListOfWords);
bool PrintList(const vector<string> &ListOfWords); // read only e com referência (sem cópia)
bool SearchWord(const vector<string> &ListOfWords);
bool SearchSubstring(const vector<string> &ListOfWords);
bool RemoveByIndex(vector<string> &ListOfWords, size_t index); // not read only
bool RemoveBySubstring(vector<string> &ListOfWords);
void LoadData(vector<string> &ListOfWords);
void SaveData(const vector<string> &ListOfWords);

int main()
{
    vector<string> ListOfWords;
    LoadData(ListOfWords);
    for (;;)
    {
        char option;
        cout << "-------------------------------------------------------" << endl;
        cout << "UFxC String Store V.0" << endl;
        cout << "1. Insert string" << endl;
        cout << "2. Print index and string" << endl;
        cout << "3. Search string (literal)" << endl;
        cout << "4. Search substrings" << endl;
        cout << "5. Remove string (by index)" << endl;
        cout << "6. Remove by substrings (all occurrences)" << endl; // opcional, remover todos os index com determinada substring
        cout << "0. Quit" << endl;
        cout << "-------------------------------------------------------" << endl;

        cout << "Enter an option: ";
        cin >> option;

        if (option == '1')
        {
            InsertWord(ListOfWords);
        }
        else if (option == '2')
        {
            PrintList(ListOfWords);
        }
        else if (option == '3')
        {
            SearchWord(ListOfWords);
        }
        else if (option == '4')
        {
            SearchSubstring(ListOfWords);
        }
        else if (option == '5')
        {
            size_t index;
            cout << "Enter an index to remove: ";
            cin >> index;
            if (index < ListOfWords.size())
            {
                RemoveByIndex(ListOfWords, index);
            }
            else
            {
                cout << "Error: Index out of range." << endl;
            }
        }
        else if (option == '6')
        {
            RemoveBySubstring(ListOfWords);
        }
        else if (option == '0')
        {
            SaveData(ListOfWords);
            break;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}

bool InsertWord(vector<string> &ListOfWords)
{
    string word;
    cout << "Enter a word to insert: ";
    cin >> word;
    ListOfWords.push_back(word);
    return true;
}

bool PrintList(const vector<string> &ListOfWords)
{
    for (size_t i = 0; i < ListOfWords.size(); i++)
    {
        cout << "Index: " << i << " -> " << ListOfWords.at(i) << endl;
    }
    return true;
}

bool SearchWord(const vector<string> &ListOfWords)
{
    cout << "Enter a word to search: ";
    string word;
    cin >> word;

    for (size_t i = 0; i < ListOfWords.size(); i++)
    {
        if (ListOfWords.at(i) == word)
        {
            cout << "Word " << word << " has been found at position " << i << endl;
            return true;
        }
    }
    cout << "Word " << word << " not found" << endl;
    return false;
}

bool SearchSubstring(const vector<string> &ListOfWords)
{
    cout << "Enter a substring to search: ";
    string substr;
    cin >> substr;
    bool hasfound = false;
    for (size_t i = 0; i < ListOfWords.size(); i++)
    {
        string word = ListOfWords.at(i);
        size_t pos = word.find(substr);
        if (pos != string::npos)
        {
            cout << "Substring " << substr << " has been found at " << i << " -> " << word << endl;
            hasfound = true;
        }
    }
    // if(ListOfWords.at(i).find(substr).size() < ListOfWords.at(i).size()
    if (!hasfound)
        cout << "Nothing has been found" << endl;
    return hasfound;
}

bool RemoveByIndex(vector<string> &ListOfWords, size_t index)
{
    ListOfWords.erase(ListOfWords.begin() + index);
    cout << "Word at index " << index << " has been removed" << endl;
    return true;
}

bool RemoveBySubstring(vector<string> &ListOfWords)
{
    cout << "Enter a substring to search: ";
    string substr;
    cin >> substr;

    bool hasfound = false;
    for (size_t i = 0; i < ListOfWords.size();)
    {
        string word = ListOfWords.at(i);
        size_t pos = word.find(substr);
        if (pos != string::npos)
        {
            cout << "Word at index " << i << " -> " << word << " has substring " << substr << endl;
            ListOfWords.erase(ListOfWords.begin() + i);
            hasfound = true;
        }
        else
        {
            i++;
        }
    }
    if (!hasfound)
        cout << "Substring " << substr << " not found" << endl;
    return hasfound;
}

void LoadData(vector<string> &ListOfWords)
{
    ifstream file("data.txt");
    if (file.is_open())
    {
        string word;
        while (file >> word)
        {
            ListOfWords.push_back(word);
        }
        file.close();
        cout << "Data has been loaded" << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void SaveData(const vector<string> &ListOfWords)
{
    ofstream file("data.txt");
    if (file.is_open())
    {
        for (const auto &word : ListOfWords)
        {
            file << word << endl;
        }
        file.close();
        cout << "Data has been saved" << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

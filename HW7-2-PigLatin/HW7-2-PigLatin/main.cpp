#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <regex>

using namespace std;

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& seperator)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(seperator);
    pos1 = 0;

    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));		// use vector to store words
        pos1 = pos2 + seperator.size();
        pos2 = s.find(seperator, pos1);
    }

    if (pos1 != s.length())
        v.push_back(s.substr(pos1));			// store the last word
}

int main()
{
    const std::regex PATTERN("^[A-Za-z\\s]+$");							// regular expression
    string CONSONANTS = "bcdfghgklmnpqrstvwxyz", VOWELS = "aeiou";		// constant variables of consonants and vowels
    string totalInput;
    vector<string> words;

    while (true)
    {
        cout << "Please input a sentence: ";
        getline(cin, totalInput);

        if (std::regex_match(totalInput, PATTERN))		// check invalid character
        {
            if (totalInput == "Exit")
            {
                return 0;
            }

            if (totalInput[0] < 65 || totalInput[0] > 90)
            {
                cout << "The first letter is not capitalized, please input again.\n" << endl;		// check the first letter
                continue;
            }

            transform(totalInput.begin(), totalInput.end(), totalInput.begin(), ::tolower);			// converte all letters to lowercase
            SplitString(totalInput, words, " ");		// Function to split words
            cout << "Pig latin sentence : ";

            for (vector<string>::size_type i = 0; i != words.size(); ++i)
            {
                if (CONSONANTS.find(words.at(i)[0]) != string::npos)
                {
                    words.at(i) = words.at(i).substr(1).append(words.at(i).substr(0, 1)).append("ay");		// words begin with consonants
                }
                else if (VOWELS.find(words.at(i)[0]) != string::npos)		// words begin with vowels
                {
                    words.at(i) = words.at(i).append("way");
                }
                else						// ignore spaces
                {
                    continue;
                }

                if (i == 0)
                {
                    words.at(i)[0] -= 32;		// Capitalize the first letter
                }

                cout << words.at(i) << " ";
            }

            cout << "\n" << endl;
            vector <string>().swap(words);		// clear the vector
        }
        else
        {
            cout << "Invalid input!\n" << endl;
        }
    }

    return 0;
}


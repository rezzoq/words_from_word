#include <iostream>
#include <clocale>
#include <conio.h> 
#include <vector>
#include <string>
#include <fstream>

/* eng dictionary */
void en_word(std::vector<std::string> final, std::vector<std::string>& itog)
/* here we read english words and compare with our letters kit */
{
    std::string w; // written strokes
    std::ifstream f("C:\\all_words\\words.txt"); // file with engligh words
    int check = 0; /* marker in case of a word match */

    while (getline(f, w)) { /* until the end of the file we put every stroke to variable w */
        for (int i = 0; i < final.size(); i++) /* open our combined words */
            if (w == final[i]) /* and if we find conformity */
            {   /* and we try to expect the same words checking our final words base */
                for (int k = 0; k < itog.size(); k++) if (w == itog[k]) check++;
                if (check == 0) itog.push_back(w);
                check = 0;
            }
    }

    f.close(); // close our file
}

typedef char(*Func)(const char& s);
/* Main Function. Victor is our vector with entered letters. 
* Str will be returned as new "word". Number is number of
* letters, e is main and final number and it doesn't change.
*/
void my(std::vector<char>& victor, std::string str, size_t number, int e, Func ch, std::vector<std::string>& fin)
{
    for (size_t i = 0; i < victor.size(); i++)
        if (number >= 1) { /* I've used recurcion */
            my(victor, str + ch(victor[i]), number - 1, e, ch,fin);
        }
    if (str.size() == e) {
        //std::cout << str << '2' << std::endl; it was checking point
        fin.push_back(str);
    }
}

char bracket(const char& s) {
    return s;
}

int main()
{
	char word = 'a'; /* variable char for our future letters */
    std::vector<char> vec; /* and also vector for letters */
    int i = 0; /* counter for letters */

    /* pushing letters into vector until user press = */
    while ((word = std::cin.get()) != '=') 
    {
        i++;
        vec.push_back(word);
    }
    std::cout << "\n";

    std::string s;
    std::vector<std::string> fina; /* combinations of letters'll be here */
    for (int k = 1; k <= i; k++)
    {
        int e = k;
        std::cout << '3';
        my(vec, s, k, e, bracket,fina);
    }

    std::cout << ' ' << "NOW..." << std::endl;
    for (int k = 0; k < fina.size(); k++) std::cout << fina[k] << std::endl; /* checking */

    std::cout << std::endl << ' ' << "CHECK AGAIN..." << std::endl;

    std::vector<std::string> itogo; 
    en_word(fina, itogo);
    for (int k = 0; k < itogo.size(); k++) std::cout << itogo[k] << ' ';

    std::cout << "END..." << std::endl;

    return 0;
}
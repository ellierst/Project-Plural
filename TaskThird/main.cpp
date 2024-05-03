#include "Set.h" 
#include <iostream> 
#include <string> 

using namespace std;

int main() {

    Set<char> alphabet;

    string letters;

    cout << "Enter a string of letters: " << endl;
    getline(cin, letters);

    cout << "\nFirst appearance of elements: " << alphabet.findFirstAppearance(letters) << endl;

    cout << "\nElements appearing at least twice: " << alphabet.findAtLeastTwice(letters) << endl;

    cout << "\nElements only appear 1 time: " << alphabet.findOnlyOnce(letters) << endl;

    return 0;
}

#include "Set.h"

int main() {

	Set<string> alphabet;

	string letters[] = { "a", "b", "r", "a", "c", "a", "d", "a", "b", "r", "a" };
	alphabet.add(letters, 11);
	cout << "Contents of letters set:" << endl;
	alphabet.print();

	cout << "\nFirst appearance of elements: " << endl;
	Set<string> firstAppearance = alphabet.first_appearance();
	firstAppearance.print();

	cout << "\nElements appearing at least twice: " << endl;
	Set<string> atLeastTwo = alphabet.apper_min_2_times();
	atLeastTwo.print();

	cout << "\nElements only appear 1 time: " << endl;
	Set<string> onlyOne = alphabet.apper_1_times();
	onlyOne.print();

	return 0;
}
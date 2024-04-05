#include <iostream>
#include "Template.h"
#include "Test.h"

using namespace std;

int main(int argc, char** argv) {

	
	Set<int> intSet;

	intSet.add(1).add(22).add(45).add(17).add(10);
	cout << "Contents of int set:" << endl;
	intSet.print();
	cout << "Size of int set: " << intSet.getSize() << endl;

	intSet.remove(10);
	cout << "\nContents after removing 10:" << endl;
	intSet.print();

	cout << "Size of int set: " << intSet.getSize() << endl;

	cout << "\nDoes the set contain 1? " << (intSet.contains(1) ? "Yes" : "No") << endl;



	Set<int> integerSet;

	int elements[] = { 1, 22, 83, 64, 45, 18, 10 };
	integerSet.add(elements, 7);

	cout << "\nContents of integer set:" << endl;
	integerSet.print();
	cout << "Size of integer set: " << integerSet.getSize() << endl;

	cout << "\nDoes the set contain 1? " << (intSet.contains(1) ? "Yes" : "No") << endl;

	Set<int> result = intSet.grouping(integerSet);
	cout << "\nGrouping result:" << endl;
	result.print();


	Set<int> intersectionSet = intSet.intersect(integerSet);
	cout << "\nIntersection of sets:" << endl;
    intersectionSet.print();

	Set<int> differenceSet = intSet.diff(integerSet);
	cout << "\nDifference of sets (intSet - integerSet):" << endl;
	differenceSet.print();

	Set<int> symDifferenceSet = intSet.sym_diff(integerSet);
	cout << "\nSymmetric difference of sets:" << endl;
	symDifferenceSet.print();

	cout << endl;
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}

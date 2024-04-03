#include <iostream>
#include "Template.h"
#include "Test.h"

using namespace std;

int main(int argc, char** argv) {

    string shop1Products[] = { "butter", "milk", "salt", "sugar", "tea" };
    string shop2Products[] = { "milk", "meat", "fish", "salt" };
    string products[] = { "bread", "butter", "milk", "salt", "sugar", "tea", "cheese", "meat", "fish" };

    Set<string> shop1, shop2;

    for (const string& product : shop1Products) {
        shop1.add(product);
    }

    for (const string& product : shop2Products) {
        shop2.add(product);
    }

    cout << "Assortment of shop 1:" << endl;
    shop1.print();
    cout << endl;

    cout << "Assortment of shop 2:" << endl;
    shop2.print();
    cout << endl;

    //1
    Set<string> commonProducts = shop1.intersect(shop2);
    cout << "\nProducts present in every shop:" << endl;
    commonProducts.print();

    //2
    Set<string> allProductsInStores = shop1.grouping(shop2);
    cout << "\nProducts present in at least one shop:" << endl;
    allProductsInStores.print();

    //3
    Set<string> allProducts;
    for (const string& product : products) {
        allProducts.add(product);
    }

    Set<string> missingProducts = allProducts.diff(shop1.grouping(shop2));
    cout << "\nProducts missing in the network:" << endl;
    missingProducts.print();

    return 0;
}

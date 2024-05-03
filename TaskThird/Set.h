#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Set
{
private:

    struct Node
    {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head;
    int size;


public:
    Set() : head(nullptr), size(0) {}

    Set(const Set<T>& S)
    {
        head = nullptr;
        size = 0;
        Node* temp = S.head;
        while (temp != nullptr)
        {
            add(temp->value);
            temp = temp->next;
        }
    }

    ~Set()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Set(T* elems, int n) : head(nullptr), size(0)
    {
        for (int i = 0; i < n; ++i)
        {
            add(elems[i]);
        }
    }

    Set<T>& operator=(const Set<T>& other)
    {
        if (this != &other)
        {

            while (head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            size = 0;


            Node* temp = other.head;
            while (temp != nullptr)
            {
                add(temp->value);
                temp = temp->next;
            }
        }
        return *this;
    }

    Set<T>& add(const T& x)
    {
        Node* newNode = new Node(x);
        if (head == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        ++size;
        return *this;
    }

    Set<T>& add(T* elems, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            add(elems[i]);
        }
        return *this;
    }

    Set<T>& remove(const T& x)
    {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->value != x)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Element not found in set" << endl;
            return *this;
        }

        if (prev == nullptr)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
        --size;

        return *this;
    }

    void print() const
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }

    bool contains(const T& x) const
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->value == x)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

string findFirstAppearance(const string& letters) {
    string firstAppearanceString;
    Set<char> appeared;

    for (char letter : letters) {
        if (!appeared.contains(letter)) {
            firstAppearanceString.push_back(letter);
            appeared.add(letter);
        }
    }

    return firstAppearanceString;
}


string findAtLeastTwice(const string& letters) {
    string atLeastTwiceString;
    Set<char> atLeastTwice;

    for (char letter : letters) {
        if (letters.find(letter, letters.find(letter) + 1) != string::npos) {
            atLeastTwice.add(letter);
        }
    }

    for (char letter : letters) {
        if (atLeastTwice.contains(letter) && atLeastTwiceString.find(letter) == string::npos) {
            atLeastTwiceString.push_back(letter);
        }
    }

    return atLeastTwiceString;
}


string findOnlyOnce(const string& letters) {
    string onlyOnceString;
    Set<char> atLeastTwice;

    for (char letter : letters) {
        if (letters.find(letter, letters.find(letter) + 1) != string::npos) {
            atLeastTwice.add(letter);
        }
    }

    for (char letter : letters) {
        if (!atLeastTwice.contains(letter) && onlyOnceString.find(letter) == string::npos) {
            onlyOnceString.push_back(letter);
        }
    }

    return onlyOnceString;
}
};

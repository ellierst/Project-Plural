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
        if (head == nullptr || head->value > x)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->value < x)
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
        cout << "Set contents: ";
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

    Set<T> grouping(const Set<T>& S) const
    {
        Set<T> result(*this);
        Node* temp = S.head;
        while (temp != nullptr)
        {
            if (!result.contains(temp->value))
            {
                result.add(temp->value);
            }
            temp = temp->next;
        }
        return result;
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


    Set<T> intersect(const Set<T>& S) const
    {
        Set<T> result;

        Node* temp = head;
        while (temp != nullptr)
        {
            if (S.contains(temp->value))
            {
                result.add(temp->value);
            }
            temp = temp->next;
        }

        return result;
    }


    Set<T> diff(const Set<T>& S) const
    {
        Set<T> result;

        Node* temp = head;
        while (temp != nullptr)
        {
            if (!S.contains(temp->value))
            {
                result.add(temp->value);
            }
            temp = temp->next;
        }

        return result;
    }

    Set<T> sym_diff(const Set<T>& S) const
    {
        Set<T> result;

        Node* temp1 = head;
        while (temp1 != nullptr)
        {
            if (!S.contains(temp1->value))
            {
                result.add(temp1->value);
            }
            temp1 = temp1->next;
        }

        Node* temp2 = S.head;
        while (temp2 != nullptr)
        {
            if (!contains(temp2->value))
            {
                result.add(temp2->value);
            }
            temp2 = temp2->next;
        }

        return result;
    }
};
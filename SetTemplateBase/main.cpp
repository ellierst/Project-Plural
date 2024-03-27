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
            head = newNode;
        }
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                if (temp->value == x) 
                {
                    delete newNode;
                    return *this; 
                }
                temp = temp->next;
            }
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
};

int main() {
   
    Set<int> intSet;

   
    intSet.add(1).add(2).add(5).add(7).add(10);

    
    cout << "Contents of int set:" << endl;
    intSet.print();

    
    intSet.remove(10);


    cout << "Contents after removing 10:" << endl;
    intSet.print();

    Set<int> integerSet;

    
    int elements[] = { 1, 2, 3, 4, 5, 8, 10 };
    integerSet.add(elements, 7);


    cout << "Contents of integer set:" << endl;
    integerSet.print();


    return 0;
}

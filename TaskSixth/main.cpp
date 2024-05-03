#include <iostream>
#include <string>
using namespace std;


template <typename T>
class Set {
private:
    struct Node {
        T value; 
        Node* next; 
        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* head; 
    int size;

public:
    Set() : head(nullptr), size(0) {}

    ~Set() {
        
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Set<T>& add(const T& x) {
        if (!contains(x)) {
            Node* newNode = new Node(x);
            if (head == nullptr) {
                head = newNode;
            }
            else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode; 
            }
            size++;
        }
        return *this; 
    }

    bool contains(const T& x) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == x) {
                return true; 
            }
            temp = temp->next;
        }
        return false; 
    }

    int getSize() const {
        return size; 
    }

    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl; 
    }

    Set<T> intersect(const Set<T>& other) const {
        Set<T> result;
        Node* temp = head;
        while (temp != nullptr) {
            if (other.contains(temp->value)) {
                result.add(temp->value); 
            }
            temp = temp->next;
        }
        return result; 
    }

    Set<T> diff(const Set<T>& other) const {
        Set<T> result;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (!other.contains(temp->value)) {
                result.add(temp->value); 
            }
            temp = temp->next;
        }
        return result; 
    }
};

struct Person {
    string name; 
    Set<string> visits; 

    Person(const string& name) : name(name) {}

    void visit(const string& friendName) {
        visits.add(friendName); 
    }

    void printVisits() const {
        cout << name << " visited: ";
        visits.print(); 
    }
};

int main() {
    Person people[] = {
        Person("Olexa"),
        Person("Yulia"),
        Person("Kateryna"),
        Person("Vitaliy"),
        Person("Artemiy"),
        Person("Markiyan"),
        Person("Vladyslav"),
        Person("Oleg"),
        Person("Ksenia"),
        Person("Olha"),
        Person("Sofiya"),
        Person("Andriy"),
        Person("Ivan"),
        Person("Yuriy"),
        Person("Taras"),
        Person("Kostiantyn"),
        Person("Halyna"),
        Person("Vasyl"),
        Person("Solomiya"),
        Person("Mykola"),
        Person("Iryna")
    };

    people[0].visit("Yulia");
    people[0].visit("Kateryna");
    people[1].visit("Olexa");
    people[1].visit("Vitaliy");
    people[2].visit("Yulia");
    people[3].visit("Olexa");
    people[3].visit("Markiyan");
    people[4].visit("Markiyan");
    people[5].visit("Artemiy");
    people[6].visit("Markiyan");
    people[7].visit("Iryna");

    // TASK 6.1
    int minVisits = INT_MAX;
    Set<string> peopleWithMinVisits;
    for (const Person& person : people) {
        int visitCount = person.visits.getSize(); 
        if (visitCount < minVisits) {
            minVisits = visitCount;
            peopleWithMinVisits = Set<string>();
            peopleWithMinVisits.add(person.name);
        }
        else if (visitCount == minVisits) {
            peopleWithMinVisits.add(person.name);
        }
    }
    cout << "People who visit least often: ";
    peopleWithMinVisits.print(); 

    // TASK 6.2
    for (const Person& person : people) {
        Set<string> visits = person.visits; 
        Set<string> others;
        for (const Person& otherPerson : people) {
            if (person.name != otherPerson.name) {
                others.add(otherPerson.name);
            }
        }

        if (visits.getSize() == others.getSize() && visits.intersect(others).getSize() == others.getSize()) {
            cout << person.name << " visited all friends." << endl;
        }
    }

    // TASK 6.3
    for (int i = 0; i < 21; i++) {
        for (int j = i + 1; j < 21; j++) {
            for (int k = j + 1; k < 21; k++) {
                if (people[i].visits.contains(people[j].name) &&
                    people[i].visits.contains(people[k].name) &&
                    people[j].visits.contains(people[i].name) &&
                    people[j].visits.contains(people[k].name) &&
                    people[k].visits.contains(people[i].name) &&
                    people[k].visits.contains(people[j].name)) {
                    cout << "Close circle of three friends found: "
                        << people[i].name << ", " << people[j].name << ", " << people[k].name << endl;
                }

                for (int l = k + 1; l < 21; l++) {
                    if (people[i].visits.contains(people[j].name) &&
                        people[i].visits.contains(people[k].name) &&
                        people[i].visits.contains(people[l].name) &&
                        people[j].visits.contains(people[i].name) &&
                        people[j].visits.contains(people[k].name) &&
                        people[j].visits.contains(people[l].name) &&
                        people[k].visits.contains(people[i].name) &&
                        people[k].visits.contains(people[j].name) &&
                        people[k].visits.contains(people[l].name) &&
                        people[l].visits.contains(people[i].name) &&
                        people[l].visits.contains(people[j].name) &&
                        people[l].visits.contains(people[k].name)) {
                        cout << "Tight circle of four friends found: "
                            << people[i].name << ", " << people[j].name << ", "
                            << people[k].name << ", " << people[l].name << endl;
                    }
                }
            }
        }
    }

    // TASK 6.4
    for (const Person& person : people) {
        person.printVisits(); 
    }

    return 0;
}

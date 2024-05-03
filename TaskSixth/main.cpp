#include <iostream>
#include <string>

using namespace std;

// Основні свої міркування я виклав у файлі README.txt, 
// проте також я б хотів окремо ще в самому коді прокоментувати декілька рядків, на реалізацію яких слід було б звернути увагу.

template <typename T>
class Set {
private:
    struct Node {
        T value; 
        Node* next; 
        Node(const T& value) : value(value), next(nullptr) {} // Конструктор
    };

    Node* head; 
    int size; // Розмір списку 

public:
    // Конструктор за замовчуванням
    Set() : head(nullptr), size(0) {}

    // Деструктор
    ~Set() {
        
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Додає елемент до списку, якщо він не міститься в ньому
    Set<T>& add(const T& x) {
        // Перевіряє, чи елемент вже міститься в списку
        if (!contains(x)) {
            // Створює новий вузол та додає його в кінець списку
            Node* newNode = new Node(x);
            if (head == nullptr) {
                head = newNode; // Якщо список порожній, встановлює новий вузол як голову
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

    // Перевіряє, чи містить список певний елемент
    bool contains(const T& x) const {
        Node* temp = head;
        // Проходить по списку та порівнює значення
        while (temp != nullptr) {
            if (temp->value == x) {
                return true; 
            }
            temp = temp->next;
        }
        return false; 
    }

    // Повертає розмір списку
    int getSize() const {
        return size; // Повертає кількість елементів у списку
    }

    // Виводить всі елементи списку
    void print() const {
        Node* temp = head;
        // Проходить по списку та виводить значення кожного елемента
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl; 
    }

    // Повертає новий Set, що містить елементи, які присутні в обох Set
    Set<T> intersect(const Set<T>& other) const {
        Set<T> result;
        Node* temp = head;
        // Проходить по поточному Set та перевіряє, чи є кожен елемент в іншому Set
        while (temp != nullptr) {
            if (other.contains(temp->value)) {
                result.add(temp->value); // Додає елементи, які присутні в обох Set
            }
            temp = temp->next;
        }
        return result; 
    }

    // Повертає новий Set, що містить елементи, які присутні лише в поточному Set
    Set<T> diff(const Set<T>& other) const {
        Set<T> result;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (!other.contains(temp->value)) {
                result.add(temp->value); // Додає елементи, які присутні лише в поточному Set
            }
            temp = temp->next;
        }
        return result; 
    }
};

struct Person {
    string name; 
    Set<string> visits; 

    // Конструктор
    Person(const string& name) : name(name) {}

    // Додає візит до іншої людини
    void visit(const string& friendName) {
        visits.add(friendName); // Додає ім'я до Set відвідувань
    }

    // Виводить список відвідувань
    void printVisits() const {
        cout << name << " visited: ";
        visits.print(); // Виводить Set імен, яких відвідувала людина
    }
};

int main() {
    // Створення списку людей
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

    // Додаємо візити для людей
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

    // TASK 6.1: Хто з людей ходить в гості найменше разів?
    int minVisits = INT_MAX;
    Set<string> peopleWithMinVisits;
    for (const Person& person : people) {
        int visitCount = person.visits.getSize(); // Кількість візитів людини
        // Якщо кількість візитів менша за поточний мінімум, оновлюємо мінімум та перелік осіб
        if (visitCount < minVisits) {
            minVisits = visitCount;
            peopleWithMinVisits = Set<string>();
            peopleWithMinVisits.add(person.name);
        }
        else if (visitCount == minVisits) {
            // Якщо кількість візитів така ж, додаємо особу до списку осіб з мінімальним візитом
            peopleWithMinVisits.add(person.name);
        }
    }
    cout << "People who visit least often: ";
    peopleWithMinVisits.print(); // Виводимо людей, які ходять в гості найменше разів

    // TASK 6.2: Хто відвідав усіх своїх друзів?
    // Перевіряємо кожну людину, щоб визначити, чи вона відвідала всіх інших людей
    for (const Person& person : people) {
        Set<string> visits = person.visits; // Set відвідувань людини
        Set<string> others;
        // Створюємо Set інших людей, яких потрібно перевірити
        for (const Person& otherPerson : people) {
            if (person.name != otherPerson.name) {
                others.add(otherPerson.name);
            }
        }

        // Якщо всі інші люди є у відвідуваннях, виводимо, що людина відвідала всіх друзів
        if (visits.getSize() == others.getSize() && visits.intersect(others).getSize() == others.getSize()) {
            cout << person.name << " visited all friends." << endl;
        }
    }

    // TASK 6.3: Перевіряємо, чи є тісне коло з трьох або чотирьох друзів
    // Потрійний цикл для перевірки комбінацій людей
    for (int i = 0; i < 21; i++) {
        for (int j = i + 1; j < 21; j++) {
            for (int k = j + 1; k < 21; k++) {
                // Перевіряємо, чи ці три людини є частиною тісного кола
                if (people[i].visits.contains(people[j].name) &&
                    people[i].visits.contains(people[k].name) &&
                    people[j].visits.contains(people[i].name) &&
                    people[j].visits.contains(people[k].name) &&
                    people[k].visits.contains(people[i].name) &&
                    people[k].visits.contains(people[j].name)) {
                    cout << "Close circle of three friends found: "
                        << people[i].name << ", " << people[j].name << ", " << people[k].name << endl;
                }

                // Четвертий цикл для перевірки комбінацій з чотирма людьми
                for (int l = k + 1; l < 21; l++) {
                    // Перевіряємо, чи ці чотири людини є частиною тісного кола
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

    // TASK 6.4: Виводимо таблицю відвідувань для кожної людини
    for (const Person& person : people) {
        person.printVisits(); // Виводимо список відвідувань для кожної людини
    }

    return 0;
}

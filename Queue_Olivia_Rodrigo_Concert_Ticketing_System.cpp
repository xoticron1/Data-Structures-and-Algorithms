#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <atomic>

using namespace std;

class Person {
public:
    string name;
    int ticket_number;

    Person(string person_name, int ticket)
        : name(person_name), ticket_number(ticket) {}
};

class Queue {
private:
    queue<Person> q;
    int next_ticket_number = 1;
    mutex mtx;

public:
    void Enqueue(const string& person_name) {
        lock_guard<mutex> lock(mtx);
        Person new_person(person_name, next_ticket_number);
        q.push(new_person);
        cout << person_name << " added to the queue with Ticket #" << next_ticket_number << endl;
        next_ticket_number++;
        cout << "Queue size: " << q.size() << endl;
    }

    void AutoDequeue() {
        lock_guard<mutex> lock(mtx);
        if (!q.empty()) {
            Person next_person = q.front();
            q.pop();
            cout << next_person.name << " received their ticket (Ticket #" << next_person.ticket_number << ")" << endl;
        } else {
            cout << "No one is in the queue." << endl;
        }
    }

    int Position(const string& person_name) {
        lock_guard<mutex> lock(mtx);
        int position = 1;
        queue<Person> temp = q;

        while (!temp.empty()) {
            Person current_person = temp.front();
            temp.pop();
            if (current_person.name == person_name) {
                return position;
            }
            position++;
        }
        return -1;
    }

    bool IsEmpty() {
        lock_guard<mutex> lock(mtx);
        return q.empty();
    }

    int Size() {
        lock_guard<mutex> lock(mtx);
        return q.size();
    }
};

void displayMenu() {
    cout << "\nWelcome to Olivia Rodrigo's Concert Ticketing System!" << endl;
    cout << "1. Enqueue a person" << endl;
    cout << "2. Check your position in the queue" << endl;
    cout << "3. Exit" << endl;
}

int getOption() {
    int option;
    while (true) {
        cout << "Choose an option: ";
        if (cin >> option) {
            return option;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    Queue concert_queue;
    atomic<bool> running(true);
    int option;
    string name;
    int input_count = 0;

    while (running) {
        displayMenu();
        option = getOption();

        switch (option) {
        case 1:
            cout << "Enter the name: ";
            cin.ignore(); 
            getline(cin, name);
            concert_queue.Enqueue(name);
            input_count++;
            break;

        case 2:
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            int position;
            position = concert_queue.Position(name);
            if (position == -1) {
                cout << name << " is not in the queue." << endl;
            } else {
                cout << name << " is at position " << position << " in the queue." << endl;
            }
            input_count++;
            break;

        case 3:
            cout << "Exiting system. Goodbye!" << endl;
            running = false;
            break;

        default:
            cout << "Invalid option, please choose again." << endl;
        }

        if (input_count == 3) {
            cout << "\nAuto dequeue processing...\n" << endl;
            concert_queue.AutoDequeue();
            input_count = 0; // Reset the counter
        }
    }
    return 0;
}
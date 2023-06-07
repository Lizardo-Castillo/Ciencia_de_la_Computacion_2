#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer {
public:
    virtual void update(int value) = 0;
};

class Subject {
private:
    int value;
    vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // Buscar y eliminar el observador de la lista
        vector<Observer*>::iterator it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void setValue(int newValue) {
        value = newValue;
        notify();
    }

    int getValue() {
        return value;
    }

    void notify() {
	    for (vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
	        Observer* observer = *it;
	        observer->update(value);
	    }
	}

};

class ConcreteObserver : public Observer {
public:
    void update(int value) {
        cout << "Valor actualizado: " << value << endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1, observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setValue(42);  // Notificará a los observadores

    subject.detach(&observer2);

    subject.setValue(99);  // Solo observer1 recibirá la notificación

    return 0;
}

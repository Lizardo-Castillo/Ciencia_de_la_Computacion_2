#include <iostream>
#include <string>

class Servant {
public:
    void doTaskA() {
        std::cout << "Servant realizando tarea A." << std::endl;
    }

    void doTaskB() {
        std::cout << "Servant realizando tarea B." << std::endl;
    }
};

class Client {
private:
    Servant* servant;

public:
    Client(Servant* servant) : servant(servant) {}

    void delegateTaskA() {
        servant->doTaskA();
    }

    void delegateTaskB() {
        servant->doTaskB();
    }
};

int main() {
    Servant servant;
    Client client(&servant);

    client.delegateTaskA();  // Delegar la tarea A al servant
    client.delegateTaskB();  // Delegar la tarea B al servant

    return 0;
}

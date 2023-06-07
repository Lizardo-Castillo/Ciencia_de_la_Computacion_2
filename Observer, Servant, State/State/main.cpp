#include <iostream>
#include <string>

class Context;

class State {
public:
    virtual void handle(Context* context) = 0;
};

class ConcreteStateB; // Declaración previa de la clase ConcreteStateB

class ConcreteStateA : public State {
public:
    void handle(Context* context);
};

class ConcreteStateB : public State {
public:
    void handle(Context* context);
};

class Context {
private:
    State* state;

public:
    Context(State* initialState) : state(initialState) {}

    void setState(State* newState) {
        state = newState;
    }

    void request() {
        state->handle(this);
    }
};

void ConcreteStateA::handle(Context* context) {
    std::cout << "Manejando la solicitud en el Estado A." << std::endl;
    // Cambiar al siguiente estado
    context->setState(new ConcreteStateB());
}

void ConcreteStateB::handle(Context* context) {
    std::cout << "Manejando la solicitud en el Estado B." << std::endl;
    // Cambiar al estado anterior
    context->setState(new ConcreteStateA());
}

int main() {
    Context context(new ConcreteStateA());

    context.request();  // Manejar la solicitud en el Estado A
    context.request();  // Manejar la solicitud en el Estado B
    context.request();  // Manejar la solicitud en el Estado A

    return 0;
}

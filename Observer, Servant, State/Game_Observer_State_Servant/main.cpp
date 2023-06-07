#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Observer Pattern

class Observer {
public:
    virtual void update() = 0;
};

class Player : public Observer {
private:
    std::string name;

public:
    Player(std::string playerName) : name(playerName) {}

    void update() override {
        std::cout << name << ": ¡Ha ocurrido un evento en el juego!" << std::endl;
    }
};

class Game {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // Buscar y eliminar el observador de la lista
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() {
        for (auto observer : observers) {
            observer->update();
        }
    }

    void play() {
        // Simular el juego y generar un evento
        std::cout << "¡El juego ha empezado!" << std::endl;
        notify();
        std::cout << "¡El juego ha terminado!" << std::endl;
    }
};

// Servant Pattern

class Servant {
public:
    virtual void execute() = 0;
};

class SimpleServant : public Servant {
public:
    void execute() override {
        std::cout << "Servant Simple: Realizando una tarea simple." << std::endl;
    }
};

class ComplexServant : public Servant {
public:
    void execute() override {
        std::cout << "Servant Complejo: Realizando una tarea compleja." << std::endl;
    }
};

// State Pattern

class GameState {
public:
    virtual void handle(class Context* context) = 0;
};

class StartState : public GameState {
public:
    void handle(class Context* context) override;
};

class PlayingState : public GameState {
public:
    void handle(class Context* context) override;
};

class EndState : public GameState {
public:
    void handle(class Context* context) override;
};

class Context {
private:
    GameState* state;
    Game* game;

public:
    Context(Game* game) : state(new StartState()), game(game) {}

    void setState(GameState* newState) {
        delete state;
        state = newState;
    }

    void handleRequest() {
        state->handle(this);
    }

    Game* getGame() const {
        return game;
    }
};

void StartState::handle(Context* context) {
    std::cout << "Estado de Inicio: Preparando el juego." << std::endl;
    context->setState(new PlayingState());
}

void PlayingState::handle(Context* context) {
    std::cout << "Estado de Juego: Jugando." << std::endl;
    context->setState(new EndState());
}

void EndState::handle(Context* context) {
    std::cout << "Estado de Fin: Finalizando el juego." << std::endl;
    context->setState(nullptr);
}

int main() {
    // Crear objetos y establecer relaciones

    Game game;
    Player player1("Jugador 1");
    Player player2("Jugador 2");
    game.attach(&player1);
    game.attach(&player2);

    SimpleServant simpleServant;
    ComplexServant complexServant;

    Context context(&game);

    // Ejecutar el juego con diferentes configuraciones de State y Servant

    std::cout << "Configuracion 1: SimpleServant y StartState" << std::endl;
    context.handleRequest();
    simpleServant.execute();

    std::cout << "\nConfiguracion 2: ComplexServant y PlayingState" << std::endl;
    context.handleRequest();
    complexServant.execute();

    std::cout << "\nConfiguracion 3: SimpleServant y EndState" << std::endl;
    context.handleRequest();
    simpleServant.execute();

    // Desvincular jugadores

    game.detach(&player1);
    game.detach(&player2);

    return 0;
}

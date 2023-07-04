#include <SFML/Graphics.hpp>

int main()
{
    //<>
    // Crea una instancia de sf::RenderWindow
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Bomberman Juego");

    // Crear una textura y cargar la imagen de Fondo
    sf::Texture texture;
    texture.loadFromFile("AudioVisual/Imagenes/Juego/Superior.png");
    // Crear un sprite y asignar la imagen de Fondo
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Crear una textura y cargar la imagen del Mapa
    sf::Texture mapa;
    mapa.loadFromFile("AudioVisual/Imagenes/Juego/Mapa.png");
    // Crear un sprite y asignar la imagen del Mapa
    sf::Sprite mapa_sprite;
    mapa_sprite.setTexture(mapa);
    //Posicion Inicial
    mapa_sprite.setPosition(0, 128);
    //Cambiar el tamaño de la imagen
    mapa_sprite.setScale(4.41f, 3.71f);

    //Para calcular cada pixel
    sf::RectangleShape square_bloque;
    square_bloque.setSize(sf::Vector2f(70.0f, 60.0f));
    square_bloque.setFillColor(sf::Color::Red);

    //Crear una textura y cargar la imagen del Jugador
    sf::Texture player;
    player.loadFromFile("AudioVisual/Imagenes/Juego/Jugador.png");
    //Crear un sprite y asignar la imagen del Jugador
    sf::Sprite player_sprite;
    player_sprite.setTexture(player);
    //Cambiar el tamaño de la imagen;
    player_sprite.setPosition(140.0f, 156.0f);
    player_sprite.setTextureRect(sf::IntRect(71.0f, 26.0f, 16.0f, 24.0f));
    player_sprite.setScale(4.5f, 3.8f);

    //Crear una textura y cargar la imagen del Jugador
    sf::Texture prueba;
    prueba.loadFromFile("AudioVisual/Imagenes/Juego/Mapa_Prueba.png");
    //Crear un sprite y asignar la imagen del Jugador
    sf::Sprite prueba_sprite;
    prueba_sprite.setTexture(prueba);
    // Bucle principal
    while (window.isOpen())
    {
        // Procesa los eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player_sprite.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            int xTexture = 0;

            player_sprite.move(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player_sprite.move(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player_sprite.move(1, 0);
        }

        // Lógica del juego

        // Renderizado
        window.clear(); // Limpia la ventana

        // Aquí puedes agregar tu código de renderizado, dibujando en la ventana
        // Dibuja el sprite de la imagen de fondo
        window.draw(sprite);
        // Dibuja el sprite de la imagen del mapa
        window.draw(mapa_sprite);

        // Dibujar el cuadrado en cada píxel de la ventana
        for (int i = 0; i < window.getSize().x; i++)
        {

            for (int j = 0; j < window.getSize().y; j++)
            {
                if (i % 141 == 0 && j % 119 == 0 && i < 846 && j < 564) {
                    square_bloque.setPosition(212 + i, 246 + j);
                    window.draw(square_bloque);
                }
            }
        }
        //window.draw(prueba_sprite);
        window.draw(player_sprite);
        window.display(); // Muestra los cambios en pantalla
    }

    return 0;
}
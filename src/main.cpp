#include <iostream>
#include <SFML/Audio.hpp>
#include "game.h"
#include "sprite.h"
#include "text.h"
#include "score.h"

int main()
{    
    // Window Info
    const char* WINDOW_NAME = "Highway Henry";
    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 900;

    // Texture File Names
    const char* TITLE_SCREEN_TEXTURE_FILE = "../sprites/title-screen2.png";
    const char* ROAD_TEXTURE_FILE         = "../sprites/road2.png";
    const char* CAR_TEXTURE_FILE          = "../sprites/car2.png";
    const char* ROAD_BLOCK_TEXTURE_FILE       = "../sprites/roadblock.png";
    
    // Road Info
    const float LANE_1 = 175.0f;
    const float LANE_2 = 325.0f;
    const int NUM_LANES = 2;

    const float ROAD_TOP_POS = -4.95f;
    const float ROAD_BOTTOM_POS = -723.187f;
    
    float road_pos = ROAD_BOTTOM_POS;
    
    // Car Info
    const int CAR_WIDTH = 32;
    const int CAR_HEIGHT = 32;
    int CAR_FRAME = 0;
    const float CAR_SCALE = 6.0f;
    const float CAR_Y = 650.0f;
    const float CAR_X_OFFSET = -50.0f;
    
    // ROAD_BLOCK Info
    const int ROAD_BLOCK_WIDTH = 32;
    const int ROAD_BLOCK_HEIGHT = 16;
    const float ROAD_BLOCK_SCALE = 3.0f;
    const float INIT_ROAD_BLOCK_Y = -2000.0f;
    const float NORM_ROAD_BLOCK_Y = -1000.0f;

    // Initialise Text
    const int TITLE_TEXT_SIZE = 75;
    const int TITLE_TEXT_X_OFFSET = 100;
    const int TITLE_TEXT_Y_OFFSET = 200;

    const int BODY_TEXT_SIZE = 30;
    const int BODY_TEXT_X_OFFSET = 50;
    const int BODY_TEXT_Y_OFFSET = 350;

    const char* INIT_SCORE_TEXT = "Score: 0";
    const int SCORE_COUNT_SIZE = 50;
    const int SCORE_TEXT_X_OFFSET = 10;
    const int SCORE_TEXT_Y_OFFSET = 10;

    const char* GAME_OVER_TEXT = "GAME OVER";
    const char* DEATH_TEXT = "[SPACE] to play again.\n"         \
                             "[Y] to go to the main menu.\n"    \
                             "[ESC] to quit the game.";

    // Audio
    const float MUSIC_VOL = 25.0f;

    // Window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);

    // Create Title Screen
    Sprite title_screen(TITLE_SCREEN_TEXTURE_FILE);

    // Create Text Objects
    Score score_count(INIT_SCORE_TEXT, SCORE_COUNT_SIZE);
    Text game_over_text(GAME_OVER_TEXT, TITLE_TEXT_SIZE, TITLE_TEXT_X_OFFSET, TITLE_TEXT_Y_OFFSET);
    Text death_text(DEATH_TEXT, BODY_TEXT_SIZE, BODY_TEXT_X_OFFSET, BODY_TEXT_Y_OFFSET);
    
    // 1st Implentation Road
    sf::Texture road_texture;
    if (!road_texture.loadFromFile(ROAD_TEXTURE_FILE))
        std::cout << "ERROR: Unable to load road texture!\n";

    sf::Vector2u road_size;
    road_size = road_texture.getSize();

    float x_scale = (float) WINDOW_WIDTH / road_size.x;
    float y_scale = (float) WINDOW_HEIGHT / road_size.y;
    
    sf::Sprite road_sprite;
    road_sprite.setTexture(road_texture);
    road_sprite.setScale(x_scale, 2 * y_scale);


    // 2nd Implementation
    Sprite road(ROAD_TEXTURE_FILE);
    sf::Vector2u road_texture_size = road.getTextureSize();
    const float ROAD_X_SCALE = 1.0f;
    const float ROAD_Y_SCALE = 2.0f;
    road.setScale(ROAD_X_SCALE, 2 * ROAD_Y_SCALE);

    // Car
    Sprite car(CAR_TEXTURE_FILE);
    car.setWidth(CAR_WIDTH);
    car.setHeight(CAR_HEIGHT);
    car.setFrame(CAR_FRAME);
    car.setImg();
    car.setScale(CAR_SCALE, CAR_SCALE);
    car.setPos(LANE_1 + CAR_X_OFFSET, CAR_Y);

    // ROAD_BLOCK
    Sprite road_block(ROAD_BLOCK_TEXTURE_FILE);
    road_block.setWidth(ROAD_BLOCK_WIDTH);
    road_block.setHeight(ROAD_BLOCK_HEIGHT);
    road_block.setImg();
    road_block.setScale(ROAD_BLOCK_SCALE, ROAD_BLOCK_SCALE);
    road_block.setPos(LANE_1, INIT_ROAD_BLOCK_Y);

    // Clock and Random Number Generator
    sf::Clock clock;
    srand((unsigned) time(NULL));
    
    // Audio
    sf::SoundBuffer coin_sfx;

    if (!coin_sfx.loadFromFile("../audio/sfx/coin.WAV")) {
        std::cout << "Error: Unable to load coin sfx file.\n";
    }

    sf::Sound coin_speaker;

    coin_speaker.setBuffer(coin_sfx);
    coin_speaker.setVolume(50.0f);

    sf::SoundBuffer explosion_sfx;

    if (!explosion_sfx.loadFromFile("../audio/sfx/explosion.WAV")) {
        std::cout << "Error: Unable to load explosion sfx file.\n";
    }

    sf::Sound explosion_speaker;
    explosion_speaker.setVolume(30.0f);

    explosion_speaker.setBuffer(explosion_sfx);

    sf::Music start_music;

    if (!start_music.openFromFile("../audio/music/start.ogg")) {
        std::cout << "Error: Unable to open start music file.\n";
    }

    start_music.setVolume(MUSIC_VOL);
    start_music.setLoop(true);

    sf::Music game_music;
    
    if (!game_music.openFromFile("../audio/music/game.ogg")) {
        std::cout << "Error: Unable to open game music file.\n";
    }

    game_music.setVolume(MUSIC_VOL);
    game_music.setLoop(true);

    sf::Music end_music;

    if (!end_music.openFromFile("../audio/music/end.ogg")) {
        std::cout << "Error: Unable to open end music file.\n";
    }

    end_music.setVolume(MUSIC_VOL);
    end_music.setLoop(true);

    start_music.play();

    Game game;

    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space && !game.isPlaying()) {
                    road_pos = ROAD_BOTTOM_POS;
                    road_block.setY(INIT_ROAD_BLOCK_Y);
                    game.setGameOver(false);
                    game.setPlaying(true);
                    start_music.stop();
                    end_music.stop();
                    coin_speaker.play();
                    game_music.play();
                }

                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::D) {
                    game.toggleDebugeMode();
                    std::cout << "Debug Mode: " << game.getDebugStatus() << "\n";
                }

                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                    
                break;
            }
        }

        if (game.isPlaying())
        {    
            game.update();

            // Move Road
            road_sprite.setPosition(0.0f, road_pos);
            road_pos += game.getVel();
            
            // Reset Road Position
            if (road_pos > ROAD_TOP_POS) road_pos = ROAD_BOTTOM_POS;
            
            // Car Movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                car.setPos(LANE_1 + CAR_X_OFFSET, CAR_Y);

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                car.setPos(LANE_2 + CAR_X_OFFSET, CAR_Y);

            // Create Hitbox for Car
            sf::FloatRect car_hitbox = car.sprite.getGlobalBounds();
            
            // Move road_block
            road_block.updatePos();
            road_block.addY(game.getVel());

            // Reset road_block Position
            if (road_block.getY() > 1000.0f)
            {
                coin_speaker.play();
                game.incrementScore();
                score_count.setScore(game.getScore());

                game.accelerate();

                // Set the road_block to spawn in a random lane.
                int random_lane = rand() % NUM_LANES;
                int new_lane = (random_lane == 0) ? LANE_1: LANE_2;
                road_block.setX(new_lane);
                road_block.setY(NORM_ROAD_BLOCK_Y);
            }
            
            // Create road_block Hitbox
            sf::FloatRect road_block_hitbox = road_block.sprite.getGlobalBounds();
        
            // Game Over
            if (car_hitbox.intersects(road_block_hitbox))
            {
                explosion_speaker.play();
                game.gameOver();
                score_count.resetScore();

                
                game_music.stop();
                end_music.play();
            }
        }

        if (game.isGameOver() && sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            game.setGameOver(false);
            end_music.stop();
            start_music.play();
        }
                

        window.clear();
        
        // Display Main Menu Screen
        if (!(game.isPlaying() || game.isGameOver()))
            window.draw(title_screen.sprite);

        // Display Game
        if (game.isPlaying() || game.isGameOver())
        {
            window.draw(road_sprite);
            window.draw(car.sprite);
            window.draw(road_block.sprite);
            window.draw(score_count.display);
        }
        
        // Display Game Over Screen
        if (game.isGameOver()) {
            window.draw(game_over_text.display);
            window.draw(death_text.display);
        }

        window.display();
    }

    return 0;
}

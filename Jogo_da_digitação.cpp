#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;


struct Pincel {
  Font fonte;
  Text texto;
  RenderWindow& window;
  Pincel(RenderWindow& window) : window(window) {
    fonte.loadFromFile("Roboto-Black.ttf");
    texto.setFont(fonte);
  }
  void write(std::string str, int x, int y, int size, Color cor) {
    texto.setString(str);
    texto.setCharacterSize(size);
    texto.setFillColor(cor);
    texto.setPosition(x, y);
    window.draw(texto);
  }
};
struct Bubble {
 static const int radius { 10 };
  int x;
  int y;
  char letter;
  int speed;
  bool alive { true };
  Bubble(int x, int y, char letter, int speed) : x(x), y(y), letter(letter), speed(speed){
  }
  void update() {
  this->y += this->speed;
  }
  void draw(RenderWindow& window) {
    CircleShape bubble(Bubble::radius);
    bubble.setPosition(this->x, this->y);
    bubble.setFillColor(Color::White);
    window.draw(bubble);
    static Pincel pincel(window);
    pincel.write(std::string(1,letter), x + 0.2 * Bubble::radius,y, Bubble::radius * 1.5, Color::Blue);
  }
};
struct Board{
  RenderWindow& window;
  std::vector <Bubble> bubbles;
  Pincel pincel;
  int hits { 0 };
  int misses { 0 };

  Board(RenderWindow& window) : window(window), pincel(window) {
    bubbles.push_back(Bubble(100, 100, 'A', 1));
    bubbles.push_back(Bubble(200, 100, 'B', 2));
    bubbles.push_back(Bubble(300, 100, 'C', 3));
  }
  void update() {
    if(this->check_new_bubble()) {
      this->add_new_bubble();
    }
    for(auto& bubble : bubbles) {
      bubble.update();
    }
    this->mark_outside_bubbles();
    this->remove_dead_bubbles();
  }
 void remove_dead_bubbles() {
   std::vector <Bubble>vivas;
    for(auto& bubble : bubbles) {
      if(bubble.alive) {
        vivas.push_back(bubble);
      }
    }
    this->bubbles = vivas;
  }
  bool check_new_bubble() {
 static int new_bubble_timeout { 30 };
  static int new_bubble_timer { 0 };
    new_bubble_timer--;
    if(new_bubble_timer <= 0 ) {
      new_bubble_timer = new_bubble_timeout;
      return true;
    }
    return false;
  }
  void mark_outside_bubbles() {
    for(auto& bubble : bubbles) {
      if(bubble.y + 2 * Bubble::radius > (int)  this->window.getSize().y) {
        if(bubble.alive) {
        bubble.alive = false;
        this->misses++;
        }
        
      }
    }
  }
  void mark_by_hit(char letter) {
    for(auto& bubble : bubbles) {
      if(bubble.letter == letter && bubble.alive) {
        bubble.alive = false;
        this->hits++;
        break;
      }
    }
  }
void add_new_bubble() {
  int x = rand() % ((int) this->window.getSize().x - 2 * Bubble::radius);
  int y = - 2 * Bubble::radius;
  int speed = rand() % 5 + 1;
  char letter = 'A' + rand() % 26;
  bubbles.push_back(Bubble(x, y, letter, speed));
}
  void draw() {
      pincel.write("Hits: " + std::to_string(hits) + " Misses: " + std::to_string(misses), 10, 10, 20, Color::White);
      pincel.write("Size: " + std::to_string(this->bubbles.size()), 10, 30, 20, Color::White);
    for(auto& bubble : bubbles) {
      bubble.draw(window);
    }
  }
};
struct Game {
  RenderWindow window;
  Board board;
  Game () : window(VideoMode(800, 600), "Jogo da digitação"), board(window) {
    window.setFramerateLimit(60);
  } 
  void process_events() {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }else if(event.type == Event :: TextEntered) {
       char code = static_cast<char>(event.text.unicode);
       code = toupper(code);
        board.mark_by_hit(code);
      }
    }
  }
  void draw() {
    board.update();
    window.clear(Color::Black);
    board.draw();
    window.display();
  }
  void main_loop() {
    while (window.isOpen()) {
      process_events();
      draw();
    }
  }
};

int main() {
Game game;
game.main_loop();
return 0;
}
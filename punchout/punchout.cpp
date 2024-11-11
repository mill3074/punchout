#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
using namespace sfp;

//stuff, dont worry about this

void LoadTex(Texture& tex, string filename) {
    if (!tex.loadFromFile(filename)) {
        cout << "Could not load " << filename << endl;
    }
}

void Dodge(PhysicsSprite& crossbow, int elapsedMS) {
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        Vector2f newPos(crossbow.getCenter());
        newPos.x = newPos.x + (KB_SPEED * elapsedMS);
        crossbow.setCenter(newPos);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        Vector2f newPos(crossbow.getCenter());
        newPos.x = newPos.x - (KB_SPEED * elapsedMS);
        crossbow.setCenter(newPos);
    }
}

Vector2f GetTextSize(Text text) {
    FloatRect r = text.getGlobalBounds();
    return Vector2f(r.width, r.height);
}

//stuff, dont worry about this ^^

int main() 
{
    RenderWindow window(VideoMode(1000, 1000), "PunchOut!");
    World world(Vector2f(0, 0));
    int score(0);
    int arrows(1);

    PhysicsSprite& Player = *new PhysicsSprite();
    Texture playTex;
    LoadTex(playTex, "images/STAND.png");
    crossBow.setTexture(cbowTex);
    Vector2f sz = crossBow.getSize();
    crossBow.setCenter(Vector2f(400,
        600 - (sz.y / 2)));


}




//nothing

//while OPPONENT HP > 0 {
    //pick number 1-4 (these will determine what attack to use)
    //IF attack == 1 {
        //code for attack...
        
    //IF attack == 2 {
        //code for attack...
        
    //IF attack == 3 {
        //code for attack...
        
    //IF attack == 4 {
        //code for attack...
    //wait a random interval of time...
    //loop back to top.


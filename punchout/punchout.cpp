#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
using namespace sfp;

const float KB_SPEED = 2;

//stuff, dont worry about this

void LoadTex(Texture& tex, string filename) {
    if (!tex.loadFromFile(filename)) {
        cout << "Could not load " << filename << endl;
    }
}

//void Dodge(PhysicsSprite& Player, int elapsedMS) {
//    if (Keyboard::isKeyPressed(Keyboard::Right)) {
//        Vector2f newPos(Player.getCenter());
//        newPos.x = newPos.x + (KB_SPEED * elapsedMS);
//        Player.setCenter(newPos);
//    }
//    if (Keyboard::isKeyPressed(Keyboard::Left)) {
//        Vector2f newPos(Player.getCenter());
//        newPos.x = newPos.x - (KB_SPEED * elapsedMS);
//        Player.setCenter(newPos);
    //}
//}

//testing note.

Vector2f GetTextSize(Text text) {
    FloatRect r = text.getGlobalBounds();
    return Vector2f(r.width, r.height);
}

//stuff, dont worry about this ^^

int main() 
{
    RenderWindow window(VideoMode(1000, 1000), "PunchOut!");
    World world(Vector2f(0, 0));
    int enemyHP(10);
    int playerHP(3);

    PhysicsSprite& background = *new PhysicsSprite();  
    Texture bgTex;
    LoadTex(bgTex, "images/ring.png");
    background.setTexture(bgTex);
    background.setCenter(Vector2f(500,500));

    PhysicsSprite& Enemy = *new PhysicsSprite();
    Texture enemyTex;
    LoadTex(enemyTex, "images/enemy.png");
    Enemy.setTexture(enemyTex);
    Vector2f szEnemy = Enemy.getSize();
    Enemy.setCenter(Vector2f(500,600));

    PhysicsSprite& Player = *new PhysicsSprite();
    Texture playTex;
    LoadTex(playTex, "images/STAND.png");
    Player.setTexture(playTex);
    Vector2f sz = Player.getSize();
    Player.setCenter(Vector2f(500,900));

    //vvv i lwk dont need this but it was kinda in the grading so idk vvv

    PhysicsRectangle bottom;
    bottom.setSize(Vector2f(1000, 10));
    bottom.setCenter(Vector2f(500, 1000));
    bottom.setStatic(true);
    world.AddPhysicsBody(bottom);

    PhysicsRectangle left;
    left.setSize(Vector2f(10, 1000));
    left.setCenter(Vector2f(5, 500));
    left.setStatic(true);
    world.AddPhysicsBody(left);

    PhysicsRectangle right;
    right.setSize(Vector2f(10, 1000));
    right.setCenter(Vector2f(995, 500));
    right.setStatic(true);
    world.AddPhysicsBody(right);

    Font fnt;
    if (!fnt.loadFromFile("arial.ttf")) {
        cout << "Could not load font." << endl;
        exit(3);
    }


    // dis is where shit get real 
    Clock clock;
    Time lastTime(clock.getElapsedTime());
    Time currentTime(lastTime);

    //gameplay vvvv
    long moveMS(0);
    while(enemyHP > 0 && playerHP > 0) {

        currentTime = clock.getElapsedTime();
        Time deltaTime = currentTime - lastTime;
        long deltaMS = deltaTime.asMilliseconds();
        if (deltaMS > 9) {
            moveMS = moveMS + deltaMS;
            lastTime = currentTime;
            world.UpdatePhysics(deltaMS);
            MoveCrossbow(crossBow, deltaMS);
        //potential bug, if knocked out, everything will undraw.
        window.draw(background);
        window.draw(Enemy);
        window.draw(Player);
        Text hpText;
        hpText.setString(to_string(enemyHP));
        hpText.setFont(fnt);
        window.draw(hpText);
        Text arrowCountText;
       

        window.display();

        //Player.setCenter(Vector2f(500, 900 - (sz.y / 2))); (potentially need to remove)

        //use a timer, slide them across for a certain amount of time. 

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (moveMS > 1000) { 
                moveMS = 0;
                //while statement using MS < 1000
                //swap img to a dodging frame 
                //change position by a set velocity
                //end while statement
                //set back to center (like below) 
                //(duplicate below if this works)
                //potential bug: will it take other inputs during this? what happens if i hold down right?
            cout << "right" << endl;
            Player.setCenter(Vector2f(500, 900));
            //if this idea bombs, just copy bottom part up. PUNCH_R.png, x is 600
         }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            Player.setCenter(Vector2f(400, 900 - (sz.y / 2)));
            LoadTex(playTex, "images/PUNCH_L.png");
            Player.setTexture(playTex);
            cout << "left" << endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            //same as above, but the time window should be much much smaller.
            //also have them go forwards instead of to the side.
            cout << "Punch" << endl;
        }

        //my next big concern is hitboxes. before he attacks, he needs to take damage.
        //most likely will include invisible shapes for collision with the fighter.
        //same for hitting the enemy.
        //alternative idea is that they are assigned a number based on what position/action they are in.
        //if the numbers are equal, any damage taken goes through, if not, it counts as a miss?

    }


}




//nothing

//MOVEMENT
//instead of dodging, there could be three zones, kept track of by a score? and if you are in a zone equal to 
//an attacks zone indicator, you take damage?

//ENEMY ATTACKS
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

//KNOCKED OUT
//if playerHP == 0 {
    //knockoutScore ++
    //fall off screen
    // revive = 100 * knockoutScore
    // when player presses w a s d, add reviveCount +1
    //  if revive count == revive {
    //  continue playing?
    //  if revive count <= revive {
    //  game over tally
    //
//(player will have 10 seconds to mash WASD for an amount of times equal to some sort of exponential equation with knockoutScore)
//could do something similar with enemy, instead of WASD mashing, could be a random chance that diminishes as his knockoutScore increases. first knockout guaranteed to come back.

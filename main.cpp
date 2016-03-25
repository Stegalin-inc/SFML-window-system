#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include "include/button.h"
#include "include/win.h"

void loadFont();
int wincorx=20, wincory=20, winwt=400, winht=255, bposx, bposy, bcorx, bcory, bwt, bht;
bool moved=false, resized=false;

int main()
{

    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    Button testButton;
    testButton.newButton(80,30,700/2,550/2);
    testButton.setLabel("X","times.ttf");

    Win testWin;
    testWin.initWin(wincorx,wincory,winwt,winht);
    testWin.setColor(200, 200, 0, 200);





    sf::Image splashimage;

	splashimage.loadFromFile("images/splash.png");

	sf::Texture splashtexture;

	splashtexture.loadFromImage(splashimage);

	sf::Sprite splashsprite;

	splashsprite.setTexture(splashtexture);






    while (app.isOpen())
    {

        sf::Event event;
        while (app.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                app.close();
        }

        sf::Vector2i pixelPos = sf::Mouse::getPosition(app);
        sf::Vector2f pos = app.mapPixelToCoords(pixelPos);

        if ((testButton.isCursor(pos.x,pos.y)) && /*(sf::Mouse::isButtonPressed(sf::Mouse::Left))*/ (event.type == sf::Event::MouseButtonReleased) )
        break;




        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bposy=pos.y;
        bposx=pos.x;
  wincorx = bcorx; wincory = bcory;
 // winwt = bwt; winht = bht;

        }

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        }


        if ((testWin.isMove(pos.x,pos.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
        moved=true;

        }

        if ((testWin.isResize(pos.x,pos.y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
        resized=true;

        }

        if(moved) {
        testWin.initWin(wincorx+(pos.x-bposx),wincory+(pos.y-bposy),winwt,winht);
        bcorx = wincorx+(pos.x-bposx); bcory = wincory+(pos.y-bposy);


        }

        if (event.type == sf::Event::MouseButtonReleased){
        moved=false;
        resized=false;
        wincorx = bcorx; wincory = bcory;
        winwt = bwt; winht = bht;
        }

        if (resized)
        {
         bwt = winwt+(pos.x-bposx); bht =  winht+(pos.y-bposy);
        testWin.initWin(wincorx,wincory,winwt+(pos.x-bposx),winht+(pos.y-bposy));

    }

    testButton.newButton(40,30,testWin.getPosx(testWin.getWinw()-50),testWin.getPosy(0));
    testButton.upPosText();


        app.clear(sf::Color(255,255,255));
        //app.draw(testWin.exit);
        app.draw(splashsprite);
        app.draw(testWin.title);
        app.draw(testWin.leftBorder);
        app.draw(testWin.rightBorder);
        app.draw(testWin.botBorder);
        app.draw(testWin.body);
        app.draw(testButton.button);
        app.draw(testButton.text);
        app.display();
    }

    return EXIT_SUCCESS;
}

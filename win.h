#ifndef WIN_H_INCLUDED
#define WIN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#endif // WIN_H_INCLUDED
#define TITLE_SIZE      30
#define BORDER_SIZE     5

class Win
{
    int winWeight, winHeight, titlePosX, titlePosY, leftBorderPosX, leftBorderPosY, vertBorderHeight, rightBorderPosX, rightBorderPosY, botBorderPosX, botBorderPosY, botBorderWeight;
    public:
    sf::RectangleShape title;
    sf::RectangleShape leftBorder;
    sf::RectangleShape rightBorder;
    sf::RectangleShape botBorder;

    void initWin (int posx, int posy, int wht, int hht)
    {

    titlePosX=posx;
    titlePosY=posy;
    winWeight=wht;
    winHeight=hht;
    leftBorderPosX=titlePosX;
    leftBorderPosY=titlePosY+TITLE_SIZE;
    vertBorderHeight=winHeight-TITLE_SIZE;
    rightBorderPosX=titlePosX+winWeight-BORDER_SIZE;
    rightBorderPosY=titlePosY+TITLE_SIZE;
    botBorderPosX=titlePosX;
    botBorderPosY=titlePosY+winHeight;
    botBorderWeight=winWeight;

    title.setSize(sf::Vector2f(winWeight, TITLE_SIZE));
    title.setPosition(titlePosX, titlePosY);
    leftBorder.setSize(sf::Vector2f(BORDER_SIZE, vertBorderHeight));
    leftBorder.setPosition(leftBorderPosX, leftBorderPosY);
    rightBorder.setSize(sf::Vector2f(BORDER_SIZE, vertBorderHeight));
    rightBorder.setPosition(rightBorderPosX, rightBorderPosY);
    botBorder.setSize(sf::Vector2f(botBorderWeight, BORDER_SIZE));
    botBorder.setPosition(botBorderPosX, botBorderPosY);

    //std::cout<<botBorderWeight<<"\n"<<botBorderPosX<<"\n"<<botBorderPosY<<"\n";

    title.setFillColor(sf::Color(0, 200, 0));
    leftBorder.setFillColor(sf::Color(0, 200, 0));
    rightBorder.setFillColor(sf::Color(0, 200, 0));
    botBorder.setFillColor(sf::Color(0, 200, 0));
    }

    bool isMove(float corx, float cory)
    {
        if ((corx>titlePosX) && (corx<winWeight+titlePosX) && (cory>titlePosY) && (cory<TITLE_SIZE+titlePosY))
        return true;
        else
        return false;
    }






};

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
 
using namespace sf;
using namespace std;
 
int main()
{
    VideoMode videoMode(320,240);
    RenderWindow window(videoMode,"Plus Or Minus");
 
    Font font;
    if (!font.loadFromFile("Xanadu.ttf"))
        return EXIT_FAILURE;     
 
    Text title("Plus Or Minus",font,20);
    title.setPosition(10,10);
    title.setColor(Color::Blue);
 
    Text question("What is your guess ?",font,20);
    question.setPosition(5,30);
    question.setColor(Color::White);
 
    Text enter("",font,20);
    enter.setPosition(5,50);
    enter.setColor(Color::Green);
    String textEntered;
    int numEntered=0;
 
    Text status("",font,16);
    status.setPosition(100,50);
    status.setColor(Color::Yellow);
    stringstream out("");
 
    Text won("You have discovered\n the secret number\n in less than 10 tries,\n well played !",font,20);
    won.setPosition(5,70);
    won.setColor(Color::Green);
 
    Text lost("You have failed to\n discover the secret\n number in less than\n 10 tries, better \nluck next time!",font,20);
    lost.setPosition(5,70);
    lost.setColor(Color::Red);
 
    srand(static_cast<unsigned int> (time(NULL)));
 
    int secretNumber = rand() % 100;
 
    bool isGameOn=true;
    bool playerWon=false;
    int tryNumber=0;
 
    while (window.isOpen())
    {        
        window.clear();
        window.draw(title);
        if (isGameOn)
        {
            window.draw(question);
            window.draw(enter);
            window.draw(status);
        }
        else
        {
            if (playerWon)
                window.draw(won);
            else
                window.draw(lost);                    
        }
 
        window.display();
 
        Event event;
        while (window.pollEvent(event))
        {
            if ( (event.type == Event::Closed) ||
                ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
                window.close();            
 
            if (event.type == Event::TextEntered)
            {
                char c=static_cast<char> (event.text.unicode);
                if (c >= '0' && c <= '9' )
                {
                    textEntered += event.text.unicode;
                    enter.setString (textEntered); //update the enter Text
                }
                else if (c == '\r') //'\b' to handle backspace
                {
                    tryNumber++;
 
                    stringstream in(enter.getString());
                    in >> numEntered; //just get str as an int                    
 
 
                    if (numEntered>secretNumber)
                    {                        
                        out << tryNumber;
                        out << ". ";
                        out << numEntered;
                        out <<": Minus" << endl;                        
                        status.setString(out.str());
                    }
                    if (numEntered<secretNumber)
                    {        
                        out << tryNumber;
                        out << ". ";
                        out << numEntered;
                        out <<": Plus" << endl;            
                        status.setString(out.str()); 
                    }
                     
                    if (numEntered==secretNumber)
                    {
                        playerWon=true;        
                        status.setString("");
                        isGameOn=false;
                    }
                    if (tryNumber>10)
                    {
                        playerWon=false;
                        status.setString("");
                        isGameOn=false;
                    }
                    textEntered =""; //reset textEntered
                }
            }
        }
 
    }
    return EXIT_SUCCESS;
}

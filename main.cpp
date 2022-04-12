#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <stdio.h>

#define NUMS_SIZE 250 
#define HEIGHT 600 
#define WIDTH 1500
#define MAX_NUMBER HEIGHT

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int nums[], std::vector<sf::RectangleShape> &rects)
{
  	
	for (int j = 0; j < NUMS_SIZE; j++)
        	if (nums[j] > nums[j+1]){
			swap(&nums[j], &nums[j+1]);		
		}		
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");
    window.setFramerateLimit(30);

    int nums[NUMS_SIZE];
    std::vector<sf::RectangleShape> rects;
   	
   	
    srand(time(NULL));
    int c = 0;
    
    for (int i = 0; i < NUMS_SIZE; ++i) {
    	nums[i] = (rand() % (MAX_NUMBER)) + 1;
    	
	sf::RectangleShape rectangle;
	
	rectangle.setSize(sf::Vector2f(5, nums[i]));
	rectangle.setPosition(c, HEIGHT);
	rectangle.rotate(180);
	rects.push_back(rectangle);
	
	c+=6;
    }
    
    c = 0;
    int green = 0;    
    while (window.isOpen())
    {
        sf::Event event;
	
	while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
	for (int i = 0; i < NUMS_SIZE; ++i) {
		window.draw(rects[i]);
	}
	
        window.display();
	
	// I know below is kinda garbage can. Variable c is used to prevent calling
	// the bubbleSort function more than NUM_SIZE so variable c keeps track of how many
	// times the bubbleSort function called.
  	
	if (c++ < NUMS_SIZE){
		bubbleSort(nums, rects);
    		for (int i = 0; i < NUMS_SIZE; ++i)
			rects[i].setSize(sf::Vector2f(5, nums[i]));
    	} else {
		if (green++ < NUMS_SIZE) {	
			rects[green].setFillColor(sf::Color::Green);
			window.setFramerateLimit(120);
		} else {
			window.close();
		}
	}

    }

    return 0;
}

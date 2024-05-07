#include "Engine.h"
#include <iostream>



using namespace sf;
using namespace std;

Engine::Engine()
{
	int pixelWidth = VideoMode::getDesktopMode().width / 2;
	int pixelHeight = VideoMode::getDesktopMode().height / 2;
	VideoMode vm(pixelWidth, pixelHeight);
	m_Window.create(vm, "Particles", Style::Default);
	// Load a graphic into the texture
	//textureBackground.loadFromFile("rainbow.png");
	

	
	// Create a sprite

	// Attach the texture to the sprite
	//spriteBackground.setTexture(textureBackground);
	// Set the spriteBackground to cover the screen
	//spriteBackground.setPosition(0, 0);


}

void Engine::run()
{
	Clock clock;
	
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		
		Time dt = clock.restart();
		// Update the total game time
		//m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();
		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}

void Engine::input()
{
	int i = 0;
	
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            // Quit the game when the window is closed
            m_Window.close();
        }
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				while (i < 5)
				{
					int sum = rand() % (50 - 25 + 1) + 25;
					Particle newParticle(m_Window ,sum, {event.mouseButton.x, event.mouseButton.y});
					m_particles.push_back(newParticle);
					i++;
				}

			}
		}

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
			m_Window.close();
        }
    }
}

void Engine::update(float dtAsSeconds)
{
	vector<Particle>::iterator iter;
	
	for(iter = m_particles.begin(); iter != m_particles.end();)
	{
		
		if (iter->getTTL() > 0.0)
		{
			iter->update(dtAsSeconds);
			iter++;
		}
		else
		{
			iter = m_particles.erase(iter);
		}
	}
}

void Engine::draw()
{
	
	m_Window.clear();
	for (int i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles[i]);
		
		//m_Window.draw(spriteBackground);
		
	}
	m_Window.display();

}
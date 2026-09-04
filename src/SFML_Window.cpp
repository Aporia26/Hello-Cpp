/*#include<iostream>
#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    // SFML 3 uses a Vector2u inside VideoMode constructor brackets
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3.0 Window");

    // Main game/application loop
    while (window.isOpen())
    {
        // SFML 3 window polling returns a std::optional<sf::Event>
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            // Check if the user requested to close the window
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Clear screen with a background color
        window.clear(sf::Color::Black);

        // Display the freshly drawn frame onto the window
        window.display();
    }

    return 0;
}
    _________________________________________________________________________________________________
/*#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

using namespace sf;

int main(){
    Window window(VideoMode({800,600}), "SFML WORKS",Style::Default);
     window.setFramerateLimit({60});

     window.setPosition({10,40});
     window.setSize({1908,1000});
     sf::Vector2u size = window.getSize();
auto [width, height] = size;

while(window.isOpen()){
    Event event;
    while(window.pollEvent(event)){
        if(event.type == Event::Closed)
            window.close();
        }

        window.clear();

       window.draw(shape);

        window.display();
}
  while(window.isOpen()){

    while(const std::optional event = window.pollEvent()){
        if(event->is<sf::Event::Closed>())
        window.close();
    }  
  }________________________________________________________________________________________________
}*/
#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    // Define your internal target resolution (e.g., 16:9 aspect ratio)
    const sf::Vector2f targetResolution{800.f, 600.f};

    // Professional window styles: Close button, Titlebar, and Resizing enabled
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), 
        "Professional Game Architecture", 
        sf::Style::Default
    );

    // CRITICAL: Prevents extreme GPU overheating and limits loop to monitor refresh rate
    window.setVerticalSyncEnabled(true); 

    // Clock used to measure time between frames (Delta Time)
    sf::Clock deltaClock;

    // Set up our circle
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::White);
    circle.setOrigin({50.f, 50.f});

    // Main Game Loop
    while (window.isOpen())
    {
        // 1. DYNAMIC TIME STEP (Delta Time)
        // physicalTime is the fraction of a second the last frame took to render
        sf::Time deltaTime = deltaClock.restart();
        float dtSeconds = deltaTime.asSeconds();

        // 2. BULLETPROOF EVENT HANDLING
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // Handle clean resizing across all monitor types and high-DPI displays
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // Instantly recalculate view dimensions to maintain crisp raster scaling
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
        }

        // 3. DYNAMIC LOGIC (Recalculates positions safely on the fly)
        // Get the current real-time window size 
        sf::Vector2u windowSize = window.getSize();
        
        // Dynamically snap the circle to the exact mathematical center
        float centerX = static_cast<float>(windowSize.x) / 2.f;
        float centerY = static_cast<float>(windowSize.y) / 2.f;
        circle.setPosition({centerX, centerY});
        
        // Example of smooth, frame-rate independent movement:
        // speed (pixels per second) * dtSeconds 
        // If you wanted to move it right: circle.move({ 100.f * dtSeconds, 0.f });

        // 4. RENDERING PASS
        // Dark slate gray looks much cleaner and more professional than harsh pure green
        window.clear(sf::Color(30, 30, 35)); 

        window.draw(circle);

        window.display();
    }

    return 0;
}

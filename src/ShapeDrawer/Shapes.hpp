#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdint>


struct CircleGenerator{
  uint32_t quality;
  float radius = 0;
  // derivetive of angle
  float da = 1;
  CircleGenerator(float radius_, uint32_t quality_);
  sf::Vector2f get_point(uint32_t i, float theta = 0.0);
};
void generateRoundedRect(sf::VertexArray& arr, sf::Vector2f position, float height, float width, uint32_t quality, float theta = 0.0, float range = 0.0, sf::Color color = sf::Color::Red);
void generateCircle(sf::VertexArray& arr, sf::Vector2f position, float radius, uint32_t quality, float theta = 0.0, sf::Color color = sf::Color::White);



#include "Boid.hpp"
#include <cmath>
#include <iostream>

float distance(Vector2D v1, Vector2D v2) {
    return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

float wrap(float x, float m) {
    float res = fmod(x, m);
    return res < 0 ? res + m : res;
}


Boid::Boid()
{
    max_speed = 7.5;
    pos = 50.f;
    // shape.setPointCount(3);
    shape.setRadius(1.0f);
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setPosition(transform_Vec2D(pos));
    acceleration = 0;
}

Boid::Boid(float _x, float _y)
{
    max_speed = 7.5;
    pos = Vector2D(_x, _y);
    // shape.setPointCount(3);
    speed = Vector2D(rand() % 50 -25, rand() % 50 -25);
    shape.setRadius(8.0f);
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setPosition(transform_Vec2D(pos));
    acceleration = 0;
}

void Boid::move(int width, int height)
{
    // acceleration.mulNum(0.4f);
    // speed += acceleration;

    // std::cout << "speed: " << speed.x << '\t' << speed.y << std::endl;
    // std::cout << "accel: " << acceleration.x << '\t' << acceleration.y << std::endl;

    this->pos.x = wrap(this->pos.x + this->speed.x / 1, width);
    this->pos.y = wrap(this->pos.y + this->speed.y / 1, height);
    shape.setPosition(transform_Vec2D(pos));
    // std::cout << "angle: " << speed.angle() << std::endl;
    // shape.setRotation(speed.angle() + 30);
}

sf::Vector2f Boid::transform_Vec2D(Vector2D& v)
{
    return sf::Vector2f(v.get_x(), v.get_y());
}



void Boid::update(std::vector<Boid>& boids)
{
    int count = 0;
    float viewrange = 100.f;

    Vector2D alignment(0.f, 0.f);
    Vector2D cohesion(0.f, 0.f);
    Vector2D seperation(0.f, 0.f);

    for (int i = 0; i < boids.size(); i++) 
    {
        float d = distance(this->pos, boids[i].pos);
        // std::cout << "pos: " << pos.x << "";

        // std::cout << "dis: " << d << std::endl;
        if (d > 0 && d < viewrange)
        {
            // std::cout << "dis: " << d << std::endl;
            // std::cout << "IN RANGE" << std::endl;
            alignment += boids[i].speed;
            cohesion += boids[i].pos;
            seperation += boids[i].pos - pos;
            count++;
        }
    }

    // std::cout << "count: " << count << std::endl;

    if (count > 0)
    {
        alignment.divNum(static_cast<float>(count));
        alignment.nomalize(); // alignment finished

        cohesion.divNum(static_cast<float>(count));
        cohesion -= pos;
        cohesion.nomalize(); // cohesion finished

        seperation.divNum(static_cast<float>(count));
        seperation = -seperation;
        seperation.nomalize(); // seperation finished

        speed += alignment*1.f + cohesion*1.f + seperation*1.5f;
        speed.nomalize();
        speed.mulNum(5.f);

    }

}
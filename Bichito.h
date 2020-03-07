#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>

using namespace std;
using namespace sf;

class Bichito { //-----------------------------------------------Clase "Bichito". Es la Clase de la Bomba del juego.

private:

	Sprite s_bichito;
	Texture t_bichito;

	Vector2f position;
	Vector2f acceleration;
	Vector2f velocity;

public:

	Bichito();

	void Update(float dt);

	Sprite getSprite();

	void SetPosition(Vector2f pos) { position = pos; };
	void SetAcceleration(Vector2f acc) { acceleration = acc; }
	void SetVelocity(Vector2f vel) { velocity = vel; }

	Vector2f GetPosition() { return position; }
	Vector2f GetAcceleration() { return acceleration; }
	Vector2f GetVelocity() { return velocity; }

};
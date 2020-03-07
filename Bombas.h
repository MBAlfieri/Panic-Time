#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include  "Items.h"

using namespace std;
using namespace sf;

class Bombas : public Items{
private:

	Texture T_Bombas;
	Sprite S_Bombas;

	Vector2f position; //propiedades del sprite
	Vector2f acceleration;
	Vector2f velocity;


public:

	Bombas(Vector2f Posicion_Spawn);
	Sprite getSprite() { return S_Bombas; };
	void Update(float dt);

	void SetPosition(Vector2f pos) { position = pos; };
	void SetAcceleration(Vector2f acc) { acceleration = acc; }
	void SetVelocity(Vector2f vel) { velocity = vel; }

	Vector2f GetPosition() { return position; }
	Vector2f GetAcceleration() { return acceleration; }
	Vector2f GetVelocity() { return velocity; }

};


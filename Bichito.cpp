#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "Bichito.h"

using namespace std;
using namespace sf;

Bichito::Bichito(){

	t_bichito.loadFromFile("Bomba.png");
	s_bichito.setTexture(t_bichito);

	position.x = 0.0f;
	position.y = 0.0f;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;

}

Sprite Bichito::getSprite() {

	return s_bichito;

}

void Bichito::Update(float dt) {

	velocity.x += acceleration.x * dt;
	velocity.y += acceleration.y * dt;

	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

	s_bichito.setPosition(position);

}
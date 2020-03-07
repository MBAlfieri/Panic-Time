#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "Jugador.h"

using namespace std;
using namespace sf;

Jugador::Jugador() {

	Vidas = 4;

	T_JugadorPrincipal.loadFromFile("MainPer.png");
	S_JugadorPrincipal.setTexture(T_JugadorPrincipal);

	t_Vidas.loadFromFile("Vidas.png"); 
	s_Vidas.setTexture(t_Vidas); 
	s_Vidas.setPosition(620, 560);

	T_Corazon1.loadFromFile("corazon1.png");
	T_Corazon2.loadFromFile("corazon2.png");
	T_Corazon3.loadFromFile("corazon3.png");

	S_Corazon1.setTexture(T_Corazon1);
	S_Corazon2.setTexture(T_Corazon2);
	S_Corazon3.setTexture(T_Corazon3);

	S_Corazon1.setPosition(692, 563);
	S_Corazon2.setPosition(690, 563);
	S_Corazon3.setPosition(690, 563);

	t_Puntos.loadFromFile("Puntos.png");
	s_Puntos.setTexture(t_Puntos);
	s_Puntos.setPosition(5, 560);

	position.x = 0.0f;
	position.y = 0.0f;

}


void Jugador::setSpriteCorazon3Vidas() {

	S_Corazon3.setPosition(1000, 1000);

}

void Jugador::setSpriteCorazon2Vidas() { 

	S_Corazon2.setPosition(1000, 1000);

}

void Jugador::setSpriteCorazon1Vida() {

	S_Corazon1.setPosition(1000, 1000);

}

void Jugador::UpdateJugador(float dt) {

	S_JugadorPrincipal.setPosition(position);

}

void Jugador::setRestartVidas() {

	Vidas = 3;

	S_Corazon1.setPosition(692, 563);
	S_Corazon2.setPosition(690, 563);
	S_Corazon3.setPosition(690, 563);

}
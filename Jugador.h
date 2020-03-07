#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>

using namespace std;
using namespace sf;

class Jugador { //-------------------------------------------------Clase "Jugador". Posee las Vidas y los Puntos del Jugador.

private:

	int Vidas = 3;

	Sprite S_JugadorPrincipal;
	Texture T_JugadorPrincipal;

	Sprite S_Corazon1;
	Texture T_Corazon1;

	Sprite S_Corazon2;
	Texture T_Corazon2;

	Sprite S_Corazon3;
	Texture T_Corazon3;

	Sprite s_Vidas; 
	Texture t_Vidas; 

	Sprite s_Puntos; 
	Texture t_Puntos; 

	Vector2f position; //propiedades del sprite
	Vector2f acceleration;
	Vector2f velocity;


public:

	Jugador();

	void UpdateJugador(float dt);

	Sprite getSprite() { return S_JugadorPrincipal; };
	Texture getTexture() { return T_JugadorPrincipal; };
	Sprite getSpriteVidas() { return s_Vidas; }; 
	Sprite getSpritePuntos() { return s_Puntos; }; 
	Sprite getSpriteCorazon3Vidas() { return S_Corazon3; }; 
	Sprite getSpriteCorazon2Vidas() { return S_Corazon2; };
	Sprite getSpriteCorazon() { return S_Corazon1; }; 

	void setSpriteCorazon3Vidas(); 
	void setSpriteCorazon2Vidas(); 
	void setSpriteCorazon1Vida(); 

	void SetPosition(Vector2f pos) { position = pos; };

	Vector2f GetPosition() { return position; }

	int getVidas() { return Vidas; };

	void setVidas(){ Vidas--; };

	void setRestartVidas();

};
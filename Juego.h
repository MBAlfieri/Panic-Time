#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "Bichito.h"
#include "Jugador.h"

using namespace std;
using namespace sf;

class Juego{//-----------------------------------------------Clase "Juego". Basicamente maneja el funcionamiento del juego.

private:

	Texture T_Background;
	Sprite S_Background;

	Texture T_GameOver;
	Sprite S_GameOver;

	Texture T_Puntero;
	Sprite S_Puntero;

	Texture T_Continuar;
	Sprite S_Continuar;

	Texture T_Logo;
	Sprite S_Logo;

	Texture T_MainMenu;
	Sprite S_MainMenu;

	Texture T_UniLogo;
	Sprite S_UniLogo;

	Texture T_Comenzar;
	Sprite S_Comenzar;

	Texture T_Volver;
	Sprite S_Volver;

	Texture T_SeleccionInstrucciones;
	Sprite S_SeleccionInstrucciones;

	Texture T_Instrucciones;
	Sprite S_Instrucciones;

	sf::SoundBuffer Buffer1;
	sf::Sound Rebote; 

	sf::SoundBuffer Buffer2;
	sf::Sound Bell1;

	sf::SoundBuffer Buffer3;
	sf::Sound Bell2;

	sf::SoundBuffer Buffer4;
	sf::Sound Explosion;

	sf::SoundBuffer Buffer5;
	sf::Sound GameOver;

	sf::SoundBuffer Buffer6;
	sf::Sound Click;

	Music SonidoIntro;

	Music SonidoGame;

	RenderWindow * VentanaJuego;

	bool GameOn = true;
	bool GameStart;
	bool Intro;
	bool Instrucciones;

	Bichito * BichitoEnemigo;
	Bichito * BichitoEnemigo2;
	Bichito * BichitoEnemigo3;
	Bichito * BichitoEnemigo4;
	Bichito * BichitoEnemigo5;

	Clock* Cronometro;
	Time* TiempoTranscurrido;

	Jugador * JugadorNuevo;

	Event * EventosJuego;

	float Tiempo;

	Font * Fuente; 
	Text * MisPuntos; 
	Color * ColorFont; 
	String * StringPuntos; 

	int Puntos = -50 ; 
	int PuntosFinales;


public:

	Juego(Vector2f ResolucionPantalla, String TituloDelJuego);

	void Update(float dt);

	void LoopFuncionamientoJuego();

	void Texturas();
	void Sonidos();

	Sprite getSpriteBackground() { return S_Background; };
	Sprite getSpriteContinue() { return S_Continuar; };

	void EventosDelJuego(); //Son los eventos del juego.

	void setStringPuntos(); //Cambia el tamaño y la posición de los Puntos.

	void setRestartTiempo();

	void setRestartPuntos();

	float UpdatePosicion = 400;

	float PosiblesValores;

};


/*	Trabajo Práctico Final
	Alumna: Micaela B. Alfieri
	Materia: Modelos y Algoritmos para Videojuegos I
	Institución: Universidad Nacional del Litoral
	Año: 2020 */

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Juego.h"
using namespace std;
using namespace sf;


int main(int argc, char* args[]) {

	srand(time(NULL));

	Juego Jugador1({ 800, 600 }, "Panic-Time!");

	return 0;

}
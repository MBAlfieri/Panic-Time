#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cstdlib>
#include "Juego.h"
#include "Bichito.h"
#include "Jugador.h"



Juego::Juego(Vector2f ResolucionPantalla, String TituloDelJuego) {

	VentanaJuego = new RenderWindow(VideoMode(ResolucionPantalla.x, ResolucionPantalla.y), TituloDelJuego); 
	
	VentanaJuego->setFramerateLimit(60);

	VentanaJuego->setMouseCursorVisible(false);

	Intro = true;

	GameStart = true;

	Instrucciones = false;

	Cronometro = new Clock;

	TiempoTranscurrido = new Time;

	BichitoEnemigo = new Bichito;

	BichitoEnemigo2 = new Bichito;

	BichitoEnemigo3 = new Bichito;

	BichitoEnemigo4 = new Bichito;

	BichitoEnemigo5 = new Bichito;

	ColorFont = new Color;

	EventosJuego = new Event;

	JugadorNuevo = new Jugador;

	Fuente = new Font(); //Es la Fuente.

	StringPuntos = new String; //String de los Puntos.

	MisPuntos = new Text(); //Texto que tendrá los Puntos.

	JugadorNuevo->SetPosition(Vector2f(400.0f, 462.0f));


//------------------------------------------------------------------------------------------------------------Características iniciales de las Bombas.

//----------------------Bomba 1.
	BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 9.8f));

	BichitoEnemigo->SetPosition(Vector2f(350.0f, 100.0f));

	BichitoEnemigo->SetVelocity(Vector2f(0.0f, 0.0f));


//----------------------Bomba 3.
	BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 9.8f));

	BichitoEnemigo3->SetPosition(Vector2f(350.0f, 100.0f));

	BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 0.0f));


//----------------------Bomba 4.
	BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 9.8f));

	BichitoEnemigo4->SetPosition(Vector2f(350.0f, 100.0f));

	BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 0.0f));


//----------------------Bomba 5.
	BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 9.8f));

	BichitoEnemigo5->SetPosition(Vector2f(350.0f, 100.0f));

	BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 0.0f));


	Sonidos();

	Texturas();

	LoopFuncionamientoJuego();

}



void Juego::Update(float dt) {

//-------------------------------------------------------------------------------------------------------------Limites del area dónde se mueve la Bomba


//-------------------------------------------------------------------------------------------------------------Posicion Y - Arriba (En caso de que la Bomba toque el "techo" de la ventana)
//-------------------------------------------------------------------------------------------------------------Se aporta un cierto grado de "randomizacion" en cuanto a que direccion rebotará la Bomba.
	//----------------------Bomba 1.
	if ((BichitoEnemigo->GetPosition().y < 0)) {

		PosiblesValores = (rand() % 5);

		if (PosiblesValores == 0) {

		BichitoEnemigo->SetAcceleration(Vector2f(200.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 400.0f));
		
		}


		if (PosiblesValores == 1) {

		BichitoEnemigo->SetAcceleration(Vector2f(-200.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 2) {

		BichitoEnemigo->SetAcceleration(Vector2f(100.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 3) {

		BichitoEnemigo->SetAcceleration(Vector2f(-100.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 400.0f));
		

		}

		if (PosiblesValores == 4) {

		BichitoEnemigo->SetAcceleration(Vector2f(300.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 5) {

		BichitoEnemigo->SetAcceleration(Vector2f(-300.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 400.0f));


		}


	}

	//----------------------Bomba 2.
	if ((BichitoEnemigo2->GetPosition().y < 0)) {

		PosiblesValores = (rand() % 5);

		if (PosiblesValores == 0) {

			BichitoEnemigo2->SetAcceleration(Vector2f(200.0f, 9.8f));

			BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 400.0f));

		}


		if (PosiblesValores == 1) {

			BichitoEnemigo2->SetAcceleration(Vector2f(-200.0f, 9.8f));

			BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 2) {

			BichitoEnemigo2->SetAcceleration(Vector2f(100.0f, 9.8f));

			BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 3) {

			BichitoEnemigo2->SetAcceleration(Vector2f(-100.0f, 9.8f));

			BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 4) {

			BichitoEnemigo2->SetAcceleration(Vector2f(300.0f, 9.8f));

			BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 5) {

			BichitoEnemigo2->SetAcceleration(Vector2f(-300.0f, 9.8f));

			BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 400.0f));


		}


	}

	//----------------------Bomba 3.
	if ((BichitoEnemigo3->GetPosition().y < 0)) {

		PosiblesValores = (rand() % 5);

		if (PosiblesValores == 0) {

			BichitoEnemigo3->SetAcceleration(Vector2f(200.0f, 9.8f));

			BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 400.0f));

		}


		if (PosiblesValores == 1) {

			BichitoEnemigo3->SetAcceleration(Vector2f(-200.0f, 9.8f));

			BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 2) {

			BichitoEnemigo3->SetAcceleration(Vector2f(100.0f, 9.8f));

			BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 3) {

			BichitoEnemigo3->SetAcceleration(Vector2f(-100.0f, 9.8f));

			BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 4) {

			BichitoEnemigo3->SetAcceleration(Vector2f(300.0f, 9.8f));

			BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 5) {

			BichitoEnemigo3->SetAcceleration(Vector2f(-300.0f, 9.8f));

			BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 400.0f));


		}


	}

	//----------------------Bomba 4.
	if ((BichitoEnemigo4->GetPosition().y < 0)) {

		PosiblesValores = (rand() % 5);

		if (PosiblesValores == 0) {

			BichitoEnemigo4->SetAcceleration(Vector2f(200.0f, 9.8f));

			BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 400.0f));

		}


		if (PosiblesValores == 1) {

			BichitoEnemigo4->SetAcceleration(Vector2f(-200.0f, 9.8f));

			BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 2) {

			BichitoEnemigo4->SetAcceleration(Vector2f(100.0f, 9.8f));

			BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 3) {

			BichitoEnemigo4->SetAcceleration(Vector2f(-100.0f, 9.8f));

			BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 4) {

			BichitoEnemigo4->SetAcceleration(Vector2f(300.0f, 9.8f));

			BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 5) {

			BichitoEnemigo4->SetAcceleration(Vector2f(-300.0f, 9.8f));

			BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 400.0f));


		}


	}

	//----------------------Bomba 5.
	if ((BichitoEnemigo5->GetPosition().y < 0)) {

		PosiblesValores = (rand() % 5);

		if (PosiblesValores == 0) {

			BichitoEnemigo5->SetAcceleration(Vector2f(200.0f, 9.8f));

			BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 400.0f));

		}


		if (PosiblesValores == 1) {

			BichitoEnemigo5->SetAcceleration(Vector2f(-200.0f, 9.8f));

			BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 2) {

			BichitoEnemigo5->SetAcceleration(Vector2f(100.0f, 9.8f));

			BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 3) {

			BichitoEnemigo5->SetAcceleration(Vector2f(-100.0f, 9.8f));

			BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 4) {

			BichitoEnemigo5->SetAcceleration(Vector2f(300.0f, 9.8f));

			BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 400.0f));


		}

		if (PosiblesValores == 5) {

			BichitoEnemigo5->SetAcceleration(Vector2f(-300.0f, 9.8f));

			BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 400.0f));


		}


	}



//------------------------------------------------------------------------------------------------------------Posicion Y - Abajo (En caso de que la Bomba toque el "piso" de la ventana. Se pierde una Vida si esto sucede)
//----------------------Bomba 1.
	if (BichitoEnemigo->GetPosition().y > 500.0f) {

		BichitoEnemigo->SetPosition(Vector2f(400.0f, 10.0f));

		BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 9.8f));

		BichitoEnemigo->SetVelocity(Vector2f(0.0f, 200.0f));

		Explosion.play();

		JugadorNuevo->setVidas();

	}

//----------------------Bomba 2.
	if (BichitoEnemigo2->GetPosition().y > 500.0f) {

		BichitoEnemigo2->SetPosition(Vector2f(400.0f, 10.0f));

		BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 9.8f));

		BichitoEnemigo2->SetVelocity(Vector2f(0.0f, 200.0f));

		Explosion.play();

		JugadorNuevo->setVidas();

	}

//----------------------Bomba 3.
	if (BichitoEnemigo3->GetPosition().y > 500.0f) {

		BichitoEnemigo3->SetPosition(Vector2f(400.0f, 10.0f));

		BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 9.8f));

		BichitoEnemigo3->SetVelocity(Vector2f(0.0f, 200.0f));

		Explosion.play();

		JugadorNuevo->setVidas();

	}

//----------------------Bomba 4.
	if (BichitoEnemigo4->GetPosition().y > 500.0f) {


		BichitoEnemigo4->SetPosition(Vector2f(400.0f, 10.0f));

		BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 9.8f));

		BichitoEnemigo4->SetVelocity(Vector2f(0.0f, 200.0f));

		Explosion.play();

		JugadorNuevo->setVidas();

	}

//----------------------Bomba 5.
	if (BichitoEnemigo5->GetPosition().y > 500.0f) {

		BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 9.8f));

		BichitoEnemigo5->SetPosition(Vector2f(400.0f, 10.0f));

		BichitoEnemigo5->SetVelocity(Vector2f(0.0f, 200.0f));

		Explosion.play();

		JugadorNuevo->setVidas();

	}



//-----------------------------------------------------------------------------------------------------------Posicion X - Derecha (En caso de que la Bomba toque el la parte derecha de la pantalla)
//-----------------------------------------------------------------------------------------------------------Se aporta un cierto grado de "randomizacion" en cuanto a que direccion rebotará la bomba.
//----------------------Bomba 1.
	if ((BichitoEnemigo->GetPosition().x > 740)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo->SetAcceleration(Vector2f(-160.0f, 220.0f));

		BichitoEnemigo->SetVelocity(Vector2f(-100.0f, -10.0f));
	}

//----------------------Bomba 2.
	if ((BichitoEnemigo2->GetPosition().x > 740)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo2->SetAcceleration(Vector2f(-160.0f, 220.0f));

		BichitoEnemigo2->SetVelocity(Vector2f(-100.0f, -10.0f));
	}

//----------------------Bomba 3.
	if ((BichitoEnemigo3->GetPosition().x > 740)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo3->SetAcceleration(Vector2f(-160.0f, 220.0f));

		BichitoEnemigo3->SetVelocity(Vector2f(-100.0f, -10.0f));
	}

//----------------------Bomba 4.
	if ((BichitoEnemigo4->GetPosition().x > 740)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo4->SetAcceleration(Vector2f(-160.0f, 220.0f));

		BichitoEnemigo4->SetVelocity(Vector2f(-100.0f, -10.0f));
	}

//----------------------Bomba 5.
	if ((BichitoEnemigo5->GetPosition().x > 740)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo5->SetAcceleration(Vector2f(-160.0f, 220.0f));

		BichitoEnemigo5->SetVelocity(Vector2f(-100.0f, -10.0f));
	}



//------------------------------------------------------------------------------------------------------------Posicion X - Izquierda (En caso de que la Bomba toque la parte izquierda de la pantalla)
//------------------------------------------------------------------------------------------------------------Se aporta un cierto grado de "randomizacion" en cuanto a que direccion rebotará la bomba.

//----------------------Bomba 1.
	if ((BichitoEnemigo->GetPosition().x < 5)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo->SetAcceleration(Vector2f(160.0f, 220.0f));

		BichitoEnemigo->SetVelocity(Vector2f(100.0f, 10.0f));
	}

//----------------------Bomba 2.
	if ((BichitoEnemigo2->GetPosition().x < 5)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo2->SetAcceleration(Vector2f(160.0f, 220.0f));

		BichitoEnemigo2->SetVelocity(Vector2f(100.0f, 10.0f));
	}

//----------------------Bomba 3.
	if ((BichitoEnemigo3->GetPosition().x < 5)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo3->SetAcceleration(Vector2f(160.0f, 220.0f));

		BichitoEnemigo3->SetVelocity(Vector2f(100.0f, 10.0f));
	}

//----------------------Bomba 4.
	if ((BichitoEnemigo4->GetPosition().x < 5)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo4->SetAcceleration(Vector2f(160.0f, 220.0f));

		BichitoEnemigo4->SetVelocity(Vector2f(100.0f, 10.0f));
	}

//----------------------Bomba 5.
	if ((BichitoEnemigo5->GetPosition().x < 5)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla

		BichitoEnemigo5->SetAcceleration(Vector2f(160.0f, 220.0f));

		BichitoEnemigo5->SetVelocity(Vector2f(100.0f, 10.0f));
	}
	
	

//-----------------------------------------------------------------------------------------------------------Controles del Jugador.
	if (Keyboard::isKeyPressed(Keyboard::Left)) {

		JugadorNuevo->SetPosition(Vector2f((UpdatePosicion-= 12.0f), 462.0f));
		

	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {

		JugadorNuevo->SetPosition(Vector2f((UpdatePosicion += 12.0f), 462.0f));


	}


//-----------------------------------------------------------------------------------------------------------Limites del Jugador (para que no se vaya de la ventana).

	if((JugadorNuevo->GetPosition().x < 0)) { //Detrndrá el Sprite así no sobrepasa los límites de la pantalla
		
		JugadorNuevo->SetPosition(Vector2f(UpdatePosicion = 0, 462.0f));


	}

	if ((JugadorNuevo->GetPosition().x > 695)) {

		JugadorNuevo->SetPosition(Vector2f(UpdatePosicion = 695, 462.0f));

	}



//-----------------------------------------------------------------------------------------------------------Colisiones. (Permite que la Bomba rebote cuando el jugador la toca)
//-----------------------------------------------------------------------------------------------------------Se aporta un cierto grado de "randomizacion" en cuanto a que direccion rebotará la bomba.

	FloatRect Pos(JugadorNuevo->getSprite().getPosition(), (Vector2f)JugadorNuevo->getTexture().getSize());

		//----------------------Bomba 1.
		if (BichitoEnemigo->getSprite().getGlobalBounds().intersects(Pos)) {

			Rebote.play();

			PosiblesValores = (rand() % 5);

			Puntos += 10;

			if (PosiblesValores == 0) {

				BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 200.0f));

				BichitoEnemigo->SetVelocity(Vector2f(0.0f, -400.0f));

			}


			if (PosiblesValores == 1) {

				BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo->SetVelocity(Vector2f(100.0f, -400.0f));


			}


			if (PosiblesValores == 2) {

				BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo->SetVelocity(Vector2f(-200.0f, -500.0f));


			}



			if (PosiblesValores == 3) {

				BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo->SetVelocity(Vector2f(100.0f, -400.0f));


			}



			if (PosiblesValores == 4) {


				BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo->SetVelocity(Vector2f(-50.0f, -400.0f));

			}


			if (PosiblesValores == 5) {


				BichitoEnemigo->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo->SetVelocity(Vector2f(200.0f, -400.0f));


			}

		}

		//----------------------Bomba 2.
		if (BichitoEnemigo2->getSprite().getGlobalBounds().intersects(Pos)) {

			Rebote.play();

			PosiblesValores = (rand() % 5);

			Puntos += 10;

			if (PosiblesValores == 0) {

				BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 200.0f));

				BichitoEnemigo2->SetVelocity(Vector2f(0.0f, -400.0f));

			}


			if (PosiblesValores == 1) {

				BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo2->SetVelocity(Vector2f(100.0f, -400.0f));


			}


			if (PosiblesValores == 2) {

				BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo2->SetVelocity(Vector2f(-200.0f, -500.0f));


			}



			if (PosiblesValores == 3) {

				BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo2->SetVelocity(Vector2f(100.0f, -400.0f));


			}



			if (PosiblesValores == 4) {


				BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo2->SetVelocity(Vector2f(-50.0f, -400.0f));

			}


			if (PosiblesValores == 5) {


				BichitoEnemigo2->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo2->SetVelocity(Vector2f(200.0f, -400.0f));


			}

		}

		//----------------------Bomba 3.
		if (BichitoEnemigo3->getSprite().getGlobalBounds().intersects(Pos)) {

			Rebote.play();

			PosiblesValores = (rand() % 5);

			Puntos += 10;

			if (PosiblesValores == 0) {

				BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 200.0f));

				BichitoEnemigo3->SetVelocity(Vector2f(0.0f, -400.0f));

			}


			if (PosiblesValores == 1) {

				BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo3->SetVelocity(Vector2f(100.0f, -400.0f));


			}


			if (PosiblesValores == 2) {

				BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo3->SetVelocity(Vector2f(-200.0f, -500.0f));


			}



			if (PosiblesValores == 3) {

				BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo3->SetVelocity(Vector2f(100.0f, -400.0f));


			}



			if (PosiblesValores == 4) {


				BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo3->SetVelocity(Vector2f(-50.0f, -400.0f));

			}


			if (PosiblesValores == 5) {


				BichitoEnemigo3->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo3->SetVelocity(Vector2f(200.0f, -400.0f));


			}

		}

		//----------------------Bomba 4.
		if (BichitoEnemigo4->getSprite().getGlobalBounds().intersects(Pos)) {

			Rebote.play();

			PosiblesValores = (rand() % 5);

			Puntos += 10;

			if (PosiblesValores == 0) {

				BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 200.0f));

				BichitoEnemigo4->SetVelocity(Vector2f(0.0f, -400.0f));

			}


			if (PosiblesValores == 1) {

				BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo4->SetVelocity(Vector2f(100.0f, -400.0f));


			}


			if (PosiblesValores == 2) {

				BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo4->SetVelocity(Vector2f(-200.0f, -500.0f));


			}



			if (PosiblesValores == 3) {

				BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo4->SetVelocity(Vector2f(100.0f, -400.0f));


			}



			if (PosiblesValores == 4) {


				BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo4->SetVelocity(Vector2f(-50.0f, -400.0f));

			}


			if (PosiblesValores == 5) {


				BichitoEnemigo4->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo4->SetVelocity(Vector2f(200.0f, -400.0f));


			}

		}

		//----------------------Bomba 5.
		if (BichitoEnemigo5->getSprite().getGlobalBounds().intersects(Pos)) {

			Rebote.play();

			PosiblesValores = (rand() % 5);

			Puntos += 10;

			if (PosiblesValores == 0) {

				BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 200.0f));

				BichitoEnemigo5->SetVelocity(Vector2f(0.0f, -400.0f));

			}


			if (PosiblesValores == 1) {

				BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo5->SetVelocity(Vector2f(100.0f, -400.0f));


			}


			if (PosiblesValores == 2) {

				BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo5->SetVelocity(Vector2f(-200.0f, -500.0f));


			}



			if (PosiblesValores == 3) {

				BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo5->SetVelocity(Vector2f(100.0f, -400.0f));


			}



			if (PosiblesValores == 4) {


				BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo5->SetVelocity(Vector2f(-50.0f, -400.0f));

			}


			if (PosiblesValores == 5) {


				BichitoEnemigo5->SetAcceleration(Vector2f(0.0f, 250.0f));

				BichitoEnemigo5->SetVelocity(Vector2f(200.0f, -400.0f));


			}

		}

	

//-----------------------------------------------------------------------------------------------------------Updates. Permitirá que X número de Bombas aparezcan luego de Y tiempo.
	*TiempoTranscurrido = Cronometro->getElapsedTime();

	JugadorNuevo->UpdateJugador(dt);

	BichitoEnemigo->Update(dt);

	if (TiempoTranscurrido->asSeconds() > 25) {

	BichitoEnemigo2->Update(dt);

	}

	if (TiempoTranscurrido->asSeconds() > 35) {

	BichitoEnemigo3->Update(dt);

	}

	if (TiempoTranscurrido->asSeconds() > 45) {

	BichitoEnemigo4->Update(dt);

	}

	if (TiempoTranscurrido->asSeconds() > 55) {

	BichitoEnemigo5->Update(dt);


	}

}


void Juego::LoopFuncionamientoJuego() {

	Clock clock;
	clock.restart();
	float dt;

	Bell1.play();

	SonidoIntro.setVolume(0);
	SonidoIntro.play();

	SonidoGame.play();
	SonidoGame.setLoop(true);
	SonidoGame.setVolume(0);

	while (GameOn == true) { //Inicio del Juego.

		while (Intro == true) { //Introducción del Juego.

			EventosDelJuego();

			VentanaJuego->clear();

			VentanaJuego->draw(S_Logo);

			*TiempoTranscurrido = Cronometro->getElapsedTime();

			if (TiempoTranscurrido->asSeconds() > 6 + Tiempo) {

				Tiempo = TiempoTranscurrido->asMilliseconds();

				Bell2.play();

			}

			if (TiempoTranscurrido->asSeconds() > 6) {

				VentanaJuego->draw(S_UniLogo);

				if (TiempoTranscurrido->asSeconds() > 8) {
					SonidoIntro.setVolume(100);

					VentanaJuego->draw(S_MainMenu);

					S_Comenzar.setPosition(220, 320);

					VentanaJuego->draw(S_Comenzar);

					S_SeleccionInstrucciones.setPosition(135, 450);

					VentanaJuego->draw(S_SeleccionInstrucciones);

					VentanaJuego->draw(S_Puntero);


					while (Instrucciones == true) { //Pantalla de Instrucciones.

						EventosDelJuego();

						VentanaJuego->draw(S_Instrucciones);

						S_Volver.setPosition(0, 510);

						VentanaJuego->draw(S_Volver);

						VentanaJuego->draw(S_Puntero);

						VentanaJuego->display();

					}

				}

			}

			VentanaJuego->display();
		}


		while (GameStart == true) {//Inicio de la partida.

			SonidoIntro.stop();

			Tiempo = 0;

			Fuente->loadFromFile("GILB.ttf");

			ColorFont->Black; 
			MisPuntos->setFont(*Fuente);
			MisPuntos->setPosition(100, 564); 
			MisPuntos->setScale(1, 1); 
			MisPuntos->setOutlineThickness(2); 
			MisPuntos->setOutlineColor(*ColorFont); 
			*StringPuntos = to_string(Puntos); 
			MisPuntos->setString(*StringPuntos);

			float dt = clock.restart().asSeconds();

			VentanaJuego->clear();

			EventosDelJuego();

			Update(dt);

			VentanaJuego->draw(getSpriteBackground());

			VentanaJuego->draw(JugadorNuevo->getSprite());

			VentanaJuego->draw(BichitoEnemigo->getSprite());


			if (TiempoTranscurrido->asSeconds() > 25) { //Se Muestran las Bombas luego de X Tiempo.

				VentanaJuego->draw(BichitoEnemigo2->getSprite());

			}

			if (TiempoTranscurrido->asSeconds() > 35) { //Se Muestran las Bombas luego de X Tiempo.

				VentanaJuego->draw(BichitoEnemigo3->getSprite());

			}

			if (TiempoTranscurrido->asSeconds() > 45) { //Se Muestran las Bombas luego de X Tiempo.

				VentanaJuego->draw(BichitoEnemigo4->getSprite());

			}

			if (TiempoTranscurrido->asSeconds() > 55) { //Se Muestran las Bombas luego de X Tiempo.

				VentanaJuego->draw(BichitoEnemigo5->getSprite());

			}


			VentanaJuego->draw(JugadorNuevo->getSpriteVidas());

			VentanaJuego->draw(JugadorNuevo->getSpritePuntos()); 


			if (JugadorNuevo->getVidas() == 3) { //Si se tienen 3 vidas, se muestra el Sprite correspondiente.

				VentanaJuego->draw(JugadorNuevo->getSpriteCorazon3Vidas());

			}

			if (JugadorNuevo->getVidas() == 2) { //Si se tienen 2 vidas, se muestra el Sprite correspondiente y se mueve Sprite el anterior.

				JugadorNuevo->setSpriteCorazon3Vidas();
				VentanaJuego->draw(JugadorNuevo->getSpriteCorazon3Vidas());
				VentanaJuego->draw(JugadorNuevo->getSpriteCorazon2Vidas());

			}

			if (JugadorNuevo->getVidas() == 1) {//Si se tiene 1 vida, se muestra el Sprite correspondiente y se mueve Sprite el anterior.

				JugadorNuevo->setSpriteCorazon2Vidas();
				VentanaJuego->draw(JugadorNuevo->getSpriteCorazon2Vidas());
				VentanaJuego->draw(JugadorNuevo->getSpriteCorazon());

			}

			if (JugadorNuevo->getVidas() == 0) {//Si no se tienen más vidas, se quitan los Sprites y se termina el juego.

				JugadorNuevo->setSpriteCorazon1Vida();
				VentanaJuego->draw(JugadorNuevo->getSpriteCorazon());
				GameStart = false;
				GameOver.play();

			}

			if (Puntos > 0) {

				VentanaJuego->draw(*MisPuntos); 

			}

			VentanaJuego->display();

		}


		while (GameStart == false) { //Pantalla del Game Over.

			EventosDelJuego();

			PuntosFinales = Puntos;

			S_Continuar.setPosition(250, 430);

			*StringPuntos = to_string(PuntosFinales);

			setStringPuntos();

			MisPuntos->setString(*StringPuntos);  

			VentanaJuego->draw(S_GameOver); 

			VentanaJuego->draw(*MisPuntos);

			VentanaJuego->draw(S_Continuar);

			VentanaJuego->draw(S_Puntero); 

			VentanaJuego->display();

		}

	}

}



void Juego::EventosDelJuego() {

	while (VentanaJuego->pollEvent(*EventosJuego)) {

		switch (EventosJuego->type) {
		
		case Event::Closed:

			VentanaJuego->close();

		break;
		

		case Event::MouseMoved:

			S_Puntero.setPosition((Vector2f)Mouse::getPosition(*VentanaJuego));

		break;


		case Event::MouseButtonPressed:

			Click.play();

			FloatRect Pos(S_Puntero.getPosition(), (Vector2f)S_Puntero.getTexture()->getSize());

			if (getSpriteContinue().getGlobalBounds().intersects(Pos)) { //En este caso, si se presiona "Continuar", se reinician los valores del Juego para jugar de nuevo.

				GameStart = true;
				JugadorNuevo->setRestartVidas();
				JugadorNuevo->SetPosition(Vector2f(400.0f, 462.0f));
				UpdatePosicion = 400;
				setRestartTiempo();
				setRestartPuntos();
				VentanaJuego->clear();

			}

			if(S_SeleccionInstrucciones.getGlobalBounds().intersects(Pos)) { //Me permite acceder a la pantalla con las Instrucciones.
				Instrucciones = true;

			}


			if (S_Comenzar.getGlobalBounds().intersects(Pos)) { //Me permite inicier al juego.
				Intro = false;
				SonidoGame.setVolume(100);

			}

			if (S_Volver.getGlobalBounds().intersects(Pos)) { //Me permite volver a la pantalla principal.

				Instrucciones = false;

			}
		
			break;
	
		}
	
	}

}



void Juego::Texturas() {

	T_Background.loadFromFile("Background.png");
	S_Background.setTexture(T_Background);

	T_GameOver.loadFromFile("GameOver.png");
	S_GameOver.setTexture(T_GameOver);

	T_Puntero.loadFromFile("Puntero.png");
	S_Puntero.setTexture(T_Puntero);

	T_Continuar.loadFromFile("Continuar.png");
	S_Continuar.setTexture(T_Continuar);

	T_Logo.loadFromFile("Runa Games.png");
	S_Logo.setTexture(T_Logo);
	
	T_UniLogo.loadFromFile("Logo2.png");
	S_UniLogo.setTexture(T_UniLogo);

	T_MainMenu.loadFromFile("Intro.png");
	S_MainMenu.setTexture(T_MainMenu);

	T_Comenzar.loadFromFile("Comenzar.png");
	S_Comenzar.setTexture(T_Comenzar);

	T_Instrucciones.loadFromFile("PantallaInstrucciones.png");
	S_Instrucciones.setTexture(T_Instrucciones);

	T_SeleccionInstrucciones.loadFromFile("Instrucciones.png");
	S_SeleccionInstrucciones.setTexture(T_SeleccionInstrucciones);

	T_Volver.loadFromFile("Volver.png");
	S_Volver.setTexture(T_Volver);

}


void Juego::setStringPuntos() { //Cambia el tamaño y la posición de los Puntos.

	MisPuntos->setPosition(370, 285);
	MisPuntos->setScale(1.50, 1.50);

}


void Juego::Sonidos() {

	Buffer1.loadFromFile("Rebote.wav");
	Rebote.setBuffer(Buffer1);

	Buffer2.loadFromFile("Bell.wav");
	Bell1.setBuffer(Buffer2);

	Buffer3.loadFromFile("Bell2.wav");
	Bell2.setBuffer(Buffer3);

	Buffer4.loadFromFile("Explosion.wav");
	Explosion.setBuffer(Buffer4);

	Buffer5.loadFromFile("GameOver.wav");
	GameOver.setBuffer(Buffer5);

	Buffer6.loadFromFile("Click.wav");
	Click.setBuffer(Buffer6);

	SonidoIntro.openFromFile("Intro.wav");

	SonidoGame.openFromFile("Game.wav");

}

void Juego::setRestartTiempo() {

	Tiempo = 0;
	Cronometro->restart();

}



void Juego::setRestartPuntos() {

	Puntos = 0;
	PuntosFinales = 0;

}
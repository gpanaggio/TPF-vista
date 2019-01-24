#pragma once
#include "GraficObjectPlayer.h"
#include "GraficObjectEnemy.h"
#include "GraficObjectProjectile.h"
#include <iostream>
#include <map>
//prueba
using namespace std;

class DRAW
{
public:
	DRAW();
	~DRAW();
//	bool init();
	void createObjGraf(double ID, PLAYER_TYPE type);						// crea un objeto grafico del tipo deseado y se lo añade al mapa de objetos
	void createObjGraf(double ID, ENEMY_TYPE type);
	void createObjGraf(double ID, PROYECTILE_TYPE type);
	template <typename T> void startDraw(T state, double ID, Direction dir, POINT pos);		// inicia la secuencia de dibujo de un objeto grafico
	void draw();															// esta funcion refresca los objetos graficos activos

private:
	map<double, Obj_Graf> mapObjGraf;									// mapa de objetos graficos
};
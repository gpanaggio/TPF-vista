#pragma once
#include "GraficObject.h"

enum PROYECTILE_TYPE {SNOW, FIRE, BALL};		// ¿la bola es un proyectil?

enum PROYECTILE_STATE {MOVING, DECAYING};					// el proyectil decae cuando se detiene a los 3 casilleros y se cae

#define MOVE_RATIO_FIRE	(0.1)					// segundos que le tarda al proyectil recorrer un casillero
#define VEL_FIRE	(BLOCK_SIZE/(FPS*MOVE_RATIO_FIRE))
#define MOVE_RATIO_SNOW	(0.1)
#define VEL_SNOW	(BLOCK_SIZE/(FPS*MOVE_RATIO_SNOW))
#define MOVE_RATIO_BALL	(0.05)
#define VEL_BALL	(BLOCK_SIZE/(FPS*MOVE_RATIO_SNOW))

#define SNOW_PICS	NULL
#define FIRE_PICS	NULL
#define BALL_PICS	NULL						// cantidad de imagenes de cada una para saber repetir el ciclo


class Obj_Graf_Projectile :
	public Obj_Graf
{
public:
	Obj_Graf_Projectile();
	Obj_Graf_Projectile(double ID, PROYECTILE_TYPE type);
	~Obj_Graf_Projectile();

	void draw();
	void hit();
	void startDraw(Direction dir, void *state, POINT pos);

private:
	PROYECTILE_TYPE type;
	PROYECTILE_STATE state;
	void loadBitmap(PROYECTILE_TYPE type);										// dependiendo del enemigo se le cargan determinadas imagenes
};


#pragma once
#include "GraficObject.h"

enum ENEMY_TYPE {PURPLE, FATTY, CRAZY};

enum ENEMY_STATE { WALKING, JUMPING, IDLE, TRAPPED, ATTACKING, FALLING };				// algunos montruos no atacan

class Obj_Graf_Enemy :
	public Obj_Graf
{
public:
	Obj_Graf_Enemy();
	Obj_Graf_Enemy(double ID, ENEMY_TYPE type);		// luego tengo que ver como arreglo que me entrenen con un ENEMY_TYPE
	~Obj_Graf_Enemy();

	void draw();
	void startDraw(Direction dir, void *estado, POINT pos);

private:
	ENEMY_TYPE type;
	ENEMY_STATE state;
	void loadBitmap(ENEMY_TYPE type);										// dependiendo del enemigo se le cargan determinadas imagenes
};


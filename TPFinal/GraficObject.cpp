#include "GraficObject.h"

Obj_Graf::Obj_Graf()
{

}

Obj_Graf::Obj_Graf(double ID)
{
	this->ID = ID;
//	this->InitalPos = InitialPos;
}





//void Obj_Graf::startDraw(Direction dir, STATE state, POINT pos)
//{
//	this->active = true;
//	this->dir = dir;
//	this->pos = pos;
//    this->state = state;
//	this->actualImage = 0;			// comienza con la primera imagen
//}


Obj_Graf::~Obj_Graf()
{}

void Obj_Graf::setID(double ID)
{
	this->ID = ID;
}

void Obj_Graf::setPos(POINT p)
{
	this->pos = p;
}

void Obj_Graf::setPos(double x, double y)
{
	POINT p(x, y);
	this->pos = p;
}

void Obj_Graf::setInitalPos(POINT pos)
{
	this->InitalPos = pos;
}

bool Obj_Graf::isActive()
{
	return this->active;
}
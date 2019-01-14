#include "GraficObjectProjectile.h"



Obj_Graf_Projectile::Obj_Graf_Projectile()
{
}


Obj_Graf_Projectile::Obj_Graf_Projectile(double ID, PROYECTILE_TYPE type) : Obj_Graf(ID)
{
	this->actualImage = 0;
	loadBitmap(type);
	this->type = type;
	switch (type)
	{
	case SNOW:
		this->velX = VEL_SNOW;
		break;
	case FIRE:
		this->velX = VEL_FIRE;
		break;
	case BALL:
		this->velX = VEL_BALL;
		break;
	}
}

Obj_Graf_Projectile::~Obj_Graf_Projectile()
{
}

void Obj_Graf_Projectile::draw()
{
	switch (this->type)
	{
	case SNOW:
		switch (this->dir)														// segun la direccion voy a espejar o no
		{
		case Direction::Left:
			switch (this->state)
			{
			case MOVING:
				if (this->pos.get_x_coord() <= (this->InitalPos.get_x_coord() - BLOCK_SIZE))
				{
					this->pos.set_x_coord(this->InitalPos.get_x_coord() - BLOCK_SIZE);
					this->active = false;
					al_draw_bitmap(this->images[this->state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), NULL);
				}
				else
				{
					al_draw_bitmap(this->images[state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), NULL);
					this->pos.set_x_coord(this->pos.get_x_coord() - this->velX);
					(this->actualImage <= SNOW_PICS) ? this->actualImage++ : this->actualImage = 0;
				}
				break;
			case DECAYING:
				// FALTA
				break;
			}
			break;
		case Direction::Right:
			switch (this->state)
			{
			case MOVING:
				if (this->pos.get_x_coord() <= (this->InitalPos.get_x_coord() - BLOCK_SIZE))
				{
					this->pos.set_x_coord(this->InitalPos.get_x_coord() - BLOCK_SIZE);
					this->active = false;
					al_draw_bitmap(this->images[this->state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), ALLEGRO_FLIP_HORIZONTAL);
				}
				else
				{
					al_draw_bitmap(this->images[state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), ALLEGRO_FLIP_HORIZONTAL);
					this->pos.set_x_coord(this->pos.get_x_coord() - this->velX);
					(this->actualImage <= SNOW_PICS) ? this->actualImage++ : this->actualImage = 0;
				}
				break;
			case DECAYING:
				// FALTA
				break;
			}
			break;
		}

	case FIRE:
		switch (this->dir)														// segun la direccion voy a espejar o no
		{
		case Direction::Left:
			switch (this->state)
			{
			case MOVING:
				if (this->pos.get_x_coord() <= (this->InitalPos.get_x_coord() - BLOCK_SIZE))
				{
					this->pos.set_x_coord(this->InitalPos.get_x_coord() - BLOCK_SIZE);
					this->active = false;
					al_draw_bitmap(this->images[this->state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), NULL);
				}
				else
				{
					al_draw_bitmap(this->images[state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), NULL);
					this->pos.set_x_coord(this->pos.get_x_coord() - this->velX);
					(this->actualImage <= FIRE_PICS) ? this->actualImage++ : this->actualImage = 0;
				}
				break;
			case DECAYING:
				// FALTA
				break;
			}
			break;
		case Direction::Right:
			switch (this->state)
			{
			case MOVING:
				if (this->pos.get_x_coord() <= (this->InitalPos.get_x_coord() - BLOCK_SIZE))
				{
					this->pos.set_x_coord(this->InitalPos.get_x_coord() - BLOCK_SIZE);
					this->active = false;
					al_draw_bitmap(this->images[this->state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), ALLEGRO_FLIP_HORIZONTAL);
				}
				else
				{
					al_draw_bitmap(this->images[state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), ALLEGRO_FLIP_HORIZONTAL);
					this->pos.set_x_coord(this->pos.get_x_coord() - this->velX);
					(this->actualImage <= FIRE_PICS) ? this->actualImage++ : this->actualImage = 0;
				}
				break;
			case DECAYING:
				// FALTA
				break;
			}
			break;
		}

	case BALL:
		//switch (this->dir)														// segun la direccion voy a espejar o no
		//{
		//case Direction::Left:
		//{
		//	if (this->pos.get_x_coord() <= (this->InitalPos.get_x_coord() - BLOCK_SIZE))
		//	{
		//		this->pos.set_x_coord(this->InitalPos.get_x_coord() - BLOCK_SIZE);
		//		this->isActive = false;
		//		al_draw_bitmap(this->images[this->state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), NULL);
		//	}
		//	else
		//	{
		//		al_draw_bitmap(this->images[state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), NULL);
		//		this->pos.set_x_coord(this->pos.get_x_coord - this->velX);
		//		(this->actualImage <= BALL_PICS) ? this->actualImage++ : this->actualImage = 0;
		//	}
		//	break;
		//}
		//case Direction::Right:
		//{
		//	if (this->pos.get_x_coord() <= (this->InitalPos.get_x_coord() - BLOCK_SIZE))
		//	{
		//		this->pos.set_x_coord(this->InitalPos.get_x_coord() - BLOCK_SIZE);
		//		this->isActive = false;
		//		al_draw_bitmap(this->images[this->state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), ALLEGRO_FLIP_HORIZONTAL);
		//	}
		//	else
		//	{
		//		al_draw_bitmap(this->images[state][this->actualImage], this->pos.get_x_coord(), this->pos.get_y_coord(), ALLEGRO_FLIP_HORIZONTAL);
		//		this->pos.set_x_coord(this->pos.get_x_coord - this->velX);
		//		(this->actualImage <= BALL_PICS) ? this->actualImage++ : this->actualImage = 0;
		//	}
		//	break;
		//}
		//}
		break;
	}
}

void Obj_Graf_Projectile::startDraw(Direction dir, void *state, POINT pos)
{
	this->active = true;
	this->dir = dir;
	this->pos = pos;
	this->InitalPos = pos;
	this->state = *(PROYECTILE_STATE *)state;
	this->actualImage = 0;			// comienza con la primera imagen
}

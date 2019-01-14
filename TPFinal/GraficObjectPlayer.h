#pragma once
#include "GraficObject.h"

#define WALKING_PICS	(20)				// cantidad de imagenes del personaje caminando
#define JUMPING_PICS	(10)
#define ATTACKING_PICS	(3)
#define IDLE_PICS		(1)
#define FALLING_PICS	(1)

#define MOVE_RATIO	(0.3)							// segundos que tarda el personaje en recorrer un bloque
#define VELOCITY_X (BLOCK_SIZE/(FPS*MOVE_RATIO))	// pixeles que va a recorrer el personaje por cada frame de refresco

#define FOLDER_CHARA	("characters")				// carpeta donde estan contenidas todas las imagenes de los personajes
#define FOLDER_TOM		("TOM")						// carpeta para cada personaje en particular
#define FOLDER_NICK		("NICK")
#define FOLDER_WALKING	("WALKING")					// carpetas que vas a contener imagenes de una categoria
#define FOLDER_JUMPING	("JUMPING")
#define FOLDER_IDLE		("IDLE")
#define FOLDER_ATTACKING	("ATTACKING")
#define FOLDER_FALLING		("FALLING")
#define FILE_TOM_WALKING	("homerdance-F")			// nombre generico de los archivos .png de tom caminando
#define FILE_TOM_JUMPING	("Super Mario Running-F")
#define FILE_TOM_IDLE		("tomIdle-F")
#define FILE_TOM_ATTACKING	("Explosion 2-F")
#define FILE_TOM_FALLING	("Sonic Running-F")
#define FILE_NICK_WALKING	("nickWalk-F")			// nombre generico de los archivos png de tom caminando
#define FILE_NICK_JUMPING	("nickJump-F")
#define FILE_NICK_IDLE		("nickIdle-F")
#define FILE_NICK_ATTACKING	("nickAttack-F")
#define FILE_NICK_FALLING	("nickFall-F")

enum PLAYER_TYPE { TOM, NICK };

enum PLAYER_STATE { player_WALKING, player_JUMPING, JUMPING_FOWARD, player_IDLE, player_ATTACKING, player_FALLING };


class Obj_Graf_Player :
	public Obj_Graf
{
public:
	Obj_Graf_Player();
	Obj_Graf_Player(double ID, PLAYER_TYPE type);		// se setea la velorcidad del player
	~Obj_Graf_Player();

	void draw();
	void startDraw(Direction dir, void *estado, POINT pos);

private:
	PLAYER_STATE state;
	PLAYER_TYPE type;
	void loadBitmap(PLAYER_TYPE type);						// se pasa el tipo para saber que imagenes cargar
};
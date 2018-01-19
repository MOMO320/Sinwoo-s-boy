#include "stdafx.h"
#include "Select_character.h"


Select_character::Select_character()
{
}


Select_character::~Select_character()
{
}

HRESULT Select_character::init()		 
{

	return S_OK;
}
void Select_character::release()		 
{
}
void Select_character::update()			 
{
}
void Select_character::render()			 
{
	SelectTile::render();


}

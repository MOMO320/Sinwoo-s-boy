#include "stdafx.h"
#include "Select_Event.h"


Select_Event::Select_Event()
{
}


Select_Event::~Select_Event()
{
}


HRESULT Select_Event::init()		 
{

	return S_OK;
}
void Select_Event::release()		 
{
}
void Select_Event::update()			 
{
}
void Select_Event::render()			
{
	SelectTile::render();


}

#ifndef	RESOURCES_H
#define RESOURCES_H

#include "olcPixelGameEngine.h"

class Resources
{
	Resources();

public:
	static Resources& get()
	{
		static Resources res;
		return res;
	}

	Resources(Resources&&) = delete;
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	Resources& operator=(Resources&&) = delete;

	//Main
	olc::Renderable mainLogo;
	olc::Renderable pressStart;
	olc::Renderable playerOnePress;
	olc::Renderable playerTwoPress;

	//Inventory
	olc::Renderable slot;
	olc::Renderable empty_slot;
	olc::Renderable bronze_coin;
	olc::Renderable grenade;

	//Tanks
	olc::Renderable base;
	olc::Renderable turret;

	//Weapons
	olc::Renderable projectileCircle;
};


#endif
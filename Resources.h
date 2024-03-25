#ifndef	RESOURCES_H
#define RESOURCES_H

#include "olcPixelGameEngine.h"

#define SCALE_256 0.25f

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

	olc::Renderable playerOneWins;
	olc::Renderable playerTwoWins;

	//Inventory
	olc::Renderable slot;
	olc::Renderable empty_slot;
	olc::Renderable bronze_coin;
	olc::Renderable grenade;
	olc::Renderable ammo;
	olc::Renderable ammoSilver;
	olc::Renderable	hpPotion;

	//Tanks
	olc::Renderable base;
	olc::Renderable turret;

	//Weapons
	olc::Renderable projectileCircle;
	olc::Renderable rocketBasic;

	//Effects
	olc::Renderable explodeEffect;
	olc::Renderable hpGainEffect;
	olc::Renderable inventoryFullEffect;
	olc::Renderable muzzleFlash;
	olc::Renderable muzzleFlashMirrored;
	olc::Renderable crosshair;

	//Collision Masks
	olc::Renderable explodeMask;
	olc::Renderable HitMarker;

	//Powerups
	olc::Renderable speedPowerup;
	olc::Renderable swapPowerup;

	//Particles
	olc::Renderable PartRing;
	olc::Renderable PartCircle;
	olc::Renderable PartSmoke;
	olc::Renderable PartExplosionCenter;
};


#endif
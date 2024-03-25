#include "Resources.h"

Resources::Resources()
{
	mainLogo.Load("./gfx/Laser Drift 2 logo 2.png");
	pressStart.Load("./gfx/press start.png");
	playerOnePress.Load("./gfx/playerOnePress.png");
	playerTwoPress.Load("./gfx/playerTwoPress.png");
	playerOneWins.Load("./gfx/playerOneWins.png");
	playerTwoWins.Load("./gfx/playerTwoWins.png");

	slot.Load("./gfx/InventoryItems/slot.png");
	empty_slot.Load("./gfx/InventoryItems/empty_slot.png");
	bronze_coin.Load("./gfx/InventoryItems/bronze_coin.png");
	grenade.Load("./gfx/InventoryItems/grenade.png");
	ammo.Load("./gfx/InventoryItems/ammo.png");
	ammoSilver.Load("./gfx/InventoryItems/bullets_silver.png");
	hpPotion.Load("./gfx/InventoryItems/large_red_potion.png");

	base.Load("./gfx/base.png");
	turret.Load("./gfx/turret.png");

	projectileCircle.Load("./gfx/circle.png");
	rocketBasic.Load("./gfx/rocketBasic.png");

	crosshair.Load("./gfx/crosshair.png");
	explodeEffect.Load("./gfx/yellow_explode_01-sheet.png");
	explodeMask.Load("./gfx/explosionMask.png");
	muzzleFlash.Load("./gfx/Particles/muzzleFlash.png");
	muzzleFlashMirrored.Load("./gfx/Particles/muzzleFlashMirror.png");
	HitMarker.Load("./gfx/HitMarker.png");

	hpGainEffect.Load("./gfx/hpGainEffect.png");
	inventoryFullEffect.Load("./gfx/inventoryFull.png");

	speedPowerup.Load("./gfx/speedPowerup.png");
	swapPowerup.Load("./gfx/reverse.png");

	//Particles
	PartRing.Load("./gfx/Particles/Ring.png");
	PartCircle.Load("./gfx/Particles/Circle.png");
	PartSmoke.Load("./gfx/Particles/Smoke.png");
	PartExplosionCenter.Load("./gfx/Particles/explode.png");
}
#include "Resources.h"

Resources::Resources()
{
	mainLogo.Load("./gfx/Laser Drift 2 logo 2.png");
	pressStart.Load("./gfx/press start.png");
	playerOnePress.Load("./gfx/playerOnePress.png");
	playerTwoPress.Load("./gfx/playerTwoPress.png");
	HitMarker.Load("./gfx/HitMarker.png");

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

	explodeEffect.Load("./gfx/yellow_explode_01-sheet.png");
	explodeMask.Load("./gfx/explosionMask.png");

	hpGainEffect.Load("./gfx/hpGainEffect.png");
}
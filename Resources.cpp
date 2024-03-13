#include "Resources.h"

Resources::Resources()
{
	mainLogo.Load("./gfx/Laser Drift 2 logo 2.png");
	pressStart.Load("./gfx/press start.png");
	playerOnePress.Load("./gfx/playerOnePress.png");
	playerTwoPress.Load("./gfx/playerTwoPress.png");

	slot.Load("./gfx/InventoryItems/slot.png");
	empty_slot.Load("./gfx/InventoryItems/empty_slot.png");
	bronze_coin.Load("./gfx/InventoryItems/bronze_coin.png");
	grenade.Load("./gfx/InventoryItems/grenade.png");

	base.Load("./gfx/base.png");
	turret.Load("./gfx/turret.png");

	projectileCircle.Load("./gfx/circle.png");

	explodeEffect.Load("./gfx/yellow_explode_01-sheet.png");
	explodeMask.Load("./gfx/explosionMask.png");
}
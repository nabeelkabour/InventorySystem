#include "Game.h"
#include "Player.h"
#include "Actor.h"
#include "Collision.h"
#include "HitSplat.h"
#include "Items.h"
#include "Pickup.h"
#include "GameOver.h"

Player::Player(PlayerID id, olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, olc::GamePad* _gamepad, std::string name) : 
	Actor(pos, hp, hpMax, spr, name),
	gamepad(_gamepad),
	playerId(id)
{
	switch (id)
	{
	case PlayerID::ONE:
		colorBase = olc::CYAN;
		colorTurret = olc::BLUE;
		break;

	case PlayerID::TWO:
		colorBase = olc::RED;
		colorTurret = olc::YELLOW;
		break;
	}

	scale = { 0.2f, 0.2f };

	uint8_t numGrenades = 4;
	for (uint8_t i = 0; i < 3; ++i)
	{
		if (playerInventory.GainItem(ItemIndex::itemIndex[ItemId::GRENADE]))
		{
			--numGrenades;
		}
		else
		{
			std::cout << "Not enough inventory." << std::endl;
			std::cout << (uint32_t)numGrenades;
			break;
		}
	}

	playerInventory.GainItem(ItemIndex::itemIndex[ItemId::AMMOSILVER]);
	playerInventory.GainItem(ItemIndex::itemIndex[ItemId::AMMO]);
}

void Player::Update(float fElapsedTime)
{
	//Player Input
	if (gamepad->getButton(olc::GPButtons::DPAD_L).bPressed)
	{
		playerInventory.MoveSelectLeft();
	}

	if (gamepad->getButton(olc::GPButtons::DPAD_R).bPressed)
	{
		playerInventory.MoveSelectRight();
	}

	if (gamepad->getButton(olc::GPButtons::FACE_D).bPressed)
	{
		//Select Item
		playerInventory.selectItem();
	}

	if (gamepad->getButton(olc::GPButtons::R2).bPressed)
	{
		if (playerInventory.inventory[playerInventory.selected].amount > 0)
		{
			playerInventory.inventory[playerInventory.selected].use(this, game.GetOpponent(this));

			playerInventory.inventory[playerInventory.selected].amount--;
			if (playerInventory.inventory[playerInventory.selected].amount <= 0)
			{
				playerInventory.inventory[playerInventory.selected] = ItemIndex::itemIndex[ItemId::NONE];
			}
		}
	}

	if (gamepad->getButton(olc::GPButtons::FACE_R).bPressed)
	{
		//Create item and empty slot.
		Actor* dropItem = new ItemPickup(position, playerInventory.inventory[playerInventory.selected]);
		game.entitiesManifested.push_back(dropItem);
		game.actors.push_back(dropItem);

		playerInventory.inventory[playerInventory.selected] = ItemIndex::itemIndex[ItemId::NONE];
	}

	ManifestedEntity::Update(fElapsedTime);

	float gamepadX = gamepad->getAxis(olc::GPAxes::LX);
	float gamepadY = gamepad->getAxis(olc::GPAxes::LY);
	olc::vf2d velocity = { gamepadX, gamepadY };
	float velocityMag = velocity.mag();

	olc::vf2d vel = velocity;
	if (velocityMag > 1.f) vel = velocity.norm();
	position += vel * fElapsedTime * speed;
	if (position.x > game.ScreenWidth()) position.x = float(game.ScreenWidth());
	if (position.x < 0.f) position.x = 0.f;
	if (position.y > game.ScreenHeight()) position.y = float(game.ScreenHeight());
	if (position.y < 0.f) position.y = 0.f;

	for (Actor* other : game.actors)
	{
		if (other == this or !other->collidable) continue;

		if (CollidesWith(other))
		{
			other->Collide(this);
		}
	}
}

void Player::Draw(float fElaspedTime) 
{
	float gamepadTurretX = gamepad->getAxis(olc::GPAxes::RX);
	float gamepadTurretY = gamepad->getAxis(olc::GPAxes::RY);

	//float turretAngle = 0.f;

	if (playerId == PlayerID::TWO and gamepadTurretX == 0.f and gamepadTurretY == 0.f)
	{
		turretAngle = 3.14159f;
	}
	else
	{
		olc::vf2d turretVector = { gamepadTurretX, gamepadTurretY };
		if (turretVector.mag() > 1.f) turretVector = turretVector.norm();
		turretAngle = atan2(turretVector.y, turretVector.x);
	}

	game.DrawRotatedDecal(position, Resources::get().base.Decal(), 0.f, { 256.f / 2.f, 256.f / 2.f }, scale, colorBase);
	game.DrawRotatedDecal(position, Resources::get().turret.Decal(), turretAngle, { 0.f, 32.f }, scale, colorTurret);

	float posX = 0.f;

	switch (playerId)
	{
	case PlayerID::ONE:
		posX = 25.f;
		break;

	case PlayerID::TWO:
		posX = float(game.ScreenWidth()) * 0.65f;
		break;
	}

	playerInventory.Draw(posX, 0.f);

	//Draw hp bar
#define HP_BAR_HEIGHT 15.f
#define HP_BAR_WIDTH 300.f
	switch (playerId)
	{
	case PlayerID::ONE:
		game.FillRectDecal(
			{ 0.f, game.ScreenHeight() - HP_BAR_HEIGHT },
			{ float(hp), game.ScreenHeight() - HP_BAR_HEIGHT },
			colorBase
		);
		break;

	case PlayerID::TWO:
		game.FillRectDecal(
			{ float(game.ScreenWidth()) - float(hp), game.ScreenHeight() - HP_BAR_HEIGHT },
			{ float(game.ScreenWidth()), game.ScreenHeight() - HP_BAR_HEIGHT },
			colorBase
		);
		break;
	}
}

void Player::Collide(Player* player)
{
	playerCollideCooldown += game.GetElapsedTime();

	if (playerCollideCooldown >= 2.f)
	{
		player->Damage(15.f);
		//player->hp--;

		game.entitiesManifested.push_back(new HitSplat(player->position, 15));

		playerCollideCooldown = 0.f;
	}
}

void Player::Damage(float damage)
{
	hp -= damage;

	if (hp <= 0.f)
	{
		game.LevelChange(new LMainMenu);
	}
}
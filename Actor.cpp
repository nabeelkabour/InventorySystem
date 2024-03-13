#include "Game.h"
#include "Actor.h"

Actor::Actor(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, std::string name) : 
	ManifestedEntity(pos, spr),
	hp(hp),
	hpMax(hpMax),
	name(name)
{}


//bool Actor::CollidesWith(Actor* other)
//{	// Possibly add check for nullptr
//	return other->position.x + (other->spr->sprite->width * other->scale.x) >= position.x and
//		other->position.x <= position.x + (spr->sprite->width * scale.x) and
//		other->position.y + (other->spr->sprite->height * other->scale.y) >= position.y and
//		other->position.y <= (position.y + spr->sprite->height * scale.y);
//}

bool Actor::CollidesWith(Actor* other)
{	// Possibly add check for nullptr
	//float otherPosX = other->position.x;
	//float otherPosY = other->position.y;
	//float posX = position.x;
	//float posY = position.y;

	//game.FillRectDecal({ other->position.x + (other->spr->sprite->width / 2 * other->scale.x), other->position.y + (other->spr->sprite->height / 2 * other->scale.y) },
	//	{ posX + (spr->sprite->width / 2.f * scale.x), other->spr->sprite->height * other->scale.y },
	//	olc::Pixel(255, 255, 255, 100)
	//);

	return other->position.x + (other->spr->sprite->width / 2.f * other->scale.x) >= position.x - (spr->sprite->width / 2.f * scale.x) and
		other->position.x - (other->spr->sprite->width / 2.f * other->scale.x) <= position.x + (spr->sprite->width / 2.f * scale.x) and
		other->position.y + (other->spr->sprite->height / 2.f * other->scale.y) >= position.y - spr->sprite->height / 2.f * scale.y and
		other->position.y - (other->spr->sprite->height / 2.f * other->scale.y) <= (position.y + spr->sprite->height / 2.f * scale.y);
}

//bool Actor::CollidesWith(Actor* other, float scaleSelf, float scaleOther)
//{	// Possibly add check for nullptr
//	return other->position.x + (other->spr->sprite->width * scaleOther) >= position.x and
//		other->position.x <= position.x + (spr->sprite->width * scaleSelf) and
//		other->position.y + (other->spr->sprite->height * scaleOther) >= position.y and
//		other->position.y <= (position.y + spr->sprite->height * scaleSelf);
//}

//void Actor::Collide(Player* player)
//{
//
//}
#include "Actor.h"

Actor::Actor(olc::vf2d pos, int32_t hp, int32_t hpMax, olc::Decal* spr, std::string name) : 
	ManifestedEntity(pos, spr),
	hp(hp),
	hpMax(hpMax),
	name(name)
{}


bool Actor::CollidesWith(Actor* other)
{	// Possibly add check for nullptr
	return other->position.x + (other->spr->sprite->width * other->scale.x) >= position.x and
		other->position.x <= position.x + (spr->sprite->width * scale.x) and
		other->position.y + (other->spr->sprite->height * other->scale.y) >= position.y and
		other->position.y <= (position.y + spr->sprite->height * scale.y);
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
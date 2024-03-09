#ifndef ENTITY_H
#define ENTITY_H

//Entities are anything 
class Entity
{
public:
	bool persistent = false;
	bool remove_flag = false;

	virtual void Create() = 0;
	virtual void Update(float fElapsedTime) = 0;
};

#endif
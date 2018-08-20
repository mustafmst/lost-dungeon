#pragma once
#include "Box2D/Box2D.h"
namespace ld
{

class GoldContactListener : public b2ContactListener
{
public:
	GoldContactListener(){};
	~GoldContactListener(){};
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

}


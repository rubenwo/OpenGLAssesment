#pragma once
#include "SimulationObject.hpp"

class SimulationObject;

class Component
{
protected:
	SimulationObject* simulation_object_;
public:
	Component();
	~Component();

	virtual void update(float elapsedTime)
	{
	};

	inline void setGameObject(SimulationObject* simulation_object) { this->simulation_object_ = simulation_object_; }
};

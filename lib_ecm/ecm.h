#pragma once
#include "maths.h"
#include <algorithm>
#include <memory>
#include <typeindex>
#include <vector>

class Entity {
protected:
	std::vector<std::shared_ptr<Component>> _components;
	sf::Vector2f _position;
	float _rotation;	// where face?
	bool _alive;		// update this?
	bool _visible;		// render this?
	bool _fordeletion;	// delete this?

public:
	Entity();
	virtual ~Entity();
	virtual void update(double dt);
	virtual void render();
	
	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &_position);
		
	float getRotation() const;
	void setRotation(float _rotation);
	
	bool isAlive() const;
	void setAlive(bool _alive);
	
	bool isVisible() const;
	void setVisible(bool _visible);
	
	bool is_fordeletion() const;
	void setForDelete(bool _fordeletion);
};

class Component {
protected:
	Entity *const _parent;
	bool _fordeletion; // delete this?
	explicit Component(Entity *const p);
	
public:
	Component() = delete;
	bool is_fordeletion() const;
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Component;
};
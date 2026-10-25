#pragma once
#include "Transform.h"
#include "Mesh.h"
#include <DirectXMath.h>
#include <memory>
class GameEntity {
public:
	Transform objectTransform;
	std::shared_ptr<Mesh> meshPointer;

	GameEntity(Mesh givenMesh);

	std::shared_ptr<Mesh> GetMesh();
	Transform* GetTransform();
};
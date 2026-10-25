#include "GameEntity.h"

GameEntity::GameEntity(Mesh givenMesh) {
	meshPointer = std::make_shared<Mesh>(givenMesh);
}

std::shared_ptr<Mesh> GameEntity::GetMesh() {
	return meshPointer;
}

Transform* GameEntity::GetTransform() {
	return &objectTransform;
}
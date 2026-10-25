#include "Transform.h"

using namespace DirectX;

Transform::Transform() {
	XMStoreFloat4x4(&world, XMMatrixIdentity());
	XMStoreFloat4x4(&worldInverseTranspose, XMMatrixIdentity());
	position = { 0,0,0 };
	rotation = { 0,0,0 };
	scale = { 1,1,1 };
}

void Transform::SetPosition(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;

	GetWorldMatrix();
}

void Transform::SetPosition(XMFLOAT3 givenPosiiton) {
	position.x = givenPosiiton.x;
	position.y = givenPosiiton.y;
	position.z = givenPosiiton.z;

	GetWorldMatrix();
}

void Transform::SetRotation(float pitch, float yaw, float roll) {
	rotation.x = pitch;
	rotation.y = yaw;
	rotation.z = roll;

	GetWorldMatrix();
}

void Transform::SetRotation(XMFLOAT3 givenRotation) {
	rotation.x = givenRotation.x;
	rotation.y = givenRotation.y;
	rotation.z = givenRotation.z;

	GetWorldMatrix();
}

void Transform::SetScale(float x, float y, float z) {
	scale.x = x;
	scale.y = y;
	scale.z = z;

	GetWorldMatrix();
}

void Transform::SetScale(XMFLOAT3 givenScale) {
	scale.x = givenScale.x;
	scale.y = givenScale.y;
	scale.z = givenScale.z;

	GetWorldMatrix();
}

XMFLOAT3 Transform::GetPosition() {
	return position;
}
XMFLOAT3 Transform::GetPitchYawRoll() {
	return rotation;
}
XMFLOAT3 Transform::GetScale() {
	return scale;
}

XMFLOAT4X4 Transform::GetWorldMatrix() {
	XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);
	XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
	XMMATRIX translationMatrix = XMMatrixTranslation(position.x, position.y, position.z);

	XMMATRIX worldMatrix = scaleMatrix * rotationMatrix * translationMatrix;

	XMStoreFloat4x4(&world, worldMatrix);
	XMStoreFloat4x4(&worldInverseTranspose, XMMatrixInverse(0, XMMatrixTranspose(worldMatrix)));

	return world;
}

XMFLOAT4X4 Transform::GetWorldInverseTransposeMatrix() {
	return worldInverseTranspose;
}

void Transform::MoveAbsolute(float x, float y, float z) {
	position.x += x;
	position.y += y;
	position.z += z;

	GetWorldMatrix();
}
void Transform::MoveAbsolute(XMFLOAT3 offset) {
	position.x += offset.x;
	position.y += offset.y;
	position.z += offset.z;

	GetWorldMatrix();
}

void Transform::Rotate(float x, float y, float z) {
	rotation.x += x;
	rotation.y += y;
	rotation.z += z;

	GetWorldMatrix();
}
void Transform::Rotate(XMFLOAT3 givenRotation) {
	rotation.x += givenRotation.x;
	rotation.y += givenRotation.y;
	rotation.z += givenRotation.z;

	GetWorldMatrix();
}

void Transform::Scale(float x, float y, float z) {
	scale.x *= x;
	scale.y *= y;
	scale.z *= z;

	GetWorldMatrix();
}
void Transform::Scale(XMFLOAT3 givenScale) {
	scale.x  *= givenScale.x;
	scale.y  *= givenScale.y;
	scale.z  *= givenScale.z;

	GetWorldMatrix();
}
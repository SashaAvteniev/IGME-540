#pragma once
#include "Transform.h"
#include <DirectXMath.h>

class Camera {
public:
	Transform cameraTransform;

	DirectX::XMFLOAT4X4 viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix;

	float FOVAngle;
	float nearClip;
	float farClip;
	float moveSpeed;
	float lookSpeed;

	bool perspective;

	Camera(float aspectRatio, DirectX::XMFLOAT3 startingPosition, float fieldOfView, float nearClipGiven, float farClipGiven, float moveSpeedGiven, float lookSpeedGiven, bool usingPerspective);

	DirectX::XMFLOAT4X4 GetViewMatrix();
	DirectX::XMFLOAT4X4 GetProjectionMatrix();

	void UpdateProjectionMatrix(float aspectRatio);
	void UpdateViewMatrix();
	void Update(float deltaTime);


};
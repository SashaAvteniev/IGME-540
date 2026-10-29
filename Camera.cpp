#include "Camera.h"

#include "Input.h"

using namespace DirectX;
Camera::Camera(float aspectRatio, DirectX::XMFLOAT3 startingPosition, float fieldOfView, float nearClipGiven, float farClipGiven, float moveSpeedGiven, float lookSpeedGiven, bool usingPerspective)
{
	cameraTransform.SetPosition(startingPosition);

	FOVAngle = fieldOfView;
	nearClip = nearClipGiven;
	farClip = farClipGiven;
	moveSpeed = moveSpeedGiven;
	lookSpeed = lookSpeedGiven;

	perspective = usingPerspective;

	UpdateViewMatrix();
	UpdateProjectionMatrix(aspectRatio);
}

DirectX::XMFLOAT4X4 Camera::GetViewMatrix()
{
	return viewMatrix;
}

DirectX::XMFLOAT4X4 Camera::GetProjectionMatrix()
{
	return projectionMatrix;
}

void Camera::UpdateProjectionMatrix(float aspectRatio)
{
	if (perspective) {
		XMMATRIX matrix = XMMatrixPerspectiveFovLH(FOVAngle, aspectRatio, nearClip, farClip);
		XMStoreFloat4x4(&projectionMatrix, matrix);
	}
	else {
		XMMATRIX matrix = XMMatrixOrthographicLH(100, 100, nearClip, farClip);
		XMStoreFloat4x4(&projectionMatrix, matrix);
	}
}

void Camera::UpdateViewMatrix()
{}

void Camera::Update(float deltaTime)
{}

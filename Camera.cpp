#include "Camera.h"
#include <iostream>
#include "Input.h"


using namespace std;
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

	cout << cameraTransform.rotation.x << "," << cameraTransform.rotation.y << "," << cameraTransform.rotation.z << endl;

}

DirectX::XMFLOAT4X4 Camera::GetViewMatrix()
{
	return viewMatrix;
}

DirectX::XMFLOAT4X4 Camera::GetProjectionMatrix()
{
	return projectionMatrix;
}

void Camera::UpdateProjectionMatrix(float aspectRatioGiven)
{
	XMMATRIX matrix = XMMatrixPerspectiveFovLH(XMConvertToRadians(FOVAngle), aspectRatioGiven, nearClip, farClip);
	XMStoreFloat4x4(&projectionMatrix, matrix);
	/*
		if (perspective) {
		XMMATRIX matrix = XMMatrixPerspectiveFovLH(FOVAngle, aspectRatio, nearClip, farClip);
		XMStoreFloat4x4(&projectionMatrix, matrix);
	}
	else {
		XMMATRIX matrix = XMMatrixOrthographicLH(100, 100, nearClip, farClip);
		XMStoreFloat4x4(&projectionMatrix, matrix);
	}
	*/

}

void Camera::UpdateViewMatrix()
{
	XMFLOAT3 positionFloats = cameraTransform.GetPosition();
	XMVECTOR positionVector = XMLoadFloat3(&positionFloats);
	XMFLOAT3 forwardFloats = cameraTransform.GetForward();
	XMVECTOR forwardVector = XMLoadFloat3(&forwardFloats);
	XMVECTOR worldUp = XMVectorSet(0, 1, 0, 0);

	XMMATRIX matrix = XMMatrixLookToLH(positionVector, forwardVector, worldUp);

	XMStoreFloat4x4(&viewMatrix, matrix);
}

void Camera::Update(float deltaTime)
{
	if (Input::KeyDown('W')) { 
		cameraTransform.MoveRelative(0, 0, moveSpeed * deltaTime);
	}

	if (Input::KeyDown('S')) { 
		cameraTransform.MoveRelative(0, 0, -moveSpeed * deltaTime);
	}

	if (Input::KeyDown('A')) { 
		cameraTransform.MoveRelative(-moveSpeed * deltaTime, 0, 0);
	}

	if (Input::KeyDown('D')) { cameraTransform.MoveRelative(moveSpeed * deltaTime, 0, 0); }

	if (Input::KeyDown('Q')) { cameraTransform.MoveRelative(0, moveSpeed * deltaTime, 0); }

	if (Input::KeyDown('E')) { cameraTransform.MoveRelative(0, -moveSpeed * deltaTime, 0); }

	if (Input::MouseLeftDown())
	{
		int cursorMovementX = Input::GetMouseXDelta();
		int cursorMovementY = Input::GetMouseYDelta();
		
		cameraTransform.Rotate(cursorMovementY * lookSpeed, cursorMovementX*lookSpeed , 0);
		
		float currentPitch = cameraTransform.rotation.x;

		if (currentPitch > (XM_PI / 2)) {
			cameraTransform.rotation.x = (XM_PI / 2);
		}
		else if (currentPitch < -(XM_PI / 2)) {
			cameraTransform.rotation.x = -(XM_PI / 2);
		}
	}

	UpdateViewMatrix();


}

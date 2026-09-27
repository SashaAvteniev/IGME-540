#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include <memory>

#include "Mesh.h"

class Game
{
public:
	// Basic OOP setup
	Game();
	~Game();
	Game(const Game&) = delete; // Remove copy constructor
	Game& operator=(const Game&) = delete; // Remove copy-assignment operator

	// Primary functions
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);
	void OnResize();
	void BuildUI();
private:

	float backgroundColor[4];
	bool showDefault = true;
	float positionVector[3] = { 0,0,0 };
	char starting[256] = "Textbox";
	// Initialization helper methods - feel free to customize, combine, remove, etc.
	void LoadShaders();
	void CreateGeometry();

	// Note the usage of ComPtr below
	//  - This is a smart pointer for objects that abide by the
	//     Component Object Model, which DirectX objects do
	//  - More info here: https://github.com/Microsoft/DirectXTK/wiki/ComPtr


	// Shaders and shader-related constructs
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;

	// Mesh's
	std::shared_ptr<Mesh> baseTriangle;
	std::shared_ptr<Mesh> squareTest;
	std::shared_ptr<Mesh> weirdTest;
};


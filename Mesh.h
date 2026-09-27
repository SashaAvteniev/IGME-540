#pragma once
#include <wrl/client.h>
#include <d3d11.h>
#include "Vertex.h"
#include "Graphics.h"

using Microsoft::WRL::ComPtr;

class Mesh {
public:
	Mesh(Vertex verteces[], int vertecesLength, unsigned int indeces[], int indecesLength);
	~Mesh();


	ComPtr<ID3D11Buffer> GetVertexBuffer();
	ComPtr<ID3D11Buffer> GetIndexBuffer();
	int GetIndexCount();
	int GetVertexCount();

	void Draw();

private:
	ComPtr<ID3D11Buffer> vertexBuffer;
	ComPtr<ID3D11Buffer> indexBuffer;

	int indexBuffIndexNum;
	int vertexBuffVertexNum;
};

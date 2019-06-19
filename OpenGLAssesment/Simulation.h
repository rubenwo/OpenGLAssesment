#pragma once

namespace Simulation
{
	struct point
	{
		float x;
		float y;
		float z;
	};

	struct face
	{
		int vtx[3];
	};

	extern int globalW, globalH;
	void LoadContent();
	void Render();
	void Idle();
	void Reshape(int w, int h);
	void OnMouseActiveMove(int x, int y);
	void OnMousePassiveMove(int x, int y);
	void OnMouseScroll(int button, int state, int x, int y);
	void OnKeyPressed(unsigned char key, int x, int y);
	void OnSpecialKey(unsigned char key, int x, int y);

	void OnClose();
}

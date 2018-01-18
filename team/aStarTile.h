#pragma once
#include "gameNode.h"
#include <string>

class aStarTile : public gameNode
{
private:
	int _idX;
	int _idY;
	POINT _center;
	int _costFromStart;
	int _costToGoal;
	int _totalCost;
	bool _isOpen;
	bool _canOn;
	aStarTile* _parentNode;
	RECT _rc;

	COLORREF _color;
	HBRUSH _brush;
	HPEN _pen;

	string _attribute;

public:
	aStarTile();
	~aStarTile();

	HRESULT init();
	void release();
	void update();
	void render();

	// x ,y �ε��� ������ ������

	void setIdX(int idx) { _idX = idx; }
	int getIdX() { return _idX; }

	void setIdY(int idY) { _idY = idY; }
	int getIdY() { return _idY; }

	// ������ Į�� ���� �Լ� 
	void setcolor(COLORREF color)
	{
		DeleteObject(_brush);
		_color = color;
		_brush = CreateSolidBrush(color);
	}

	RECT getRect() { return _rc; }

	void setCenter(POINT center) { _center.x = center.x, _center.y = center.y; }
	POINT getCenter() { return _center; }

	// �Ӽ� ������
	void setAttribute(string str) { _attribute = str; }
	string getAttribute() { return _attribute; }

	void setCostFromStart(int costFromStart) { _costFromStart = costFromStart; }
	int getCostFromStart() { return _costFromStart; }

	void setCostToGoal(int costToGoal) { _costToGoal = costToGoal; }
	int getCostToGoal() { return _costToGoal; }

	void setTotalCost(int totalCost) { _totalCost = totalCost; }
	int getTotalCost() { return _totalCost; }

	void setParentNode(aStarTile* tile) { _parentNode = tile; }
	aStarTile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

};


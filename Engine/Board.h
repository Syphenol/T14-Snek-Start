#pragma once
#include "Graphics.h"
#include "Location.h"

class Board

{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBoarder();
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	int x_offset = 30;
	int y_offset = 30;
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int padding = 10;
	static constexpr int bWidth = 4;
	static constexpr int cellPadding = 2;
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	//testesttest
	Graphics& gfx;

};
#include "Board.h"
#include <assert.h>
#include "Graphics.h"

Board::Board(Graphics & gfx)
	:
	gfx ( gfx )
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRectDim(loc.x * dimension + x_offset + cellPadding, loc.y * dimension + 
		y_offset+ cellPadding, dimension- cellPadding, dimension- cellPadding, c);

}

void Board::DrawBoarder()
{


	int xMin=x_offset-padding;
	int yMin=y_offset-padding;
	int xMax=width*dimension+padding+x_offset;
	int yMax=height*dimension+padding+y_offset;
	
	for (int i = 1; i <= bWidth; ++i) {
		for (int x1 = xMin-i; x1 <= xMax+i; ++x1)
		{
			gfx.PutPixel(x1, yMin-i, borderColor);
		}
		for (int x2 = xMin-i; x2 <= xMax+i; ++x2)
		{
			gfx.PutPixel(x2, yMax+i, borderColor);
		}

		for (int y1 = yMin-i; y1 <= yMax+i; ++y1)
		{
			gfx.PutPixel(xMin-i, y1, borderColor);
		}
		for (int y2 = yMin-i; y2 <= yMax+i; ++y2)
		{
			gfx.PutPixel(xMax+i, y2, borderColor);
		}
	}

		
	


}


int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

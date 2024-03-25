#include "olcPixelGameEngine.h"
#include "Game.h"

int main()
{
	if (game.Construct(SCREENWIDTH, SCREENHEIGHT, 3, 3))
		game.Start();

	return 0;
}
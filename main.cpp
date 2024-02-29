#include "olcPixelGameEngine.h"
#include "Game.h"

int main()
{
	if (game.Construct(480, 270, 2, 2))
		game.Start();

	return 0;
}
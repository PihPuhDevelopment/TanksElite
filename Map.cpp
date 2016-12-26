#include "Map.h"
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include "Block.h"
#include "Color.h"

Map::Map(const std::string& filename, float origin_x, float origin_y) : Point(origin_x, origin_y)
{
	ReadMapFromFile(filename);
}

bool Map::Intersects(const Rectangle& r)
{
	for(const Block& b : blocks)
	{
		if(r.Intersects(b.GetRect()))
		{
			return true;
		}
	}
	return false;
}

void Map::Tick()
{
	for(Block& b : blocks)
	{
		b.Tick();
	}
}
void Map::Render()
{
	for(Block& b : blocks)
	{
		b.Render();
	}
}

void Map::ReadMapFromFile(const std::string& filename)
{
	std::ifstream fin(filename);
	char buf;
	int w, h;
	fin >> w >> h;
	buf = fin.get();
	for(int i = h; i > 0; i--)
	{
		for(int j = 0; j <= w; j++)
		{
			buf = fin.get();
			switch(buf)
			{
				case '1':	blocks.push_back(Block(j - x, i - y, 0.8f, 0.8f, Color(77, 77, 77), false)); //undestructible wall
							break;
				case '2':	blocks.push_back(Block(j - x, i - y, 0.8f, 0.8f, Color(25, 212, 0), false)); //undestructible player
							break;
				case '3':	blocks.push_back(Block(j - x, i - y, 0.8f, 0.8f, Color(179, 179, 179), true, 1)); //destructinble wall
							break;
				case '4':   blocks.push_back(Block(j - x, i - y, 0.8f, 0.8f, Color(255, 76, 5), true, 3)); //undestructible enemy
							break;
			}
		}
	}
	fin.close();
}

void Map::Translate(float x, float y)
{
	for(Block& b : blocks)
	{
		b.Translate(x, y);
	}
}

std::list<Block>& Map::GetBlocks()
{
	return blocks;
}

void Map::Keyboard(int key)
{

}

void Map::SpecialKeyboard(int key)
{

}
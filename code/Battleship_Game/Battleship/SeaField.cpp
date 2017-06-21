#include <iostream>
#include <time.h>

#include "SeaField.h"

using namespace std;

SeaField::SeaField()
{
	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			gameBoard_[i][j] = 0;
	//for (int i = 0; i < 12; i++)
	//	for (int j = 0; j < 12; j++)
	//		tomporaryStorage_[i][j] = 178;
	setShips();
}

void SeaField::setShips()
{
	srand(time(NULL));
	int x, y, shipCount = 0;
	bool direction;
	int shipSize[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

	while (shipCount < 1)//sizeof(shipSize)/4)
	{
		//while(true)
		{
			direction = true;//rand() % 2;
			if (direction == true)
			{
				x = rand() % 11;
				y = rand() % (9 - shipSize[shipCount]);
			}
			else
			{
				x = rand() % (9 - shipSize[shipCount]);
				y = rand() % 11;
			}

			if (isThereCollision(x, y, direction, shipSize[shipCount]) == true)
			{
			}//break;
		}
		setShip(x, y, direction, shipSize[shipCount]);
		shipCount++;
	}
}

bool SeaField::isThereCollision(const int& x, const int& y,
	const bool&direction, const int& shipSize)
{
	if(direction == true)
		for (int i = y + 1; i <= y + shipSize; i++)
		{
			if (//gameBoard_[x - 1][i] == 0 &&
				gameBoard_[x][i] == 0 )
				//gameBoard_[x + 1][i] == 0) 
			{
				gameBoard_[x][i] = 1;
				//draw();
			}
			else
				return false;
		}
	if(direction == false)
		for (int i = x + 1; i <= x + shipSize; i++)
		{
			if (gameBoard_[i][y - 1] == 0 &&
				gameBoard_[i][y] == 0 &&
				gameBoard_[i][x + 1] == 0)
			{ 
				gameBoard_[i][y] = 1;
				//draw();
			}
			else
				return false;
		}

	return true;



	
}

void SeaField::setShip(const int& x, const int& y,
	const bool& direction, const int& shipSize)
{
	
}

void SeaField::draw() const
{
	for (int i = 0; i < FIELD_SIZE; i++) 
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			cout << gameBoard_[j][i];
		}
		cout << endl;
	}
	cout << endl;
}
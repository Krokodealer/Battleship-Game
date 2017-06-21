class SeaField
{
public:
	SeaField();
	bool isAnyShipAlive() const;
	int isHit(const int& x, const int& y);
	void clearField();
	void draw() const;

private:
	static const int FIELD_SIZE = 10;
	int gameBoard_[FIELD_SIZE][FIELD_SIZE];
	void setShips();
	bool isThereCollision(const int& x, const int& y,
		const bool& direction, const int& shipSize);
	void setShip(const int& x, const int& y, 
		const bool& direction, const int& shipSize);
};
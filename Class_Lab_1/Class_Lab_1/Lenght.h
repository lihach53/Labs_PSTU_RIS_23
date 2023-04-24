#pragma once
class Lenght
{
private:
	double first_x;
	double second_y;
public:
	double getX() {
		return this->first_x;
	}
	double getY() {
		return this->second_y;
	}
	double distance(double x, double y);
	void Init(double, double);
	void read();
	void show();
};
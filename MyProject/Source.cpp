#include <iostream>
#include <string>

class EventLocation
{
	int noSeats;
	int noRows;
	int zones;
	char* locationName;
public:
	EventLocation(int seats, int rows, int zone, char* locationName)
		:noSeats(seats), noRows(rows), zones(zone)
	{
		if (noSeats < 0 || noRows < 0 || zones < 0)
		{
			throw std::exception("Invalid values");
		}
		this->locationName = new char[strlen(locationName) + 1];
		strcpy_s(this->locationName, strlen(locationName)+1, locationName);
	}

}


int main()
{

}
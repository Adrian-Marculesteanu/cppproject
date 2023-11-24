#include <iostream>
#include <string>

enum class SeatType{NORMAL,SPECIAL_NEEDS,VIP};

class EventDetails
{
	const int eventId = 0;
	char* eventLocation = nullptr;
	std::string eventName = "";
	std::string eventDate = "";
	std::string eventTime = "";
	int maxParticipants = 0;

	static int noEvents;
public:
	EventDetails(const int id, char* location, std::string name, std::string date, std::string time, int noParticipants) :eventId(id)
	{
		this->eventName = name;
		this->eventDate = date;
		this->eventTime = time;
		this->maxParticipants = noParticipants;
		if (location != nullptr)
		{
			this->eventLocation = new char[strlen(location) + 1];
			strcpy_s(this->eventLocation, strlen(location) + 1, location);
		}
		noEvents++;
	}



	~EventDetails()
	{
		delete[] this->eventLocation;
		noEvents--;
	}
};

class SeatsDetails
{
	int noNormalSeats = 0;
	int noVIPSeats = 0;
	int noSpecialNeedsSeats = 0;
public:
};


int EventDetails::noEvents = 0;


int main()
{
	;
}
#include <iostream>
#include <string>

enum class SeatType{NORMAL,SPECIAL_NEEDS,VIP};

class EventDetails
{
	const int EventId = 0;
	char* eventLocation = nullptr;
	std::string eventName = "";
	std::string eventDate = "";
	std::string eventTime = "";
	int maxParticipants = 0;

	static int noEvents;
public:

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
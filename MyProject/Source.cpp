#include <iostream>
#include <string>

enum class SeatType{NORMAL,SPECIAL_NEEDS,VIP};

class Event
{
	int eventId = 0;
	char* eventLocation = nullptr;
	std::string eventName = "";
	char eventDate[11] = "";
	std::string eventTime = "";
	int maxParticipants = 0;

	static int noEvents;
public:
	const static int MIN_NAME_SIZE=3;
	

	//GETTERS AND SETTERS 

	int getEventId()
	{
		return this->eventId;
	}
	int setEventId(int id)
	{
		this->eventId = id;
	}


	std::string getEventName()
	{
		return this->eventName;
	}
	void setEventName(std::string name)
	{
		if (name.size() < MIN_NAME_SIZE)
		{
			throw std::exception("Name size too low");
		}
		if (name[0] < 'A' || name[0]>'Z')
		{
			throw std::exception("Name doesn't start with capital letter");
		}
		this->eventName = name;
	}


	std::string getEventTime()
	{
		return this->eventTime;
	}
	void setEventTime(std::string time)
	{
		if (time.size() != 5||time[3]!=':')
		{
			throw std::exception("Not valid time format (ex: 22:53)");
		}
		for (int i = 0;i < 5;i++)
		{
			if (i == 3)
			{
				continue;
			}
			else
			{
				if (time[i] < '0' || time[i]>'9')
				{
					throw std::exception("Not valid time format (ex: 22:53)");
				}
			}
		}
		this->eventTime = time;
	}


	 char* getEventLocation()
	{
		 char* copy;
		 if(this->eventLocation == nullptr)
		{
			 return nullptr;
		}
		 char* copy = new char[strlen(this->eventLocation) + 1];
		 strcpy_s(copy, strlen(this->eventLocation) + 1, this->eventLocation);
		 return copy;

	}
	void setEventLocation(char* location)
	{
		if (location != nullptr)
		{
			this->eventLocation = new char[strlen(location) + 1];
			strcpy_s(this->eventLocation, strlen(location) + 1, location);
		}
		else
		{
			throw std::exception("You are trying to pass a null pointer");
		}
	}


	int getMaxParticipants()
	{
		return this->maxParticipants;
	}
	void setMaxParticipants(int participants)
	{
		if (participants < 0)
		{
			throw std::exception("Participants amount can't be negative");
		}
		this->maxParticipants = participants;
	}



	std::string getEventDate()
	{
		return std::string(this->eventDate);
	}
	void setEventDate(std::string date)
	{
		if (date.length() == 10 && date[2] == '/' && date[5] == '/')
		{
			for (int i = 0;i < 10;i++)
			{
				this->eventDate[i] = date[i];
			}
			this->eventDate[10] = '\0';
		}
		else
		{
			throw std::exception("The date does not have the required format (DD/MM/YYYY)");
		}
	}

	//CONSTRUCTORS AND DESTRUCTOR

	Event()
	{
		this->setEventName("Unnamed");
		noEvents++;
	}

	
	Event(int id, std::string name)
	{
		this->setEventId(id);
		this->setEventName(name);
		noEvents++;
	}

	Event(int id, char* location, std::string name, std::string date, std::string time, int noParticipants)
	{
		this->setEventId(id);
		this->setEventName(name);
		this->setEventTime(time);
		this->setMaxParticipants(noParticipants);
		this->setEventLocation(location);
		this->setEventDate(date);
		noEvents++;
	}
	Event(Event& source)
	{
		this->setEventId(source.getEventId());
		this->setEventName(source.getEventName());
		this->setEventTime(source.getEventTime());
		this->setMaxParticipants(source.getMaxParticipants());
		this->setEventLocation(source.getEventLocation());
		this->setEventDate(source.getEventDate());
		noEvents++;

	}

	~Event()
	{
		delete[] this->eventLocation;
		noEvents--;
	}

	// METHODS FOR DISPLAYING/PROCESSING ATTRIBUTES

	void DisplayEssentialInfo()
	{
		std::cout << "\nEvent name: " << getEventName();
		std::cout << "\nEvent date: " << getEventDate();
		std::cout << "\nEvent time: " << getEventTime();
	}
	void DisplayComprehensiveInfo()
	{
		std::cout << "\nEvent id: " << getEventId();
		std::cout << "\nEvent name: " << getEventName();
		std::cout << "\nEvent location: " << getEventLocation();
		std::cout << "\nEvent date: " << getEventDate();
		std::cout << "\nEvent time: " << getEventTime();
		std::cout << "\nEvent max participants: " << getMaxParticipants();
	}

	// OPERATORS OVERLOAD


};

class SeatsDetails
{
	int noNormalSeats = 0;
	int noVIPSeats = 0;
	int noSpecialNeedsSeats = 0;
public:
};


int Event::noEvents = 0;


int main()
{
	;
}
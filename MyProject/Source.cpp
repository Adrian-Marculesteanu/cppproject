#include <iostream>
#include <string>

enum class SeatType{NORMAL,SPECIAL_NEEDS,VIP};

class Event
{
	bool eventStatus= false;
	int eventId = 0;
	char* eventLocation = nullptr;
	std::string eventName = "";
	char eventDate[11] = "";
	std::string eventTime = "";
	int maxParticipants = 0;

	static int noEvents;
public:
	const static int MIN_NAME_SIZE = 3;


	//GETTERS AND SETTERS 
	bool getStatus()
	{
		if (this->eventStatus == true)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void setStatus(bool status)
	{
		this->eventStatus = status;
	}

	int getEventId()
	{
		return this->eventId;
	}
	void setEventId(int id)
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
		if (time.size() != 5 || time[2] != ':')
		{
			throw std::exception("Not valid time format (ex: 22:53)");
		}
		for (int i = 0;i < 5;i++)
		{
			if (i == 2)
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
		if (this->eventLocation == nullptr)
		{
			return nullptr;
		}
		char* copy = new char[strlen(this->eventLocation) + 1];
		strcpy_s(copy, strlen(this->eventLocation) + 1, this->eventLocation);
		return copy;

	}
	void setEventLocation(const char* location)
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

	Event(int id,const char* location, std::string name, std::string date, std::string time, int noParticipants,bool status)
	{
		this->setEventId(id);
		this->setStatus(status);
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
		this->setStatus(source.getStatus());
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

	Event& operator=(Event& source)
	{
		if (&source == this)
		{
			return *this;
		}
		this->setEventId(source.getEventId());
		this->setEventName(source.getEventName());
		this->setEventTime(source.getEventTime());
		this->setMaxParticipants(source.getMaxParticipants());
		this->setEventLocation(source.getEventLocation());
		this->setEventDate(source.getEventDate());
		return *this;
	}

	friend void operator<<(std::ostream& console, Event& source);
	friend void operator>>(std::istream& input, Event& source);

	bool operator==(Event& other)
	{
		if (this->eventName == other.eventName && strcmp(eventDate, other.eventDate) == 0 && this->eventTime == other.eventTime)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Event& operator+=(int add)
	{
		if (add > 0)
		{
			this->maxParticipants += add;
		}
		return *this;
	}
	Event& operator-=(int sub)
	{
		if (sub > 0 && this->maxParticipants - sub >= 0)
		{
			this->maxParticipants -= sub;
		}
		return*this;
	}
	bool operator<=(Event& other)
	{
		return this->maxParticipants <= other.maxParticipants;
	}

	Event& operator++() 
	{
		++this->maxParticipants;
		return*this;
	}
	Event& operator++(int)
	{
		Event temp = *this;
		++(*this);
		return temp;
	}
	Event& operator!()
	{
		this->eventStatus = !(this->eventStatus);
		return*this;
	}

};

int Event::noEvents = 0;

class SeatsDetails
{
	int noNormalSeats = 0;
	int noVIPSeats = 0;
	int noSpecialNeedsSeats = 0;
public:
};


void operator<<(std::ostream& console, Event& source)
{
	console << std::endl << "Event Id: " << source.getEventId();
	console << std::endl << "Event name: " << source.getEventName();
	console << std::endl << "Event date: " << source.getEventDate();
	console << std::endl << "Event time: " << source.getEventTime();
	char* location = source.getEventLocation();
	if (location != nullptr)
	{
		console << std::endl << "Event location: " << location;
	}
	else
	{
		console << std::endl << "Event location: Not specified";
	}
	console << std::endl << "Max participants amount: " << source.getMaxParticipants();
}
void operator>>(std::istream& input, Event& source)
{
	int eventId, maxParticipants;
	std::string eventName, eventTime,eventDate;
	char* location;
	char temp[100];
	std::cout << "\nThe event id is: ";
	input >> eventId;
	std::cout << "\nThe event name is: ";
	input >> eventName;
	std::cout << "\nThe event time is: ";
	input >> eventTime;
	std::cout << "\nThe event date is: ";
	input >> eventDate;
	std::cout << "\nThe event location is: ";
	input >> temp;
	std::cout << "\nMax participation amount is: ";
	input >> maxParticipants;
	
	location = new char[strlen(temp) + 1];
	strcpy_s(location, strlen(temp) + 1, temp);

	source.setEventId(eventId);
	source.setEventName(eventName);
	source.setEventTime(eventTime);
	source.setEventLocation(location);
	source.setEventDate(eventDate);
	source.setMaxParticipants(maxParticipants);

}






int main()
{
	//AT THE MOMENT JUST A TESTING AREA FOR MY CLASSES



	//Event event1;
	//const char* location2 = "Bucharest";
	//Event event2(10, location2,"Festival", "24/12/2000", "22:22", 100, true);
	//const char* locationNew = "Average Club";
	////std::cout << event1;
	////std::cout << event2;
	//event1 = event2;
	////std::cout << std::endl << event1;
	////Event event3;
	////std::cin >> event3;
	////std::cout << std::endl << event3;*/
	////Event event3(event1);
	////event3.setEventName("SCHOOL");
	////std::cout << event3;

	////if (event2 == event3)
	////{
	////	std::cout << "Are equal";
	////}
	////else { std::cout<<"Are different"; }
	///*event2.DisplayComprehensiveInfo();event2.DisplayEssentialInfo();*/
	////event2 += (15);event2 -= (10);
	////std::cout << std::endl << "Participation count after adding 15 and substracting 10: " << event2.getMaxParticipants();
	////
	//////if (event2 <= event1) std::cout << "\n mai mic e2 ca e1";
	//////else{ std::cout << "\n mai mic e1 ca e2"; }
	////event1++;std::cout << "Max participants: " << event1.getMaxParticipants();
	////!event1;std::cout << "Status is now: " << event1.getStatus();
	////!event1;std::cout << "Status is now: " << event1.getStatus();
	//event1.setEventLocation(locationNew);
	//std::cout << "New location is: " << event1.getEventLocation();
	//event1.setEventName("Cristian");
	//std::cout << "New name is: " << event1.getEventName();
	//event1.setEventDate("01/01/2001");
	//std::cout << "New date is: " << event1.getEventDate();
	//event1.setEventTime("15:30");
	//std::cout << "New time is: " << event1.getEventTime();

}
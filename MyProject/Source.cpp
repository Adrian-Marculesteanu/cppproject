#include <iostream>
#include <string>
#include <fstream>
#include <random>
enum Type { NORMAL, VIP, SPECIAL_NEEDS };

class Seats
{
public:
	
	int totalNormalSeats = 0;
	int totalVIPSeats = 0;
	int totalSpecialNeedsSeats = 0;
	int totalSeats = 0;
	int availableNormalSeats = 0;
	int availableVIPSeats = 0;
	int availableSpecialNeedsSeats = 0;
	
	static int managedLocations;

	//Seat* seats;
	//int* availableSeats = nullptr;
	/*char seatsDescription[30] = "";*/


	//GETTERS AND SETTERS

	int getTotalSeats()
	{
		return this->totalSeats;
	}
	void setTotalSeats(int noSeats)
	{
		if (noSeats >= 0)
		{
			this->totalSeats = noSeats;
		}
		else {
			throw std::exception("The value of the seats amount can't be negative");
		}
	}

	int getNormalSeats()
	{
		return this->totalNormalSeats;
	}
	void setNormalSeats(int noSeats)
	{
		if (noSeats > 0)
		{
			this->totalNormalSeats = noSeats;
		}
		else {
			throw std::exception("The value of the seats amount can't be negative");
		}
	}

	int getVIPSeats()
	{
		return this->totalVIPSeats;
	}
	void setVIPSeats(int noSeats)
	{
		if (noSeats > 0) {
			this->totalVIPSeats = noSeats;
		}
		else {
			throw std::exception("The value of the seats amount can't be negative");
		}
	}

	int getSpecialNeedsSeats()
	{
		return this->totalSpecialNeedsSeats;
	}
	void setSpecialNeedsSeats(int noSeats)
	{
		if (noSeats > 0) {
			this->totalSpecialNeedsSeats = noSeats;
		}
		else {
			throw std::exception("The value of the seats amount can't be negative");
		}
	}


	int getAvailableSeats(Type seatType)
	{
		switch (seatType) {
		case NORMAL:
			return availableNormalSeats;
		case VIP:
			return availableVIPSeats;
		case SPECIAL_NEEDS:
			return availableSpecialNeedsSeats;
		default:
			return 0;
		}
	}
	void setAvailableNormalSeats(int seats) {
		this->availableNormalSeats = seats;
	}

	void setAvailableVIPSeats(int seats) {
		this->availableVIPSeats = seats;
	}

	void setAvailableSpecialNeedsSeats(int seats) {
		this->availableSpecialNeedsSeats = seats;
	}

	/*std::string getSeatsDescription()
	{
		return std::string(this->seatsDescription);
	}
	void setSeatsDescription(std::string description)
	{
		int i;
		if (description.size() < 3)
		{
			throw std::exception("Description is too short!");
		}
		if (description.size() > sizeof(this->seatsDescription))
		{
			throw std::exception("Description too long");
		}
		for (i = 0;i < description.size();i++)
		{
			this->seatsDescription[i] = description[i];
		}
		seatsDescription[i] = '\0';
	}*/


	// CONSTRUCTORS AND DESTRUCTORS

	Seats()
	{
		
		this->setTotalSeats(0);
		managedLocations++;

		//this-> setSeatsDescription("Description not available");
	}

	Seats(int totalSeats, int normalSeats, int VIPSeats, int specialNeedsSeats)
	{
		if (totalSeats == (normalSeats + VIPSeats + specialNeedsSeats))
		{
			this->setTotalSeats(totalSeats);
			this->setNormalSeats(normalSeats);
			this->setVIPSeats(VIPSeats);
			this->setSpecialNeedsSeats(specialNeedsSeats);
			this->setAvailableNormalSeats(normalSeats);
			this->setAvailableSpecialNeedsSeats(specialNeedsSeats);
			this->setAvailableVIPSeats(VIPSeats);
			managedLocations++;
		}
		else
		{
			std::cout << ("The seat amount does not add up, please double check to avoid future errors");
		}
	}


	Seats(Seats& source)
	{
		this->setTotalSeats(source.getTotalSeats());
		this->setNormalSeats(source.getNormalSeats());
		this->setVIPSeats(source.getVIPSeats());
		this->setSpecialNeedsSeats(source.getSpecialNeedsSeats());
		this->setAvailableNormalSeats(source.getAvailableSeats(NORMAL));
		this->setAvailableSpecialNeedsSeats(source.getAvailableSeats(SPECIAL_NEEDS));
		this->setAvailableVIPSeats(source.getAvailableSeats(VIP));
		managedLocations++;
	}

	~Seats()
	{
		managedLocations--;
	}



	void DisplayTotalSeats()
	{
		std::cout << "\n Total seats amount: " << this->totalSeats;
		std::cout << "\n Total normal seats amount: " << this->totalNormalSeats;
		std::cout << "\n Total VIP seats amount: " << this->totalVIPSeats;
		std::cout << "\n Total Special needs seats amount: " << this->totalSpecialNeedsSeats;
		std::cout << "\n Total available normal seats amount: " << this->availableNormalSeats;
		std::cout << "\n Total available VIP seats amount: " << this->availableVIPSeats;
		std::cout << "\n Total available Special needs seats amount: " << this->availableSpecialNeedsSeats;
	}

	void decrementAvailableSeats(Type seatType) {
		switch (seatType) {
		case NORMAL:
			if (this->availableNormalSeats > 0) {
				this->availableNormalSeats--;
			}
			break;
		case VIP:
			if (this->availableVIPSeats > 0) {
				this->availableVIPSeats--;
			}
			break;
		case SPECIAL_NEEDS:
			if (this->availableSpecialNeedsSeats > 0) {
				this->availableSpecialNeedsSeats--;
			}
			break;
		}
	}




	//OVERLOADING THE OPERATORS

	Seats& operator=(Seats& source)
	{
		if (&source == this)
		{
			return *this;
		}
		this->setTotalSeats(source.getTotalSeats());
		this->setNormalSeats(source.getNormalSeats());
		this->setVIPSeats(source.getVIPSeats());
		this->setSpecialNeedsSeats(source.getSpecialNeedsSeats());
		this->setAvailableNormalSeats(source.getAvailableSeats(NORMAL));
		this->setAvailableSpecialNeedsSeats(source.getAvailableSeats(SPECIAL_NEEDS));
		this->setAvailableVIPSeats(source.getAvailableSeats(VIP));
		return *this;
	}

	friend void operator<<(std::ostream& console, Seats& source);
	friend void operator>>(std::istream& input, Seats& source);


	//bool operator==(Seats& other)
	//{
	//	if (this->totalSeats == other.totalSeats)
	//	{
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}
	//bool operator<(Seats& other)
	//{
	//	if (this->totalSeats < other.totalSeats)
	//	{
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}

	//Seats& operator+=(int add)
	//{
	//	if (add > 0)
	//	{
	//		this->totalSeats += add;
	//	}
	//	return*this;
	//}
	//Seats& operator-=(int sub)
	//{
	//	if (sub > 0)
	//	{
	//		this->totalSeats -= sub;
	//	}
	//	return*this;
	//}

	//Seats& operator++()
	//{
	//	++(this->totalSeats);
	//	return *this;
	//}
	//Seats& operator++(int)
	//{
	//	Seats temp = *this;
	//	++(*this);
	//	return temp;
	//}




	void serialize(std::ofstream& file) const {
		file.write(reinterpret_cast<const char*>(this), sizeof(Seats));
	}

	void deserialize(std::ifstream& file) {
		file.read(reinterpret_cast<char*>(this), sizeof(Seats));
	}


};
int Seats::managedLocations = 0;

void operator<<(std::ostream& console, Seats& source)
{
	source.DisplayTotalSeats();
}
void operator>>(std::istream& input, Seats& source)
{
	int totalSeats;
	int normalSeats,avNormalSeats;
	int vipSeats,avVIPSeats;
	int specialNeedsSeats,avSNSeats;
	std::cout << "\n The total seats amount is: ";
	input >> totalSeats;
	source.setTotalSeats(totalSeats);
	std::cout << "\n The total normal seats amount is: ";
	input >> normalSeats;
	source.setNormalSeats(normalSeats);
	std::cout << "\n The total VIP seats amount is: ";
	input >> vipSeats;
	source.setVIPSeats(vipSeats);
	std::cout << "\n The total special needs seats amount is: ";
	input >> specialNeedsSeats;
	source.setSpecialNeedsSeats(specialNeedsSeats);
	std::cout << "\n The available normal seats amount is: ";
	input >> avNormalSeats;
	if (avNormalSeats<=normalSeats && avNormalSeats >= 0)
	{
		source.setAvailableNormalSeats(avNormalSeats);
	}
	std::cout << "\n The available VIP seats amount is: ";
	input >> avVIPSeats;
	if (avVIPSeats >= 0 && avVIPSeats <= vipSeats) {
		source.setAvailableVIPSeats(avVIPSeats);
	}
	std::cout << "\n The available special needs seats amount is: ";
	input >> avSNSeats;
	if (avSNSeats >= 0 && avSNSeats <= specialNeedsSeats) {
		source.setAvailableSpecialNeedsSeats(avSNSeats);
	}

	

}


class Event
{
public:
	bool eventStatus= false;
	int eventId = 0;
	char* eventLocation = nullptr;
	std::string eventName = "";
	char eventDate[11] = "";
	std::string eventTime = "";
	Seats eventSeats;

	static int noEvents;
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
	void setEventLocation(std::string location)
	{
		if (!location.empty())
		{
			this->eventLocation = new char[location.length() + 1];
			strcpy_s(this->eventLocation, location.length() + 1, location.c_str());
		}
		else
		{
			throw std::invalid_argument("You are trying to pass an empty string");
		}
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
	Seats& getEventSeats()
	{
		return this->eventSeats;
	}
	void setEventSeats(Seats& seats)
	{
		this->eventSeats = seats;
	}


	//void setEventLocation(const char* location)
//{
//	if (location != nullptr)
//	{
//		this->eventLocation = new char[strlen(location) + 1];
//		strcpy_s(this->eventLocation, strlen(location) + 1, location);
//	}
//	else
//	{
//		throw std::exception("You are trying to pass a null pointer");
//	}
//}

/*int getMaxParticipants()
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
}*/

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

	Event(int id,std::string location, std::string name, std::string date, std::string time,bool status,Seats& seats)
	{
		this->setEventId(id);
		this->setStatus(status);
		this->setEventName(name);
		this->setEventTime(time);
		this->setEventLocation(location);
		this->setEventDate(date);
		this->setEventSeats(seats);
		noEvents++;
	}
	Event(Event& source)
	{
		this->setEventId(source.getEventId());
		this->setStatus(source.getStatus());
		this->setEventName(source.getEventName());
		this->setEventTime(source.getEventTime());
		this->setEventLocation(source.getEventLocation());
		this->setEventDate(source.getEventDate());
		this->setEventSeats(source.getEventSeats());
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
		std::cout << std::endl;
		std::cout << "\nEvent name: " << getEventName();
		std::cout << "\nEvent date: " << getEventDate();
		std::cout << "\nEvent time: " << getEventTime();
		std::cout << "\nEvent location: " << getEventLocation();
		std::cout << "\nAvailable normal seats:" << eventSeats.getAvailableSeats(NORMAL);
		std::cout << "\nAvailable VIP seats:" << eventSeats.getAvailableSeats(VIP);
		std::cout << "\nAvailable special needs seats:" << eventSeats.getAvailableSeats(SPECIAL_NEEDS);
	}
	//void DisplayComprehensiveInfo()
	//{
	//	std::cout << "\nEvent id: " << getEventId();
	//	std::cout << "\nEvent name: " << getEventName();
	//	std::cout << "\nEvent location: " << getEventLocation();
	//	std::cout << "\nEvent date: " << getEventDate();
	//	std::cout << "\nEvent time: " << getEventTime();
	//}

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
		this->setEventLocation(source.getEventLocation());
		this->setEventDate(source.getEventDate());
		this->setEventSeats(source.getEventSeats());
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
	//Event& operator+=(int add)
	//{
	//	if (add > 0)
	//	{
	//		this->maxParticipants += add;
	//	}
	//	return *this;
	//}
	//Event& operator-=(int sub)
	//{
	//	if (sub > 0 && this->maxParticipants - sub >= 0)
	//	{
	//		this->maxParticipants -= sub;
	//	}
	//	return*this;
	//}
	//bool operator<=(Event& other)
	//{
	//	return this->maxParticipants <= other.maxParticipants;
	//}

	//Event& operator++() 
	//{
	//	++this->maxParticipants;
	//	return*this;
	//}
	//Event& operator++(int)
	//{
	//	Event temp = *this;
	//	++(*this);
	//	return temp;
	//}
	Event& operator!()
	{
		this->eventStatus = !(this->eventStatus);
		return*this;
	}


	void serialize(std::ofstream& file) const {
		file.write(reinterpret_cast<const char*>(&eventStatus), sizeof(eventStatus));
		file.write(reinterpret_cast<const char*>(&eventId), sizeof(eventId));
		int locationLength = strlen(eventLocation);
		file.write(reinterpret_cast<const char*>(&locationLength), sizeof(locationLength));
		file.write(eventLocation, locationLength);
		int nameLength = eventName.length();
		file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
		file.write(eventName.c_str(), nameLength);
		file.write(eventDate, sizeof(eventDate));
		int timeLength = eventTime.length();
		file.write(reinterpret_cast<const char*>(&timeLength), sizeof(timeLength));
		file.write(eventTime.c_str(), timeLength);
		eventSeats.serialize(file);
	}



	void deserialize(std::ifstream& file) {
		file.read(reinterpret_cast<char*>(&eventStatus), sizeof(eventStatus));
		file.read(reinterpret_cast<char*>(&eventId), sizeof(eventId));
		int locationLength;
		file.read(reinterpret_cast<char*>(&locationLength), sizeof(locationLength));
		delete[] eventLocation;
		eventLocation = new char[locationLength + 1];
		file.read(eventLocation, locationLength);
		eventLocation[locationLength] = '\0'; 
		int nameLength = 0;
		file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
		char* nameBuffer = new char[nameLength + 1];
		file.read(nameBuffer, nameLength);
		nameBuffer[nameLength] = '\0';
		eventName = nameBuffer;
		delete[] nameBuffer;
		file.read(eventDate, sizeof(eventDate));
		int timeLength = 0;
		file.read(reinterpret_cast<char*>(&timeLength), sizeof(timeLength));
		char* timeBuffer = new char[timeLength + 1];
		file.read(timeBuffer, timeLength);
		timeBuffer[timeLength] = '\0';
		eventTime = timeBuffer;
		delete[] timeBuffer;
		eventSeats.deserialize(file);
	}



};

int Event::noEvents = 0;

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
	console << std::endl << "Seats information:";
	source.eventSeats.DisplayTotalSeats();
}
void operator>>(std::istream& input, Event& source)
{
	int eventId, totalSeats, normalSeats, specialNeedsSeats, VIPSeats;
	std::string eventName, eventTime,eventDate;
	char* location;
	char temp[100];
	Seats seats;
	std::cout << "\nThe event id is: ";
	input >> eventId;
	std::cout << "\nThe event name is: ";
	std::getline(input >> std::ws, eventName);
	std::cout << "\nThe event time is: ";
	input >> eventTime;
	std::cout << "\nThe event date is: ";
	input >> eventDate;
	std::cout << "\nThe event location is: ";
	input.ignore(); //
	input.getline(temp, sizeof(temp));
	std::cout << "\n The total seats amount is: ";
	input >> totalSeats;
	source.eventSeats.setTotalSeats(totalSeats);
	std::cout << "\n The total normal seats amount is: ";
	input >> normalSeats;
	source.eventSeats.setNormalSeats(normalSeats);
	std::cout << "\n The total VIP seats amount is: ";
	input >> VIPSeats;
	source.eventSeats.setVIPSeats(VIPSeats);
	std::cout << "\n The total special needs seats amount is: ";
	input >> specialNeedsSeats;
	source.eventSeats.setSpecialNeedsSeats(specialNeedsSeats);
	
	location = new char[strlen(temp) + 1];
	strcpy_s(location, strlen(temp) + 1, temp);

	source.setEventId(eventId);
	source.setEventName(eventName);
	source.setEventTime(eventTime);
	source.setEventLocation(location);
	source.setEventDate(eventDate);

}

//class Seat
//{
//	bool isAvailable;
//	Type seatType;
//public:
//	bool getAvailability()
//	{
//		return this->isAvailable;
//	}
//	void setAvailability(bool status)
//	{
//		this->isAvailable = status;
//	}
//	Type getSeatType()
//	{
//		return this->seatType;
//	}
//	void setSeatType(Type type)
//	{
//		this->seatType = type;
//	}
//
//	Seat()
//	{
//		this->setAvailability(1);
//	}
//	Seat(Type type)
//	{
//		this->setAvailability(1);
//		this->setSeatType(type);
//	}
//	Seat(bool available,Type type)
//	{
//		this->setAvailability(available);
//		this->setSeatType(type);
//	}
//	
//};

class Ticket
{

public:
	int ticketId=0;
	char ownerName[30] = "";
	Type ticketType;
	Event ticketEvent;


	//int ticketPrice=0;
	//bool isValid=0;
	///*Seat* seat;*/

	static int noTickets;

	//GETTERS AND SETTERS 

	int getTicketId()
	{
		return this->ticketId;
	}
	void generateTicketId()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1000,9999);
		this->ticketId = dis(gen);
	}

	std::string getOwnerName()
	{
		return std::string(this->ownerName);
	}
	void setOwnerName(std::string owner)
	{
		int i;
		if (owner.size() < 3)
		{
			throw std::exception("Name is too short!");
		}
		if (owner.size() > sizeof(this->ownerName))
		{
			throw std::exception("Name too long");
		}
		for (i = 0;i < owner.size();i++)
		{
			this->ownerName[i] = owner[i];
		}
		this->ownerName[i] = '\0';
	}

	Type getTicketType()
	{
		return this->ticketType;
	}
	void setTicketType(Type type)
	{
		this->ticketType = type;
	}

	Event& getTicketEvent()
	{
		return this->ticketEvent;
	}
	void setTicketEvent(Event& source)
	{
		source.eventSeats.decrementAvailableSeats(this->getTicketType());
		this->ticketEvent = source;
	}
	/*void setTicketPrice(int price)
	{
		if (price > 0) {
			this->ticketPrice = price;
		}
		else {
			throw std::exception("Price can't be negative");
		}
	 }
	int getTicketPrice()
	{
		return this->ticketPrice;
	}*/
	//bool getIsValid()
	//{
	//	return this->isValid;
	//}
	//void setIsValid(bool valid)
	//{
	//	this->isValid = valid;
	//}
	/*void setTicketType(const Type& type) {
		if (this->ticketType == nullptr) {
			this->ticketType = new Type(type);
		}
		else {
			*ticketType = type;
		}
	}
	Type& getTicketType()  {
		if (this->ticketType == nullptr) {
			 Type defaultTicketType=NORMAL;
			return defaultTicketType;
		}
		return *ticketType;
	}*/

	
	
	//CONSTRUCTORS AND DESTRUCTOR
	Ticket()
	{
		this->generateTicketId();
		this->setOwnerName("John Doe");
		////this->setIsValid(true);
		//this->setTicketType(NORMAL);
		noTickets++;
	}
	Ticket(std::string name, Type type,Event& event)
	{

		if ((type == NORMAL && event.eventSeats.getAvailableSeats(NORMAL) == 0) ||
			(type == VIP && event.eventSeats.getAvailableSeats(VIP) == 0) ||
			(type == SPECIAL_NEEDS && event.eventSeats.getAvailableSeats(SPECIAL_NEEDS) == 0))
		{
			std::cout << "No available seats of this type. Cannot generate ticket." << std::endl;
		}
		else {
			this->generateTicketId();
			this->setOwnerName(name);
			this->setTicketType(type);
			this->setTicketEvent(event);
			noTickets++;
		}
	}

	Ticket(Ticket& source)
	{
		this->generateTicketId();

		this->setOwnerName(source.getOwnerName());

		this->setTicketType(source.getTicketType());

		this->setTicketEvent(source.getTicketEvent());
		noTickets++;
		/*	this->setTicketId(source.getTicketId());
		this->setTicketPrice(source.getTicketPrice());
		this->setIsValid(source.getIsValid());*/
	}
	~Ticket()
	{
		noTickets--;
	}

	//GENERIC METHODS FOR DISPLAY

	void DisplayOwnerName()
	{
		std::cout << "\n The ticket owner is: " << getOwnerName();
	}
	void DisplayTicketInformation()
	{
		std::cout << "\n The ticket ID is:  " << getTicketId();
		std::cout << "\n The ticket owner is: " << getOwnerName();
		std::cout << "\n The ticket type is: " << getTicketType();
		//std::cout << "\n The ticket status is: " << getIsValid();
		//std::cout << "\n The ticket price is: " << getTicketPrice();
	}


	std::string getTicketTypeString() {
		switch (this->getTicketType()) {
		case 0:
			return "Normal";
		case 1:
			return "VIP";
		case 2:
			return "Special Needs";
		default:
			return "Unknown";
		}
	}

	//OVERLOADING THE OPERATORS 
	Ticket& operator=(Ticket& source)
	{
		if (&source == this)
		{
			return *this;
		}
		this->setOwnerName(source.getOwnerName());
		this->setTicketType(source.getTicketType());
		/*	this->setTicketPrice(source.getTicketPrice());
		this->setIsValid(source.getIsValid());
		/*this->setTicketId(source.getTicketId());*/
		return*this;
	}

	bool operator==(Ticket& other)
	{
		if (std::string(this->ownerName) == std::string(other.ownerName) && this->ticketId == other.ticketId)
		{
			return true;
		}
			return false;
	}
	friend void operator<<(std::ostream& console, Seats& source);
	friend void operator>>(std::istream& input, Seats& source);

	/*bool operator <(Ticket& other) {
		if (this->ticketPrice < other.ticketPrice)
		{
			return true;
		}
		else {
			return false;
		}
	}*/
	/* Ticket& operator+=(int add){
		{
			if (add > 0)
			{
				this->ticketPrice += add;
			}
			else {
				throw std::exception("Number can't be negative");
			}
		}*/
	/*}*/
	// Ticket& operator-=(int sub) {
	//	{
	//		if (sub > 0)
	//		{
	//			this->ticketPrice -= sub;
	//		}
	//		else {
	//			throw std::exception("Number can't be negative");
	//		}
	//	}
	//}
	/* Ticket& operator++()
	 {
		 ++(this->ticketPrice);
		 return* this;
	 }
	 Ticket& operator++(int)
	 {
		 Ticket temp = *this;
		 ++(*this);
		 return temp;
	 }*/
	 //bool operator!()
	 //{
		// this->isValid = !this->isValid;
		// return this->isValid;
	 //}

	void serialize(std::ofstream& file) const {
		file.write(reinterpret_cast<const char*>(&ticketId), sizeof(ticketId));
		file.write(reinterpret_cast<const char*>(&ticketType), sizeof(ticketType));
		file.write(ownerName, sizeof(ownerName));
		ticketEvent.serialize(file);
	}

	void deserialize(std::ifstream& file) {
		file.read(reinterpret_cast<char*>(&ticketId), sizeof(ticketId));
		file.read(reinterpret_cast<char*>(&ticketType), sizeof(ticketType));
		file.read(ownerName, sizeof(ownerName));
		ticketEvent.deserialize(file);
	}


};
int Ticket::noTickets = 0;
void operator<<(std::ostream& console, Ticket& source)
{
	console<<std::endl << "\nTicket id: " << source.getTicketId();
	console << std::endl << "Event name: " << source.ticketEvent.getEventName();
	console << std::endl << "Ticket owner name: " << source.getOwnerName();
	console << std::endl << "Ticket type is:" << source.getTicketTypeString();
	//console << std::endl << "Ticket status: " << source.getIsValid();
	//console << std::endl << "\nTicket price is: " << source.getTicketPrice();
}
void operator>>(std::istream& input, Ticket& source)
{
	int id, price;
	std::string ownerName;
	Type type;
	std::string typeString;
	std::cout << "\nWhat is the name of the owner?";
	input.ignore();
	std::getline(input, ownerName); 
	source.setOwnerName(ownerName);
	std::string ticketTypeStr;
	std::cout << "\nWhat is the ticket type? NORMAL/VIP/SPECIAL_NEEDS: ";
	input >> typeString;
	if (typeString == "NORMAL") {
		type = Type::NORMAL;
	}
	else if (typeString == "VIP") {
		type = Type::VIP;
	}
	else if (typeString == "SPECIAL_NEEDS") {
		type = Type::SPECIAL_NEEDS;
	}
	else {
		throw std::invalid_argument("Invalid ticket type entered.");
	}
	source.setTicketType(type);

	//std::cout << "\nWhat is the ticket id?:";
//input >> id;
//source.setTicketId(id);
//std::cout << "\nWhat is the price of the ticket?";
//input >> price;
/*source.setTicketPrice(price);*/
//std::cout << "\n What is the status of the ticket? 0-not active// 1-active";
//input >> valid;
//source.setIsValid(valid);

}

void generateTicket(Event& event)
{
	std::string name; Type type; int typeInteger;
	std::cout << "\nWhat is your name? \n";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "What kind of ticket would you like? Please type the corresponding digit:\n ";
	std::cout << "1-Normal ticket; 2-VIP Ticket; 3-Special Needs Ticket\n";
	std::cin >> typeInteger;
	while (typeInteger != 1 && typeInteger != 2 && typeInteger != 3) 
	{
		std::cout << "Invalid input. Please choose a valid ticket type (1, 2, or 3): ";
		std::cin >> typeInteger;
	}
	if (typeInteger == 1)
	{
		type = NORMAL;
	}
	else if (typeInteger == 2)
	{
		type = VIP;
	}
	else if (typeInteger == 3)
	{
		type = SPECIAL_NEEDS;
	}
	else
	{
		std::cout << "You did not choose one of the variants provided";
	}
	if (typeInteger == 1 || typeInteger == 2 || typeInteger == 3)
	{
		Ticket ticket(name, type, event);
		std::ofstream outFile("tickets.bin", std::ios::binary | std::ios::app);
		{
			if (!outFile.is_open()) {
				std::cout << "File not open";
			}
			ticket.serialize(outFile);
			outFile.close();
			std::cout << ticket;
		}
	}
}

void searchTicketByID(int searchID)
{
	std::ifstream inFile("tickets.bin", std::ios::binary);
	if (!inFile.is_open()) {
		std::cout << "File not open." << std::endl;
		return;
	}

	Ticket currentTicket;
	bool found = false;

	while (inFile.peek() != EOF) {
		currentTicket.deserialize(inFile);

		if (currentTicket.getTicketId() == searchID) {
			found = true;
			break;
		}
	}

	inFile.close();

	if (found==true) {
		std::cout << "Ticket found!" << std::endl;
	}
	else {
		std::cout << "Ticket not found." << std::endl;
	}
}



int main()
{


	std::ifstream inFile("events.bin", std::ios::binary);
	if (!inFile.is_open()) {
		std::cout << "Error opening file";
	}
	Event eventFootball,eventMovie,eventTheatre;
	eventFootball.deserialize(inFile), eventMovie.deserialize(inFile);eventTheatre.deserialize(inFile);
	inFile.close();


	int choice = 1;int ticketChoice;
	std::cout << "\nHello! What would you like to do today? Please write the corresponding digit of your choice:\n";
	while (choice != 0)
	{
		std::cout << "\n1- View the available events; 2-Buy a ticket for one of the events; 3-Search an ID in the list of tickets\nEntering '0' instead will exit the program\n";
		std::cin >> choice;
		if (choice == 1)
		{
			eventFootball.DisplayEssentialInfo();
			eventMovie.DisplayEssentialInfo();
			eventTheatre.DisplayEssentialInfo();
		}
		if (choice == 2)
		{
			do {
				std::cout << "Which event would you like to buy a ticket for?\n 1-FCSB-CFR Cluj; 2-Murder on the Orient Express; 3-A Lost Letter\n";
				std::cin >> ticketChoice;

				if (ticketChoice == 1)
				{
					generateTicket(eventFootball);
					std::cout << "\nDone! Thank you.";
					break;
				}
				else if (ticketChoice == 2)
				{
					generateTicket(eventMovie);
					std::cout << "\nDone! Thank you.";
					break;
				}
				else if (ticketChoice == 3)
				{
					generateTicket(eventTheatre);
					std::cout << "\nDone! Thank you.";
					break;
				}
				else
				{
					std::cout << "You have not chosen one of the available events! Please input your option again\n";
				}
			} while (true);
		}
		if (choice == 3)
		{
			int searchedID;
			std::cout << "\nPlease input the ID you wish to search!\n";
			std::cin >> searchedID;
			searchTicketByID(searchedID);
		}
	}


	std::ofstream outFile("events.bin", std::ios::binary);
	{
		if (!outFile.is_open()) {
			std::cout << "Error opening file";
		}
		eventFootball.serialize(outFile);eventMovie.serialize(outFile);eventTheatre.serialize(outFile);
		outFile.close();
	}

}
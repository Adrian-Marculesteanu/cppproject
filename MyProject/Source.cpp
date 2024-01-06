#include <iostream>
#include <string>

enum TicketType { NORMAL, VIP, SPECIAL_NEEDS };

class Seats
{
private:
	/*char seatsDescription[30] = "";*/
	int totalNormalSeats = 0;
	int totalVIPSeats = 0;
	int totalSpecialNeedsSeats = 0;
	int totalSeats = 0;
	//int* availableSeats = nullptr;

	static int managedLocations;


public:
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
	//void setAvailableSeats(int* seatsArray)
	//{
	//	if (seatsArray != nullptr)
	//	{
	//		this->availableSeats = new int[3];
	//		memcpy(this->availableSeats, seatsArray, sizeof(int) * 3);
	//	}
	//	else 
	//	{
	//		throw std::exception("Invalid array provided");
	//	}
	//}
	//int* getAvailableSeats()
	//{
	//	if (this->availableSeats != nullptr)
	//	{
	//		int* copy = new int[3];
	//		memcpy(copy, availableSeats, sizeof(int) * 3);
	//		return copy;
	//	}
	//	else
	//	{
	//		return nullptr;
	//	}
	//}


	// CONSTRUCTORS AND DESTRUCTORS

	Seats()
	{
		//this-> setSeatsDescription("Description not available");
		this->setTotalSeats(0);
		managedLocations++;
	}

	Seats(int totalSeats, int normalSeats, int VIPSeats, int specialNeedsSeats)
	{
		if (totalSeats == (normalSeats + VIPSeats + specialNeedsSeats))
		{
			this->setTotalSeats(totalSeats);
			this->setNormalSeats(normalSeats);
			this->setVIPSeats(VIPSeats);
			this->setSpecialNeedsSeats(specialNeedsSeats);
			managedLocations++;
		}
		else
		{
			std::cout << ("The seat amount does not add up, please double check to avoid future errors");
		}
	}
	//Seats(int totalSeats, int normalSeats, int VIPSeats, int specialNeedsSeats)
	//{
	//	if (totalSeats == (normalSeats + VIPSeats + specialNeedsSeats))
	//	{
	//		this->setTotalSeats(totalSeats);
	//		this->setNormalSeats(normalSeats);
	//		this->setVIPSeats(VIPSeats);
	//		this->setSpecialNeedsSeats(specialNeedsSeats);
	//		managedLocations++;
	//	}
	//	else
	//	{
	//		std::cout << ("The seat amount does not add up, please double check to avoid future errors");
	//	}
	//}

	Seats(Seats& source)
	{
		this->setTotalSeats(source.getTotalSeats());
		this->setNormalSeats(source.getNormalSeats());
		this->setVIPSeats(source.getVIPSeats());
		this->setSpecialNeedsSeats(source.getSpecialNeedsSeats());
		managedLocations++;
	}

	~Seats()
	{
		managedLocations--;
	}


	//GENERIC METHODS FOR DISPLAYING ATTRIBUTES

	//void DisplayAvailableSeats()
	//{
	//	if (this->availableSeats != nullptr)
	//	{
	//		std::cout << "\nRemaining normal seats: " << this->availableSeats[0];
	//		std::cout << "\nRemaining VIP seats: " << this->availableSeats[1];
	//		std::cout << "\nRemaining special needs seats: " << this->availableSeats[2];
	//	}
	//	else {
	//		std::cout << "Seat information not available at the moment D:";
	//	}
	//}
	void DisplayTotalSeats()
	{
		std::cout << "\n Total seats amount: " << this->totalSeats;
		std::cout << "\n Total normal seats amount: " << this->totalNormalSeats;
		std::cout << "\n Total VIP seats amount: " << this->totalVIPSeats;
		std::cout << "\n Total Special needs seats amount: " << this->totalSpecialNeedsSeats;

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
		return *this;
	}

	friend void operator<<(std::ostream& console, Seats& source);
	friend void operator>>(std::istream& input, Seats& source);


	bool operator==(Seats& other)
	{
		if (this->totalSeats == other.totalSeats)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool operator<(Seats& other)
	{
		if (this->totalSeats < other.totalSeats)
		{
			return true;
		}
		else {
			return false;
		}
	}

	Seats& operator+=(int add)
	{
		if (add > 0)
		{
			this->totalSeats += add;
		}
		return*this;
	}
	Seats& operator-=(int sub)
	{
		if (sub > 0)
		{
			this->totalSeats -= sub;
		}
		return*this;
	}

	Seats& operator++()
	{
		++(this->totalSeats);
		return *this;
	}
	//Seats& operator++(int)
	//{
	//	Seats temp = *this;
	//	++(*this);
	//	return temp;
	//}





};
int Seats::managedLocations = 0;

void operator<<(std::ostream& console, Seats& source)
{
	//console << std::endl << "Total seats: " << source.getTotalSeats();
	//console << std::endl << "Total normal seats: " << source.getNormalSeats();
	//console << std::endl << "Total VIP seats: " << source.getVIPSeats();
	//console << std::endl << "Total special needs seats: " << source.getSpecialNeedsSeats();
	source.DisplayTotalSeats();

}
void operator>>(std::istream& input, Seats& source)
{
	int totalSeats;
	int normalSeats;
	int vipSeats;
	int specialNeedsSeats;
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
	//std::cout << "\nThe description of the seats is: ";
	//input.ignore();
	//input.getline(temp, sizeof(temp));
	//strncpy_s(source.seatsDescription, temp, sizeof(source.seatsDescription) - 1);
	//source.seatsDescription[sizeof(source.seatsDescription)] = '\0';
	//std::cout << "Remaining normal seats amount: ";
	//input >> availableSeats[0];
	//std::cout << "Remaining VIP seats amount: ";
	//input >> availableSeats[1];
	//std::cout << "Remaining special needs seats amount:";
	//input >> availableSeats[2];
	//source.setAvailableSeats(availableSeats);

}


class Event
{
private:
	bool eventStatus= false;
	int eventId = 0;
	char* eventLocation = nullptr;
	std::string eventName = "";
	char eventDate[11] = "";
	std::string eventTime = "";
	Seats eventSeats;

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
		eventSeats = seats;
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

	Event(int id,const char* location, std::string name, std::string date, std::string time,bool status,Seats& seats)
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
	/*std::cout << "\nThe event name is: ";
	input >> eventName;*/
	std::cout << "\nThe event name is: ";
	std::getline(input >> std::ws, eventName);
	std::cout << "\nThe event time is: ";
	input >> eventTime;
	std::cout << "\nThe event date is: ";
	input >> eventDate;
	std::cout << "\nThe event location is: ";
	input.ignore(); // Ignore the newline character left in the stream
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




class Ticket
{

private:
	int ticketId=0;
	char ownerName[30] = "";
	TicketType* ticketType=nullptr;
	int ticketPrice=0;
	bool isValid=0;

	static int noTickets;
public:

	//GETTERS AND SETTERS 

	int getTicketId()
	{
		return this->ticketId;
	}
	void setTicketId(int id)
	{
		if (id > 0) {
			this->ticketId = id;
		}
		else {
			throw std::exception("ID can't be negative");
		}
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
	void setTicketType(const TicketType& type) {
		if (this->ticketType == nullptr) {
			this->ticketType = new TicketType(type);
		}
		else {
			*ticketType = type; 
		}
	}
	 TicketType& getTicketType()  {
		if (this->ticketType == nullptr) {
			 TicketType defaultTicketType=NORMAL;
			return defaultTicketType;
		}
		return *ticketType;
	}
	void setTicketPrice(int price)
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
	}
	bool getIsValid()
	{
		return this->isValid;
	}
	void setIsValid(bool valid)
	{
		this->isValid = valid;
	}

	
	
	//CONSTRUCTORS AND DESTRUCTOR
	Ticket()
	{
		this->setOwnerName("John Doe");
		this->setIsValid(true);
		this->setTicketType(NORMAL);
		noTickets++;
	}
	Ticket(std::string name, TicketType type)
	{
		this->setOwnerName(name);
		this->setTicketType(type);
		this->setIsValid(true);
		noTickets++;
	}
	Ticket(int id, std::string name, TicketType type,int price)
	{
		this->setTicketId(id);
		this->setOwnerName(name);
		this->setTicketPrice(price);
		this->setTicketType(type);
		this->setIsValid(true);
		noTickets++;
	}
	Ticket(Ticket& source)
	{
		this->setTicketId(source.getTicketId());
		this->setOwnerName(source.getOwnerName());
		this->setTicketPrice(source.getTicketPrice());
		this->setTicketType(source.getTicketType());
		this->setIsValid(source.getIsValid());
		noTickets++;
	}
	~Ticket()
	{
		delete[] this->ticketType;
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
		std::cout << "\n The ticket price is: " << getTicketPrice();
		std::cout << "\n The ticket type is: " << getTicketType();
		std::cout << "\n The ticket status is: " << getIsValid();
	}

	//OVERLOADING THE OPERATORS 
	Ticket& operator=(Ticket& source)
	{
		if (&source == this)
		{
			return *this;
		}
		this->setTicketId(source.getTicketId());
		this->setOwnerName(source.getOwnerName());
		this->setTicketPrice(source.getTicketPrice());
		this->setTicketType(source.getTicketType());
		this->setIsValid(source.getIsValid());
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

	bool operator <(Ticket& other) {
		if (this->ticketPrice < other.ticketPrice)
		{
			return true;
		}
		else {
			return false;
		}
	}
	 Ticket& operator+=(int add){
		{
			if (add > 0)
			{
				this->ticketPrice += add;
			}
			else {
				throw std::exception("Number can't be negative");
			}
		}
	}
	 Ticket& operator-=(int sub) {
		{
			if (sub > 0)
			{
				this->ticketPrice -= sub;
			}
			else {
				throw std::exception("Number can't be negative");
			}
		}
	}
	 Ticket& operator++()
	 {
		 ++(this->ticketPrice);
		 return* this;
	 }
	 Ticket& operator++(int)
	 {
		 Ticket temp = *this;
		 ++(*this);
		 return temp;
	 }
	 bool operator!()
	 {
		 this->isValid = !this->isValid;
		 return this->isValid;
	 }

};
int Ticket::noTickets = 0;
void operator<<(std::ostream& console, Ticket& source)
{
	console << std::endl << "\nTicket id: " << source.getTicketId();
	console << std::endl << "\nTicket owner name: " << source.getOwnerName();
	console << std::endl << "\nTicket price is: " << source.getTicketPrice();
	console << std::endl << "Ticket type is:" << source.getTicketType();
	console << std::endl << "Ticket status: " << source.getIsValid();

}
void operator>>(std::istream& input, Ticket& source)
{
	int id, price;
	bool valid;std::string ownerName;
	TicketType type;
	std::string typeString;
	std::cout << "\nWhat is the ticket id?:";
	input >> id;
	source.setTicketId(id);
	std::cout << "\nWhat is the price of the ticket?";
	input >> price;
	source.setTicketPrice(price);
	std::cout << "\n What is the status of the ticket? 0-not active// 1-active";
	input >> valid;
	source.setIsValid(valid);
	std::cout << "\nWhat is the name of the owner?";
	input.ignore();
	std::getline(input, ownerName); 
	source.setOwnerName(ownerName);
	std::string ticketTypeStr;
	std::cout << "\nWhat is the ticket type? NORMAL/VIP/SPECIAL_NEEDS: ";
	input >> typeString;
	if (typeString == "NORMAL") {
		type = TicketType::NORMAL;
	}
	else if (typeString == "VIP") {
		type = TicketType::VIP;
	}
	else if (typeString == "SPECIAL_NEEDS") {
		type = TicketType::SPECIAL_NEEDS;
	}
	else {
		throw std::invalid_argument("Invalid ticket type entered.");
	}

	source.setTicketType(type);

}


int main()
{
	//AT THE MOMENT JUST A TESTING AREA FOR MY CLASSES



	//Event event1;
	//const char* location2 = "Bucharest";
	//Event event2(10, location2,"Festival", "24/12/2000", "22:22", 100, true);
	//const char* locationNew = "Average Club";
	//std::cout << event1;
	//std::cout << event2;
	//event1 = event2;
	//std::cout << std::endl << event1;
	//Event event3;
	//std::cin >> event3;
	//std::cout << std::endl << event3;
	//event3.setEventName("SCHOOL");
	//std::cout << event3;

	//if (event2 == event3)
	//{
	//	std::cout << "Are equal";
	//}
	//else { std::cout<<"Are different"; }
	//event2.DisplayComprehensiveInfo();event2.DisplayEssentialInfo();
	//event2 += (15);event2 -= (10);
	//std::cout << std::endl << "Participation count after adding 15 and substracting 10: " << event2.getMaxParticipants();
	//
	//if (event2 <= event1) std::cout << "\n mai mic e2 ca e1";
	//else{ std::cout << "\n mai mic e1 ca e2"; }
	//event1++;std::cout << "Max participants: " << event1.getMaxParticipants();
	//!event1;std::cout << "Status is now: " << event1.getStatus();
	//!event1;std::cout << "Status is now: " << event1.getStatus();
	//event1.setEventLocation(locationNew);
	//std::cout << "New location is: " << event1.getEventLocation();
	//event1.setEventName("Cristian");
	//std::cout << "New name is: " << event1.getEventName();
	//event1.setEventDate("01/01/2001");
	//std::cout << "New date is: " << event1.getEventDate();
	//event1.setEventTime("15:30");
	//std::cout << "New time is: " << event1.getEventTime();
	//Seats seats1(20, 10, 5, 5);
	//std::cout << "total seats is : " << seats1.getTotalSeats();
	//seats1.setTotalSeats(50);
	//std::cout << "total seats is : " << seats1.getTotalSeats();
	//seats1.setSeatsDescription("Seats for football game");
	//std::cout<<"The description is:  "<<seats1.getSeatsDescription();
	//int seatArray[3] = { 100, 50, 20 };
	//seats1.setAvailableSeats(seatArray);
	//seats1.getAvailableSeats();
	//Seats seats2(seats1);
	//std::cout << "total seats is : " << seats1.getTotalSeats();
	//std::cout << "The description is:  " << seats1.getSeatsDescription();
	//seats1.setAvailableSeats(seatArray);
	//seats1.getAvailableSeats();
	//seats1.DisplayAvailableSeats();
	//seats1.DisplayTotalSeats();
	//std::cout << seats1;
	//std::cin >> seats2;
	//std::cout << seats2;
	//++seats1;
	//std::cout << seats1;
	//Ticket ticket1;
	//std::cout << ticket1;
	//Ticket ticket2(10, "Adrian Madalin", VIP, 100);
	//std::cout << ticket2;
	//Ticket ticket3;
	//ticket3 = ticket2;
	//if (ticket3 == ticket2)
	//{
	//	std::cout << "Adevarat";
	//}
	//else
	//{
	//	std::cout << "Fals";
	//}
	//++ticket3;
	//std::cout << ticket3;
	//!ticket3;
	//std::cout<<std::endl<<ticket3.getIsValid();
	//!ticket3;
	//std::cout << std::endl << ticket3.getIsValid();
	//ticket3.DisplayOwnerName();
	//ticket3.DisplayTicketInformation();



	//Seats seats;
	//std::cin >> seats;
	//const char* location = "Bucuresti strada ";
	//Event event(1,location,"Meci fotbal","24/12/2005","22:22",1,seats);
	//Event event;
	//std::cin >> event;
	//std::cout << event;

}
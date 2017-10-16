#include <iostream>

using namespace std;

//define class item
//important class for inheritance of subclasses Pen, Printer, Safebox
class Item
{
private:
	int _code;
	char* codeName;
	int _color;
	int _brand;
	double _height;
	double _length;
	double _width;
	double _weight;
	double _price;

public:
	Item(); //empty constructor

	Item(int code, int color, int brand, double height, double length, double width, double weight, double price); //non-empty constructor

																												   //set methods defined
	void set_code(int code);
	void set_color(int color);
	void set_brand(int brand);
	void set_height(double height);
	void set_length(double length);
	void set_width(double width);
	void set_weight(double weight);
	void set_price(double price);

	//get methods defined
	int get_code();
	char* get_codeName();
	int get_color();
	int get_brand();
	double get_height();
	double get_length();
	double get_width();
	double get_weight();
	double get_price();

	//display accessor defined
	void display();
};

//class Item empty constructor
Item::Item()
{
	_code = 0;
	_color = 0;
	_brand = 0;
	_height = 0;
	_length = 0;
	_width = 0;
	_weight = 0;
	_price = 0;
}

//class item non-empty constructor
Item::Item(int code, int color, int brand, double height, double length, double width, double weight, double price)
{
	_code = code;
	_color = color;
	_brand = brand;
	_height = height;
	_length = length;
	_width = width;
	_weight = weight;
	_price = price;
}

//set method for code
void Item::set_code(int code)
{
	_code = code;
}

//set method for color
void Item::set_color(int color)
{
	_color = color;
}

//set method for brand
void Item::set_brand(int brand)
{
	_brand = brand;
}

//set method for height
void Item::set_height(double height)
{
	_height = height;
}

//set method for length
void Item::set_length(double length)
{
	_length = length;
}

//set method for width
void Item::set_width(double width)
{
	_width = width;
}

//set method for weight
void Item::set_weight(double weight)
{
	_weight = weight;
}

//set method for price
void Item::set_price(double price)
{
	_price = price;
}

//get method for code
int Item::get_code()
{
	return _code;
}

//get method for code name
char* Item::get_codeName()
{
	if (_code == 1) { codeName = "Pen"; }
	else if (_code == 2) { codeName = "Printer"; }
	else if (_code == 3) { codeName = "Safe Box"; }
	return codeName;
}

//get method for color
int Item::get_color()
{
	return _color;
}

//get method for brand
int Item::get_brand()
{
	return _brand;
}

//get method for height
double Item::get_height()
{
	return _height;
}

//get method for length
double Item::get_length()
{
	return _length;
}

//get method for width
double Item::get_width()
{
	return _width;
}

//get method for weight
double Item::get_weight()
{
	return _weight;
}

//get method for price
double Item::get_price()
{
	return _price;
}

//accessor display definition
//used to print the class items to the screen
void Item::display()
{
	cout << "\n" << "Code Name: " << get_codeName()
		<< " Color: " << get_color()
		<< " Brand: " << get_brand()
		<< " Height: " << get_height()
		<< " Length: " << get_length()
		<< " Width: " << get_width()
		<< " Weight: " << get_weight()
		<< " Price: " << get_price() << "\n" << endl;
}

//Define Class Pen
//Class Pens inherit the class Item
class Pens : public Item
{
protected:
	int _type;
	bool _AssortedInk;
	int _PacketSize;
	char* _ColorName;
	char* Brand;
	char* TypeName;
	char* YesNo;
	int SummaryQuant;

public:
	//empty constructor
	Pens();

	//non-empty constructor
	Pens(int code, int color, int brand, double height, double length, double width, double weight, double price, int type, bool AssortedInk, int PacketSize);

	//set and get methods defined
	int getType();
	void setType(int type);
	bool getAssortedInk();
	void setAssortedInk(bool AssortedInk);
	bool getPacketSize();
	void setPacketSize(int PacketSize);
	char* getColorName();
	char* getBrandName();
	char* getTypeName();
	char* getInkBool();

	//display accessor for class Pens
	void display();

	//define summary for Pens
	double summary();
	double PenPriceTotal = 0;
};

//class empty constructor
Pens::Pens() : Item()
{
	_type = 0;
	_AssortedInk = 0;
	_PacketSize = 0;
}

//class Pens non-empty constructor
Pens::Pens(int code, int color, int brand, double height, double length, double width, double weight, double price, int type, bool AssortedInk, int PacketSize) :
	Item(code, color, brand, height, length, width, weight, price)
{
	_type = type;
	_AssortedInk = AssortedInk;
	_PacketSize = PacketSize;
}

//set method for type
void Pens::setType(int type)
{
	_type = type;
}

//set method for Packet Size
void Pens::setPacketSize(int PacketSize)
{
	_PacketSize = PacketSize;
}

//set method for Assorted Ink
void Pens::setAssortedInk(bool AssortedInk)
{
	_AssortedInk = AssortedInk;
}

//get method for type
int Pens::getType()
{
	return _type;
}

//get method for packet size
bool Pens::getPacketSize()
{
	return _PacketSize;
}

//get method for assorted ink
bool Pens::getAssortedInk()
{
	return _AssortedInk;
}

//function to get color name for class pen using get_color function from inherited class Item
char* Pens::getColorName()
{
	if (get_color() == 1) { _ColorName = "Red"; }
	else if (get_color() == 2) { _ColorName = "Blue"; }
	else if (get_color() == 3) { _ColorName = "Green"; }
	else if (get_color() == 2) { _ColorName = "Black"; }
	return _ColorName;
}

//function to get brand name for class pen using get_brand function from inherited class Item
char* Pens::getBrandName()
{
	if (get_brand() == 1) { Brand = "Pilot"; }
	else if (get_brand() == 2) { Brand = "Paper Mate"; }
	else if (get_brand() == 3) { Brand = "Uni-Ball"; }
	else if (get_brand() == 4) { Brand = "Sharpie"; }
	return Brand;
}

//function to get type name for class pen using get_type function from class Pens
char* Pens::getTypeName()
{
	if (getType() == 1) { TypeName = "Ball Point"; }
	else if (getType() == 2) { TypeName = "Roller Ball"; }
	else if (getType() == 3) { TypeName = "Fountain"; }
	else if (getType() == 4) { TypeName = "Calligraphy"; }
	return TypeName;
}



//function to get type name for class pen using getInkBool function from class Pens
char* Pens::getInkBool()
{
	if (getAssortedInk() == 0) { YesNo = "No"; }
	else if (getAssortedInk() == 1) { YesNo = "Yes"; }
	return YesNo;
}

//display accessor to print the bag contents for Pens items
void Pens::display()
{
	cout << "\n" << "Code name: " << get_codeName()
		<< " Color: " << getColorName()
		<< " Brand: " << getBrandName()
		<< " Height: " << get_height()
		<< " Length: " << get_length()
		<< " Width: " << get_width()
		<< " Weight: " << get_weight()
		<< " Price: " << get_price()
		<< " Type: " << getTypeName()
		<< " Assorted Ink: " << getInkBool()
		<< " Packet Size: " << getPacketSize() << "\n" << endl;
}

//summary function for the summary of price for all pen items
double Pens::summary()
{
	//every time the function gets called it adds pen item price to the total
	PenPriceTotal = PenPriceTotal + get_price();
	return PenPriceTotal;
}


//Define Class Printer
//Class Printer inherits the class Item
class Printer : public Item
{
protected:
	int _type;
	bool _network;
	int _TrayCapacity;
	char* ColorName;
	char* Brand;
	char* TypeName;
	char* YesNo;

public:
	//empty constructor
	Printer();

	//non-empty constructor
	Printer(int code, int color, int brand, double height, double length, double width, double weight, double price, int type, bool network, int TrayCapacity);

	//set and get methods defined
	int getType();
	void setType(int type);
	bool getNetwork();
	void setNetwork(bool network);
	bool getTrayCapacity();
	void setTrayCapacity(int TrayCapacity);
	char* getColorName();
	char* getBrandName();
	char* getTypeName();
	char* getNetworkBool();

	//display accessor for class Printer
	void display();

	//define summary for Printer
	double Summary();

	double PrinterPriceTotal = 0;
};

//class empty constructor
Printer::Printer() : Item()
{
	_type = 0;
	_network = 0;
	_TrayCapacity = 0;
}

//class Printer non-empty constructor
Printer::Printer(int code, int color, int brand, double height, double length, double width, double weight, double price, int type, bool network, int TrayCapacity) :
	Item(code, color, brand, height, length, width, weight, price)
{
	_type = type;
	_network = network;
	_TrayCapacity = TrayCapacity;
}

//set method for type
void Printer::setType(int type)
{
	_type = type;
}

//set method for network
void Printer::setNetwork(bool network)
{
	_network = network;
}

//set method for tray capacity
void Printer::setTrayCapacity(int TrayCapacity)
{
	_TrayCapacity = TrayCapacity;
}

//get method for type
int Printer::getType()
{
	return _type;
}

//get method for network
bool Printer::getNetwork()
{
	return _network;
}

//get method for tray capacity
bool Printer::getTrayCapacity()
{
	return _TrayCapacity;
}

//function to get color name for class printer using get_color function from inherited class Item
char* Printer::getColorName()
{
	if (get_color() == 1) { ColorName = "Black"; }
	else if (get_color() == 2) { ColorName = "White"; }
	return ColorName;
}

//function to get brand name for class printer using get_brand function from inherited class Item
char* Printer::getBrandName()
{
	if (get_brand() == 1) { Brand = "Dell"; }
	else if (get_brand() == 2) { Brand = "HP"; }
	else if (get_brand() == 3) { Brand = "Cannon"; }
	else if (get_brand() == 4) { Brand = "Brother"; }
	return Brand;
}

//function to get type name for class printer using getType function from class Printer
char* Printer::getTypeName()
{
	if (getType() == 1) { TypeName = "All-In-One"; }
	else if (getType() == 2) { TypeName = "Laser"; }
	else if (getType() == 3) { TypeName = "InkJet"; }
	return TypeName;
}



//function to answer the question to whether the printer is a network printer
char* Printer::getNetworkBool()
{
	if (getNetwork() == 0) { YesNo = "No"; }
	else if (getNetwork() == 1) { YesNo = "Yes"; }
	return YesNo;
}

//display accessor to print the bag contents for printer items
void Printer::display()
{
	cout << "\n" << "Code name: " << get_codeName()
		<< " Color: " << getColorName()
		<< " Brand: " << getBrandName()
		<< " Height: " << get_height()
		<< " Length: " << get_length()
		<< " Width: " << get_width()
		<< " Weight: " << get_weight()
		<< " Price: " << get_price()
		<< " Type: " << getTypeName()
		<< " Network: " << getNetworkBool()
		<< " Tray Capacity: " << getTrayCapacity() << "\n" << endl;
}

//summary function for the summary of price for all printer items
double Printer::Summary()
{
	//every time the function gets called it adds printer item price to the total
	PrinterPriceTotal = PrinterPriceTotal + get_price();
	return PrinterPriceTotal;
}


//Define Class Safebox
//Class Safebox inherits the class Item
class SafeBox : public Item
{
protected:
	int _type;
	bool _FireResistant;
	int _ElectronicLock;
	char* ColorName;
	char* Brand;
	char* TypeName;
	char* YesNo;

public:
	//empty constructor
	SafeBox();

	//non-empty constructor
	SafeBox(int code, int color, int brand, double height, double length, double width, double weight, double price, int type, bool FireResistant, bool ElectronicLock);

	//set and get methods defined
	int getType();
	void setType(int type);
	bool getFireResistant();
	void setFireResistant(bool FireResistant);
	bool getElectronicLock();
	void setElectronicLock(bool ElectronicLock);
	char* getColorName();
	char* getBrandName();
	char* getTypeName();
	char* getFireResistantYesNo();
	char* getElectronicLockYesNo();

	//display accessor for class safebox
	void display();

	//define summary for safebox
	double Summary();

	double SafeBoxPriceTotal = 0;
};

//class empty constructor
SafeBox::SafeBox() : Item()
{
	_type = 0;
	_FireResistant = 0;
	_ElectronicLock = 0;
}

//class safebox non-empty constructor
SafeBox::SafeBox(int code, int color, int brand, double height, double length, double width, double weight, double price, int type, bool FireResistant, bool ElectronicLock) :
	Item(code, color, brand, height, length, width, weight, price)
{
	_type = type;
	_FireResistant = FireResistant;
	_ElectronicLock = ElectronicLock;
}


//set method for type
void SafeBox::setType(int type)
{
	_type = type;
}

//set method for fire resistant
void SafeBox::setFireResistant(bool FireResistant)
{
	_FireResistant = FireResistant;
}

//set method for electronic lock
void SafeBox::setElectronicLock(bool ElectronicLock)
{
	_ElectronicLock = ElectronicLock;
}

//get method for type
int SafeBox::getType()
{
	return _type;
}

//get method for fire resistant
bool SafeBox::getFireResistant()
{
	return _FireResistant;
}

//get method for electronic lock
bool SafeBox::getElectronicLock()
{
	return _ElectronicLock;
}

//function to get color name for class safebox using get_color function from inherited class Item
char* SafeBox::getColorName()
{
	if (get_color() == 1) { ColorName = "Black"; }
	else if (get_color() == 2) { ColorName = "Red"; }
	return ColorName;
}

//function to get brand name for class safebox using get_brand function from inherited class Item
char* SafeBox::getBrandName()
{
	if (get_brand() == 1) { Brand = "SentrySafe"; }
	else if (get_brand() == 2) { Brand = "First Alet"; }
	else if (get_brand() == 3) { Brand = "Honeywell"; }
	return Brand;
}

//function to get type name for class SafeBox using getType function from class SafeBox
char* SafeBox::getTypeName()
{
	if (getType() == 1) { TypeName = "Water Proof"; }
	else if (getType() == 2) { TypeName = "Wall Mountable"; }
	else if (getType() == 3) { TypeName = "Desktop"; }
	return TypeName;
}



//function to answer the question to whether the safebox is fire resistant
char* SafeBox::getFireResistantYesNo()
{
	if (getFireResistant() == 0) { YesNo = "No"; }
	else if (getFireResistant() == 1) { YesNo = "Yes"; }
	return YesNo;
}

//function to answer the question to whether the safebox has an electronic lock
char* SafeBox::getElectronicLockYesNo()
{
	if (getElectronicLock() == 0) { YesNo = "No"; }
	else if (getElectronicLock() == 1) { YesNo = "Yes"; }
	return YesNo;
}

//display accessor to print the bag contents for safebox items
void SafeBox::display()
{
	cout << "\n" << "Code name: " << get_codeName()
		<< " Color: " << getColorName()
		<< " Brand: " << getBrandName()
		<< " Height: " << get_height()
		<< " Length: " << get_length()
		<< " Width: " << get_width()
		<< " Weight: " << get_weight()
		<< " Price: " << get_price()
		<< " Type: " << getTypeName()
		<< " Fire Resistant: " << getFireResistantYesNo()
		<< " Electronic Lock: " << getElectronicLock() << "\n" << endl;
}

//summary function for the summary of price for all safebox items
double SafeBox::Summary()
{
	//every time the function gets called it adds safebox item price to the total
	SafeBoxPriceTotal = SafeBoxPriceTotal + get_price();
	return SafeBoxPriceTotal;
}

















int main() {

	//cout << "Hello world!!" << std::endl;

	Item* Bag[256]; //array bag
	Pens* onePen; //defining pointer of the class type pens
	Printer* onePrinter; //defining pointer of the class type printer
	SafeBox* oneSafeBox; // defining pointer of the class type safebox

	//defining variables for cin
	char command[1000]; //since the string is not used, defined the command in array
	int quantity;
	int BagCount = 0;
	int code;
	int color;
	int brand;
	double height;
	double length;
	double width;
	double weight;
	double price;
	int type;
	bool attribute10;
	int attribute11;
	int bagPosition = 0;
	int noItems = 0;
	double totalPrice = 0;
	int PenCount = 0;
	int PrinterCount = 0;
	int SafeBoxCount = 0;

	cout << "--------------------\n" << "Read lines: " << endl;

	
	while (!cin.eof()) // while end of line is not reached
	{
		cin >> command >> quantity >> code >> color >> brand >> height >> length >> width >> weight >> price >> type >> attribute10 >> attribute11;

		cout << command << "; "
			<< quantity << "; "
			<< code << "; "
			<< color << "; "
			<< brand << "; "
			<< height << "; "
			<< length << "; "
			<< width << "; "
			<< weight << "; "
			<< price << "; "
			<< type << "; "
			<< attribute10 << "; "
			<< attribute11 << endl;

		for (int i = 0; i < quantity; i++)
		{
			if (code == 1) { Bag[noItems + i] = new Pens(code, color, brand, height, length, width, weight, price, type, attribute10, attribute11); }
			else if (code == 2) { Bag[noItems + i] = new Printer(code, color, brand, height, length, width, weight, price, type, attribute10, attribute11); }
			else if (code == 3) { Bag[noItems + i] = new SafeBox(code, color, brand, height, length, width, weight, price, type, attribute10, attribute11); }
		}

		noItems = noItems + quantity; //count the number of items created
		totalPrice = totalPrice + price*quantity; //add the total price of all items

	}

	cout << "\n" << "******** Bag Items ********\n\n";
	//for all the items in the bag call the accessor for the appropriate item - pen, printer, or safebox
	for (int i = 0; i < noItems; i++)
	{
		switch ((*Bag[i]).get_code()) {

		//pens
		case 1: {
			cout << "Bag Item " << i << " ";
			(static_cast<Pens*>(Bag[i]))->display();
			PenCount++; //keep track of the number of pens for the summary
			break;
		}

		//printers
		case 2: {
			cout << "Bag Item " << i << " ";
			(static_cast<Printer*>(Bag[i]))->display();
			PrinterCount++; //keep track of the number of printers for the summary
			break;
		}
		
		//safeboxes
		case 3: {
			cout << "Bag Item " << i << " ";
			(static_cast<SafeBox*>(Bag[i]))->display();
			SafeBoxCount++; //keep track of the number of safeboxes for the summary
			break;
		}
		
		default: cout << "I do not recognize this item in the bag." << endl; //error check
		}
	}

	double PenSum = 0;
	double PrinterSum = 0;
	double SafeBoxSum = 0;

	cout << "\n--------------------\n" << "Summary:\n" << endl;

	for (int i = 0; i < noItems; i++)
	{
		switch ((*Bag[i]).get_code()) {

		//pens summary
		case 1: {
			PenSum += (static_cast<Pens*>(Bag[i]))->summary();
			break;
		}

		//printers summary
		case 2: {
			PrinterSum += (static_cast<Printer*>(Bag[i]))->Summary();
			break;
		}

		//safeboxes summary
		case 3: {
			SafeBoxSum += (static_cast<SafeBox*>(Bag[i]))->Summary();
			break;
		}

		default: cout << "I do not recognize this item in the bag." << endl;
		}

	}

	//display summary
	cout << "Pen count: " << PenCount << "\n"
		<< "Pen price: " << PenSum << "\n"
		<< "Printer count: " << PrinterCount << "\n"
		<< "Printer price: " << PrinterSum << "\n"
		<< "Safebox count: " << SafeBoxCount << "\n"
		<< "Safebox price: " << SafeBoxSum << "\n"
		<< "Total bag price: " << totalPrice << "\n"
		<< endl;
	system("PAUSE");
	return 0;

}

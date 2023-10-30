#include "rental.h"

Admin::Admin()
{
  adminCount = 20;
  ptrID = new string[adminCount];
  ptrPassword = new string[adminCount];
}

Admin::~Admin()
{
  delete ptrID;
  ptrID = nullptr;
  delete ptrPassword;
  ptrPassword = nullptr;
}

Customer::Customer()
{
  creditScore = 0;
}

Customer::~Customer()
{
  
}

InventoryItem::InventoryItem()
{
  vector<string> listOfCars;
  vector<float> listOfPrices;
  readSportsCar();
  readOffroadCar();
  readSUVCar();
}

InventoryItem::~InventoryItem()
{
  listOfCars.clear();
  listOfPrices.clear();
}

Sports::Sports(string sportsCar, float sportsPrice)
{
  this->sportsCar = sportsCar;
  this-> sportsPrice = sportsPrice;
}

Sports::~Sports()
{

}

SUV::SUV(string SUVCar, float SUVPrice)
{
  this->SUVCar = SUVCar;
  this->SUVPrice = SUVPrice;
}

SUV::~SUV()
{

}

Offroad::Offroad(string offroadCar, float offroadPrice)
{
  this->offroadCar = offroadCar;
  this->offroadPrice = offroadPrice;
}

Offroad::~Offroad()
{

}

Cart::Cart()
{
  vector<string> receiptCars;
  vector<float> recieptPrice;
}

Cart::~Cart()
{
  receiptCars.clear();
  receiptPrice.clear();
}

Dealer::Dealer()
{
  vector<InventoryItem*> cars;
}

Dealer::~Dealer()
{
  cars.clear();
}

void InventoryItem::print()
{
   
}

void displayMenu()
{
    cout << "1.  Login As Admin\n"
              << "2.  Login As Customer\n"
              << "3.  End Program\n"
              << "Enter Choice:  ";
}

void displayMenu2()
{
  cout << "1.  Add Car\n"
              << "2.  Remove Car\n"
              << "3.  Show Cars\n"
              << "4.  Logout\n"
              << "Enter Choice:  ";
}

void displayMenu3()
{
  cout << "1.  Print Cars\n"
              << "2.  Search Car\n"
              << "3.  Select Car\n"
              << "4.  Show Cart\n"
              << "5.  Checkout\n"
              << "6.  Logout\n"
              << "Enter Choice:  ";
}

int getChoice(int & choice1) 
{
  cin >> choice1; 
  cin.ignore();
  cout << endl;
    while (choice1 < 1 || choice1 > 3) {
      cout << endl;
      cout << "Invalid Entry!!\n" << endl;
      cout << "Enter Choice:  ";
      cin >> choice1; 
      cin.ignore();
      cout << endl;
    }
  return choice1;
}
int getChoice2(int & choice2)
{
  cin >> choice2; 
  cout << endl;
    while (choice2 < 1 || choice2 > 4) {
      cout << endl;
      cout << "Invalid Entry!!\n" << endl;
      cout << "Enter Choice:  ";
      cin >> choice2; 
      cout << endl;
    }
  return choice2;
}

int getChoice3(int & choice3)
{
  cin >> choice3; 
  cout << endl;
  cin.ignore();
    while (choice3 < 1 || choice3 > 6) {
      cout << endl;
      cout << "Invalid Entry!!\n" << endl;
      cout << "Enter Choice:  ";
      cin >> choice3; 
      cout << endl;
      cin.ignore();
    }
  return choice3;
}

int endProgram(bool & start1) //ends the program
{
  start1 = false;
  cout << "\n\n\t\tThank you for using this system!!\n\n";
  return start1;
}

void Admin::loginInfo()
{
  string word;
  ifstream input(FILE_NAME);
  if (!input) 
  {
    cout << "File does not exist " << FILE_NAME << endl;
    return;
  }
  int index = 0;
  while (!input.eof()) 
    {
      getline(input, word);
      ptrID[index] = word;
      getline(input, word);
      ptrPassword[index] = word;
      index++;
    }
}

void Admin::login()
{
  string id;
  string password;
  int i = 0;
  do 
  {
    cout << endl;
    cout << "Enter your id: ";
    getline(cin >> ws, id);
    cout << "Enter your password: ";
    getline(cin >> ws, password);
    while (i < adminCount) {
      if (ptrID[i] == id && ptrPassword[i] == password)
      {
        cout << endl;
        cout << "Successful Login\n";
        cout << endl;
        return;
      }
      i++; 
    }
    i = 0;
    if (ptrID[i] != id || ptrPassword[i] != password)
    {
      cout << endl;
      cout << "Login Unsuccessful\n" << endl;
    }
  } while (ptrID[i] != id || ptrPassword[i] != password); 
}

void Customer::login()
{
  int limit = 620;
  int limit2 = 850;
  cout << "What is your credit Score: ";
  cin >> creditScore;
  cout << endl;
  cin.ignore();
  while (creditScore < limit || creditScore > limit2)
  {
    cout << "\n Your credit score must be higher than 620 and can't be more than 850! \n" << endl;
    cout << "What is your credit Score: ";
    cin >> creditScore;
    cout << endl;
    cin.ignore();
  }
}

void Sports::print()
{
  const int spacing = 20;
  cout << "Car: " << left << setw(spacing) << sportsCar << " Price: $" << sportsPrice << endl;
}

void Offroad::print()
{
  const int spacing = 20;
  cout << "Car: " << left << setw(spacing) << offroadCar << " Price: $" << offroadPrice << endl;
}

void SUV::print()
{
  const int spacing = 20;
  cout << "Car: " << left << setw(spacing) << SUVCar << " Price: $" << SUVPrice << endl;
}

void Dealer::readOffRoad()
{
  string car;
  float price;
  string priceString;
  ifstream input(OFFROAD_CARS);
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, car);
      input >> price;
      input.ignore();
      cars.push_back(new Offroad(car, price));
    }
    input.close();
  }
}

void Dealer::readSports()
{
  string car;
  float price;
  string priceString;
  ifstream input(SPORTS_CARS);
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, car);
      input >> price;
      input.ignore();
      cars.push_back(new Sports(car, price));
    }
    input.close();
  }
}

void Dealer::readSUV()
{
  string car;
  float price;
  string priceString;
  ifstream input(SUV_CARS);
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, car);
      input >> price;
      input.ignore();
      cars.push_back(new SUV(car, price));        
    }
    input.close();
  }
}

void Dealer::print()
{
  readSports();
  readOffRoad();
  readSUV();
  for (InventoryItem* ptr : cars)
  {
    ptr->print();
  }
}

void InventoryItem::readSportsCar()
{
  string car;
  float price;
  ifstream input(SPORTS_CARS);
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, car);
      input >> price;
      input.ignore();
      listOfCars.push_back(car);
      listOfPrices.push_back(price);
    }
    input.close();
  }
}

void InventoryItem::readOffroadCar()
{
  string car;
  float price;
  ifstream input(OFFROAD_CARS);
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, car);
      input >> price;
      input.ignore();
      listOfCars.push_back(car);
      listOfPrices.push_back(price);
    }
    input.close();
  }
}

void InventoryItem::readSUVCar()
{
  string car;
  float price;
  ifstream input(SUV_CARS);
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, car);
      input >> price;
      input.ignore();
      listOfCars.push_back(car);
      listOfPrices.push_back(price);
    }
    input.close();
  }
}

void InventoryItem::search()
{
  cout << "What car are you looking for: ";
  getline(cin, car);
  for (int i = 0; i < listOfCars.size(); i++)
  {
    if (car == listOfCars[i])
    {
      cout << "The " << listOfCars[i] << " was found" << endl;
      cout << "This car is priced at $" << listOfPrices[i] << " per month\n" << endl;
      return;
    }
  }
  cout << "Car Not Found.\n\n";
}

void InventoryItem::showCars()
{
  cout << "Our inventory includes: " << endl;
  const int spacing = 20;
  for (int i = 0; i < listOfCars.size(); i++)
  {
    cout << "Car: " << left << setw(spacing) << listOfCars[i] << " Price: $" << listOfPrices[i] << endl;
  }
}

void InventoryItem::add()
{
  string carType;
  string carName;
  float carPrice;
  cout << "What is the name of the car: ";
  getline(cin >> ws, carName);
  cout << "what is the price of the car: ";
  cin >> carPrice;
  listOfCars.push_back(carName);
  listOfPrices.push_back(carPrice);
  cout << "The car " << carName << " was added\n" << endl;
}

void InventoryItem::remove()
{
  string carName;
  cout << "What car is being removed: ";
  getline(cin >> ws, carName);
  for (int i = 0; i < listOfCars.size(); i++)
  {
    if (listOfCars[i] == carName)
    {
      listOfCars.erase(listOfCars.begin()+i);
      listOfPrices.erase(listOfPrices.begin()+i);
      cout << "Car was removed\n" << endl;
      return;
    }
  }
  cout << "Car was not found\n" << endl;
}

void Cart::select()
{
  InventoryItem a;
  string carName;
  cout << "What car do you want: ";
  getline(cin >> ws, carName);
  for (int i = 0; i < a.listOfCars.size(); i++)
  {
    if (a.listOfCars[i] == carName)
    {
      receiptCars.push_back(a.listOfCars[i]);
      receiptPrice.push_back(a.listOfPrices[i]);
      cout << "The " << a.listOfCars[i] << " was added to your cart\n" << endl;
      return;
    }
  }
  cout << "Car was not found\n" << endl;
}

void Cart::checkout()
{
  const int spacing = 20;
  float finalPrice;
  cout << "The reciept includes: " << endl;
  for (int i = 0; i < receiptPrice.size(); i++)
  {
    cout << "Car: " << left << setw(spacing) << receiptCars[i] << " Price: $" << receiptPrice[i] << endl;
    finalPrice += receiptPrice[i];
  }
  cout << "You owe $" << finalPrice << " per day\n" << endl;
}

void Cart::showCart()
{
  const int spacing = 20;
  for (int i = 0; i < receiptCars.size(); i++)
  {
    cout << "Car: " << left << setw(spacing) << receiptCars[i] << " Price: $" << receiptPrice[i] << endl;
    cout << endl;
  }
}
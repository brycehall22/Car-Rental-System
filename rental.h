/*
Author: Bryce Hall
Class : CSI - 240 / 01 : Advanced Programming
Assignment : Final Project
Date Assigned : 4/10/22
Due Date : 4/25/22 11:59PM

Description :
Create the proposed program which is a car rental system

Certification of Authenticity :

I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const string FILE_NAME = "admin.dat";
const string OFFROAD_CARS = "offroad.dat";
const string SPORTS_CARS = "sports.dat";
const string SUV_CARS = "SUV.dat";

class User
{
public:
virtual void login()=0;
};


class Admin : public User
{
public:
  Admin();
  ~Admin();
  void login();
  void loginInfo();
private:
  int adminCount;
  int adminTotal;
  string *ptrID;
  string *ptrPassword;
};

class Customer : public User
{
public:
  Customer();
  ~Customer();
  void login();

private:
  int creditScore;
};

class InventoryItem
{
public: 
  InventoryItem();
  ~InventoryItem();
  friend class Cart;
  void readSportsCar();
  void readOffroadCar();
  void readSUVCar();
  virtual void print();
  void search();
  void showCars();
  void remove();
  void add();
  string car;
  vector<string> listOfCars;
  vector<float> listOfPrices;
};

class Cart
{
public:
  Cart();
  ~Cart();
  void checkout();
  void select();
  void showCart();
  vector<string> receiptCars;
  vector<float> receiptPrice;
};

class Dealer
{
public:
  Dealer();
  ~Dealer();
	void readOffRoad();
	void readSports();
	void readSUV();
	void print();
	vector<InventoryItem*> cars;
};

class Sports : public InventoryItem
{
public:
  Sports(){}
  Sports(string sportsCar, float sportsPrice);
  ~Sports();
  void print();
  string getSportsCar(){return sportsCar;}
  float GetSportsPrice(){return sportsPrice;}

protected:
  string sportsCar;
  float sportsPrice;
};

class SUV : public InventoryItem
{
public: 
  SUV(){}
  SUV(string SUVCar, float SUVPrice);
  ~SUV();
  void print();
  string getSUVCar(){return SUVCar;}
  float getSUVPrice(){return SUVPrice;}

protected:
  string SUVCar;
  float SUVPrice;
};

class Offroad : public InventoryItem
{
public:
  Offroad() {}
  Offroad(string offroaadCar, float offroadPrice);
  ~Offroad();
  void print();
  string getOffroadCar(){return offroadCar;}
  float getOffroadPrice(){return offroadPrice;}

protected: 
  string offroadCar;
  float offroadPrice;
};

int getChoice(int & choice1);
int getChoice2(int & choice2);
int getChoice3(int & choice3);
void displayMenu();
void displayMenu2();
void displayMenu3();
int endProgram(bool & start1);
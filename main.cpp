#include <iostream>
#include "rental.h"

int main() {
  int choice = 0;
  int adminChoice = 0;
  int customerChoice = 0;
  bool doOnce = true;
  bool start = true; 
  Admin theAdmin;
  Dealer dealer;
  Cart theCart;
  InventoryItem inventory;
  string carName;
  while (start == true)
  {
    while (choice != 3) 
    {
      int adminChoice = 0;
      int customerChoice = 0;
      displayMenu();
      getChoice(choice);
      if (choice == 1)
      {
        theAdmin.loginInfo();
        theAdmin.login();
        while (adminChoice != 4)
        {
          if (doOnce == true)
          {
            cout << "Our inventory includes: " << endl;
            dealer.print();
            doOnce = false;
            cout << endl;
          }
          displayMenu2();
          getChoice2(adminChoice);
          switch (adminChoice)
          {
           case 1:
              inventory.add();
              break;
           case 2:
              inventory.remove();
              break;
            case 3:
              inventory.showCars();
              cout << endl;
              break;
           case 4:
              continue;
          }
        }
      }
      if (choice == 2)
      {
        Customer theCustomer;
        theCustomer.login();
        while(customerChoice != 6)
        {
          if (doOnce == true)
          {
            cout << "Our inventory includes: " << endl;
            dealer.print();
            doOnce = false;
            cout << endl;
          }
          displayMenu3();
          getChoice3(customerChoice);
          switch (customerChoice)
          {
           case 1:
              inventory.showCars();
              cout << endl;
              break;
           case 2:
              inventory.search();
              break;
           case 3:
              theCart.select();
              break;
           case 4:
              theCart.showCart();
              break;
           case 5:
              theCart.checkout();
              break;
            case 6:
              continue;
        }
      }
      }
      if (choice == 3)
      {
        endProgram(start);
      }
    }
  }
}
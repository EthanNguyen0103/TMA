#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
 

// function prototypes

void printIntroMenu();

void printMainMenu();

void start();

void login();

void createAccount();

void user();
 

// global variable (use this variable to store the user’s menu selection)

char menuInput;
char userInput;
std::vector <std::string> userName;
std::vector <std::string> userPass;
std::string newUserName;
std::string newUserPass;
int userMoney {0};
int newUserMoney {0};

 
 

// the main function

int main()

{
  // TO WRITE A WELCOME MESSAGE HERE
  std::cout << "Hi! Welcome to Mr.Zamar's ATM Machine" << std::endl;
  // call the function start
  start();

 

  std::cout << std::endl;
  return 0;
}

 

void printIntroMenu()

{
  // WRITE CODE HERE
  std::cout<<"\tPlease select an option from the menu below:" << std::endl;
  std::cout<<"l -> Login" << std::endl;
  std::cout<<"c -> Create New Account" << std::endl;
  std::cout<<"q -> Quit" << std::endl;
}

 

void printMainMenu()

{
  // WRITE CODE HERE
  std::cout<<"d -> Deposit Money" << std::endl;
  std::cout<<"w -> Withdraw Money" << std::endl;
  std::cout<<"r -> Request Balance" << std::endl;
  std::cout<<"q -> Quit" << std::endl;
}

 

void start()

{
  // EXPLANATION OF CODE THAT GOES HERE IS BELOW
  while (1)
  {
    std::cout << "Please select an option from the menu below:" << std::endl;
    printIntroMenu();
    std::cin >> menuInput;
    /* code */  
    switch (menuInput)
    {
    case 'l':
      login();
      break;
    case 'c':
      createAccount();
      break;
    case 'q':
      std::cout << "Thanks for stopping by!" << std::endl;
      exit(0);
      break;
    default:
      std::cout << "Error command" << std::endl;
      break;
    }
  }
  
}


void createAccount()

{
  // PHASE 2 

  std::cout << "Please enter your user name: ";
  std::cin >> newUserName;
  userName.push_back(newUserName);
  std::cout << "Please enter your password: "; 
  std::cin >> newUserPass;
  userPass.push_back(newUserPass);
  std::cout << "Thank You! Your account has been created!" << std::endl;
}

 

void login()

{

  // PHASE 2
  std::cout << "Please enter your user name: ";
  std::cin >> newUserName;
  std::cout << "Please enter your password: "; 
  std::cin >> newUserPass;
  if(newUserName.empty()){
    std::cout << "******** LOGIN FAILED! ********" << std::endl;
  }
  for(int i =0; i< userName.size();i++){
    if(newUserName==userName[i] && newUserPass==userPass[i]){
      std::cout << "Access Granted!" << std::endl;
      user();
    }
    else
      std::cout << "******** LOGIN FAILED! ********" << std::endl;
  }
}

void user(){
  while (1)
  {
    printMainMenu();
    std::cin>> userInput;
    switch (userInput)
    {
    case 'd':
      std::cout <<"Amount of deposit: ";
      std::cin >> userMoney;
      break;
    case 'w':
      std::cout <<"Amount of withdraw: ";
      std::cin >> newUserMoney;
      if(userMoney<=0 || newUserMoney >userMoney)
      {
        std::cout <<"Don't have enough month to withdraw" << std::endl;
        break;
      }
      userMoney -= newUserMoney;
      break;
    case 'r':
      std::cout <<"Your balance is: " << userMoney << std::endl; 
      break;
    case 'q':
      std::cout << "Thanks for stopping by!" << std::endl;
      exit(0);
      break;
    default:
      std::cout << "Error command" << std::endl;
      break;
    }
  }
}

// CODE ENDS HERE
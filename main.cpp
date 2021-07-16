#include <iostream>
#include "Nodes.h"
#include <cstring>
#include <vector>
using namespace std;

void beach(Beach & b);
void shopping(Shopping & s);
void restaurant(Restaurant & r);

int main(){
  cout << "Welcome to Event Planner!" << endl;
  char choice = 'a';

  do {
    cout << " " << endl;
    cout << "-----------------------" << endl;
    cout << "Select an event to plan." << endl;
    cout << "1 - Beach Trip" << endl;
    cout << "2 - Shopping Trip" << endl;
    cout << "3 - Restaurant" << endl;
    cout << "q - quit program" << endl;
    cin >> choice;
    cin.ignore(1000, '\n');
    
    //beach
    if(choice == '1'){
      int a = 0;
      string word;
      char food[150];
      char dir[500];
      vector<string> vtr;
      char yn[5];
      cout << "Enter the amount of items you would like to " << endl;
      cout << "add to the list of things to bring to the beach" << endl;
      cout << "> ";
      cin >> a;
      cin.ignore(1000, '\n');
      cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

      for(int i = 0; i < a; i++){
	cout << "> ";
	getline(cin, word);
	vtr.push_back(word);
      }
      cout << "Please enter what you plan to do for food (go out, bring lunch, etc)." << endl;
      cout << "> ";
      cin.get(food, 150);
      cin.get();
      cout << "Enter the directions to the beach: " << endl;
      cout << "> ";
      cin.get(dir, 500);
      cin.get();
      Beach b(vtr, dir, food);
      b.read();
      
      cout << "Would you like to change any fields or look at more beach options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
	beach(b);
      }
    }
    
    //shopping
    else if (choice == '2'){
      int a = 0;
      int b = 0;
      string word;
      string item;
      vector<string> shops;
      vector<string> items;
      int bg;
      char yn[5];

      cout << "Enter the amount of stores you would like to visit." << endl;
      cin >> a;
      cin.get();
      cout << "Enter each store in 1 at a time, separated by a newline." << endl;
      for(int i = 0; i < a; i++){
	cout << "> ";
	getline(cin, word);
	shops.push_back(word);
      }
      cout << "Enter how many items you would like to add to your shopping list" << endl;
      cin >> b;
      cin.get();
      cout << "Enter each item in 1 at a time, separated by a newline." << endl;
      for(int j = 0; j < b; j++){
	cout << "> ";
	getline(cin, item);
	items.push_back(item);
      }

      cout << "What is your budget for this shopping trip?" << endl;
      cout << "> ";
      cin >> bg;
      cin.get();

      Shopping s(shops, items, bg);
      s.read();
      cout << "Would you like to change any fields or look at more shopping options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
	shopping(s);
      }
    }

    //restaurant
    else if(choice == '3'){
      Restaurant r;
      char yn[5];
      r.read();
      cout << "Would you like to change or view more restaurant options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
	restaurant(r);
      }
    }
  } while(choice != 'q'); 
  
  
  return 0;
}

void beach(Beach & b){
  char choice;
  string word;
  int amount;
  vector<string> to_add;
  vector<string> to_remove;

  cout << "Select an option." << endl;
  cout << "1 - add items to bring to the beach " << endl;
  cout << "2 - remove from the list of items to bring" << endl;
  cout << "3 - display your current beach trip details" << endl;
  cout << "4 - check the weather at the beach" << endl;
  cout << "5 - hear a fun fact about this beach" << endl;
  cin >> choice;
  cin.ignore(1000, '\n');

  //add items
  if (choice == 1){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add.push_back(word);
    }    
  }

  //remove items
  else if (choice == 2){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove.push_back(word);
    }    
  }

  //display
  else if (choice == 3){
    b.display();
  }

  //check weather
  else if (choice == 4){
    b.check_weather();
  } 

  //fun fact
  else if (choice == 5){
    b.fun_fact();
  }

  else {
    cout << "That was not one of the options." << endl;
  }
  
}

void shopping(Shopping & s){
  char i;
  vector<string> to_add1;
  vector<string> to_remove1;
  vector<string> to_add2;
  vector<string> to_remove2;
  int amount;
  string word;
  
  cout << "Select an option." << endl;
  cout << "1 - Add stores to the list. " << endl;
  cout << "2 - Remove stores from the list." << endl;
  cout << "3 - Add items to your shopping list. " << endl;
  cout << "4 - Remove items from your shopping list." << endl;
  cout << "5 - Display all details of your shopping trip." << endl;
  cout << "> ";
  cin >> i;
  cin.get();

  if(i == '1'){
    cout << "how many stores would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each store (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add1.push_back(word);
    }    
    s.add_stores(to_add1);
  }

  else if(i == '2'){
    cout << "how many stores would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each store (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove1.push_back(word);
    }    
    s.remove_stores(to_remove1);
  }

  else if(i == '3'){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add2.push_back(word);
    }
    s.add_items(to_add2);
  }

  else if(i == '4'){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove2.push_back(word);
    }    
    s.remove_items(to_remove2);
  }

  else if(i == '5'){
    s.display();
  }
}

void restaurant(Restaurant & r){
  CLL rest;
  char c;
  char d;
  char name[50];
  
  cout << "Select an option." << endl;
  cout << "1 - Get the contact info of the restaurant." << endl;
  cout << "2 - Write a yelp review of this restaurant." << endl;
  cout << "3 - Display all restaurant details." << endl;
  cout << "4 - Data structures stuff" << endl;
  cout << "> ";
  cin >> c;
  cin.get();
  if(c == '1'){
    r.contact_info();
  } else if (c == '2'){
    r.write_yelp_review();
  } else if (c == '3'){
    r.display();
  } else if (c == '4'){
    cout << "Select an option. " << endl;
    cout << "1 - add another restaurant" << endl;
    cout << "2 - remove a restaurant" << endl;
    cout << "3 - display all restaurants" << endl;
    cout << "4 - remove all restaurants" << endl;
    cin >> d;
    cin.get();

    if(c == '1'){
      Restaurant n;
      n.read();
      rest.insert(n);
    }

    else if(c == '2'){
      cout << "Enter the name of the restaurant you would like to remove." << endl;
      cout << "> ";
      cin.get(name, 50);
      cin.get();
      rest.remove(name);
    }

    else if(c == '3'){
      rest.display();
    }

    else if(c == '4'){
      rest.remove_all();
    }

    else {
      cout << "That was not one of the options." << endl;
    }
  }  
}

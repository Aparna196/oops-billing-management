#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include<algorithm>
using namespace std;

class Bill{
private:
 string Item;
 int Rate, Quantity;
public:
 Bill():Item(""), Rate(0), Quantity(0){ }
 
 void setItem(string item){
 Item = item;
 }
 
void setRate(int rate){
 Rate = rate;
}
void setQuant(int quant){
 Quantity = quant;
}

string getItem(){
return Item;
}

int getRate(){
 return Rate;
}

int getQuant(){
 return Quantity;
}

};

string toLower(string str){

    transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;
}
void addItem(Bill &b){
bool close = false;
while(!close){
	int choice;
cout<<"\t1.Add."<<endl;
cout<<"\t2.close."<<endl;
cout<<"\tEnter Choice: ";
if(!(cin >> choice)){
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "\tInvalid Choice!" << endl;
    Sleep(2000);
    continue;
}

if(choice==1){
	system("cls");
string item;
int rate, quant;

cout<<"\tEnter Item Name: ";
cin.ignore();
getline(cin, item);
b.setItem(item);

cout << "\tEnter Rate Of Item: ";

while(true){

    if(!(cin >> rate)){

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "\tInvalid Input! Enter Numeric Value: ";
    }

    else if(rate <= 0){

        cout << "\tRate Must Be Greater Than 0: ";
    }

    else{
        break;
    }
}

b.setRate(rate);

cout << "\tEnter Quantity Of Item: ";

while(true){

    if(!(cin >> quant)){

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "\tInvalid Input! Enter Numeric Value: ";
    }

    else if(quant <= 0){

        cout << "\tQuantity Must Be Greater Than 0: ";
    }

    else{
        break;
    }
}

b.setQuant(quant);

ofstream out("Bill.txt", ios::app);
if(!out){
	cout<<"\tError: File Can't Open!"<<endl;
}
else{
out<<b.getItem()<<" "<<b.getRate()<<" "<<b.getQuant()<<endl;
}
out.close();
cout<<"\tItem Added Successfuly"<<endl;
Sleep(3000);
}

else if(choice == 2){
	system("cls");
close = true;
cout<<"\tBack To Main Menu!"<<endl;
Sleep(3000);
}
else{
    cout<<"\tInvalid Choice!"<<endl;
    Sleep(2000);
}
}
}

void printBill(){
system("cls");
int count = 0;
bool close = false;
while(!close){
system("cls");
int choice;
cout<<"\t1.Add Bill."<<endl;
cout<<"\t2.Close Session."<<endl;
cout<<"\tEnter Choice: ";
if(!(cin >> choice)){
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "\tInvalid Choice!" << endl;
    Sleep(2000);
    continue;
}

if(choice==1){
string item;
int quant;
cout<<"\tEnter Item: ";
cin.ignore();
getline(cin, item);
cout << "\tEnter Quantity: ";

while(true){

    if(!(cin >> quant)){

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "\tInvalid Input! Enter Numeric Value: ";
    }

    else if(quant <= 0){

        cout << "\tQuantity Must Be Greater Than 0: ";
    }

    else{
        break;
    }
}

ifstream in("Bill.txt",ios::app);
if(!in){
    cout<<"\tFile Can't Open!"<<endl;
    return;
}
ofstream out("Bill Temp.txt",ios::app);

string line;
bool found = false;

while(getline(in, line)){
stringstream ss;
ss<<line;
string itemName;
int itemRate, itemQuant;
ss >> itemName >> itemRate >> itemQuant;

if(toLower(item) == toLower(itemName)){
found = true;
if(quant <= itemQuant){
int amount = itemRate * quant;
cout<<"\t Item | Rate | Quantity | Amount"<<endl;
cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl;
int newQuant = itemQuant - quant;
itemQuant = newQuant;
count +=amount;
out<<itemName<<" "<<itemRate<<" "<<itemQuant<<endl;
}
else{
cout<<"\tSorry, "<<item<<" Ended!"<<endl;
}
}
else{
out<<line<<endl;
}	
}
if(!found){
cout<<"\tItem Not Available!"<<endl;
}
out.close();
in.close();
remove("Bill.txt");
rename("Bill Temp.txt", "Bill.txt");
}
else if(choice ==2){
close = true;
cout<<"\tCounting Total Bill"<<endl;
}
else{
    cout<<"\tInvalid Choice!"<<endl;
    Sleep(2000);
}
Sleep(3000);
}
system("cls");
cout<<endl<<endl;
cout<<"\t Total Bill ----------------- : "<<count<<endl<<endl;
cout<<"\tThanks For Shopping!"<<endl;
Sleep(5000);
}

int main(){
Bill b;

bool exit = false;
while(!exit){
system("cls");
int val;

cout<<"\tWelcome To Super Market Billing System"<<endl;
cout<<"\t**************************************"<<endl;
cout<<"\t\t1.Add Item."<<endl;
cout<<"\t\t2.Print Bill."<<endl;
cout<<"\t\t3.Exit."<<endl;
cout<<"\t\tEnter Choice: ";
if(!(cin >> val)){
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "\tInvalid Choice!" << endl;
    Sleep(2000);
    continue;
}

if(val==1){
system("cls");
addItem(b);	
Sleep(3000);
}

else if(val==2){
printBill();
}

else if(val==3){
	system("cls");
exit = true;
cout<<"\tGood Luck!"<<endl;
Sleep(3000);
}	
else{
    cout<<"\tInvalid Choice!"<<endl;
    Sleep(2000);
}
}
}
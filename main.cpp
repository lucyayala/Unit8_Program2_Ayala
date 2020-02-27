//a program to practice passing a struc by pointer (*)
#include <iostream>
#include <string>
using namespace std;
//declaration of the struct
struct car
{
string Make;
string Model;
int Year;
string Color;
};

//function definition declared above int main()
void printCar(car *c)
{
  cout << "\nCar details: " << endl;
  cout << "Make - " << c->Make << endl;
  cout << "Model - " << c->Model << endl;
  cout << "Year - " << c->Year << endl;
// set the color variable based upon the year, and print it 
if (c->Year <= 2010)
{
 c->Color = "RED";
}
else if (c->Year > 2010)
{
c->Color = "GREEN";
}
//print the color to the screen
cout << "Color - " << c->Color << endl;
}

void preserveData (car &c)
{
  cout << "\nORIGINAL DATA: " << endl;
  printCar(&c);

    car *p_car = &c;

cout << "\nData copied into a new struct p_car";
printCar(p_car);

    new(p_car) car;
    cout << p_car->Year << endl; //print current Year

    new(p_car) car(); //default constructor
    cout << p_car->Year << endl; //0

  cout << "\nData after default const. reset:  " << endl;
  printCar(p_car);

 cout << "\nORIGINAL DATA: " << endl;
  printCar(&c);


}

int main() 
{
  //Declare an instance of the struct
  car car1;//Structure variable
  car1.Make = "Hyundai";
  car1.Model = "Genesis";
  car1.Year = 2016;

  car car2 = {"GMC", "Yukon", 1975};

  car car3 = {"Toyota", "Avalon", 2003};

  //print each car
  printCar (&car1);
  printCar (&car2);
  printCar (&car3);
  preserveData(car1);
  preserveData(car2);
  preserveData(car3);
  return 0;
}
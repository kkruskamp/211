//chart.cpp
//Kruskamp, Kyle
//kkruskamp
#include <iostream>
using namespace std;

int find_number(int*, int);

int main()
{

  const int max = 100; // MAX INTEGER
  int value, largest;
  int counter = 0; 
  int array[max]; //NO HARD CODE

  for (int size = 0; size < max; size++) //FOR LOOP FOR USER INPUT INTO ARRAY
  {

    cin >> value;
    array[size] = value;

      if (value == 0) // USER INPUT == 0 THEN BREAK
    {
      break;
    }

    counter++;

  }

  largest = find_number(array, counter); //SET VALUE2 TO THE FUNCTION FIND_NUMBER PASS IN THE ARRAY AND THE VALUE OF THE ARRAY

  for (int row = largest; row > 0; row--)
  {
    for (int column = 0; column < counter; column++)
    {
      if (row > array[column])
      {
        cout << " ";
      }
      else
      {
        cout << "*";
      }
    }

    cout << endl;

  }
  cout << endl;
  
  for (int row = largest; row > 0; row--)
  {
    for (int column = 0; column < counter; column++)
    {
     if (row < array[column])
      {
        cout << " ";
      }
      else
      {
        cout << "*";
      }
    }

    cout << endl;

  }


  return 0;

}


int find_number(int array[], int number) // ARRAY IS AN INT POINTER NUMBER IS RETURNED
{
  int largest = array[0]; //ASSIGN FIND TO FIRST VALUE IN ARRAY 

  for (int i = 0; i < number; i++)
  {
    if (array[i] > largest) // IF VALUE IN ARRAY IS GREATER THAN LAST PLACEHOLDER VALUE
    {
      largest = array[i]; //SET HIGHEST NUMBER TO FIND INTEGER
    }
  }
  return largest; //RETURN LARGEST NUMBER
}


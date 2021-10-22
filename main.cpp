
#include <iostream>
#include <iomanip>
using namespace std;


//=========================Sorting==================
//the void function calls by the main func and sort the array by the seletion sorting
//Notice that we are passing to the function values that were store on the heap [dynamic array].
void sort(double *&elements, int SIZE){
    
    int startScan, minIndex;
    double minValue;
    for (startScan = 0; startScan < (SIZE-1); startScan++){
        
        minIndex = startScan;
        minValue = elements[startScan];
        for (int index = startScan + 1; index <SIZE; index++)
            {
            if (elements[index] < minValue){
                minValue = elements[index];
                minIndex = index;
            }
        }
        elements[minIndex] = elements[startScan];
        elements[startScan] = minValue;
    }
}



////===============Calculatin Average=================
////the double func calculates average 
//////Notice that we are passing to the function values form the heap [dynamic array]
double average(double *&elems, int SIZE){
    double aver {0.0};
    double sum {0.0};
    for (int i{0}; i <= SIZE - 1; i++){
        sum = sum + elems[i];
}
 aver = sum / SIZE;
 return aver;
}


int main()
{
//=======================Main Func=============================

cout << fixed << setprecision(2);
int size = 0;

double *ptr_array {nullptr};
cout << "How many test scores will you enter? ";
cin >> size;//here uder defines size of our dynamic array 

ptr_array = new double [size];// here I declare a dynamic array that stores its values on the heap



//the func below stores values from a user to the dynamic arary. 'If' func, that is nasted in the 'for' func, checks if an inputed value >= 0, 
for (int counter {0}; counter < size; counter++){
    double temp[size] {};
    cout << "Enter the score " << counter + 1 << "  ";
    cin >> temp[counter];
    if ( temp[counter] < 0.0){
        while (temp[counter] < 0.0){//if value is less than 0.0 then the for loop keeps running till we get the right number
     cout << "Negative scores are not allowed. Enter another score for this test: " << "  "
     ;
     cin >> temp[counter];// after we've gotten the right number, it locates to the dynamic array
    }
}
  if (temp[counter] >= 0.0 ) {
    *(ptr_array + counter) = temp[counter];
     }
}

 sort(ptr_array,size);// here I pass the dynamic array values to the sort function that is sorting dynamic array's value in ascending order, using the Selection sort
 cout << endl;
 cout << "The test scores in ascending order, and their average, are: " << endl;
 cout << "                                                           Scores " << endl;
 cout << "                                                           ===== " << endl;
 //the if func below shows the dynamic array's values in ascending order
 for (int i {0}; i <= size - 1 ; i++){
 cout << "                                                           " << *(ptr_array + i) << endl;
 }
 
//below I pass  the dynamic array values to the double func that is calculate the average 
cout << "\n Average score: " << average(ptr_array, size) << endl;
cout << endl;
delete [] ptr_array; // here I release the memory allocation 
    system("pause");
	return 0;
}


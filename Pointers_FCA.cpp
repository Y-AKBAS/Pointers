#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void print(char *c)
{
    c[0] = 'd';
    while (*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

//2D Array with pointers
void printArr(int (*arr)[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // first and second are the same:
            // cout << *(*(arr + i) + j) << " " ;
            cout << *(arr[i] + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int Add(int a, int b)
{
    return a + b;
}

void display(char *name)
{
    cout << "\nHello " << name << endl;
}

void displayDisplay(void (*ptr)(char *), char *str) // pointer to a function. function callsbacks
{
    if (strlen(str) < 2)
        ptr("Displaying display(char *) via a function pointer");
    else
        ptr(str);
}

int compare(int a, int b)
{
    if (a > b)
        return 1;
    else
        return -1;
}

bool changeCompare = false;

int absolute_compare(int a, int b)
{
    if (abs(a) > abs(b))
        return 1;
    else
        return -1;
}

void bublesort(int *arr, int size, int (*compare)(int, int))
{
    int temp, count = 0;
    cout << "\nsize of array: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (changeCompare == false)
            {
                if (compare(arr[j], arr[j + 1]) > 0)
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    count++;
                }
            }
            else
            {
                if (absolute_compare(arr[j], arr[j + 1]) > 0)
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    count++;
                }
            }
        }
    }
    cout << "Count of bbs: " << count << endl;
}

struct Buch {
    string titel;
    string autor;
};

int main()
{
    cout << endl;

    //======================================== Pointer aritmethic ===================================//

    // int a = 5;
    // cout << "a: " << a << endl;
    // int *p = &a;
    // int **pp = &p;
    // int ***ppp = &pp;
    // ***ppp = 12;
    // cout << "a: " << a << endl
    //      << endl;

    // int arr[] = {2, 3, 4, 5, 6};
    // int *pa = arr;
    // cout << "*pa: " << *pa << endl;

    // char c[10] = "Hello";
    // char *cp = c;
    // print(cp);
    // print(c);

    //======================================== Pointer to Array===================================//

    // int array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int *arr1 = array1;

    // cout << "1D Array: " << endl
    //      << endl;

    // cout << "arr1: " << arr1 << endl;
    // cout << "*arr1: " << *arr1 << endl; // arr1[0]
    // cout << "&arr1: " << &arr1 << endl
    //      << endl;

    // int array[9][9] = {
    //     {2, 8, 6, 9, 3, 7, 1, 5, 4},
    //     {3, 4, 5, 6, 8, 1, 7, 9, 2},
    //     {7, 1, 9, 2, 4, 5, 3, 6, 8},
    //     {1, 7, 4, 5, 6, 8, 9, 2, 3},
    //     {6, 3, 8, 7, 2, 9, 4, 1, 5},
    //     {5, 9, 2, 3, 1, 4, 6, 8, 7},
    //     {4, 5, 3, 1, 9, 2, 8, 7, 6},
    //     {8, 2, 1, 4, 7, 6, 5, 3, 9},
    //     {9, 6, 7, 8, 5, 3, 2, 4, 1}};

    // int(*arr)[9] = array;

    // printArr(arr);
    // //printArr(array);

    // cout << "2D Array: " << endl
    //      << endl;

    // cout << "arr: " << arr << endl;
    // cout << "*arr: " << *arr << endl; // *arr==arr[0]
    // cout << "arr[0]: " << arr[0] << endl;
    // cout << "&arr: " << &arr << endl
    //      << endl;

    // cout << "*arr[0]: " << *arr[0] << endl;
    // cout << "*(*(arr+0)+0): " << *(*(arr + 0) + 0) << endl; // array[0][0]
    // cout << "**arr: " << **arr << endl                      // array[0][0]
    //      << endl;

    // cout << "arr[0]+1: " << arr[0] + 1 << endl;
    // cout << "*(arr[0]+1): " << *(arr[0] + 1) << endl;
    // cout << "*(*(arr+0)+1): " << *(*(arr + 0) + 1) << endl;
    // cout << "*(*arr+1): " << *(*arr + 1) << endl
    //      << endl;

    // cout << "**arr+1: " << **arr + 1 << endl;
    // cout << "*(*(arr+1)+0): " << *(*(arr + 1) + 0) << endl;

    // cout << endl;

    // cout << "3D Array: " << endl
    //      << endl;

    // int array3[3][2][2] =
    //     {
    //         {{1, 2}, {3, 4}},
    //         {{5, 6}, {7, 8}},
    //         {{9, 10}, {11, 12}}};

    // // c[i][j][k]= *(c[i][j]+k) = *(*(c[i]+j)+k) = *(*(*(c+i)+j)+k)

    //====================================== Dynamic Memory Allocation =================================//

    //Dynamic Memory Allocation in C/C++. We should free()/delete the pointer if we are done with it.

    /*
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << "p: " << p << " *p: " << *p << endl;
    free(p);
    cout << "After free(p) :"
         << " p: " << p << " *p: " << *p << endl
         << endl;

    //for array of size 10:
    int *pArray = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        pArray[i] = i;
    }
    for (int i = 0; i < 10; i++)
        cout << pArray[i] << " ";

    free(pArray);

    cout << "\nAfter free(pArray): \n";
    for (int i = 0; i < 10; i++)
        cout << pArray[i] << " ";

    //calloc is like malloc but it initializes the data with 0 and takes 2 arguments(size_t size,sizeof(datatype))
    int *pCalloc = (int *)calloc(10, sizeof(int));
    cout << "\n\n*pCalloc: " << endl
         << endl;

    for (int i = 0; i < 10; i++)
        cout << *(pCalloc + i) << " ";

    //realloc allows us to define the size of an array again.
    int *pRealloc = (int *)realloc(pCalloc, 2 * sizeof(int)); //realloc(NULL, 2 * sizeof(int)) equivalent to malloc
    cout << "\n\nCpp Part: \n\n";

    free(pCalloc);
    free(pRealloc);

    int *pCpp = new int;
    *pCpp = 20;
    cout << "pCpp: " << pCpp << " *pCpp: " << *pCpp << endl;
    delete pCpp;
    cout << "After delete pCpp :"
         << " pCpp: " << pCpp << " *pCpp: " << *pCpp << endl
         << endl;

    //for Array of size 10:

    int *pCppArray = new int[10];

    for (int i = 0; i < 10; i++)
    {
        pCppArray[i] = i;
    }
    for (int i = 0; i < 10; i++)
        cout << pCppArray[i] << " ";

    delete[] pCppArray;

    cout << "\nAfter delete [] pCppArray: \n";
    for (int i = 0; i < 10; i++)
        cout << pCppArray[i] << " ";  */

    //======================================== Function Pointers ===================================//

    // Functions and arrays are stored in memory blocks and the name of them gives us the first starting point.
    // Because of that if we point to an array or to a function we don't have to use '&' like we use at the others
    /*
    int (*p)(int, int); // Add function returns int. Since the type of the pointer must be int.
    p = &Add;           // We must mention the arguments too like (int,int).

    int x = (*p)(2, 5); // (*p)(2,5) or p(2,5) both are legal function calls.
    int y = p(2, 5);

    cout << "x: " << x << " y: " << y << endl;

    void (*ptr)(char *);
    ptr = display; // For example we didn't use '&' here
    (*ptr)("James");
    ptr("John");

    displayDisplay(ptr, "");
    displayDisplay(ptr, "dude. You're displaying display");

    int arrr[] = {3, 2, 4, -1, 6, -13, 8, -9, 7, 5};

    // Note that we are passing just function names without arguments or ()
    bublesort(arrr, 10, compare); //Sorting incrementally.
    for (int x : arrr)
        cout << x << " ";

    changeCompare = true;

    bublesort(arrr, 10, absolute_compare); // sorting without caring about - (abs() function)
    for (int x : arrr)
        cout << x << " ";
*/
  //======================================== Pointer to Struct ===================================//       

    Buch b = { "Algorithms","Abdulbari" };
    Buch* bp;
    bp = &b;
    cout << bp->titel << " " << bp->autor << endl;


    //struct Buch* bptr;
    //bptr = (struct Buch*)malloc(sizeof(struct Buch)); //  "malloc()" is C language
    //bptr->titel = string();
    //bptr->autor = string();
    //bptr->titel = "Databases";
    //bptr->autor = "Robinson";
    //cout << "Anything" << endl;
    //cout << bptr->titel << " " << bptr->autor << endl;

    Buch* bptr1;
    bptr1 = new Buch;                               // This is C++ language
    bptr1->titel = "Java Core";
    bptr1->autor = "Abdulbari";
    cout << bptr1->titel << " " << bptr1->autor << endl;

    delete bptr1;

    //Bitwise Swap
    /*
    int x = 10, y = 15;
    cout << "x: " << x << " y: " << y << endl;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout << "x: " << x << " y: " << y << endl;
    */

    cout << endl;
    return 0;
}
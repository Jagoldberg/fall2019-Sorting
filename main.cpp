#include <iostream>
#include <fstream>
#include<time.h>
using namespace std;

void bubbleSort(double myArray[]){
  for(int i = 0; i < 10; ++i){
    int temp = 0;
    for(int j = 0; j < 9; ++j){
      if(myArray[j] > myArray[j+1]){
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void selectionSort(double arr[], int n){
  int i, j, minIndex, tmp;
  for(i = 0; i < n-1; i++){
    minIndex = i;
    for(j = i+1; j < n; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    if(minIndex != i){
      tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
}

void insertSort(double arr[]){
  for(int j = 1; j < 10; ++j){//marker
    double temp = arr[j]; //store marked item
    int k = j; //where to start shifting
    while(k > 0 && arr[k-1] >= temp){ //while the thing to the left is larger, shift
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp; //put marked item in right spot
  }
}

void merge(double arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(double arr[], int a, int b){  //parameters are array, starting index, and size of array-1
  if (a < b){
    int c = (a+b)/2;
    mergeSort(arr, a, c);
    mergeSort(arr, c+1, b);
    merge(arr, a, c, b);

  }
}




int main(int argc, char** argv) {
  ifstream sourceFile;

  sourceFile.open(argv[1]);
  if(sourceFile.is_open()){
    int arrSize;
    const char* temp;
    string line;
    time_t timer;

    getline(sourceFile, line);//Line 1: number of windows
    temp = line.c_str();
    arrSize = atoi(temp);
    double* bubbleArr = new double[arrSize];
    double* selectArr = new double[arrSize];
    double* insertArr = new double[arrSize];
    double* mergeArr = new double[arrSize];

    int i = 0;
    while(getline(sourceFile, line)){
      bubbleArr[i++] = stod(line);
      selectArr[i++] = stod(line);
      insertArr[i++] = stod(line);
      mergeArr[i++] = stod(line);
    }

    time_t rawtime;
    struct tm * timeinfo;


    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Bubble Sort Start time: " << asctime(timeinfo) << endl;
    bubbleSort(bubbleArr);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "bubbleSort End time:" << asctime(timeinfo) << endl;
    cout << "Selection Sort Start time: " << asctime(timeinfo) << endl;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    selectionSort(selectArr, arrSize);
    cout << "Selection Sort End time: " << asctime(timeinfo) << endl;
    cout << "Insertion Sort Start time: " << asctime(timeinfo) << endl;
    insertSort(insertArr);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Insertion Sort End time:" << asctime(timeinfo) << endl;
    cout << "Merge Sort Start time: " << asctime(timeinfo) << endl;
    mergeSort(mergeArr, 0, arrSize-1);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Merge Sort End time: " << asctime(timeinfo) << endl;

} else {
    int arrSize;
    const char* temp;
    string line;
    time_t timer;

    cout << "Enter the size of the array" << endl;
    cin >> arrSize;

    double* bubbleArr = new double[arrSize];
    double* selectArr = new double[arrSize];
    double* insertArr = new double[arrSize];
    double* mergeArr = new double[arrSize];

    srand(time(NULL));

    for(int i = 0; i < arrSize; ++i){
      double rand_n = (double)(rand() % 100 + 1);
      bubbleArr[i] = rand_n;
      selectArr[i] = rand_n;
      insertArr[i] = rand_n;
      mergeArr[i] = rand_n;
    }
    time_t rawtime;
    struct tm * timeinfo;


    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Bubble Sort Start time: " << asctime(timeinfo) << endl;
    bubbleSort(bubbleArr);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "bubbleSort End time:" << asctime(timeinfo) << endl;
    cout << "Selection Sort Start time: " << asctime(timeinfo) << endl;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "selection sort has started" << endl;
    selectionSort(selectArr, arrSize);
    cout << "Selection Sort End time: " << asctime(timeinfo) << endl;
    cout << "Insertion Sort Start time: " << asctime(timeinfo) << endl;
    insertSort(insertArr);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Insertion Sort End time:" << asctime(timeinfo) << endl;
    cout << "Merge Sort Start time: " << asctime(timeinfo) << endl;
    mergeSort(mergeArr, 0, arrSize-1);
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Merge Sort End time: " << asctime(timeinfo) << endl;

}


  return 0;
}

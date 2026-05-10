//============================================================================
// Name        : project3_Knighton_kmk0120.cpp
// Author      : Katie Knighton kmk0120
// References  : cplusplus.com/reference/algorithm/sort/ for sorting vector 3
// 			   : cplusplus.com/doc/tutorial/files/ for writing to a file
//             : https://stackoverflow.com/questions/20636914/c-mean-median-and-mode
//             : https://stackoverflow.com/questions/19920542/c-calculating-the-mode-of-a-sorted-array
//             : https://stackoverflow.com/questions/1232040/how-do-i-empty-an-array-in-javascript
//  
//============================================================================
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//function decloration

int readfile(double* ptr, ifstream& instream);
int sort(double inputArray1[], int inputArray1_size, double inputArray2[], int inputArray2_size, double* ptr);
void writefile(double outputArray[], int outputArray_size, string output_filename);
void mean(double array[], int arraysize);
void mode(double array[], int arraysize);
void median(double array[], int arraysize);

//const max size for arrays just to make code easier
const int MAX_SIZE = 1000;


//main//
int main() {

    string filename1;
    int file1_size;
    double file1_array[MAX_SIZE];

    string filename2;
    int file2_size;
    double file2_array[MAX_SIZE];

    string filename3;
    int file3_size;
    double file3_array[MAX_SIZE];

    string filename4;
    int file4_size;
    double file4_array[MAX_SIZE];

    string filename5;
    int file5_size;
    double file5_array[MAX_SIZE];

    double output_array1[2*MAX_SIZE];
    int output1_size;
    double output_array2[2*MAX_SIZE];
    int output2_size;
    double output_array3[2*MAX_SIZE];
    int output3_size;
    double output_array4[2*MAX_SIZE];
    int output4_size;

    int numfiles;
    string output_filename;

    ifstream inStream;

    cout << "*** Welcome to Katie's Data Analyzer ***" << endl;
    cout << "Enter the number of files to read:" << endl;
    cin >> numfiles;

    if (numfiles == 1){
        cout << "Enter the filename for file 1 \n";
        cin >> filename1;

        inStream.open((char*)filename1.c_str());
        file1_size = readfile(file1_array, inStream);
        if((file1_size = 1000) || (file1_size = 0)){
            cout << "invalid input";
        }
        inStream.close();

        cout << "The list of " << file1_size << " values in " << filename1 << " is:" << endl;
        for(int i=0; i<file1_size; i++) {
        cout << file1_array[i] << endl;
        
        }
        output1_size = sort(file1_array, file1_size, file2_array, file2_size, output_array1);
        cout << "\n *** Summarized Statistics ***\n";
        cout << "The orderly sorted list of " << output1_size << " is:\n";
        for(int i=0; i<output1_size; i++) {
            cout << output_array1[i] << " ";
        }
        mean(output_array1, output1_size);
        median(output_array1, output1_size);
        mode(output_array1, output1_size);

        cout << "Enter the output filename to save: ";
        cin >> output_filename;

        writefile(output_array1, file1_size + file2_size, output_filename);
	    cout << "*** File " + output_filename + " has been written to disk ***" << endl;
        cout << "*** Goodbye ***";
            

    }
    else if (numfiles == 2){
        cout << "Enter the filename for file 1 \n";
        cin >> filename1;

        inStream.open((char*)filename1.c_str());
        file1_size = readfile(file1_array, inStream);
        inStream.close();
        if((file1_size = 1000) || (file1_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file1_size << " values in " << filename1 << " is:" << endl;
        for(int i=0; i<file1_size; i++) {
            cout << file1_array[i] << endl;
        }
        cout << "Enter the filename for file 2 \n";
        cin >> filename2;

        inStream.open((char*)filename2.c_str());
        file2_size = readfile(file2_array, inStream);
        inStream.close();
        if((file2_size = 1000) || (file2_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file2_size << " values in " << filename2 << " is:" << endl;
        for(int i=0; i<file2_size; i++) {
            cout << file2_array[i] << endl;
        }
        output1_size = sort(file1_array, file1_size, file2_array, file2_size, output_array1);
        cout << "\n *** Summarized Statistics ***\n";
        cout << "The orderly sorted list of " << output1_size << " is:\n";
        for(int i=0; i<output1_size; i++) {
            cout << output_array1[i] << " ";
        
        }
        mean(output_array1, output1_size);
        median(output_array1, output1_size);
        mode(output_array1, output1_size);

        cout << "Enter the output filename to save: ";
        cin >> output_filename;

        writefile(output_array1, file1_size + file2_size, output_filename);
	    cout << "*** File " + output_filename + " has been written to disk ***" << endl;
        cout << "*** Goodbye ***";

    }
    else if (numfiles == 3){
        cout << "Enter the filename for file 1 \n";
        cin >> filename1;

        inStream.open((char*)filename1.c_str());
        file1_size = readfile(file1_array, inStream);
        inStream.close();
        if((file1_size = 1000) || (file1_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file1_size << " values in " << filename1 << " is:" << endl;
        for(int i=0; i<file1_size; i++) {
            cout << file1_array[i] << endl;
        }
        cout << "Enter the filename for file 2 \n";
        cin >> filename2;

        inStream.open((char*)filename2.c_str());
        file2_size = readfile(file2_array, inStream);
        inStream.close();
        if((file2_size = 1000) || (file2_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file2_size << " values in " << filename2 << " is:" << endl;
        for(int i=0; i<file2_size; i++) {
            cout << file2_array[i] << endl;
        }
        cout << "Enter the filename for file 3 \n";
        cin >> filename3;

        inStream.open((char*)filename3.c_str());
        file3_size = readfile(file3_array, inStream);
        inStream.close();
        if((file3_size = 1000) || (file3_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file3_size << " values in " << filename3 << " is:" << endl;
        for(int i=0; i<file3_size; i++) {
            cout << file3_array[i] << endl;
        }
        output1_size = sort(file1_array, file1_size, file2_array, file2_size, output_array1);
        output2_size = sort(output_array1, output1_size, file3_array, file3_size, output_array2);
        cout << "\n *** Summarized Statistics ***\n";
        cout << "The orderly sorted list of " << output2_size << " is:\n";
        for(int i=0; i<output2_size; i++) {
            cout << output_array2[i] << " ";
        
        }
        mean(output_array2, output2_size);
        median(output_array2, output2_size);
        mode(output_array2, output2_size);

        cout << "Enter the output filename to save: ";
        cin >> output_filename;

        writefile(output_array2, file1_size + file2_size, output_filename);
	    cout << "*** File " + output_filename + " has been written to disk ***" << endl;
        cout << "*** Goodbye ***";

    }
    else if (numfiles == 4){
        cout << "Enter the filename for file 1 \n";
        cin >> filename1;

        inStream.open((char*)filename1.c_str());
        file1_size = readfile(file1_array, inStream);
        inStream.close();
        if((file1_size = 1000) || (file1_size = 0)){
            cout << "invalid input";
        }


        cout << "The list of " << file1_size << " values in " << filename1 << " is:" << endl;
        for(int i=0; i<file1_size; i++) {
            cout << file1_array[i] << endl;
        }
        cout << "Enter the filename for file 2 \n";
        cin >> filename2;

        inStream.open((char*)filename2.c_str());
        file2_size = readfile(file2_array, inStream);
        inStream.close();
        if((file2_size = 1000) || (file2_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file2_size << " values in " << filename2 << " is:" << endl;
        for(int i=0; i<file2_size; i++) {
            cout << file2_array[i] << endl;
        }
        cout << "Enter the filename for file 3 \n";
        cin >> filename3;

        inStream.open((char*)filename3.c_str());
        file3_size = readfile(file3_array, inStream);
        inStream.close();
        if((file3_size = 1000) || (file3_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file3_size << " values in " << filename3 << " is:" << endl;
        for(int i=0; i<file3_size; i++) {
            cout << file3_array[i] << endl;
        }

        cout << "Enter the filename for file 4 \n";
        cin >> filename4;

        inStream.open((char*)filename4.c_str());
        file4_size = readfile(file4_array, inStream);
        inStream.close();
        if((file4_size = 1000) || (file4_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file4_size << " values in " << filename4 << " is:" << endl;
        for(int i=0; i<file4_size; i++) {
            cout << file4_array[i] << endl;
        }
        output1_size = sort(file1_array, file1_size, file2_array, file2_size, output_array1);
        output2_size = sort(output_array1, output1_size, file3_array, file3_size, output_array2);
        output3_size = sort(output_array2, output2_size, file4_array, file4_size, output_array3);
        cout << "\n *** Summarized Statistics ***\n";
        cout << "The orderly sorted list of " << output3_size << " is:\n";
        for(int i=0; i<output3_size; i++) {
            cout << output_array3[i] << " ";
        
        }

        mean(output_array3, output3_size);
        median(output_array3, output3_size);
        mode(output_array3, output3_size);

        cout << "Enter the output filename to save: ";
        cin >> output_filename;

        writefile(output_array3, file1_size + file2_size, output_filename);
	    cout << "*** File " + output_filename + " has been written to disk ***" << endl;
        cout << "*** Goodbye ***";
    }


    
    if (numfiles == 5) {
        cout << "Enter the filename for file 1 \n";
        cin >> filename1;
 
        inStream.open((char*)filename1.c_str());
        file1_size = readfile(file1_array, inStream);
        inStream.close();
        if((file1_size = 1000) || (file1_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file1_size << " values in " << filename1 << " is:" << endl;
        for(int i=0; i<file1_size; i++) {
            cout << file1_array[i] << endl;
        }
        cout << "Enter the filename for file 2 \n";
        cin >> filename2;

        inStream.open((char*)filename2.c_str());
        file2_size = readfile(file2_array, inStream);
        inStream.close();
        if((file2_size = 1000) || (file2_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file2_size << " values in " << filename2 << " is:" << endl;
        for(int i=0; i<file2_size; i++) {
            cout << file2_array[i] << endl;
        }
        cout << "Enter the filename for file 3 \n";
        cin >> filename3;

        inStream.open((char*)filename3.c_str());
        file3_size = readfile(file3_array, inStream);
        inStream.close();
        if((file3_size = 1000) || (file3_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file3_size << " values in " << filename3 << " is:" << endl;
        for(int i=0; i<file3_size; i++) {
            cout << file3_array[i] << endl;
        }

        cout << "Enter the filename for file 4 \n";
        cin >> filename4;

        inStream.open((char*)filename4.c_str());
        file4_size = readfile(file4_array, inStream);
        inStream.close();
        if((file4_size = 1000) || (file4_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file4_size << " values in " << filename4 << " is:" << endl;
        for(int i=0; i<file4_size; i++) {
            cout << file4_array[i] << endl;
        }

        cout << "Enter the filename for file 5 \n";
        cin >> filename5;

        inStream.open((char*)filename5.c_str());
        file5_size = readfile(file5_array, inStream);
        inStream.close();
        if((file5_size = 1000) || (file5_size = 0)){
            cout << "invalid input";
        }

        cout << "The list of " << file5_size << " values in " << filename5 << " is:" << endl;
        for(int i=0; i<file5_size; i++) {
            cout << file5_array[i] << endl;
        }

        output1_size = sort(file1_array, file1_size, file2_array, file2_size, output_array1);
        output2_size = sort(output_array1, output1_size, file3_array, file3_size, output_array2);
        output3_size = sort(output_array2, output2_size, file4_array, file4_size, output_array3);
        output4_size = sort(output_array3, output3_size, file5_array, file5_size, output_array4);
        cout << "\n *** Summarized Statistics ***\n";
        cout << "The orderly sorted list of " << output3_size << " is:\n";
        for(int i=0; i<output3_size; i++) {
            cout << output_array3[i] << " ";
        
        }

        mean(output_array4, output4_size);
        median(output_array4, output4_size);
        mode(output_array4, output4_size);

        cout << "Enter the output filename to save: ";
        cin >> output_filename;

        writefile(output_array4, file1_size + file2_size, output_filename);
	    cout << "*** File " + output_filename + " has been written to disk ***" << endl;
        cout << "*** Goodbye ***";

    }
    if(!isdigit(numfiles) || numfiles <= 0 || numfiles >= 6){
            cout << "invalid number of files" << "\n *** Goodbye ***";
    }
    return 0;
    
}





//functions
int readfile(double* ptr, ifstream& inStream) {
    int size = 0;
    string data;
    
    while(getline(inStream, data)) {

        //converts string to int
        double temp = 0;
        bool neg = false;
        for(int i=0; i<data.length(); i++) {
            if(data[i] == '-') {
                neg = true;
            }

            else if(!isdigit(data[i]) || data[i] != ',' || data[i] != '.') {
                size = 999;
                break;
            }
            
            else {
                temp *= 10;
                temp += (int)data[i]-48;
            }
        }

        neg ? *(ptr + size) = (-1)*temp : *(ptr + size) = temp;

        size++;
    }

    return size;
}

int sort(double inputArray1[], int inputArray1_size, double inputArray2[], int inputArray2_size, double* ptr) {

    double outputArray[MAX_SIZE];

    for(int i=0; i<inputArray1_size; i++) {
        outputArray[i] = inputArray1[i];
    }

    for(int i=0; i<inputArray2_size; i++) {
        outputArray[i + inputArray1_size] = inputArray2[i];
    }


    //sort the array
    int outputArray_size = inputArray1_size + inputArray2_size;
    double temp;

    //bubble sort
    for(int i = 0; i<outputArray_size; i++) {
        for(int j = i+1; j<outputArray_size; j++) {
            if(outputArray[j] < outputArray[i]) {
                temp = outputArray[i];
                outputArray[i] = outputArray[j];
                outputArray[j] = temp;
            }
        }
    }


    for(int i=0; i<outputArray_size; i++) {
        *(ptr + i) = outputArray[i];
    }
    
    return outputArray_size;
}

void writefile(double outputArray[], int outputArray_size, string output_filename) {
    ofstream outStream((char*)output_filename.c_str());

    for(int i=0; i<outputArray_size; i++) {
        outStream << outputArray[i] << endl;
    }

    outStream.close();

}

void mean(double array[], int arraysize){
    double mean;
    for(int i = 0; i < arraysize; i++){
        mean = mean + array[i];

    }
    mean = mean/arraysize;
    cout << "\n The mean is " << mean << ".\n";
}
void mode (double array[], int arraysize){
    int counter;
    for (int i=0; i < arraysize; i++){
        for (int j=i+1; j < arraysize; j++){
            if (array[j] == array[i]){
                counter++;
            }
        }
    }
    cout << "\n The mode is" << counter << ".\n";
}
void median (double array[], int arraysize){
    if ((arraysize % 2) != 0) {
        int temp = ((arraysize+1)/2)-1;
        cout << "\n The median is " << array[temp] << ".\n";
    }
    else{// then it's even! :)
        cout << "The median is "<< array[(arraysize/2)-1] << " and " << array[arraysize/2] << endl;
    }
}
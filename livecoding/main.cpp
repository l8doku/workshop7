/*******************************************************************************
 *
 *  Workshop 7
 *
 * 1) Define an alias VecNames for the std::vector<std::string> datatype using the typedef keyword.
 *
 * 2) Create a function called toCountSurvived
 * that obtains an input stream
 * object (given by reference) istream& (input.csv), 
 * reads the whole file line by line and get a
 * surname ("Braund; Mr. Owen Harris" will be just "Braund")
 *  of survived person from input.csv (Survived column). 
 * Function returns VecNames data type -- vector of 
 * survived surnames.
 *
 * 3) Create a method printVec(const VecNames& aliveNames).
 * The method prints the content of the given vector out to the standard output with elements and its enumeration
 * 1) Name_1
 * 2) Name_2
 * ...
 * N) Name_n
 *
 * 4) Create a method 
 * named genThreeDigitNumber(const int& random_state).
 * The method return random 
 * three digit number as std::string.
 * Use:
 * std::mt19937 gen(time(nullptr));
 * std::uniform_int_distribution<int> distr(0,9);
 * int rNum = distr(gen); // random number
 *
 * 5) Create new vector newVec as VecNames and fill it by random numbers. newVec size should be the same as obtained
 * from toCountSurvived
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <string>


typedef std::vector<std::string> VecNames;
void printVec(const VecNames& aliveNames);
void toCountSurvived(const std::istream& inputStream);
std::string genThreeDigitNumber(const int& random_state);



// reads the whole file line by line and get a
// * surname ("Braund; Mr. Owen Harris" will be just "Braund")
// *  of survived person from input.csv (Survived column). 
// * Function returns VecNames data type -- vector of 
// * survived surnames.
VecNames toCountSurvived(std::istream& inputStream)
{
    
    VecNames aliveNames;
    std::string buffer;
    std::string lastName;
    std::string unneeded;
    std::getline(inputStream, buffer);
    while (!inputStream.eof())
    {
        
        std::getline(inputStream, buffer);
        std::stringstream ss(buffer);
        
        std::getline(ss, unneeded, ',');
        std::getline(ss, unneeded, ',');
        std::getline(ss, unneeded, ',');

        std::getline(ss, lastName, ';');
        aliveNames.push_back(lastName);
    }
    return aliveNames;
}




//std::string& assign(char *)
//{
    
//}



std::string genThreeDigitNumber(const int& random_state)
{
  
    std::mt19937 gen(random_state);
    std::uniform_int_distribution<int> my_distribution(0,9);
    int firstDigit = my_distribution(gen);
    
    int secondDigit = my_distribution(gen);
    int thirdDigit = my_distribution(gen);
    int randomNumber = firstDigit * 100 + secondDigit * 10 + thirdDigit;
    std::string result = std::to_string(randomNumber);
    return result;
}







void printVec(const VecNames& aliveNames)
{
    int vecSize = aliveNames.size();
    for (int i = 0; i < vecSize; ++i)
    {
        std::cout << i + 1 << ") ";
        std::cout << aliveNames[i] << std::endl;
    }
}




int main ()
{
    const std::string INP_FILE_NAME = "/home/georgii/WORK/DSBA/repositories/workshop7/WH7/livecoding/input.csv";
    
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);
    
    std::string example;
    std::string example1;
    example1 = example.assign("123");
    example1[1] = 'z';
    std::cout << example << std::endl;
    std::cout << example1; 
    
    //    VecNames survivorNames = toCountSurvived(input_file);
//    printVec(example);


}



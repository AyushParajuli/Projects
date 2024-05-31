/*
    Name : Ayush Parajuli
    Student_Id - 165601212
    email - aparajuli6@myseneca.ca
    Date - 10 March 2023
    Note: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      unsigned int countLines(const char* filename);
      void sort(double* collectionPtr, unsigned int size);


      double* m_Collection;
      char m_file_name[256];
      unsigned int m_collection_size;
      bool m_orgflag;
      bool m_addedflag;

      void setEmpty();

      //this function loads the data file
      bool load();

      //this function create instance to overwrite the data file
      bool save();

   public:
       void setEmpty2();

       //one argument constructor
       Numbers(const char* filename = "");

       //default constructor
       Numbers();

       //destructor
       ~Numbers();

       //copy constructor
       Numbers(const Numbers& other);

       //Copy Assignment Operator
       Numbers& operator=(const Numbers& other);

       //REturns the largest double number in the collection
       double max() const;

       //Returns the smallest double number in the collection
       double min() const;
       
       //Returns the average of the double number in the collection
       double average() const;

       //Boollean type conversion operator over load
       operator bool() const;

       void sort();

       //It returns the reference of the current object
       Numbers& operator+=(double value);

       //Displays the function.
       std::ostream& display(std::ostream& ostr = std::cout) const;

       // Helper Function

       //Overload the insertion operator
      friend std::ostream& operator<<(std::ostream& os, const Numbers& numbers);

      //Overload the extraction operator
      friend std::istream& operator>>(std::istream& is, Numbers& numbers);

   };

}
#endif // !SDDS_NUMBERS_H_


/*
    Name : Ayush Parajuli
    Student_Id - 165601212
    email - aparajuli6@myseneca.ca
    Date - 10 March 2023
    Note: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/




#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Numbers.h"
using namespace std;

namespace sdds {

   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

   void Numbers::setEmpty2()
   {
       m_Collection = nullptr;
       m_collection_size = 0;
       //m_file_name[0] = '\0';
       m_orgflag = true;
       m_addedflag = false;
   }

   void Numbers::setEmpty()
   {
       m_Collection = nullptr;
       m_collection_size = 0;
       m_file_name[0] = '\0';
       m_orgflag = true; 
       m_addedflag = false;
   }
   
   //one argument constructor
   //creating an original instance of the Numbers class by receiving the data file name
   Numbers::Numbers(const char* filename)
   {
       
       setEmpty();
       strcpy(m_file_name, filename);
       load();
   }

   //default constructor
   Numbers::Numbers()
   {
       setEmpty();
   }

   //destructor
   Numbers::~Numbers()
   {
       save();
       delete[] m_Collection;
   }

   //copy constructor
   Numbers::Numbers(const Numbers& other)
   {
       // creating an copy out of already existing Numbers object
       setEmpty();
       *this = other; //calling the assignment operator
       
   }

   //Copy Assignment Operator
   Numbers& Numbers::operator=(const Numbers& other)
   {
       if (this != &other)
       {
           save();

           //Delete the current collection 
           delete[] m_Collection;

           //set size to same as other, it will set the current object to empty state since others have to elements
           // (i.e others.m_collection_size is 0 )
           m_collection_size = other.m_collection_size;


           if (other.m_collection_size > 0)
           {
               m_orgflag = false;

               // allocating new memory
               m_Collection = new double[m_collection_size];

               
               for (unsigned int i = 0; i < m_collection_size; ++i)
               {
                   //copy element from other to collection.
                   m_Collection[i] = other.m_Collection[i];
               }
           }
           else
           {
               m_Collection = nullptr;
           }

           //Copying all other file from other
           strcpy(m_file_name, other.m_file_name);
           m_addedflag = other.m_addedflag;
           //m_orgflag != other.m_orgflag;
       }
       return *this;
       
   }

   //this function loads the data file
   bool  Numbers::load()
   {
       if (m_Collection != nullptr)
       {
           delete[] m_Collection;
           setEmpty();
       }
       unsigned int numlines = countLines(m_file_name);

       if (numlines > 0)
       {
           m_Collection = new double[numlines]; // allocating memory to the number of lines
           std::ifstream inputFile(m_file_name); // creating an instance of ifstream with an filename,
           
           unsigned int numReads = 0;

           double values;
           // check if the ifsream is in goodstate

           while (/*inputFile.good() && numReads < numlines*/ inputFile >> values)
           {
               //keeping the double values from the file into the element and count the numb no of reads
               m_Collection[numReads++] = values; 
           }

           // checking id the number successfully reads or not.
           if (numReads != numlines)
           {
               delete[] m_Collection;
               setEmpty();
               return false;
           }

           
           m_collection_size = numlines;//setting the collection size to the number of double values read
           m_orgflag = true;
           m_addedflag = false;
           return true;
       }

       return false;

   }

   //this function create instance to overwrite the data file
   bool Numbers::save()
   {
       if (m_orgflag && m_addedflag)
       {
           std::ofstream out_file(m_file_name);
           out_file << fixed << setprecision(2);
           for (unsigned int i = 0; i < m_collection_size; ++i)
           {
               out_file << m_Collection[i] << endl;
           }
           out_file.close();
           m_addedflag = false;      
           return true;
       }
       else
       {
           return false;
       }

       
   }

   //Returns the largest double number in the collection
   double  Numbers::max() const
   {
       if (m_collection_size == 0)
       {
           return 0.0;
       }
       double maxvalue = m_Collection[0];
       for (unsigned int i = 1u; i < m_collection_size; ++i)
       {
           //checking if the value is largest or not
           if (m_Collection[i] > maxvalue)
           {
               maxvalue = m_Collection[i];
           }
       }
       return maxvalue;
   }

   //Returns the smallest double number in the collection
   double  Numbers::min() const
   {
       if (m_collection_size == 0)
       {
           return 0.0;
       }
       double minvalue = m_Collection[0];
       for (unsigned int i = 0; i < m_collection_size; ++i)
       {
           //checking if the value is smallest or not
           if (m_Collection[i] < minvalue)
           {
               minvalue = m_Collection[i]; // returning min value.
           }
       }
       return minvalue;
   }

   //Returns the average of the double number in the collection
   double  Numbers::average() const
   {
       if (m_collection_size == 0)
       {
           return 0.0;
       }
       double average = 0.0;
       for (unsigned int i = 0; i < m_collection_size; ++i)
       {
           average += m_Collection[i];
       }
       return average / m_collection_size;

   }

   //Boollean type conversion operator over load
   Numbers::operator bool() const
   {
       //returns m_Collection is not null.
       return m_Collection != nullptr;
   }


   void Numbers::sort()
   {
       if (m_collection_size > 0)
       {
           //calling the provided sort function.
           sort(m_Collection, m_collection_size);
       }
   }

   //It returns the reference of the current object
   Numbers& Numbers::operator+=(double value)
   {
       if (*this)
       {
           //Get new size
           int newSize = this->m_collection_size + 1;

           //Allocating the memory
           double* newCollection = new double[newSize];

           //copy values
           for (auto i = 0; i < newSize - 1; ++i)
           {
               newCollection[i] = this->m_Collection[i];
           }

           //Instert new values
           newCollection[newSize - 1] = value;

           // Deallocate memory
           delete[] m_Collection;
           m_Collection = nullptr;

           //Assign collection to new memory
           m_Collection = newCollection;

           //update anyother values 
           m_collection_size = newSize;
           m_addedflag = true;

           //write values to file
           save();
       }
       return *this;
   }

   //Displays the function.
   std::ostream& Numbers::display(ostream& ostr) const
   {
      /* ostr << (m_orgflag ? "" : "Copy of ") << m_file_name << endl;*/

       //checking if its empty or not
       if (m_collection_size == 0)
       {
           ostr << "Empty list";
       }
       else
       {
           
           ostr << fixed << setprecision(2);
           if (!m_orgflag)
           {
               ostr << "Copy of ";
           }
           ostr << m_file_name << endl;
           for (unsigned int i = 0; i < m_collection_size; ++i)
           {
               ostr << m_Collection[i];
               //checking if current element is not the last element
               if (i != m_collection_size - 1)
               {
                   ostr << ", ";
               }
           }
           ostr << endl;
           ostr.fill('-'); 
           ostr.width(76);
           ostr << "";
           ostr << endl;
           ostr << "Total of " << m_collection_size << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average() << endl;
           ostr.fill('=');
           ostr.width(76);
           ostr << "";
       }
       return ostr;
   }

   // Helper Function

   //Overload the insertion operator
   ostream& operator<<(ostream& os, const Numbers& numbers)
   {
       // it allows a Numbers object to be streamed into an output stream
       return numbers.display(os);
   }

   //Overload the extraction operator
   // operator>> function allows for easy extraction of double values from an input stream and addition to a Numbers object. 
   istream& operator>>(istream& is, Numbers& numbers)
   {
       double value;
       is >> value; //storing the variable names value, inside the is.
       if (is.good())
       {
           numbers += value;
       }
      numbers.sort();
       return is;
   }

}

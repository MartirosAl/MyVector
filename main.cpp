#include <iostream>


class Vector
{
   double* elements;
   size_t size;
   size_t capasity;

public:

   Vector(double* elements_ = nullptr, size_t size_ = 0);

   Vector(Vector& other_);

   Vector operator+(const Vector& other_) const;

   Vector& operator=(const Vector& other_);

   Vector& operator+=(const Vector& other_);
   
   double operator*(const Vector& other_);

   Vector operator&(const Vector& other_);

   Vector& operator&=(const Vector& other_);

   bool operator==(const Vector& other_);

   bool operator!=(const Vector& other_);

   bool operator!();

   double& operator[](int index_);

   void Push_Back(double elem_);

   void Print_Vectors();
};

Vector::Vector(double* elements_, size_t size_)
{
   if (!elements)
   {
      elements = nullptr;
      size = 0;
      capasity = 0;
   }

   elements = new double[size_];
   size = size_;
   capasity = size_;
   for (size_t i = 0; i < size; i++)
   {
      elements[i] = elements_[i];
   }
} 

Vector::Vector(Vector& other_)
{
   size = other_.size;
   capasity = other_.capasity;

   elements = new double[capasity];
   for (size_t i = 0; i < size; i++)
      elements[i] = other_.elements[i];
}

Vector Vector::operator+(const Vector& other_) const
{
   if (size != other_.size)
   {
      Vector temp(nullptr, 0);
      return temp;
   }

   Vector result;
   result.elements = new double[size];
   result.size = size;
   result.capasity = size;

   for (size_t i = 0; i < size; i++)
   {
      result.elements[i] = elements[i] + other_.elements[i];
   }

   return result;
}

double& Vector::operator[](int index_)
{
   if (index_ >= size || index_ < 0)
      exit(1);

   return elements[index_];
}

Vector& Vector::operator=(const Vector& other_)
{
   if (this == &other_)
      return *this;

   if (capasity < other_.size)
   {
      delete[] elements;
      elements = new double[other_.capasity];
      capasity = other_.capasity;
   }
   size = other_.size;

   for (size_t i = 0; i < other_.size; i++)
   {
      elements[i] = other_.elements[i];
   }

   return *this;
}

Vector& Vector::operator+=(const Vector& other_)
{
   if (size != other_.size)
      return *this;

   for (size_t i = 0; i < size; i++)
   {
      elements[i] = elements[i] + other_.elements[i];
   }

   return *this;
}

void Vector::Push_Back(double element_)
{
   if (capasity > size)
   {
      elements[size] = element_;
      size++;
      return;
   }
   
   if (capasity == 0)
   {
      elements = new double[1];
      capasity = size = 1;
      elements[0] = element_;
      return;
   }
   else
   {
      double* new_arr = new double[capasity * 2];
      new_arr = elements;
      delete[] elements;

      elements = new double[capasity * 2];
      elements = new_arr;
      elements[size] = element_;
      size++;
   }
}

void Vector::Print_Vectors()
{
   for (size_t i = 0; i < size; i++)
      printf("%.2lf ", elements[i]);

}

double Vector::operator*(const Vector& other_)
{
   if (size != other_.size)
      exit(2);

   double temp = 0;

   for (size_t i = 0; i < size; i++)
      temp += (elements[i] * other_.elements[i]);
   
   return temp;
}

Vector Vector::operator&(const Vector& other_)
{
   Vector temp;

   temp.elements = new double[size + other_.size + 1];

   temp.elements = elements;
   for (size_t i = 0; i < other_.size; i++)
      temp.elements[size + i] = other_.elements[i];

   return temp;
}

Vector& Vector::operator&=(const Vector& other_)
{
   if (capasity <= size + other_.size)
   {
      double* temp = new double[size];

      for (size_t i = 0; i < size; i++)
         temp[i] = elements[i];
      
      delete[] elements;
      elements = new double[capasity + other_.size];

      for (size_t i = 0; i < size; i++)
         elements[i] = temp[i];
      for (size_t i = 0; i < other_.size; i++)
         elements[i + size] = other_.elements[i];
      return *this;
   }

   for (size_t i = 0; i < other_.size; i++)
      elements[i + size] = other_.elements[i];

   return *this;
}

bool Vector::operator==(const Vector& other_)
{
   if (size != other_.size)
      return false;

   for (size_t i = 0; i < size; i++)
      if (elements[i] != other_.elements[i])
         return false;

   return true;
}

bool Vector::operator!=(const Vector& other_)
{
   if (*this == other_)
      return false;
   return true;
}

bool Vector::operator!()
{
   return (size != 0);
}


int main()
{
   const size_t size = 5;
   double arr[size] = { 4, 3, 2, 4.5, 8 };
   Vector vector(arr, size);

   vector.Print_Vectors();

   return 0;
}
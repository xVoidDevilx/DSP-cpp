#include <DSP.hpp>
#include <algorithm>
#include <random>
#include <ctime>

// Annoying to type, declare them here
using std::array; using std::is_arithmetic; using std::enable_if;
using std::vector;

template <typename T>
constexpr array<T, 10> DSP<T>::_signalset;

template <typename T>
typename enable_if<is_arithmetic<T>::value, vector<T>>::type
DSP<T>::GenerateAgile(unsigned int size)
{
   std::vector<T> output(size);

   // Create random number generator
   static std::mt19937 rng(std::time(nullptr)); // Seed with current time
   
   if constexpr (std::is_integral<T>::value) 
   {
      std::uniform_int_distribution<T> dist(0, 9); // Range for integers
      std::generate(output.begin(), output.end(), [&]() { return dist(rng); });
   }
   else if constexpr (std::is_floating_point<T>::value) 
   {
      std::uniform_real_distribution<T> dist(0.0, 9.9); // Range for floats
      std::generate(output.begin(), output.end(), [&]() { return dist(rng); });
   }
   return output; 
}

template <typename T>
typename enable_if<is_arithmetic<T>::value, vector<T>>::type
DSP<T>::GenerateFixed() 
{
   vector<T> output;
   std::random_device rd;
   std::uniform_int_distribution<int> dist(0,9);
   std::uniform_int_distribution<int> vals(1,5);
   
   T fixed_val = DSP<T>::_signalset[dist(rd)];

   for (unsigned int i = 0 ; i<5; i++)
   {
      output.insert(output.end(), vals(rd), fixed_val);
   }
   return output;
}

template <typename T>
typename enable_if<is_arithmetic<T>::value, vector<T>>::type
DSP<T>::GenerateRamp()
{
   vector<T> output;
   std::random_device rd;
   std::uniform_int_distribution<int> dist(0,9);
   std::uniform_int_distribution<int> vals(1,5);
   T start = DSP<T>::_signalset[dist(rd)];

   for (unsigned int i = 0; i<5; i++)
   {  
      auto records = vals(rd);
      for (auto j = 0 ; j < records; j++)
      {
         output.emplace_back((start+j)%10);   //putting a num into the ramp 
      }
      // update the start position
      start = (start + records)%10;
   }
   return output;
}

template <typename T>
typename enable_if<is_arithmetic<T>::value, vector<T>>::type
DSP<T>::GenerateStaggered(unsigned int size) 
{
   return DSP<T>::GenerateAgile(size);
}

/*template <typename T>
typename enable_if<is_arithmetic<T>::value, vector<T>>::type
DSP<T>::UpdateLUT() 
{

}*/

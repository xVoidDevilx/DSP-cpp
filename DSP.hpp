#pragma once

#include <array>
#include <map>
#include <vector>
#include <unordered_set>
#include <type_traits>

template <typename T>
class DSP
{
private:
   // Using std::enable_if to restrict this to arithmetic types only (int, float, double)
   static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
   static constexpr std::array<T, 10> _signalset = {{0,1,2,3,4,5,6,7,8,9}};
   
   std::map<unsigned int, std::unordered_set<T>> _LUT;
   enum
   {
      FIXED,
      AGILE,
      STEPPED,
      STAGGERED
   };

protected:
public:
   // Default constructor and destructor
   DSP() = default;
   ~DSP() = default;

   // These functions are only enabled for arithmetic types (integers or floating-point numbers)
   typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type
   GenerateAgile(unsigned int size=100);

   typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type
   GenerateFixed();

   typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type
   GenerateRamp();

   typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type
   GenerateStaggered(unsigned int size=10);

   //typename std::enable_if<std::is_arithmetic<T>::value, std::vector<T>>::type
   //void UpdateLUT(unsigned int eid, T);
};

template class DSP<int>;

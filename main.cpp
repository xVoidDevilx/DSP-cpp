#include <DSP.hpp>
#include <string>
#include <iostream>
int main () 
{
   // Create a DSP object for generation of signals
   DSP<int> int_generator;
   //DSP<float> float_generator;
   //DSP<double> double_generator;

   // Must generate a vector of the same values
   std::cout << "FIXED SIGNAL:" << std::endl;
   std::cout << "{ ";
   for (const auto signal: int_generator.GenerateFixed())
   {
      std::cout << std::to_string(signal) << " ";
   }
   std::cout << "}" << std::endl;

   // Must generate a vector of the ramp values (123...123...123)
   std::cout << "RAMP SIGNAL:" << std::endl;
   std::cout << "{ ";
   for (const auto signal: int_generator.GenerateRamp())
   {
      std::cout << std::to_string(signal) << " ";
   }
   std::cout << "}" << std::endl;

   // Must generate a vector with all possible values randomly (0-9)
   std::cout << "AGILE SIGNAL:" << std::endl;
   std::cout << "{ ";
   for (const auto signal: int_generator.GenerateAgile())
   {
      std::cout << std::to_string(signal) << " ";
   }
   std::cout << "}" << std::endl;

   // Must generate a vector with not all values randomly (0-9)
   std::cout << "STAGGERED SIGNAL:" << std::endl;
   std::cout << "{ ";
   for (const auto signal: int_generator.GenerateStaggered())
   {
      std::cout << std::to_string(signal) << " ";
   }
   std::cout << "}" << std::endl;

   return 0;
}

#include <iostream>
#include <cstdlib>

std::string getOsName();
std::string General();

int main(void){

  std::cout << "## COREG ##" << endl;
  std::cout << getOsName();
  std::cout << General();
  return 0;
}

  
    std::string getOsName()
{
    #elif _WIN64
    return "Windows 64-bit";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "MacOS";
    #elif __linux__
    return "Linux";
    return "Other";
    #endif
}   

    std::string General ()
{
  int i;
  std::cout << "Checking if processor is available...";
  if (system(NULL))
      std::cout << "Ok";
  else 
      exit (EXIT_FAILURE);
  std::cout << "Executing command DIR...\n";
  i=system ("dir");
  std::cout <<  "%d" << i;
  
  return "sysinfo done.";
}
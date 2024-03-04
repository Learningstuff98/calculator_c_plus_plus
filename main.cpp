#include  <iostream>

std::string get_desired_operation() {
  std::cout << "Please enter one of the following options:" << std::endl;
  std::cout << "add or exit." << std::endl;
  std::string desired_operation {""};
  getline(std::cin, desired_operation);
  return desired_operation;
};

int main() {
  std::string desired_operation {get_desired_operation()};
  while(desired_operation != "exit") {
    if(desired_operation == "add") {
      std::cout << "ADD OPERATIONS GO HERE." << std::endl;
      desired_operation = get_desired_operation();
    } else {
        std::cout << "ERROR! ERROR! INVALID SELECTION!" << std::endl;
        desired_operation = get_desired_operation();
    }
  };
  std::cout << "Program shutting down. Goodbye.";
};

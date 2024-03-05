#include <iostream>

std::string get_desired_operation() {
  std::cout << "Please enter one of the following options:" << std::endl;
  std::cout << "add or exit." << std::endl;
  std::string desired_operation {""};
  getline(std::cin, desired_operation);
  return desired_operation;
};

bool is_valid_integer(std::string const &int_input) {
  if(int_input[0] == '0') {
    return false;
  }
  for(auto const &int_char: int_input) {
    if(int_char != '0' && int_char != '1' && int_char != '2' && int_char != '3' && int_char != '4' && int_char != '5' && int_char != '6' && int_char != '7' && int_char != '8' && int_char != '9') {
      return false;
    }
  }
  return true;
};

std::string get_int(std::string message) {
  std::cout << message << std::endl;
  std::string int_input {""};
  getline(std::cin, int_input);
  if(is_valid_integer(int_input)) {
    return int_input;
  } else {
    return "ERROR!";
  }
};

void add_integers() {
  std::string int_1 {get_int("Enter the first number:")};
  std::string int_2 {get_int("Enter the second number:")};
  if(int_1 != "ERROR!" && int_2 != "ERROR!") {
    std::cout << "The sum is: " << (std::stoi(int_1) + std::stoi(int_2)) << std::endl;
  } else {
    std::cout << "ERROR! ERROR! INVLID INPUT!" << std::endl;
  }
};

int main() {
  std::string desired_operation {get_desired_operation()};
  while(desired_operation != "exit") {
    if(desired_operation == "add") {
      add_integers();
      desired_operation = get_desired_operation();
    } else {
      std::cout << "ERROR! ERROR! INVALID SELECTION!" << std::endl;
      desired_operation = get_desired_operation();
    }
  };
  std::cout << "Program shutting down. Goodbye.";
  return 0;
};

#include <iostream>

std::string get_desired_operation() {
  std::cout << "Please enter one of the following options:" << std::endl;
  std::cout << "add or exit." << std::endl;
  std::string desired_operation {""};
  getline(std::cin, desired_operation);
  return desired_operation;
};

bool is_valid_integer(std::string &input) {

  // what if one of the inputs is 0?

  bool is_negative {false};
  if(input[0] == '-') {
    input.erase(0, 1);
    is_negative = true;
  }
  if(input == "") {
    return false;
  }
  if(input.length() > 1 && input[0] == '0') {
    return false;
  }
  for(auto const &input_char: input) {
    if(
      input_char != '0' &&
      input_char != '1' &&
      input_char != '2' &&
      input_char != '3' &&
      input_char != '4' &&
      input_char != '5' &&
      input_char != '6' &&
      input_char != '7' &&
      input_char != '8' &&
      input_char != '9'
    ) {
      return false;
    }
  }
  if(is_negative) {
    input.insert(0, 1, '-');
  }
  return true;
};

std::string get_input(std::string message) {
  std::cout << message << std::endl;
  std::string input {""};
  getline(std::cin, input);
  if(is_valid_integer(input)) {
    return input;
  } else {
    return "error";
  }
};

void add_integers() {
  std::string int_1 {get_input("Enter the first number:")};
  std::string int_2 {get_input("Enter the second number:")};
  if(int_1 != "error" && int_2 != "error") {
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

#include "model.h"

/**
 * @brief Addition of new operator/operand to model's stack or queue
 *
 * @details All operands undergo conversion from string to double and then are added to the queue.
 * All variables (x) are pushed to the queue as a structure with a distinct type. 
 * If we are dealing with operator then:
 * 1. Operators with more than 1 character (sin, sqrt, atan) are translated to single character code
 * 2. If the operator is ')', we go to delete_parenthesis function
 * 3. In case of unary + and - (occur at the beginning of the string have '(' before them), treat them as '0-smth'
 * 4. In case of other operations except for '(, move all characters with higher priority from stack to queue (queue_manipulation), then add operation to stack
 * 5. Add '(' to stack if it's a current operator
 * @param new_op string containing operator or operand
**/

void Model::add_from_view(std::string new_op) {
    // detect x
    if (new_op[0] == 'x') {
        operators_and_operands ops{0, '\0', X};
        output_queue.push(ops);
        last_op = 'x';
        return;
    }
    // detect numbers
    if (((new_op[0] >= '0')&&(new_op[0] <= '9'))||(new_op[0] == '.')||(new_op[0] == 'e')) {
        if (valid_number(new_op)) {
            double num = std::stod(new_op);
            operators_and_operands ops{num, '\0', OPERAND};
            output_queue.push(ops);
            last_op = 'd';
        }
        return;
    }
    // operations -> char code
    char operation = new_op[0];
    if (translation.count(new_op) == 1) {
        operation = translation[new_op];
    }
    // closing parenthesis
    if (operation == ')') {
        delete_parenthesis();
        last_op = operation;
        return;
    }

    // unary + and -
    if ((operation == '+' || operation == '-') && (last_op == '(')) {
        queue_manipulation(priority['?']);
        output_queue.push(operators_and_operands(zero));
    } else if (operation != '(') {
        // other ops
        if (priority.count(operation) != 0) {
            queue_manipulation(priority[operation]);
        }
    }
    operators_and_operands ops{0, operation, OPERATION};
    operand_stack.push(ops);

    last_op = operation;
}

/**
 * @brief Moves operators with higher priority from stack to queue
 *
 * @details Pops operators from queue and moves them to stack while they are mentioned in the set, passed to the function
 * @param higher_operations set of operations with higher priority than current operator from add_from_view
**/
void Model::queue_manipulation(std::unordered_set<char> higher_operations) {
    while (!operand_stack.empty()) {
        operators_and_operands removed = operand_stack.top();
        if (higher_operations.count(removed.operatorr) == 0) {
            break;
        }
        operand_stack.pop();
        output_queue.push(removed);
    }
}


/**
 * @brief ELiminates '(' form the stack if ')' was encountered in add_from_view
 *
 * @details Empties the stack and moving operands to queue until we get '('. 
 * If the stack is empty and '(' wasn't encountered, counts it as an error
**/
void Model::delete_parenthesis() {
    bool flag = true;
    while (!operand_stack.empty()) {
        operators_and_operands removed = operand_stack.top();
        operand_stack.pop();
        if (removed.operatorr != '(') {
            output_queue.push(removed);
        } else {
            flag = false;
            break;
        }
    }
    error = flag;
}

/**
 * @brief When input to the structures is finished, calculate the result of the expression
 *
 * @details In this function we use 3 structures: stack and queue filled during input and
 * the additional stack to put operands during calculation. Since in the beginning of the function
 * we empty the first stack, and only then use the second, for the convinience purposes single
 * instance of the class is used.
 * 1. We empty the first stack and transfer operands to the queue. In case of error, execution is stopped
 * 2. Result is calculated using the queue:
 *    - operands are pushed to the second stack
 *    - variables (x) are substituted with their real value and pushed to the stack as operands
 *    - for each operator single (for unary operators) or two (for binary) operands are taken from the stack
 *      then operation is performed with the help of perfom_operation function
 * 3. When output queue is empty, calculation is completed. Size of stack should be = 1 (with only node being our result)
**/
void Model::calculate() {
    fill_queue();
    if (error) {
        return;
    }
    operators_and_operands result;
    while (!output_queue.empty()) {
        operators_and_operands oper = output_queue.front();
        output_queue.pop();
        if (oper.value_type == OPERAND) {
            operand_stack.push(oper);
        } else if (oper.value_type == X) {
            oper.operand = value_of_x;
            oper.value_type = OPERAND;
            operand_stack.push(oper);
        } else  {
            char operation = oper.operatorr;
            if (operand_stack.empty()) {
                error = true;
                return;
            }
            operators_and_operands one = operand_stack.top();
            operand_stack.pop();
            operators_and_operands two;
            if (unary.count(oper.operatorr) == 0) {
                // binary operations -- get second value
                if (operand_stack.empty()) {
                    error = true;
                    return;
                }
                two = operand_stack.top();
                operand_stack.pop();
            }
            perfom_operation(one.operand, two.operand, operation, result.operand);
            if (error == true) {
                return;
            }
            operand_stack.push(operators_and_operands(result));
        }
    }
    if ((operand_stack.size() != 1) || (output_queue.size()!= 0)) {
        error = true;
    }
    return_value = operand_stack.top().operand;
}
/**
 * @brief Fills vectors with X and corresponding Y values to plot later
 *
 * @details Determines the step based on the stated size of the vectors.
 * For each X value calculates the Y value using operand_stack and output_queue,
 * pushes both back to the vectors.
 * @param x_min lower limit of x axis
 * @param x_max higher limit of x axis
 * @param xstd vector storing x values
 * @param ystd vector storing y values
 * @param step expected size of both vectors = number of dots to plot
**/
void Model::graph(double x_min, double x_max, std::vector<double>& xstd, std::vector<double>& ystd, unsigned int step) {
    value_of_x = x_min;
    double size = (x_max - x_min) / (step - 2);
    for (unsigned int i = 0; i < step; i++) {
        if (value_of_x < x_max) {
            calc_x();
            if (error == false) {
                xstd.push_back(value_of_x);
                ystd.push_back(return_value);
            }
        }
        value_of_x += size;
    }
}

/**
 * @brief Calculates the result without loosing the structures from add_from_view
 *
 * @details Creates copies of operand_stack and output_queue using copy constructor,
 * calculates the result, restores original values of both structures.
**/
void Model::calc_x() {
    std::stack<operators_and_operands> save_stack(operand_stack);
    std::queue<operators_and_operands> save_queue(output_queue);
    error = false;
    return_value = 0;
    calculate();
    operand_stack = save_stack;
    output_queue = save_queue;
}

/**
 * @brief Moves objects from stack to queue before calculation
 *
 * @details Simultaneously checks for '(' operators -- there should be none if we have
 * valid bracket sequences
**/
void Model::fill_queue() {
    while (!operand_stack.empty()) {
        operators_and_operands ops = operand_stack.top();
        operand_stack.pop();
        output_queue.push(ops);
        if (ops.operatorr == '(') {
            error = true;
        }
    }
}

/**
 * @brief Performes singular operations
 *
 * @param one first operand
 * @param two second operand (zero in case of unary operation)
 * @param operation one-character code of the operation that should be performed
 * @param result reference to the result value
**/
void Model::perfom_operation(double one, double two, char operation, double& result) {
  switch (operation) {
    case '-':
      result = two - one;
      break;
    case '+':
      result = two + one;
      break;
    case '*':
      result = two * one;
      break;
    case '/':
      if (fabs(one) < 0.00001) {
        error = true;
      } else {
        result = two / one;
      }
      break;
    case '^':
      result = pow(two, one);
      break;
    case 'c':
      result = cos(one);
      break;
    case 's':
      result = sin(one);
      break;
    case 't':
      result = tan(one);
      break;
    case 'l':
      result = log10(one);
      break;
    case 'm':
      result = fmod(two, one);
      break;
    case 'o':
      result = acos(one);
      break;
    case 'i':
      result = asin(one);
      break;
    case 'a':
      result = atan(one);
      break;
    case 'q':
      result = pow(one, 0.5);
      break;
    case 'e':
      result = log(one);
      break;
  }
}

/**
 * @brief Tokenizes the string that contains our expression
 *
 * @param unprocessed expression (should not contain spaces or typos)
 * @details This function is not used in MVC and only utilized for tests where instead of
 * sequence of single operands we get a long string with expression. Purpose of this function is
 * to transform the latter to the former (in form of vector of strings).
**/
std::vector<std::string> Model::test_adapter(const std::string& unprocessed) {
    std::vector<std::string> processed;
    int skip = 0;
    std::string number;
    for(std::string::const_iterator it = unprocessed.begin(); it != unprocessed.end(); ++it) {
        if (skip != 0) {
            skip--;
            continue;
        }
        if ((*it >='0' && *it <='9') || (*it == '.')) {
            number.push_back(*it);
            continue;
        } else {
            if (!number.empty()) {
                processed.push_back(number);
                number.clear();
            }
        }
        switch (*it) {
            case 'c':
                skip = 2;
                processed.push_back("cos");
                break;
            case 't':
                skip = 2;
                processed.push_back("tan");
                break;
            case 'm':
                skip = 2;
                processed.push_back("mod");
                break;
            case 'a': // atan acos asin
                skip = 3;
                switch (*(it+1)) {
                    case 't':
                        processed.push_back("atan");
                        break;
                    case 'c':
                        processed.push_back("acos");
                        break;
                    case 's':
                        processed.push_back("asin");
                        break;
                }
                break;
            case 's': // sin sqrt
                switch (*(it+1)) {
                    case 'i':
                        skip = 2;
                        processed.push_back("sin");
                        break;
                    case 'q':
                        skip = 3;
                        processed.push_back("sqrt");
                        break;
                }
                break;
            case 'l': // log ln
                switch (*(it+1)) {
                    case 'o':
                        skip = 2;
                        processed.push_back("log");
                        break;
                    case 'n':
                        skip = 1;
                        processed.push_back("ln");
                        break;
                }
                break;
            default:
                std::string a{*it};
                processed.push_back(a);
                break;
        }
    }
    if (!number.empty()) {
        processed.push_back(number);
        number.clear();
    }
    return processed;
}

/**
 * @brief Checks if string represents valid unsigned double
 *
 * @param num string containing supposed double
**/
bool Model::valid_number(const std::string& num) {
    static const std::regex r("^[0-9]+([.][0-9]+)?([e][-+]?[0-9]+)?$");
    bool ok_number = std::regex_match(num, r);
    error = (ok_number == false)? true : error;
    return ok_number;
}
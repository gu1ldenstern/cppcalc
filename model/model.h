#ifndef MODEL_H
#define MODEL_H

#include <math.h>

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <regex>

class Model {
public:
    //! result of the calculation
    double return_value = 0;
    //! flag, reflects validity of the expression
    bool error = false;
    //! current value of the variable (x)
    double value_of_x = 0;
private:
    //! marker reflecting the nature of the passed value -- is it operand, operation or variable
    enum {OPERAND, OPERATION, X};
    //! represents the node of stack and queue
    struct operators_and_operands {
            double operand = 0;
            char operatorr = '\0';
            int value_type = OPERAND; // ex is_operand
        };
    //! stack for operations and operands
    std::stack<operators_and_operands> operand_stack;
    //! queue for operations and operands
    std::queue<operators_and_operands> output_queue;
    //! dictionary mapping long function names to one-char code
    std::unordered_map<std::string, char> translation {{"cos", 'c'}, {"acos", 'o'}, {"sin", 's'},
    {"asin", 'i'}, {"tan", 't'}, {"atan", 'a'},
    {"sqrt", 'q'}, {"ln", 'e'}, {"log", 'l'},
    {"mod", 'm'}};
    //! most recent operator in add_from_view
    char last_op = '(';
    //! struct representing operand zero. probably isn't really neccessary
    operators_and_operands zero{0, '\0', OPERAND};

    // PRIORITIES:
    // const set<std::char> empty {};
    //! set of operations with the highest priority (higher than unary)
    std::unordered_set<char> highest {'^'};
    //! set of operations with high priority (higher than trigonometry, exponent, logarithm)
    std::unordered_set<char> high {'^', 'c', 'o', 's', 'i', 't', 'a', 'l', 'e', 'q'};
    //! set of operations with the low priority (higher than division and multiplication)
    std::unordered_set<char> low {'^', 'c', 'o', 's', 'i', 't', 'a', 'l', 'e', 'q', 'm', '/', '*'};
    //! set of operations with the lowest priority (higher than addition and substitution)
    std::unordered_set<char> lowest {'^', 'c', 'o', 's', 'i', 't', 'a', 'l', 'e', 'q', 'm', '/', '*', '+', '-'};
    //! set of unary operations
    std::unordered_set<char> unary {'c', 'o', 's', 'i', 't', 'a', 'l', 'e', 'q'};
    //! dictionary mapping operation to its priority
    std::unordered_map<char, std::unordered_set<char>> priority {{'+', lowest}, {'-', lowest}, {'/', low}, {'*', low}, {'^', high}, {'?', highest}};
    void queue_manipulation(std::unordered_set<char> higher_operations);
    void delete_parenthesis();
    void fill_queue();
    bool valid_number(const std::string& num);
    // void free_queue();
    void perfom_operation(double one, double two, char operation, double& result);
public:
    void add_from_view(std::string new_op);
    void calculate();
    void calc_x();
    void graph(double x_min, double x_max, std::vector<double>& xstd, std::vector<double>& ystd, unsigned int step);
    std::vector<std::string> test_adapter(const std::string& unprocessed);
};


#endif  // MODEL_H
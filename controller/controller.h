#include <iostream>
#include <vector>
#include <string>

#include "../model/model.h"

class Controller {
private:
    //! model from MVC pattern: reinitialized after each expression
    Model model;
    //! expression displayed in View
    std::string view_expression;
    //! used to store inputed numbers while input is not finished
    std::string current_number;
public:
    //! flag reflecting occurence of variables in the expression
    bool x_occured = false;
    std::string add_operator(std::string value);
    std::string add_operand(std::string value);
    std::string x(std::string value);
    void fill_vectors(double x_min, double x_max, std::vector<double>& xstd, std::vector<double>& ystd, unsigned int step);
    std::string calculate(double x_single = 0);
    std::string destroy();
    std::string get_view_expression() {return view_expression;}
    void finish_number();
};


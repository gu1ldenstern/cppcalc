#include "controller.h"


/**
 * @brief Activated if operator is passed from view: adds it to model
 *
 * @details Additionally checks if number input is finished: if so, also
 * transfers it to the model. Returns full expression to the queue
 * @param value operator
**/
std::string Controller::add_operator(std::string value) {
    if (((value[0] == '-') || (value[0] == '+')) && ((!current_number.empty())&&(current_number.back() == 'e'))) {
        add_operand(value);
        return view_expression;
    }
    finish_number();
    model.add_from_view(value);
    view_expression.append(value);
    return view_expression;
}

/**
 * @brief Activated if operand is passed from view: temporarily stores it
 *
 * @details Also returns full expression to the queue
 *
 * @param value operand
**/
std::string Controller::add_operand(std::string value) {
    current_number.append(value);
    view_expression.append(value);
    return view_expression;
}

/**
 * @brief Activated if operand is passed from view: temporarily stores it
 *
 * @details Also returns full expression to the queue
 *
 * @param value variable
**/
std::string Controller::x(std::string value) {
    x_occured = true;
    model.add_from_view(value);
    view_expression.append(value);
    return view_expression;
}

/**
 * @brief Actives when '=' is pressed. Calculates expression and returns the result
 *
 * @details Like add_operator() checks if number input is finished.
 * Activates model's calculate function and returns string with result if 
 * expression is valid or "ERROR" if expression contains a typo.
 * @param value of x for which y should be calculated
**/
//! @todo remove trailing zeros
std::string Controller::calculate(double x_single) {
    finish_number();
    if (!x_occured) {
        model.calculate();
    } else {
        model.value_of_x = x_single;
        model.calc_x();
    }
    bool error = model.error;
    std::string res = std::to_string(model.return_value);
    if (!x_occured){
        destroy();
    }
    if (error == true) {
        return "ERROR";
    } else {
        return res;
    }
}

/**
 * @brief Reinitializes the model
 *
**/
std::string Controller::destroy() {
    current_number.clear();
    model = Model();
    view_expression = "";
    return "";
}

/**
 * @brief Finished inputting the number and calls model to fill the vectors
 * @param x_min lower limit of x axis
 * @param x_max higher limit of x axis
 * @param xstd vector storing x values
 * @param ystd vector storing y values
 * @param step expected size of both vectors = number of dots to plot
**/
void Controller::fill_vectors(double x_min, double x_max, std::vector<double>& xstd, std::vector<double>& ystd, unsigned int step) {
    finish_number();
    model.graph(x_min, x_max, xstd, ystd, step);
}

/**
 * @brief Helper function; adds inputted number to the model
**/
void Controller::finish_number() {
    if (!current_number.empty()) {
        model.add_from_view(current_number);
        current_number.clear();
    }
}

// void Controller::calc_x(double x_val) {
//     finish_number();
//     model.value_of_x = x_val;
//     model.calc_x();
//     bool error = model.error;
//     std::string res = std::to_string(model.return_value);
//     destroy();
//     if (error == true) {
//         return "ERROR";
//     } else {
//         return res;
//     }
// }
#include <gtest/gtest.h>
#include "../model/model.h"
#define DIFF 1e-5

void calculator(std::string st, double& res, bool& error) {
    Model model;
    std::vector<std::string> vec = model.test_adapter(st);
    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it) {
        model.add_from_view(*it);
    }
    model.calculate();
    res = model.return_value;
    error = model.error;
}

TEST(RANDOM, rand1) {
    double res;
    bool error;
    std::string expression =  "2+4";
    double true_res = 6;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand2) {
    double res;
    bool error;
    std::string expression =  "2+4*(10+46-7)";
    double true_res = 198;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand3) {
    double res;
    bool error;
    std::string expression = "(2.2)^(-2.2)";
    double true_res = 0.176469681;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand4) {
    double res;
    bool error;
    std::string expression = "5+(3+sin(8/2-3.5))*2";
    double true_res =  11.958851;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand5) {
    double res;
    bool error;
    std::string expression = "sin(9)-(-2)";
    double true_res = 2.41211848524;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand6) {
    double res;
    bool error;
    std::string expression =  "cos(sin(tan(3)))";
    double true_res = 0.98992582956;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand7) {
    double res;
    bool error;
    std::string expression =  "5+7-1";
    double true_res = 11;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand8) {
    double res;
    bool error;
    std::string expression =  "5.76+43-11";
    double true_res = 37.76;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand9) {
    double res;
    bool error;
    std::string expression =  "1237.55+13.3+(-6)";
    double true_res = 1244.85;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand10) {
    double res;
    bool error;
    std::string expression = "0.88-54";
    double true_res = -53.12;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand11) {
    double res;
    bool error;
    std::string expression = "34+99.56-1.1111";
    double true_res = 132.4489;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand12) {
    double res;
    bool error;
    std::string expression = "1.054356663+0.00004";
    double true_res = 1.054396663;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand13) {
    double res;
    bool error;
    std::string expression = "11+7^2-(45+sin(0.7))";
    double true_res = 14.3557823128;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand14) {
    double res;
    bool error;
    std::string expression = "sin(cos(0.75))+1.5^3/4.5";
    double true_res = 1.418127185211;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand15) {
    double res;
    bool error;
    std::string expression =  "sin(0.2^4)*cos(100-95*1.5)";
    double true_res = 0.000141414;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand16) {
    double res;
    bool error;
    std::string expression =  "5mod3*6/12+3*(log(3)+tan(3))";
    double true_res = 2.00372413494;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand17) {
    double res;
    bool error;
    std::string expression = "5*9+(4+2)/5.4";
    double true_res = 46.1111111111;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand18) {
    double res;
    bool error;
    std::string expression = "3+155.40905+ln(30/2)^11";
    double true_res = 57599.650844034542;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand19) {
    double res;
    bool error;
    std::string expression =  "cos(1)+sin(2)*sin(1)/14";
    double true_res = 0.594956;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand20) {
    double res;
    bool error;
    std::string expression = "43.987+11*(atan(2)+sqrt(4))+1.5mod2";
    double true_res = 79.66563592;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand21) {
    double res;
    bool error;
    std::string expression =  "0.03*(-4)^2";
    double true_res = 0.48;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand22) {
    double res;
    bool error;
    std::string expression = "sin(cos(4))";
    double true_res = -0.608083;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand23) {
    double res;
    bool error;
    std::string expression = "tan(log(0.4))+cos(1.2)";
    double true_res = -0.05800935062;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand24) {
    double res;
    bool error;
    std::string expression = "asin(1)*tan(2)-(atan(2)+ln(4))";
    double true_res = -5.9256956700264893;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand25) {
    double res;
    bool error;
    std::string expression =  "log(3)^ln(1.3)";
    double true_res = 0.823538;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand26) {
    double res;
    bool error;
    std::string expression = "2.11^log(2)*ln(0.5)";
    double true_res = -0.867849;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand27) {
    double res;
    bool error;
    std::string expression =  "asin(cos(3^3))";
    double true_res =-0.296462;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand28) {
    double res;
    bool error;
    std::string expression = "cos(0.65+sqrt(2+1))+1";
    double true_res = 0.274848433242;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand29) {
    double res;
    bool error;
    std::string expression = "(+atan(5+2mod3))-(+sin(5.23))";
    double true_res = 2.29790300903;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand30) {
    double res;
    bool error;
    std::string expression = "(-cos(2-4)^3)";
    double true_res = 0.072067555748;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand31) {
    double res;
    bool error;
    std::string expression = "4mod3+ln(0.67)";
    double true_res = 0.5995224334;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand32) {
    double res;
    bool error;
    std::string expression = "(1.654+0.00034)/sqrt(2)";
    double true_res = 1.1697959323882;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}

TEST(RANDOM, rand33) {
    double res;
    bool error;
    std::string expression = "1";
    double true_res = 1;
    calculator(expression, res, error);
    EXPECT_NEAR(res, true_res, DIFF);
    ASSERT_EQ(error, 0);
}


TEST(ERROR, err1) {
    double res;
    bool error;
    std::string expression = "2+";
    calculator(expression, res, error);
    ASSERT_EQ(error, 1);
}

TEST(ERROR, err2) {
    double res;
    bool error;
    std::string expression =  "3+(3+(3+(3+)))";
    calculator(expression, res, error);
    ASSERT_EQ(error, 1);
}

TEST(ERROR, err3) {
    double res;
    bool error;
    std::string expression = "4+53.43-";
    calculator(expression, res, error);
    ASSERT_EQ(error, 1);
}

TEST(ERROR,  sum_sum) {
  bool error;
  double res;
  std::string expression = "2++2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sum_sub) {
  bool error;
  double res;
  std::string expression = "2+-2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sum_mult) {
  bool error;
  double res;
  std::string expression = "2+*2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sum_div) {
  bool error;
  double res;
  std::string expression = "2+/2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sum_degree) {
  bool error;
  double res;
  std::string expression = "2+^2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sub_sum) {
  bool error;
  double res;
  std::string expression = "2-+2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sub_sub) {
  bool error;
  double res;
  std::string expression = "2--2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sub_mult) {
  bool error;
  double res;
  std::string expression = "2-*2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sub_div) {
  bool error;
  double res;
  std::string expression = "2-/2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sub_degree) {
  bool error;
  double res;
  std::string expression = "2-^2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mult_sum) {
  bool error;
  double res;
  std::string expression = "2*+2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mult_sub) {
  bool error;
  double res;
  std::string expression = "2*-2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mult_mult) {
  bool error;
  double res;
  std::string expression = "2**2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mult_div) {
  bool error;
  double res;
  std::string expression = "2*/2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mult_degree) {
  bool error;
  double res;
  std::string expression = "2*^2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_sum) {
  bool error;
  double res;
  std::string expression = "2/+2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_sub) {
  bool error;
  double res;
  std::string expression = "2/-2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_mult) {
  bool error;
  double res;
  std::string expression = "2/*2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_div) {
  bool error;
  double res;
  std::string expression = "2//2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_degree) {
  bool error;
  double res;
  std::string expression = "2/^2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  degree_sum) {
  bool error;
  double res;
  std::string expression = "2^+2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  degree_sub) {
  bool error;
  double res;
  std::string expression = "2^-2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  degree_mult) {
  bool error;
  double res;
  std::string expression = "2^*2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  degree_div) {
  bool error;
  double res;
  std::string expression = "2^/2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  degree_degree) {
  bool error;
  double res;
  std::string expression = "2^^2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_int) {
  bool error;
  double res;
  std::string expression = "(5+5)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  right_brace_int_2) {
  bool error;
  double res;
  std::string expression = "(5+5)5";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  left_brace_sum) {
  bool error;
  double res;
  std::string expression = "(+5)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  left_brace_sub) {
  bool error;
  double res;
  std::string expression = "(-5)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  left_brace_degree) {
  bool error;
  double res;
  std::string expression = "(^5)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sum_mod) {
  bool error;
  double res;
  std::string expression = "2+mod2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_sum) {
  bool error;
  double res;
  std::string expression = "2mod+2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sub_mod) {
  bool error;
  double res;
  std::string expression = "2-mod2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_sub) {
  bool error;
  double res;
  std::string expression = "2mod-2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mult_mod) {
  bool error;
  double res;
  std::string expression = "2*mod2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_mult) {
  bool error;
  double res;
  std::string expression = "2mod*2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_mod) {
  bool error;
  double res;
  std::string expression = "2/mod2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_div) {
  bool error;
  double res;
  std::string expression = "2mod/2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  degree_mod) {
  bool error;
  double res;
  std::string expression = "2^mod2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_degree) {
  bool error;
  double res;
  std::string expression = "2mod^2";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  div_zero) {
  bool error;
  double res;
  std::string expression = "2/0";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  braces_1) {
  bool error;
  double res;
  std::string expression = "5+3*(6-2))";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  braces_2) {
  bool error;
  double res;
  std::string expression = "5+3*((6-2)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  braces_3) {
  bool error;
  double res;
  std::string expression = "5+3*(6-2)+(-1)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  unary_minus) {
  bool error;
  double res;
  std::string expression = "(-6-9)+(-1)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  unary_plus) {
  bool error;
  double res;
  std::string expression = "(6-9)+(+1)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  left_brace_plus) {
  bool error;
  double res;
  std::string expression = "sin(+6)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  left_brace_minus) {
  bool error;
  double res;
  std::string expression = "asin(-6)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  left_brace_mult) {
  bool error;
  double res;
  std::string expression = "atan(*6)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  left_brace_div) {
  bool error;
  double res;
  std::string expression = "log(/6)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  left_brace_degree_2) {
  bool error;
  double res;
  std::string expression = "log(^6)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  left_brace_mod) {
  bool error;
  double res;
  std::string expression = "log(mod6)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_plus) {
  bool error;
  double res;
  std::string expression = "sin(6+)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_minus) {
  bool error;
  double res;
  std::string expression = "asin(6-)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_mult) {
  bool error;
  double res;
  std::string expression = "atan(6*)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_div) {
  bool error;
  double res;
  std::string expression = "log(6/)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_degree) {
  bool error;
  double res;
  std::string expression = "log(6^)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  right_brace_mod) {
  bool error;
  double res;
  std::string expression = "log(6mod)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  double_ok) {
  bool error;
  double res;
  std::string expression = "5.6+9.0";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  double_error) {
  bool error;
  double res;
  std::string expression = "5..6+9.0";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  one_more) {
  bool error;
  double res;
  std::string expression = "(5+x))";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_point) {
  bool error;
  double res;
  std::string expression = "5.";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  three_point) {
  bool error;
  double res;
  std::string expression = "5...1+1";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_left_brace) {
  bool error;
  double res;
  std::string expression = "(";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_right_brace) {
  bool error;
  double res;
  std::string expression = ")";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_minus) {
  bool error;
  double res;
  std::string expression = "5-";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_plus) {
  bool error;
  double res;
  std::string expression = "5+";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_mult) {
  bool error;
  double res;
  std::string expression = "5*";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_m) {
  bool error;
  double res;
  std::string expression = "5m";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_degree) {
  bool error;
  double res;
  std::string expression = "5^";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  no_next_div) {
  bool error;
  double res;
  std::string expression = "5/";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_minus) {
  bool error;
  double res;
  std::string expression = "3mod-";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  minus_mod) {
  bool error;
  double res;
  std::string expression = "-mod";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_right_brace) {
  bool error;
  double res;
  std::string expression = "mod(5)";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sqrt_mod) {
  bool error;
  double res;
  std::string expression = "modsqrt";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  cos_mod) {
  bool error;
  double res;
  std::string expression = "modcos";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  sin_mod) {
  bool error;
  double res;
  std::string expression = "modsin";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_tan) {
  bool error;
  double res;
  std::string expression = "modtan";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_atan) {
  bool error;
  double res;
  std::string expression = "modatan";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_log) {
  bool error;
  double res;
  std::string expression = "modlog";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  mod_sqrt) {
  bool error;
  double res;
  std::string expression = "modsqrt";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  minus_s) {
  bool error;
  double res;
  std::string expression = "-sin";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  minus_cos) {
  bool error;
  double res;
  std::string expression = "-cos";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  minus_atan) {
  bool error;
  double res;
  std::string expression = "-atan";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  minus_ln) {
  bool error;
  double res;
  std::string expression = "-ln";
  calculator(expression, res, error);
  ASSERT_EQ(error, 1);
}

TEST(ERROR,  another_right_brace_plus) {
  bool error;
  double res;
  std::string expression = "(5+5)+1";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}

TEST(ERROR,  another_right_brace_mod) {
  bool error;
  double res;
  std::string expression = "(5+5)mod1";
  calculator(expression, res, error);
  ASSERT_EQ(error, 0);
}
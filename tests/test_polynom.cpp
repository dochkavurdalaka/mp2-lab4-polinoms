#pragma once
#include "Parser.h"
#include <gtest/gtest.h>


TEST(Monom, can_create_monom)
{
	
	ASSERT_NO_THROW(Monom a(0.5, 123););
}

TEST(Monom, cout_operator_works_correctly)
{
	Monom a(0.5, 123);
	std::stringstream in;
	in << a;
	std::string temp = in.str();


	EXPECT_EQ(temp, "0.5xy^2z^3");
}

TEST(Monom, operator_minus)
{
	Monom a(0.5, 123);
	std::stringstream in;
	in << -a;
	std::string temp = in.str();


	EXPECT_EQ(temp, "-0.5xy^2z^3");
}

TEST(Monom, operator_conversion)
{
	Monom a(0.5, 123);
	Monom b(0.3, 122);

	EXPECT_EQ(true, b<a);
}

TEST(Monom, operator_equality)
{
	Monom a(0.5, 123);
	Monom b(0.3, 123);

	EXPECT_EQ(true, b == a);
}


TEST(Polinom, can_create_Polinom) {
	std::string tem = "x^2yz+xyz^2";
	ASSERT_NO_THROW(Polinom pol = Parser(tem).getPolinom());
}



TEST(Polinom, can_copy_polinom) {
	std::string tem = "x^2yz+xyz^2";
	Polinom pol = Parser(tem).getPolinom();
	ASSERT_NO_THROW(Polinom pol1(pol));
}


TEST(Polinom, operator_square_scopes_polinom_works_correctly) {
	std::string tem = "x^2yz+xyz^2";
	Polinom pol = Parser(tem).getPolinom();
	Monom a(1, 112);
	EXPECT_EQ(a,pol[1]);
}

TEST(Polinom, method_add_works_correctly) {
	std::string tem = "x^2yz+xyz^2";
	Polinom pol = Parser(tem).getPolinom();
	Monom a(1, 121);
	pol.add(a);
	EXPECT_EQ(a, pol[1]);

}


TEST(Polinom, method_add_removes_opposite_elements) {
	std::string tem = "x^2yz+xyz^2";
	Polinom pol = Parser(tem).getPolinom();
	pol.add(Monom(-1, 211));
	EXPECT_EQ(Monom(1, 112), pol[0]);

}

TEST(Polinom, operator_minus_works_correctly) {
	std::string tem = "x^2yz+xyz^2";
	Polinom pol = Parser(tem).getPolinom();
	pol = -pol;
	std::stringstream in;
	in << pol;
	tem = in.str();
	EXPECT_EQ(tem, "-x^2yz-xyz^2");
}

TEST(Polinom, operator_plus_works_correctly) {
	std::string tem = "x^2yz+xyz^2";
	std::string lem = "x^2yz+xyz";
	Polinom pol = Parser(tem).getPolinom();
	Polinom pol2 = Parser(lem).getPolinom();
	std::stringstream in;
	in << pol+pol2;
	tem = in.str();
	EXPECT_EQ(tem, "2x^2yz+xyz^2+xyz");
}

TEST(Polinom, operator_multiply_works_correctly) {
	std::string tem = "x^2yz+xyz^2";
	std::string lem = "x^2yz+xyz";
	Polinom pol = Parser(tem).getPolinom();
	Polinom pol2 = Parser(lem).getPolinom();
	std::stringstream in;
	in << pol * pol2;
	tem = in.str();
	EXPECT_EQ(tem, "x^4y^2z^2+x^3y^2z^3+x^3y^2z^2+x^2y^2z^3");
}

/*
TEST(polynomial, can_create_polynomial_by_constructor_with_parametrs)
{
	ASSERT_NO_THROW(polynomial p("19x+3yz"));
	ASSERT_NO_THROW(polynomial p1("x-3.6"));
	ASSERT_NO_THROW(polynomial p2("-7.1y^9-3z^2x^6+y"));

}*/
/*
TEST(polynomial, can_create_polynomial_by_constructor_of_copy)
{
	polynomial a("43x^2y-35z+17.8x");
	ASSERT_NO_THROW(polynomial b(a));
}

TEST(polynomial, throw_then_negative_degree)
{
	ASSERT_ANY_THROW(polynomial a("11y^-4+5z"));
}

TEST(polynomial, throw_then_too_large_degree)
{
	ASSERT_ANY_THROW(polynomial a("xyz^2022+5.09"));
}

TEST(polynomial, operator_of_equal_is_correctly)
{
	polynomial a("4.9x^2y-35z+3y");
	polynomial b("12x+5.8y^3-1");
	ASSERT_NO_THROW(b = a);
	EXPECT_EQ(b, a);
}

TEST(polynomial, operator_of_doudle_equal_is_correctly)	
{
	polynomial a("37x^2y-10.17z+0");
	polynomial b("-10.17z+5+37x^2y-7+2");
	EXPECT_EQ(true, a==b);
}


TEST(polynomial, operator_of_not_equal_is_correct)
{
	polynomial a("3x^2y-35z+4yz");
	polynomial b("-35z+4zx+4yz");
	EXPECT_EQ(true, a != b);
}

TEST(polynomial, can_erase_monomial_with_zero_coefficient)
{
	polynomial a("20.22xyz-7y+3-38z^4"), b("-3+7y-20.21xyz");
	EXPECT_EQ(4, a.get_count());
	a += b;	
	//a.print();
	EXPECT_EQ(2, a.get_count());
}

TEST(polynomial, can_to_group_monomials_with_the_same_coefficients)
{
	polynomial a("15xyz-23y+4"), b("-12zyx+8");
	EXPECT_EQ(3, a.get_count());
	a += b;	
	EXPECT_EQ(3, a.get_count());
}

TEST(polynomial, can_addeq_correctly)
{
	polynomial a("32x^4yz^5"), b("-x^7+12y-7.85"), c("-x^7+32x^4yz^5+12y-7.85");
	a += b;
	EXPECT_EQ(c, a);
}

TEST(polynomial, can_add_correctly)
{
	polynomial a("32x^4yz^5"), b("x^7+12y"), c("x^7+32x^4yz^5+12y"), d;
	d = a + b;
	EXPECT_EQ(c, d);
}

TEST(polynomial, can_subeq_correctly)
{
	polynomial a("3x^4yz^5"), b("-x^7+12y-2.1"), c("x^7+3x^4yz^5-12y+2.1");
	a -= b;
	EXPECT_EQ(c, a);
}

TEST(polynomial, can_sub_correctly)
{
	polynomial a("32.45x^4yz^5"), b("x^7+12y"), c("-x^7+32.45x^4yz^5-12y"), d;
	d = a - b;
	EXPECT_EQ(c, d);
}

TEST(polynomial, can_mult_eq_polynoms_correctly)
{
	polynomial a("x^2+y"), b("7x+z"), c("7x^3+x^2z+7xy+yz");
	a *= b;
	EXPECT_EQ(c, a);
}

TEST(polynomial, can_Mult_Pol_and_Pol_correctly)
{
	polynomial a("x^2+y"), b("7x+z"), c("7x^3+x^2z+7xy+yz"), d;
	d = a * b;
	EXPECT_EQ(c, d);
}

TEST(polynomial, throw_when_too_large_degree_after_mult)
{
	polynomial a("xy^9"), b("-2x^9y^2"), c;
	ASSERT_ANY_THROW(c = a * b);
}

TEST(polynomial, can_mult_polynom_and_scalar_correctly)
{
	polynomial a("0.6xy^7+z+21.001"), b("4.2xy^7+7z+147.007"), c;
	c = a * 7;
	EXPECT_EQ(b, c);
}

TEST(polynomial, can_add_when_input_polynom_is_empty)
{
	polynomial a("x^9y^9z^2+y^6z-4y"), b, c;
	ASSERT_NO_THROW(c = a+b);
	EXPECT_EQ(a, c);
}

TEST(polynomial, can_mult_when_input_polynom_is_empty)
{
	polynomial a("z^6y^8+y^5z-1"), b;
	ASSERT_NO_THROW(a *= b);
	EXPECT_EQ(true, a.empty());
}

TEST(polynomial, function_empty_is_correct)
{
	polynomial a("3x+5"), b("-5-3x^1"), c;
	EXPECT_EQ(false, a.empty());
	a += b;
	EXPECT_EQ(true, a.empty());
	EXPECT_EQ(true, c.empty());
}

TEST(polynomial, function_clear_is_correct)
{
	polynomial a("5+x^5y^5z^5-4y+2z^2");
	EXPECT_EQ(false, a.empty());
	a.clear();
	EXPECT_EQ(true, a.empty());
}

TEST(polynomial, can_clear_empty_polynom)
{
	polynomial a;
	ASSERT_NO_THROW(a.clear());
}

TEST(polynomial, check_input_correctly) {
	ASSERT_ANY_THROW(polynomial a("^4x-2"));
	ASSERT_NO_THROW(polynomial a1("4x-2"));
	ASSERT_ANY_THROW(polynomial b("2z+5x-"));
	ASSERT_NO_THROW(polynomial b1("2z+5x"));
	ASSERT_ANY_THROW(polynomial c("5+x^5y^5z^5-+2z^2"));
	ASSERT_NO_THROW(polynomial c1("5+x^5y^5z^5-2z^2"));
	ASSERT_ANY_THROW(polynomial d("5+^-4y+2z^2"));
	ASSERT_NO_THROW(polynomial d1("5-4y+2z^2"));
	ASSERT_ANY_THROW(polynomial e("5-.765x"));
	ASSERT_NO_THROW(polynomial e1("5-0.765x"));
	ASSERT_ANY_THROW(polynomial f("-cx^2"));
	ASSERT_NO_THROW(polynomial f1("-x^2"));
}
*/
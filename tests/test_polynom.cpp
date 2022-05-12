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


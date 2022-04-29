#pragma once

#include "TList.h"

#include <gtest/gtest.h>

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> l);
}


TEST(TList,copy_constructor_works) {
	TList<int> l1;
	ASSERT_NO_THROW(TList<int> l2(l1));
}

TEST(TList, assignment_operator_works) {
	TList<int> l1;
	ASSERT_NO_THROW(TList<int> l2=l1);
}

TEST(TList, copy_constructor_works_correctly) {
	TList<int> l1;
	l1.push_back(3);
	TList<int> l2=l1;
	EXPECT_EQ(*l1.begin(), *l2.begin());

}

TEST(TList, assignment_operator_works_correctly) {
	TList<int> l1;
	l1.push_back(3);
	TList<int> l2=l1;
	EXPECT_EQ(*l1.begin(), *l2.begin());
}


TEST(TList, can_get_size) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		l1.push_top(0);
	}
	ASSERT_NO_THROW(l1.GetSize());
	EXPECT_EQ(l1.GetSize(), 8);
}



TEST(TList, push_back_method_works_correctly) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	for (int i = 0; i < 3; i++) {
		l1.push_top(i);
	}
	EXPECT_EQ(l1[7], 4);
}


TEST(TList, push_top_method_works_correctly) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	for (int i = 0; i < 3; i++) {
		l1.push_top(i);
	}
	EXPECT_EQ(l1[0], 2);
}

TEST(TList, destructor_works) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	for (int i = 0; i < 3; i++) {
		l1.push_top(i);
	}
	ASSERT_NO_THROW(l1.~TList());
}


TEST(TList, erase_works_correctly) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}

	

	for (int i = 0; i < 3; i++) {
		l1.push_top(i);
	}

	auto it = l1.begin();
	it = it.next().next().next();
	l1.erase(it);

	EXPECT_EQ(l1[4], 2);
}

TEST(TList, erase_throws_when_list_is_null) {
	TList<int> l1;
	ASSERT_ANY_THROW(l1.erase(l1.begin()));
}



TEST(TList, remove_first_works_correctly) {
	TList<int> l1;
	l1.push_back(2);
	l1.push_back(3);
	l1.remove_first();
	EXPECT_EQ(*l1.begin(),3);
}

TEST(TList, remove_last_works_correctly) {
	TList<int> l1;
	l1.push_back(2);
	l1.push_back(3);
	l1.remove_last();
	EXPECT_EQ(*l1.begin(), 2);
}

TEST(TList, remove_first_throws_exception) {
	TList<int> l1;
	ASSERT_ANY_THROW(l1.remove_first());
}


TEST(TList, remove_last_throws_exception) {
	TList<int> l1;
	ASSERT_ANY_THROW(l1.remove_last());
}


TEST(TList, insert_works_correctly) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}



	for (int i = 0; i < 3; i++) {
		l1.push_top(i);
	}


	auto it = l1.begin();

	l1.insert(it,12);


	EXPECT_EQ(l1[1], 12);
}


TEST(TList, insert_in_top_works_correctly) {
	TList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}

	for (int i = 0; i < 3; i++) {
		l1.push_top(i);
	}
	auto it = l1.end();

	l1.insert(it, 12);

	EXPECT_EQ(l1[0], 12);
}


TEST(TList, operator_square_scopes_works_correctly) {
	TList<int> l1;
	l1.push_back(5);

	EXPECT_EQ(l1[0], 5);
}

TEST(TList, operator_square_scopes_throws_exception) {
	TList<int> l1;
	l1.push_back(5);

	ASSERT_ANY_THROW(l1[10], 5);
}

TEST(TList, pop_works_correctly) {
	TList<int> l1;
	l1.push_back(5);
	l1.push_back(4);
	l1.pop();
	EXPECT_EQ(l1[0], 4);
}

TEST(TList, pop_throws_exception) {

	TList<int> l1;
	ASSERT_ANY_THROW(l1.pop());
}

TEST(TList, get_size_works_correctly) {
	TList<int> l1;
	l1.push_back(5);
	l1.push_back(4);
	EXPECT_EQ(l1.GetSize(), 2);
}


TEST(TList, cout_operator_works_correctly)
{
	TList<int> l1;
	for (int i = 0; i < 4; i++)
		l1.push_back(i+1);
	std::stringstream in;
	in << l1;
	std::string temp = in.str();


	EXPECT_EQ(temp, "1 2 3 4 ");
}


TEST(iterator, copy_constructor_works)
{
	TList<int> l;
	auto it = l.begin();

	ASSERT_NO_THROW(ListIterator<int>b(it));
}


TEST(iterator, can_create)
{
	TList<int> l;
	ASSERT_NO_THROW(auto it = l.begin());
}



TEST(iterator, operator_equal_works_correctly)
{
	TList<int> l;
	auto it = l.begin();
	auto lt = l.begin();
	EXPECT_EQ(it, lt);
}

TEST(iterator, operator_not_equal_works_correctly)
{
	TList<int> l;
	l.push_back(6);
	auto it = l.begin();
	auto lt = l.begin();
	EXPECT_NE(++it, lt);
}



TEST(iterator, dereference_operator_works_correctly) {
	TList<int> l;
	l.push_back(6);
	EXPECT_EQ(*l.begin(), 6);
}


TEST(iterator, next_works_correctly) {
	TList<int> l;
	l.push_back(6);
	l.push_back(8);
	EXPECT_EQ(*l.begin().next(), 8);
}

TEST(iterator, prefix_increment_works_correctly) {
	TList<int> l;
	l.push_back(6);
	l.push_back(8);
	auto it = l.begin();
	EXPECT_EQ(*(++it), 8);
}

TEST(iterator, postfix_increment_works_correctly) {
	TList<int> l;
	l.push_back(6);
	l.push_back(8);
	auto it = l.begin();
	EXPECT_EQ(*(it++), 6);
	EXPECT_EQ(*(it), 8);
}
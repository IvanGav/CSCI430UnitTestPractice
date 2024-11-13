/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, mixed_case_cap_first)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Abc");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_cap_last)
{
	Password my_password;
	int actual = my_password.has_mixed_case("abC");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_all_cap)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ABC");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_all_low)
{
	Password my_password;
	int actual = my_password.has_mixed_case("abc");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_one_letter_low)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_one_letter_cap)
{
	Password my_password;
	int actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_one_low)
{
	Password my_password;
	int actual = my_password.has_mixed_case("ABCDEfGHIJKLMNOP");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_one_one_cap)
{
	Password my_password;
	int actual = my_password.has_mixed_case("abcdefghiJklmnop");
	ASSERT_EQ(true, actual);
}
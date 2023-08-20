#include "../../libs/unity/unity.h"
#include "3-3.h"

#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_can_generate_all_alphabets_from_a_z_in_lowercase(void)
{
	char buffer[1024];
	expand("a-z", buffer);
	TEST_ASSERT_EQUAL_STRING("abcdefghijklmnopqrstuvwxyz", buffer);
}

static void test_function_should_generate_all_uppercase_alphabets_a_z(void) {
	char buffer[1024];
	expand("A-Z", buffer);
	TEST_ASSERT_EQUAL_STRING("ABCDEFGHIJKLMNOPQRSTUVWXYZ", buffer);
}

static void test_function_should_generate_all_numbers_from_0_9(void) {
	char buffer[1024];
	expand("0-9", buffer);
	TEST_ASSERT_EQUAL_STRING("0123456789", buffer);
}


static void test_function_should_generate_all_numbers_from_5_9(void) {
	char buffer[1024];
	expand("5-9", buffer);
	TEST_ASSERT_EQUAL_STRING("56789", buffer);
}

static void test_function_should_generate_alphabets_from_a_z_A_Z(void) {
	char buffer[1024];
	expand("a-zA-Z", buffer);
	TEST_ASSERT_EQUAL_STRING("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", buffer);

}

static void test_function_should_generate_multiple_ranges(void) {
	char buffer[1024];
	expand("a-b-c", buffer);
	TEST_ASSERT_EQUAL_STRING("abc", buffer);

}

int main(void)
{
   UnityBegin("test_3-3.c");

   RUN_TEST(test_can_generate_all_alphabets_from_a_z_in_lowercase);
   RUN_TEST(test_function_should_generate_all_uppercase_alphabets_a_z);
   RUN_TEST(test_function_should_generate_all_numbers_from_0_9);
   RUN_TEST(test_function_should_generate_all_numbers_from_5_9);
   RUN_TEST(test_function_should_generate_alphabets_from_a_z_A_Z);
   RUN_TEST(test_function_should_generate_multiple_ranges);

   return UnityEnd();
}

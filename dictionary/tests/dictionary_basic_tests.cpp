#include <gtest/gtest.h>
#include <string>

#include "../dictionary.h"

//Проверка общей функциональности контейнера cust_dictionary

TEST(BasicTest, HandlesIntKeyIntValue)
{
	containers::cust_dictionary<int, int> dict{};
	EXPECT_ANY_THROW(dict.get(0));
	EXPECT_FALSE(dict.is_set(0));
	dict.set(0, 5);
	EXPECT_TRUE(dict.is_set(0));
	EXPECT_ANY_THROW(dict.get(5));
	dict.set(5, 0);
	EXPECT_EQ(0, dict.get(5));
	EXPECT_EQ(5, dict.get(0));
	EXPECT_TRUE(dict.is_set(5));
	EXPECT_TRUE(dict.is_set(0));
}

TEST(BasicTest, HandlesStringKeyIntValue)
{
	containers::cust_dictionary<std::string, int> dict{};
	EXPECT_ANY_THROW(dict.get("0"));
	EXPECT_FALSE(dict.is_set("0"));
	dict.set("hello", 1);
	EXPECT_TRUE(dict.is_set("hello"));
	dict.set("world", 2);
	EXPECT_TRUE(dict.is_set("world"));
	EXPECT_TRUE(dict.is_set("hello"));

	EXPECT_EQ(1, dict.get("hello"));
	EXPECT_TRUE(dict.is_set("hello"));
	EXPECT_EQ(2, dict.get("world"));
	EXPECT_TRUE(dict.is_set("world"));

	EXPECT_ANY_THROW(dict.get("something"));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
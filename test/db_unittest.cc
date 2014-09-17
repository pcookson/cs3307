#include "../src/db.h"
#include <gtest/gtest.h>

TEST(Db, Connect)
{
	Db db;

	EXPECT_NO_THROW(db.Connect());
}


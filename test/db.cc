#include "../src/Db/db.h"
#include <gtest/gtest.h>
#include "../src/User/user.h"
#include "../src/User/usertable.h"

using namespace Db;

unsigned int my_trace_level=
   0x1 | // 1st level of tracing
   0x2 | // 2nd level of tracing
   0x4 | // 3rd level of tracing
   0x8 | // 4th level of tracing
   0x10; // 5th level of tracing

#define OTL_TRACE_LEVEL my_trace_level
#define OTL_TRACE_STREAM cerr

TEST(Db, Connect)
{
	Db::Db db_;

	EXPECT_NO_THROW(db_.Connect());


}

TEST(Db, NewUser)
{
	User::UserTable::Authenticate("bluebaron", "chepstow");


}

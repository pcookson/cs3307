#include "../src/User/user.h"
//#include <../contrib/gtest/gtest.h>
#include <gtest/gtest.h>

using namespace User;

TEST(User, Authenticate)
{
    User::User user;
    user.password = "correct";

    EXPECT_ANY_THROW(user.Authenticate("incorrect"));
    EXPECT_NO_THROW(user.Authenticate("correct"));
    EXPECT_EQ(AUTHENTICATION_SUCCESS, user.Authenticate("correct"));

}


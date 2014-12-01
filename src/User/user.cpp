#include <iostream>
#include "user.h"

using namespace std;

namespace User {


User::User() {
	username = "";
	permissions = USER_PERMISSION_USER;
	id = 0;
	fullPayment = false;
	creditLimit = 0;
	frozen = false;
}




} /* namespace User */

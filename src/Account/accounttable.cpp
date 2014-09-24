/*
 * accounttable.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#include "../User/user.h"
#include "account.h"
#include "chequingaccount.h"
#include "savingsaccount.h"
#include "accounttable.h"
#include "../Db/db.h"
#include "../User/usertable.h"
#include "../Utilities.h"
#include <typeinfo>

using namespace User;

AccountTable::AccountTable() {
	// TODO Auto-generated constructor stub

}

AccountTable::~AccountTable() {
	// TODO Auto-generated destructor stub
}


long AccountTable::ImbueAccount(std::vector<std::string> const& column_names, std::vector<std::string> row, Account& account)
{
	//Load the properties needed into the account object
	account.id = atoi(Db::Db::GetElementByName("id", column_names, row).c_str());
	account.balance = atoi(Db::Db::GetElementByName("balance", column_names, row).c_str());

	return SUCCESS;
}

long AccountTable::DeleteAccount(Account& account) {

	vector<string> values;
	values.push_back(Utilities::long_to_string(account.id));

	int rows_affected = 0;

	Db::Db::ExecuteNonQuery(Db::Db::ParamertizedQuery("DELETE FROM account WHERE id=?", values), rows_affected);

	if (rows_affected != 1)
		throw DELETE_ACCOUNT_FAILURE;

	return SUCCESS;
}

long AccountTable::CreateAccount(User& user, Account& account) {


    if (!user.id)
		throw USER_NOT_EXIST;

	long account_type = 0;

	//Determine the account type
    try{
        ChequingAccount &fAccount = dynamic_cast<ChequingAccount&> (account);
        account_type = CHEQUING_ACCOUNT;

    }catch(bad_cast& e)
    {
        SavingsAccount &fAccount = dynamic_cast<SavingsAccount&> (account);
        account_type = SAVINGS_ACCOUNT;
    }

    vector<string> values;
    values.push_back(Utilities::long_to_string(user.id));
    values.push_back(Utilities::long_to_string(account_type));

    int rows_affected;

    Db::Db::ExecuteNonQuery(Db::Db::ParamertizedQuery("INSERT INTO account(user_id,account_type) VALUES (?,?)", values), rows_affected);

    if(rows_affected == 0)
    	throw CREATE_ACCOUNT_FAILURE;

    return SUCCESS;
}

/*
 * db.h
 *
 *  Created on: Sep 15, 2014
 *      Author: james
 */

#ifndef DB_H_
#define DB_H_

#define SQL_INSERT_USER_FAILED 0x1

#define OTL_ODBC // Compile OTL 4.0/ODBC
// The following #define is required with MyODBC 3.51.11 and higher
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_ODBC_UNIX
#include <iostream>
#include <vector>

#include "otlv4.h" // include the OTL 4.0 header file



#include "otlv4.h"

class Db {
private:
	//Use the connection as a singleton
	otl_connect con_;

public:
	//Implementing Connect function will prevent duplicate connections
	void Connect();

	std::vector<std::string> Select(std::string sql_statement, std::vector<std::string> values);

	Db();
	virtual ~Db();


};

#endif /* DB_H_ */

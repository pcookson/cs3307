/*
 * db.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: james
 */
#define OTL_ODBC_UNIX
#define OTL_ODBC // Compile OTL 4.0/ODBC
// The following #define is required with MyODBC 5.1 and higher
#define OTL_ODBC_SELECT_STM_EXECUTE_BEFORE_DESCRIBE
#define OTL_UNICODE // Compile OTL with Unicode

#include <iostream>
#include <vector>
using namespace std;

#include "otlv4.h"
#include "db.h"

Db::Db() {
	 otl_connect::otl_initialize(); // initialize OCI environment
}

Db::~Db() {
	Db::con_.logoff();
}

void Db::Connect() {
	Db::con_.rlogon("DSN=mysql");
}

vector<string> Db::Select(string sql_statement, vector<string> values) {

	vector<string> elements;

	 otl_stream i(50, // buffer size
	              sql_statement.c_str(),
	              Db::con_
	             );

	for(vector<string>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		char tmp[255];
		tmp[254] = 0;
		i << tmp;
	}

	while (!i.eof())
	{
		string element;
		elements.push_back(element);

		cout << element << endl;
	}

	return elements;
}

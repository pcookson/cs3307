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
#define OTL_STL
#define OTL_ANSI_CPP

#include <iostream>
#include <vector>
using namespace std;

#include "../otlv4.h"
#include "db.h"

namespace Db {


otl_connect Db::con_;

Db::Db() {
	 otl_connect::otl_initialize();
	 Db::con_.rlogon("DSN=mysql");
}

Db::~Db() {
	Db::con_.logoff();
}

void Db::Connect() {


}

vector<string> Db::Select(string sql_statement, vector<string> values) {

	vector<string> elements;


	 otl_stream i(50, // buffer size
	              sql_statement.c_str(),
	              Db::con_
	             );
		try {

			for(vector<string>::iterator it = values.begin(); it != values.end(); ++it)
			{
				i << *it;
			}
		}

	 catch(otl_exception& p){ // intercept OTL exceptions
		  cerr<<p.msg<<endl; // print out error message
		  cerr<<p.stm_text<<endl; // print out SQL that caused the error
		  cerr<<p.var_info<<endl; // print out the variable that caused the error
		  throw(p);
	 }

	while (!i.eof())
	{
		string element;

		i >> element;

		elements.push_back(element);

		cout << element << endl;
	}

	return elements;
}
} /* namespace User */

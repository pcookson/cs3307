/*
 * db.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: james
 */

#include <iostream>
#include <vector>
using namespace std;

#include "db.h"
#include <mysql/mysql.h>

namespace Db {

Db::Db() {
}

Db::~Db() {
}

MYSQL* Db::conn_;

void Db::Disconnect() {
	mysql_close(conn_);
	conn_ = NULL;
}

void Db::Connect() {
	if (conn_ != NULL)
		return;
	conn_ = mysql_init(NULL);
	mysql_real_connect(conn_, MYSQL_SERVER, MYSQL_USERNAME, MYSQL_PASSWORD,
			MYSQL_DATABASE, MYSQL_REMOTE_PORT, NULL, 0);
}

string Db::GetElementByName(std::string const& name,
		vector<string> const& column_names, vector<string> const& row) {
	//Keep track of the index
	int x = 0;
	//-1 means not found
	int column_name_index = -1;

	//find the index
	for (vector<string>::const_iterator it = column_names.begin();
			it != column_names.end(); ++it, ++x) {
		if ((*it).compare(name) == 0) {
			column_name_index = x;
			break;
		}
	}

	if (column_name_index == -1)
		return "";

	return row[x];
}

long Db::Insert(string const& query, int& id) {
	PrintSqlDebug("Insert: " + query);

	if (mysql_query(conn_, query.c_str())) {
		PrintSqlError();
		throw SQL_INSERT_FAILED;
	}

	id = mysql_insert_id(conn_);

	return SUCCESS;
}

void Db::PrintSqlError() {
#ifdef SQL_PRINT_ERRORS
	cout << mysql_error(conn_) << endl;
#endif
}

void Db::PrintSqlDebug(string const& message) {
#ifdef SQL_PRINT_DEBUG
	cout << message << endl;
#endif
}

long Db::ExecuteNonQuery(string const& query, int& rows_affected) {
	PrintSqlDebug("ExecuteNonQuery: " + query);
	if (mysql_query(conn_, query.c_str())) {
		PrintSqlError();
		throw SQL_QUERY_FAILED;
	}

	rows_affected = mysql_affected_rows(conn_);

	return SUCCESS;
}

string Db::EscapeSqlValue(string const& val) {
	string escaped_string;
	escaped_string.reserve(val.length());

	for (string::const_iterator it = val.begin(); it != val.end(); ++it) {
		//Replace all occurrences of ' with '' to prevent SQL attacks
		if (*it == '\'') {
			escaped_string.push_back('\'');
			escaped_string.push_back('\'');
			continue;
		}

		escaped_string.push_back(*it);
	}

	return escaped_string;
}

std::string Db::ParamertizedQuery(std::string query, vector<string> values) {
	int value_index = 0;
	string result_query;
	result_query.reserve(query.length() + 200);
	int value_count = values.size();

	for (string::iterator it = query.begin(); it != query.end(); ++it) {
		if (*it == '?') {
			//Make sure that we don't exceed the number of values provided by the number of values requested
			if (value_index == value_count)
				throw INVALID_PARAMERTIZED_QUERY;

			result_query.push_back('\'');
			string val = Db::EscapeSqlValue(values[value_index]);

			for (string::iterator val_it = val.begin(); val_it != val.end();
					++val_it) {
				result_query.push_back(*val_it);
			}

			result_query.push_back('\'');

			++value_index;

			continue;
		}

		result_query.push_back(*it);
	}

	return result_query;
}

long Db::Select(string const& query, db_rows& rows) {

	//This is a dangerous function with possible memory leaks if changed
	//Do not use return in this function until the very last line

	PrintSqlDebug("Select: " + query);

	//Make sure these are clear in case the caller didn't
	rows.column_names.empty();
	rows.rows.empty();

	if (mysql_query(conn_, query.c_str())) {
		PrintSqlError();
		return SQL_SELECT_FAILED;
	}

	MYSQL_RES *res = mysql_store_result(conn_);
	MYSQL_ROW mysql_row;
	MYSQL_FIELD *field;

	field = mysql_fetch_fields(res);
	int field_count = mysql_num_fields(res);
	int row_count = mysql_num_rows(res);

	//Make sure they at least get an empty vector to prevent null pointer errors
	rows.rows.reserve(field_count);
	rows.column_names.reserve(row_count);

	//Do not invert this if.  You will regret it because the memory won't be freed.
	if (!(field_count == 0 || row_count == 0)) {

		//Populate column names so that the user can select by name
		for (unsigned int x = 0; (field = mysql_fetch_field(res)); x++) {
			rows.column_names.push_back(string(field->name));
		}

		//Iterate over all rows and elements and convert them to c++ structures in new memory
		//The old memory must be freed before this function exists so be careful when modifying this next block of code
		while ((mysql_row = mysql_fetch_row(res))) {
			vector<string> row;

			for (int x = 0; x < field_count; ++x) {
				row.push_back(string(mysql_row[x]));
			}

			rows.rows.push_back(row);
		}
	}

	//free memory before exiting
	mysql_free_result(res);

	return SQL_SUCCESS;
}

} /* namespace User */

/*
 * db.h
 *
 *  Created on: Sep 15, 2014
 *      Author: james
 */

#ifndef DB_H_
#define DB_H_
#include "../error.h"
#include <iostream>
#include <vector>
#include <string>
#include <mysql/mysql.h>
#include "../config.h"

#define SUCCESS 0x0

/** @brief c++ abstraction for database implementations
 *
 * Wraps around a database library and provides c++ access.
 *
 * Rows vector<string>, a set of rows are vector<vector<string> > are vector<vector<string> > and column names are vector<string>
 *
 * A struct called db_rows has been provided to take care of sets of rows but you'll have to construct single rows yourself
 * @author james
 * @date September 2014
 */
namespace Db {

/** @brief A container for a set of rows
 *
 * Column names should be returned from all functions that return a set of rows, even if the set is 1 or 0 items in length
 * The column_name index will match the row column index for all rows in the set
 */
struct db_rows {

	std::vector<std::string> column_names;
	std::vector<std::vector<std::string> > rows;
};

/** @brief c++ class wrapper for a handful of static methods for accessing databases
 *
 * Currently the only implemented database system is MySQL
 */
class Db {
private:
	static MYSQL* conn_;

public:

	/** @brief Connects to the database
	 *
	 * \throws mysql error
	 * Makes a standard connection to the database and stores the result as a singleton object
	 */
	static void Connect();

	/** @brief Performs a select query on the database and outputs db_rows
	 *
	 * Runs a select and copies the memory to c++ containers and completes a db_rows struct
	 * \throws int predefined database error constant
	 * @param query the ASCII/utf8 SQL statement
	 * @param rows the result rows in c++ containers
	 */
	static long Select(std::string const& query, db_rows& rows);

	/** @brief Gets an element of a row by its column name
	 *
	 * @param name the name of the column
	 * @param column_names a list of the column names, ordered respectively, for the rows container
	 * @param row the row of data selected from the table
	 * @return the value of the element in the same index position in the row container as the column name in the column_names container
	 */
	static std::string GetElementByName(
			std::string const& name,
			std::vector<std::string> const& column_names,
			std::vector<std::string> const& row);

	Db();
	virtual ~Db();

	/** @brief Inserts a new row into the database and returns the id
	 *
	 * @param query the ASCII/utf8 SQL statement
	 * @param id output of the row id
	 */
	static long Insert(std::string const& query, int& id);

	/** @brief Executes a query on the database with the expectation that no result will be provided
	 *
	 * \throws int SQL_QUERY_FAILED
	 * @param query the ASCII/utf8 SQL statement
	 * @param rows_affected out parameter representing the number of database rows affected by the query
	 */
	static long ExecuteNonQuery(std::string const& query, int& rows_affected);

	/** @brief Escapes an SQL value to thwart hackers
	 *
	 * @param val the string to be escaped
	 * @return a copy of the escaped string
	 */
	static std::string EscapeSqlValue(std::string const& val);

	/** @brief SQL paramertized query
	 *
	 * Emulates standard paramertized queries for database safety in preventing attacks.
	 *
	 * Requires the same number of values as ?
	 * \throws INVALID_PARAMERTIZED_QUERY
	 * @param query the ASCII/utf8 SQL statement
	 * @param values the values that match the ?s to be replaced in the query
	 * @return a new string representing a safe SQL query
	 */
	static std::string ParamertizedQuery(std::string query, std::vector<std::string> values);

	/** @brief Prints all SQL errors if SQL_PRINT_ERRORS is defined */
	static void PrintSqlError();

	/** @brief Prints all SQL debug messages if SQL_PRINT_DEBUG is defined */
	static void PrintSqlDebug(std::string const& message);

	/** @brief Disconnects from the database */
	static void Disconnect();
};

} /* namespace Db */

#endif /* DB_H_ */

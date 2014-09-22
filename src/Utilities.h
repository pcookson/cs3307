#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>

using namespace std;

class Utilities
{
public:

	/** @brief Converts a long to a string
	 *
	 * @param value the value to be converted
	 * @return a new string representing the converted value
	 */
	static string long_to_string(long value)
	{
		stringstream ss;
		ss << value;
		return ss.str();
	}

private:

};

#endif // UTILITIES_H

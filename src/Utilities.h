#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>

using namespace std;

/** @brief A wrapper class for general, repetitive tasks */
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

	/** @brief Converts a double to a string
	 *
	 * @param value the value to be converted
	 * @return a new string representing the converted value
	 */
    static string double_to_string(double value){
        stringstream ss;
        ss << value;
        return ss.str();
    }

private:

};

#endif // UTILITIES_H

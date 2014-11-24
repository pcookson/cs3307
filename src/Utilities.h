#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>

using namespace std;

/** @brief A wrapper class for general, repetitive tasks */
class Utilities
{
public:

	/** @brief Converts an int to a string
	 *
	 * @param value the value to be converted
	 * @return a new string representing the converted value
	 */
	static string int_to_string(int value){
		stringstream ss;
		ss << value;
		return ss.str();
	}

	/** @brief Converts a long to a string
	 *
	 * @param value the value to be converted
	 * @return a new string representing the converted value
	 */
	static string long_to_string(long value){
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

    static void clearScreen() {
        {
            cout << "\033[2J\033[1;1H";
            //see http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

        }
    }

    static void pressEnter() {
        cout << "Press Enter to Continue";
        cin.get();
        cin.get();
    }

private:

};

#endif // UTILITIES_H

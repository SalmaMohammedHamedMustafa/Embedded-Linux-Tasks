#ifndef STRING_H
#define STRING_H

/**
 * @brief Class representing a dynamic string.
 */
class String {
private:
    char* str = nullptr; /**< Pointer to the string data. */
    int size = 0; /**< Size of the string including null terminator. */

public:
    /**
     * @brief Default constructor that initializes an empty string.
     */
    String();

    /**
     * @brief Constructs a new string object from a C-string.
     * @param InputStr The C-string to initialize the string with.
     */
    String(char *InputStr);

    /**
     * @brief Copy constructor to create a string from another string object.
     * @param obj The string object to copy from.
     */
    String(const String &obj);

    /**
     * @brief Move constructor to create a string from another string object.
     * @param obj The string object to move from.
     */
    String(String &&obj);

    /**
     * @brief Destructor to free allocated memory.
     */
    ~String();

    /**
     * @brief Prints the string to the standard output.
     */
    void printS();

    /**
     * @brief Gets the size of the string.
     * @param obj The string object to get the size from.
     * @return The size of the string.
     */
    int GetSize(const String& obj) const;

    /**
     * @brief Assigns another string object to this string.
     * @param obj The string object to assign.
     * @return A reference to this string.
     */
    String& operator=(const String& obj);

    /**
     * @brief Assigns a C-string to this string.
     * @param InputStr The C-string to assign.
     * @return A reference to this string.
     */
    String& operator=(char* InputStr);

    /**
     * @brief Moves this string to obj.
     * @param obj The string object to move from.
     * @return A reference to this string.
     */
    String& operator=(String&& obj);

    /**
     * @brief Concatenates another string object to this string.
     * @param obj The string object to concatenate.
     * @return A new string that is the result of the concatenation.
     */
    String operator+(const String& obj) const;

    /**
     * @brief Concatenates a C-string to this string.
     * @param InputStr The C-string to concatenate.
     * @return A new string that is the result of the concatenation.
     */
    String operator+(char* InputStr) const;

    /**
     * @brief Concatenates another string object to this string and assigns the result.
     * @param obj The string object to concatenate.
     * @return A reference to this string.
     */
    String& operator+=(const String& obj);

    /**
     * @brief Compares this string with another string for equality.
     * @param obj The string object to compare with.
     * @return True if the strings are equal, false otherwise.
     */
    bool operator==(const String& obj) const;

    /**
     * @brief Compares this string with a C-string for equality.
     * @param InputStr The C-string to compare with.
     * @return True if the strings are equal, false otherwise.
     */
    bool operator==(char* InputStr) const;

    /**
     * @brief Compares this string with another string for inequality.
     * @param obj The string object to compare with.
     * @return True if the strings are not equal, false otherwise.
     */
    bool operator!=(const String& obj) const;

    /**
     * @brief Compares this string with a C-string for inequality.
     * @param InputStr The C-string to compare with.
     * @return True if the strings are not equal, false otherwise.
     */
    bool operator!=(char* InputStr) const;

    /**
     * @brief Compares this string with another string for less than.
     * @param obj The string object to compare with.
     * @return True if this string is less than the other, false otherwise.
     */
    bool operator<(const String& obj) const;

    /**
     * @brief Compares this string with another string for greater than.
     * @param obj The string object to compare with.
     * @return True if this string is greater than the other, false otherwise.
     */
    bool operator>(const String& obj) const;

    /**
     * @brief Compares this string with another string for less than or equal to.
     * @param obj The string object to compare with.
     * @return True if this string is less than or equal to the other, false otherwise.
     */
    bool operator<=(const String& obj) const;

    /**
     * @brief Compares this string with another string for greater than or equal to.
     * @param obj The string object to compare with.
     * @return True if this string is greater than or equal to the other, false otherwise.
     */
    bool operator>=(const String& obj) const;
};

#endif // STRING_H
#pragma once

#include <iostream>
#include <fstream>

/**
 * @brief A utility class for handling file operations.
 */
class FileHandler
{
public:
    /**
     * @brief Writes data to a file.
     * @param filename The name of the file to write to.
     * @param data The data to be written to the file.
     * @return True if the operation is successful, false otherwise.
     */
    static bool writeFile(std::string &filename, std::string &data);
    /**
     * @brief Reads data from a file.
     * @param filename The name of the file to read from.
     * @param content A string to store the read content.
     * @return True if the operation is successful, false otherwise.
     */
    static bool readFromFile(const std::string &filename, std::string &content);
};

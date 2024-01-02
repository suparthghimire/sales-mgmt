#include "include/FileHandler.hpp"

bool FileHandler::writeFile(std::string &filename, std::string &data)
{
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Check if the file is opened successfully
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return false;
    }

    // Write the data to the file
    outputFile << data;

    // Close the file
    outputFile.close();
    return true;
}

bool FileHandler::readFromFile(const std::string &filename, std::string &content)
{
    // Open the file for reading
    std::ifstream inputFile(filename);

    // Check if the file is opened successfully
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file for reading." << std::endl;
        return false;
    }

    // Read the entire file content into the 'content' string
    content.assign((std::istreambuf_iterator<char>(inputFile)),
                   (std::istreambuf_iterator<char>()));

    // Close the file
    inputFile.close();
    return true;
}

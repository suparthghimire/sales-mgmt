#include "include/FileHandler.hpp"
#include <string>

std::string DATA_DIR = "./data/";

bool FileHandler::writeFile(std::string &filename, std::string &data)
{
    std::string fullPath = DATA_DIR + filename + ".csv";

    // Open the file for writing
    std::ofstream outputFile(fullPath, std::ios::app);

    std::cout << fullPath << std::endl;

    // Check if the file is opened successfully
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return false;
    }

    // Write the data to the file
    outputFile << data << "\n";

    // Close the file
    outputFile.close();

    return true;
}

bool FileHandler::readFromFile(const std::string &filename, std::string &content)
{
    std::string full_path = DATA_DIR + filename + ".csv";
    // Open the file for reading
    std::ifstream inputFile(full_path);

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

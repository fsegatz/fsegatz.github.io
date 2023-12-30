/**
 * @file markdownFileReader.cpp
 * @brief Implementation of the MarkdownFileReader class.
 *
 * @date 2023-11-19
 */

#include "markdownFileReader.h"
#include <fstream>

MarkdownFileReader::MarkdownFileReader(const std::string &filePath) : filePath(filePath) {}

std::string MarkdownFileReader::read()
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        // Handle error: unable to open file
        return "";
    }
    std::string content;
    std::string line;
    while (std::getline(file, line))
    {
        content += line + "\n";
    }
    file.close();
    return content;
}

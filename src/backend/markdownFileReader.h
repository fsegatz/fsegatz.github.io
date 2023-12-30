#include <string>

/**
 * @class MarkdownFileReader
 * @brief A class for reading the content of a Markdown file.
 */
class MarkdownFileReader
{
public:
    /**
     * @brief Constructs a MarkdownFileReader object with the specified file path.
     * @param filePath The path to the Markdown file.
     */
    MarkdownFileReader(const std::string &filePath);

    /**
     * @brief Reads the content of the Markdown file.
     * @return The content of the Markdown file as a string.
     */
    std::string read();

private:
    std::string filePath;
};

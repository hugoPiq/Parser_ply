
#include "ply_parser.h"

std::vector<float> parse_line(std::string line);

PlyParser::PlyParser(std::string path_file)
{
    _path_file = path_file;
}
PlyParser::~PlyParser(){};

std::vector<std::vector<float>> PlyParser::parse_file()
{
    bool read = false;
    std::ifstream file(_path_file);
    std::vector<std::vector<float>> file_parsed;
    if (file.is_open())
    {
        std::string line;

        while (std::getline(file, line))
        {
            if (line.compare("end_header") == 0)
            {
                read = true;
                continue;
            }
            else if (line.substr(0, 14).compare("element vertex") == 0)
            {
                _vertex_count = std::stoi(line.substr(15));
                continue;
            }
            else if (line.substr(0, 12).compare("element face") == 0)
            {
                _face_count = std::stoi(line.substr(13));
                continue;
            }
            if (read)
            {
                std::vector<float> line_parsed = parse_line(line);

                file_parsed.push_back(line_parsed);
            }
        }
    }
    file.close();

    return file_parsed;
}

std::vector<float> parse_line(std::string line)
{
    const std::string separator = " ";
    bool triangle = false;
    int index_vector = 0;
    std::vector<float> line_parsed(3);
    std::string a = "";
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == separator[0])
        {
            if ((i == 1) & std::stoi(a))
            {
                // Delete the 3 at the line's beguinning
                triangle = true;
                a = "";
                continue;
            }

            if (triangle)
            {
                line_parsed[index_vector] = std::stoi(a);
            }
            else
            {
                // Points
                line_parsed[index_vector] = std::stof(a);
            }
            a = "";
            index_vector++;
        }
        a = a + line[i];
    }
    return line_parsed;
}
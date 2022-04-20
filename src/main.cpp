#include "ply_parser.h"
int main()
{
    PlyParser a = PlyParser("../data/test.ply");
    std::vector<std::vector<float>> file_parsed = a.parse_file();

    for (size_t i = 0; i < file_parsed.size(); i++)
    {
        std::cout << file_parsed[i][0] << " ";
        std::cout << file_parsed[i][1] << " ";
        std::cout << file_parsed[i][2] << std::endl;
    }
    std::cout << a._vertex_count << std::endl;
    std::cout << a._face_count << std::endl;
    return 0;
}
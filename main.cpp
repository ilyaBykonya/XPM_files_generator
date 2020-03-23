#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
/////Автогенератор четырёхцветных
/////изображенийв формате XPM



std::string getStringRGB()
{
    std::string RGB;
    std::cin >> RGB;

    return RGB;
}


int main()
{
    srand(time(0));

    setlocale(LC_ALL, "rus");

    std::cout << "Ширина: ";
    int width;
    std::cin >> width;

    std::cout << "Высота: ";
    int height;
    std::cin >> height;




    std::string filePath = std::string("D:/bufFiles/XPM_generator_images/image.xpm");

    std::ofstream xpmFile(filePath);
    static const char symbolsForPixels[] = " @.+";

    if (!xpmFile.is_open())
        std::runtime_error("file not open");

    //Вывод этого комментария обязателен
    xpmFile << "/* XPM */\n";
    //xpm_image - имя массива, может быть любым
    xpmFile << "static const char* xpm_image[] =\n";
    xpmFile << "{\n";

    //640х480 пикселов
    //4 цвета
    //1 символ на пиксел
    xpmFile << '\"' << std::to_string(width) << ' ' << std::to_string(height) << " 4 1\",\n";

    std::cout << "Введите 4 шестнадцатеричных цвета в формате 'FFFFFF':\n";
    xpmFile << "\"  c #" << getStringRGB() << "\",\n";
    xpmFile << "\"@ c #" << getStringRGB() << "\",\n";
    xpmFile << "\". c #" << getStringRGB() << "\",\n";
    xpmFile << "\"+ c #" << getStringRGB() << "\",\n";

    for (int y = 0; y < height; ++y)
    {
        xpmFile << '\"';
        for (int x = 0; x < width; ++x)
        {
            xpmFile << symbolsForPixels[rand() % 4];
        }
        xpmFile << "\",\n";
    }
    xpmFile << "};\n";

    xpmFile.close();
    return 0;
}

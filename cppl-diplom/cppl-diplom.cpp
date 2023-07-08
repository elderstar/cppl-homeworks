#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>
#include <variant>

class IniParser {
public:
    IniParser(std::string filename)
    {
        file_.open(filename);
        if (file_.is_open())
        {
            std::string input;
            std::string section_name = "";

            while (getline(file_, str)) {
                ++line_count;
                section_name = "";
                if (str.find('[') != std::string::npos) {
                    section_name = readSectionName(section_name);
                }
                section_map = readSection(section_name);
            }
            printContent(section_map);
        }
    }
    ~IniParser() {
        file_.close();
    }

    void printContent(std::map<std::string, std::map<std::string, std::string>>& section_map)
    {
        for (auto const& section : section_map) {
            std::cout << "[" << section.first << "]\n";
            for (auto const& map : section.second) {
                std::cout << map.first << "=" << map.second << "\n";
            }
        }
    }

    std::string parseString(std::string str, size_t start_pos = 0)
    {
        std::string result = "";

        for (size_t i = start_pos + 1; i < str.size(); ++i) {
            if (str[i] == ';' || str[i] == ']') break;
            if (str[i] == '=' || str[i] == '!' || str[i] == '#'
                || str[i] == '$' || str[i] == '%' || str[i] == '^'
                || str[i] == '&' || str[i] == '*'
                || str[i] == ')' || str[i] == '(' || str[i] == '№'
                || str[i] == '/' || str[i] == '\\' || str[i] == ':'
                || str[i] == '~' || str[i] == '\'' || str[i] == '"'
                || str[i] == '?' || str[i] == '+')
            throw std::logic_error("\nSyntax error in line: " + std::to_string(line_count) + ", symbol: " + str[i]);

            result += str[i];
        }
        return result;
    }

    std::string readSectionName(std::string& section_name)
    {
        section_name = "";
        if (str.find(']') == std::string::npos)
        {
            throw std::logic_error("\nSyntax error in line: " + std::to_string(line_count));
        }
        section_name = parseString(str, str.find('['));

        return section_name;
    }

    std::map<std::string, std::map<std::string, std::string>> readSection(std::string& section_name)
    {
        std::pair<std::string, std::string> pair;
        std::map<std::string, std::map<std::string, std::string>> section_map;
        while (getline(file_, str))
        {
            ++line_count;
            if (str.find('[') != std::string::npos) readSectionName(section_name);
            if (!str.empty())
            {
                if (str.find('=') != std::string::npos)
                {
                    pair.first = str.substr(0, str.find('='));
                    pair.second = parseString(str, str.find('='));
                    section_map[section_name][pair.first] = pair.second;
                }
            }
        }
        return section_map;
    }

    template<class T> T getValue(std::string request_str)
    {
        if (request_str.find('.') != std::string::npos)
        {
            std::string section_name = request_str.substr(0, request_str.find('.'));
            std::string param_name = parseString(request_str, request_str.find('.'));
            
            if (section_map.find(section_name) != section_map.end())
            {
                auto const& section = section_map[section_name];
                if (section.find(param_name) != section.end())
                {
                    std::variant<std::string, int, double> var;
                    if (std::is_same<int, T>::value)
                    {
                        var = std::stoi(section.find(param_name)->second);
                    }
                    else if (std::is_same<double, T>::value) {
                        var = std::stod(section.find(param_name)->second);
                    }
                    else {
                        var = section.find(param_name)->second;
                    }
                    return std::get<T>(var);
                }
                else {
                    
                    std::cout << "\nSuch parametr [" + param_name + "] in section [" + section_name + "] not found.\n";
                    std::cout << "Did you mind one of these one?: ";
                   
                    for (std::map<std::string, std::string>::const_iterator it = section.begin(); it != section.end(); ++it)
                    {
                        std::cout << it->first;
                        if (it != --section.end()) std::cout << ", ";
                    }
                    throw std::logic_error("\nChoose one of these parametrs.\n");
                }
            }
            else {
                throw std::logic_error("\nSuch section [" + section_name + "] not found or empty.");
            }
        }else{
            throw std::logic_error("\nWrong parsing parametr [" + request_str + "].");
        }
    }

private:
    int line_count = 0;
    std::ifstream file_;
    std::string str = "";
    std::map<std::string, std::map<std::string, std::string>> section_map;
};

int main()
{
    system("chcp 1251");
    try
    {
        IniParser parser("settings.ini");
        
        auto value = parser.getValue<int>("Section2.var1");
        std::cout << value  << "\n";
        auto value1 = parser.getValue<double>("Section1.var1");
        std::cout << value1 << "\n";
        auto value2 = parser.getValue<std::string>("Section2.var22");
        std::cout << value2 << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
    return 0;
}

#ifndef __STD_UTILS_HPP
#define __STD_UTILS_HPP

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "exceptions/path_no_access.hpp"

#include "string_utils.hpp"

namespace StdUtils
{
    template<typename T, typename vector = std::vector<T>>
    bool Contains(const vector &vec, const T &t)
    {
        return std::any_of(vec.begin(), vec.end(), std::bind2nd(std::equal_to<T>(), t));
    }

    bool Contains(const std::vector<std::string> &vec, const char *t);

    template<typename T, typename X>
    bool ContainsKey(const std::map<T, X> &map, const T &key)
    {
        return map.find(key) != map.end();
    }

    template<typename T>
    bool ContainsKey(const std::map<std::string, T> &map, const char *key)
    {
        return map.find(std::string(key)) != map.end();
    }

    bool CreateFile(const std::filesystem::path& path);
    std::vector<std::string> Ls(const std::filesystem::path &path, bool set_lowercase = false);
    std::string FileReadAllText(const std::filesystem::path &path);
}

#endif

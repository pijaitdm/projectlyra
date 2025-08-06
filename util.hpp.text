#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

// Membuat folder bertingkat dari vector nama folder.
// Return: path folder terakhir yang dibuat.
std::string buat_folder_bertingkat(const std::vector<std::string>& tingkat) {
    std::string path = "";
    for (const auto& t : tingkat) {
        if (!path.empty()) path += "/";
        path += t;
        if (!std::filesystem::exists(path)) {
            std::filesystem::create_directories(path);
            std::cout << t << " berhasil dibuat di " << path << std::endl;
        }
    }
    return path;
}

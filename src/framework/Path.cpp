//
// Created by Alessandro Mascolo on 19/08/24.
//

#include <sstream>
#include <utility>
#include "Path.h"
#include "Strings.h"

std::string Path::GeneratePath() {
    std::ostringstream str;
    str << drive << ":" << Strings::Join(folders, "/");
    if (!folders.empty()) str << '/';
    str << fileName;
    if (!extension.empty())
        str << "." << extension;
    return str.str();
}

void Path::SetDrive(std::string newDrive) {
    drive = std::move(newDrive);
}

void Path::SetExtension(std::string ext) {
    extension = std::move(ext);
}

void Path::switchToHost() {
    if (drive == "host")
        drive = "cdrom";
}

void Path::SetFilenameAndExtension(const std::string& fext) {
    unsigned int dotPos = fext.find('.');
    fileName = fext.substr(0, dotPos);
    extension = fext.substr(dotPos + 1);
}

void Path::SetFolders(std::vector<std::string> dirs) {
    folders = std::move(dirs);
}

void Path::CD(const std::string& path) {
    folders.clear();
    std::istringstream f(path);
    std::string s;
    while (getline(f, s, '/')) {
        folders.push_back(s);
    }
}

void Path::SetFilename(std::string fn) {
    fileName = std::move(fn);
}

Path::Path(const std::string& realPath) {
    bool hasExt(true);
    bool hasDir(true);
    SetDrive(realPath.substr(0, realPath.find(':')));
    if (realPath.find('.') == std::string::npos)
        hasExt = false;
    if (realPath.find('/') == std::string::npos)
        hasDir = false;
    if (hasExt)
        SetExtension(realPath.substr(realPath.rfind('.') + 1));
    if (hasDir) {
        CD(realPath.substr(realPath.find(':') + 1, realPath.rfind('/') - realPath.find(':') - 1));
        SetFilename(realPath.substr(realPath.find_last_of('/') + 1, realPath.rfind('.') - realPath.rfind('/') - 1));
    } else {
        SetFilename(realPath.substr(realPath.find(':' + 1, realPath.find('.'))));
    }
}

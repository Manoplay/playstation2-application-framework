//
// Created by Alessandro Mascolo on 19/08/24.
//

#ifndef PS2APP_PATH_H
#define PS2APP_PATH_H

#include <string>
#include <vector>

class Path {
public:
    Path(const std::string& realPath);
    void SetDrive(std::string newDrive);
    /// Changes directory using standard / notation.
    void CD(const std::string& path);
    void SetFolders(std::vector<std::string> folders);
    void SetFilename(std::string);
    void SetFilenameAndExtension(const std::string&);
    void SetExtension(std::string);
    /// This method changes host: to cdrom: and it can be called anytime to fix paths in production environment. It does nothing if DEBUG is defined
    void SwitchToValidRoot() {
#ifdef DEBUG
        return;
#else
        switchToHost();
#endif
    }
    std::string GeneratePath();
private:
    std::string drive;
    std::vector<std::string> folders;
    std::string fileName;
    void switchToHost();
    std::string extension;
};


#endif //PS2APP_PATH_H

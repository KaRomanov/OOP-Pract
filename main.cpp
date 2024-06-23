#include "./Headers/Task.h"
#include "./Headers/User.h"
#include <fstream>
#include <iostream>

const char *globalIDFile = "./data_files/global.bin";

void readGlobalID(unsigned &task_id, unsigned &user_id, unsigned &collab_id)
{
    std::ifstream ifs(globalIDFile, std::ios::binary);
    if (!ifs.is_open())
    {
        // error
    }

    ifs.read((char *)&task_id, sizeof(unsigned));
    ifs.read((char *)&user_id, sizeof(unsigned));
    ifs.read((char *)&collab_id, sizeof(unsigned));

    ifs.close();
}

void writeGlobalID(unsigned &task_id, unsigned &user_id, unsigned &collab_id)
{
    std::ofstream ofs(globalIDFile, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open())
    {
        // error
    }

    ofs.write((const char *)&task_id, sizeof(unsigned));
    ofs.write((const char *)&user_id, sizeof(unsigned));
    ofs.write((const char *)&collab_id, sizeof(unsigned));

    ofs.close();
}

int main()
{
    unsigned task_id = 1;
    unsigned user_id = 1;
    unsigned collab_id = 1;
    readGlobalID(task_id, user_id, collab_id);

    writeGlobalID(task_id, user_id, collab_id);
    return 0;
}
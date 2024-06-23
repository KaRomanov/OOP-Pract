#include "./Headers/User.h"
#include "util/String.h"
#include "util/Vector.hpp"
#include <fstream>

User::User(const MyString &name, const MyString &pass, const unsigned id)
{
    user_id = id;
    username = name;
    password = pass;
}

void User::add_task(const unsigned task_id)
{
    user_tasks.pushBack(task_id);
}

void User::delete_task(const unsigned id)
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i] == id)
        {
            user_tasks.popAt(i);
            break;
        }
    }
}

size_t User::getTaskCount() const
{
    return user_tasks.getSize();
}

unsigned User::getTaskID(const unsigned ind) const
{
    return user_tasks[ind];
}

const MyString &User::getName() const
{
    return username;
}

unsigned User::getUserID() const
{
    return user_id;
}

void User::writeToFile(std::ofstream &out) const
{
    out.write((const char *)&user_id, sizeof(user_id));

    unsigned nameSize = username.length();
    out.write((const char *)&nameSize, sizeof(nameSize));
    out.write(username.c_str(), nameSize + 1);

    nameSize = username.length();
    out.write((const char *)&nameSize, sizeof(nameSize));
    out.write(password.c_str(), nameSize + 1);

    nameSize = user_tasks.getSize();
    out.write((const char *)&nameSize, sizeof(nameSize));
    for (size_t i = 0; i < nameSize; i++)
    {
        unsigned temp = user_tasks[i];
        out.write((const char *)&temp, sizeof(temp));
    }
}

void User::readFromFile(std::ifstream &in)
{
    in.read((char *)&user_id, sizeof(user_id));

    unsigned nameSize;
    in.read((char *)&nameSize, sizeof(nameSize));
    nameSize++;
    char *newName = new char[nameSize];
    in.read(newName, nameSize);
    username = MyString(newName);
    free(newName);

    unsigned passSize;
    in.read((char *)&passSize, sizeof(passSize));
    passSize++;
    char *newPass = new char[passSize];
    in.read(newPass, passSize);
    password = MyString(newPass);
    free(newPass);

    unsigned size;
    in.read((char *)&size, sizeof(size));
    Vector<unsigned> temp(size);
    for (size_t i = 0; i < size; i++)
    {
        unsigned a;
        in.read((char *)&a, sizeof(a));
        temp[i] = a;
    }
}
#pragma once
#include "../util/String.h"
#include "../util/Vector.hpp"

class User
{
  private:
    unsigned user_id;

    MyString username;
    MyString password;

    Vector<unsigned> user_tasks;

  public:
    User()
    {
    }
    User(const MyString &name, const MyString &pass, const unsigned id);

    size_t getTaskCount() const;
    unsigned getTaskID(const unsigned ind) const;
    const MyString &getName() const;
    unsigned getUserID() const;

    void add_task(const unsigned task_id);
    void delete_task(const unsigned id);

    void writeToFile(std::ofstream &out) const;
    void readFromFile(std::ifstream &in);
};
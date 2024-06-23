#pragma once
#include "../util/Vector.hpp"
#include "Task.h"

class Collab
{
  private:
    unsigned collab_id;
    MyString name;

    Vector<unsigned> tasks;
    Vector<unsigned> assignee;

    Vector<unsigned> users;

    unsigned creator_id;

  public:
    Collab()
    {
    }
    Collab(unsigned collab_id, unsigned creator_id, const MyString &name);

    unsigned getTaskNum() const;
    unsigned getTaskID(unsigned ind) const;
    unsigned getAssigneeID(unsigned ind) const;

    unsigned getUsersCount() const;
    unsigned getUsersID(unsigned idx) const;
    unsigned getCreator() const;

    void add_user(unsigned user_id);
    unsigned getCollabID() const;
    const MyString &getCollabName() const;
    void assign_task(unsigned task_id, unsigned assignee_id);

    void writeToFile(std::ofstream &out) const;
    void readFromFile(std::ifstream &in);
};
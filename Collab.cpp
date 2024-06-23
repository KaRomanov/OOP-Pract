#include "Headers/Collab.h"

Collab::Collab(unsigned collab_id, unsigned creator_id, const MyString &name)
{
    this->collab_id = collab_id;
    this->creator_id = creator_id;
    this->name = name;
}

void Collab::add_user(unsigned user_id)
{
    users.pushBack(user_id);
}

unsigned Collab::getCollabID() const
{
    return collab_id;
}

const MyString &Collab::getCollabName() const
{
    return name;
}

void Collab::assign_task(unsigned task_id, unsigned assignee_id)
{
    tasks.pushBack(task_id);
    assignee.pushBack(assignee_id);
}

unsigned Collab::getTaskNum() const
{
    return tasks.getSize();
}

unsigned Collab::getTaskID(unsigned ind) const
{
    return tasks[ind];
}

unsigned Collab::getAssigneeID(unsigned ind) const
{
    return assignee[ind];
}

unsigned Collab::getUsersCount() const
{
    return users.getSize();
}

unsigned Collab::getUsersID(unsigned idx) const
{
    return users[idx];
}

unsigned Collab::getCreator() const
{
    return creator_id;
}

void Collab::writeToFile(std::ofstream &out) const
{
    out.write((const char *)&collab_id, sizeof(collab_id));

    unsigned size = name.length();
    out.write((const char *)&size, sizeof(size));
    out.write(name.c_str(), size + 1);

    size = tasks.getSize();
    out.write((const char *)&size, sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        unsigned temp = tasks[i];
        out.write((const char *)&temp, sizeof(temp));
    }

    size = assignee.getSize();
    out.write((const char *)&size, sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        unsigned temp = assignee[i];
        out.write((const char *)&temp, sizeof(temp));
    }

    size = users.getSize();
    out.write((const char *)&size, sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        unsigned temp = users[i];
        out.write((const char *)&temp, sizeof(temp));
    }

    out.write((const char *)&creator_id, sizeof(creator_id));
}

void Collab::readFromFile(std::ifstream &in)
{
}
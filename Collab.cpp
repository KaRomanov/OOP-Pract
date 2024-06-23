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
}

void Collab::readFromFile(std::ifstream &in)
{
}
#include "Headers/Data.h"
#include "util/Vector.hpp"
#include "util/VectorOperations.hpp"
#include <cstddef>
#include <fstream>

bool Data::checkTaskId(const unsigned task_id) const
{
    for (size_t i = 0; i < users[current_user].getTaskCount(); i++)
    {
        if (users[current_user].getTaskID(i) == task_id)
        {
            return true;
        }
    }
    return false;
}

unsigned Data::getUserID(const MyString &name) const
{
    for (size_t i = 0; i < users.getSize(); i++)
    {
        if (users[i].getName() == name)
        {
            return users[i].getUserID();
        }
    }
    return 0;
}

bool Data::isUserInCollab(unsigned collab_idx) const
{
    for (size_t i = 0; i < collaborations[collab_idx].getUsersCount(); i++)
    {
        if (current_user == collaborations[collab_idx].getUsersID(i))
        {
            return true;
        }
    }
    return false;
}

void Data::loadDashboard()
{
    Date timeNow;
    timeNow.updateCurrentTime();

    for (size_t i = 0; i < users[current_user].getTaskCount(); i++)
    {
        const Task &currTask = tasks[users[current_user].getTaskID(i)];
        if (isSameDay(currTask.getDate(), timeNow) && currTask.getStatus() != Status::OVERDUE &&
            currTask.getStatus() != Status::DONE)
        {
            dashboard.pushBack(currTask.getID());
        }
    }
}

void Data::registration(const MyString &name, const MyString &pass, const unsigned id)
{
    users.pushBack((User(name, pass, id)));
}

void Data::login(const unsigned newUser)
{
    current_user = newUser;
    loadDashboard();
}

void Data::logout()
{
    current_user = 0;
}

void Data::update_task_name(const unsigned task_id, const MyString &name)
{
    if (!checkTaskId(task_id))
    {
        std::cout << "error" << '\n';
        return;
    }
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getID() == task_id)
        {
            tasks[i].setName(name);
            break;
        }
    }
}

void Data::start_task(const unsigned task_id)
{
    if (!checkTaskId(task_id))
    {
        std::cout << "error" << '\n';
        return;
    }
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getID() == task_id)
        {
            tasks[i].setStatus(Status::IN_PROCESS);
            break;
        }
    }
}

void Data::update_task_desc(const unsigned task_id, const MyString &desc)
{
    if (!checkTaskId(task_id))
    {
        std::cout << "error" << '\n';
        return;
    }
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getID() == task_id)
        {
            tasks[i].setDesc(desc);
            break;
        }
    }
}

void Data::get_task(const unsigned task_id) const
{
    if (!checkTaskId(task_id))
    {
        std::cout << "error" << '\n';
        return;
    }
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getID() == task_id)
        {
            tasks[i].list_task();
            break;
        }
    }
}

void Data::get_task(const MyString &name) const
{
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getName() == name && checkTaskId(tasks[i].getID()))
        {
            tasks[i].list_task();
            break;
        }
    }
}

void Data::list_tasks() const
{
    for (size_t i = 0; i < users[current_user].getTaskCount(); i++)
    {
        tasks[users[current_user].getTaskID(i)].list_task();
    }
}

void Data::list_tasks(const Date &day) const
{
    for (size_t i = 0; i < users[current_user].getTaskCount(); i++)
    {
        if (isSameDay(tasks[users[current_user].getTaskID(i)].getDate(), day))
        {
            tasks[users[current_user].getTaskID(i)].list_task();
        }
    }
}

void Data::list_completed() const
{
    for (size_t i = 0; i < users[current_user].getTaskCount(); i++)
    {
        if (tasks[users[current_user].getTaskID(i)].getStatus() == Status::DONE)
        {
            tasks[users[current_user].getTaskID(i)].list_task();
        }
    }
}

void Data::finish_task(const unsigned id)
{
    if (!checkTaskId(id))
    {
        std::cout << "error" << '\n';
        return;
    }
    for (size_t i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getID() == id)
        {
            tasks[i].setStatus(Status::DONE);
            break;
        }
    }
}

void Data::remove_task(const unsigned id)
{
    users[current_user].delete_task(id);
}

void Data::add_task(const MyString &name, const MyString &due_date, const MyString &description, const unsigned task_id)
{
    tasks.pushBack(Task(name, due_date, description, task_id));
    users[current_user].add_task(task_id);
}

void Data::list_dashboard() const
{
    for (size_t i = 0; i < dashboard.getSize(); i++)
    {
        tasks[dashboard[i]].list_task();
    }
}

void Data::remove_from_dashboard(const unsigned id)
{
    for (size_t i = 0; i < dashboard.getSize(); i++)
    {
        if (dashboard[i] == id)
        {
            dashboard.popAt(i);
            break;
        }
    }
}

void Data::add_to_dashboard(const unsigned id)
{
    if (checkTaskId(id))
    {
        dashboard.pushBack(id);
    }
}

void Data::add_collab(const MyString &name, unsigned collab_id)
{
    collaborations.pushBack(Collab(collab_id, current_user, name));
}

void Data::delete_collab(const MyString &name)
{
    unsigned collabIdx;
    bool found = false;
    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (collaborations[i].getCollabName() == name && collaborations[i].getCreator() == current_user)
        {
            collabIdx = i;
            found = true;
            break;
        }
    }
    if (!found)
    {
        return;
    }
    for (size_t i = 0; i < collaborations[collabIdx].getTaskNum(); i++)
    {
        users[collaborations[collabIdx].getAssigneeID(i)].delete_task(collaborations[collabIdx].getTaskID(i));
    }
    collaborations.popAt(collabIdx);
}

void Data::list_collabs() const
{
    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (isUserInCollab(i))
        {
            std::cout << collaborations[i].getCollabName() << '\n';
        }
    }
}

void Data::add_user_collab(const MyString &name, unsigned id)
{
    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (collaborations[i].getCollabName() == name)
        {
            collaborations[i].add_user(id);
            break;
        }
    }
}

void Data::list_tasks_collab(const MyString &name) const
{
    unsigned collab_idx;
    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (collaborations[i].getCollabName() == name)
        {
            collab_idx = i;
            break;
        }
    }

    for (size_t i = 0; i < collaborations[collab_idx].getTaskNum(); i++)
    {
        tasks[collaborations[collab_idx].getTaskID(i)].list_task();
        std::cout << "Assignee: " << users[collaborations[collab_idx].getAssigneeID(i)].getName() << '\n';
    }
}

void Data::assign_task(const MyString &collab, const MyString &username, const Task &task)
{
    unsigned userID = getUserID(username);
    for (size_t i = 0; i < collaborations.getSize(); i++)
    {
        if (collaborations[i].getCollabName() == collab)
        {
            tasks.pushBack(task);
            collaborations[i].assign_task(task.getID(), userID);
            users[userID].add_task(task.getID());
        }
    }
}

void Data::writeDataToFile() const
{
    std::ofstream ofsU(UsersFile, std::ios::binary | std::ios::trunc);
    if (!ofsU.is_open())
    {
        // error
    }
    writeVector(ofsU, users);
    ofsU.close();

    std::ofstream ofsT(TasksFile, std::ios::binary | std::ios::trunc);
    if (!ofsT.is_open())
    {
        // error
    }
    writeVector(ofsT, tasks);
    ofsT.close();

    std::ofstream ofsC(CollabsFile, std::ios::binary | std::ios::trunc);
    if (!ofsC.is_open())
    {
        // error
    }
    writeVector(ofsC, collaborations);
    ofsC.close();
}

void Data::readDataFromFile()
{
    std::ifstream ifsU(UsersFile, std::ios::binary);
    if (!ifsU.is_open())
    {
        // error
    }
    readVector(ifsU, users);
    ifsU.close();

    std::ifstream ifsT(TasksFile, std::ios::binary);
    if (!ifsT.is_open())
    {
        // error
    }
    readVector(ifsT, tasks);
    ifsT.close();

    std::ifstream ifsC(CollabsFile, std::ios::binary);
    if (!ifsC.is_open())
    {
        // error
    }
    readVector(ifsC, collaborations);
    ifsC.close();
}
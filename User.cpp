#include "./Headers/User.h"

#include "util/String.h"

User::User(const MyString &name, const MyString &pass)
{
    username = name;
    password = pass;
    // write to user file
}

bool User::registration(const MyString &name, const MyString &pass)
{
    if (name == username && pass == password)
    {
        // load files
        // update login time
        return true;
    }

    return false;
}

void User::add_task(const MyString &name, const MyString &date, const MyString &desc)
{
    user_tasks.pushBack(Task(name, date, desc));
}

void User::update_task_name(const unsigned id, const MyString &name)
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getID() == id)
        {
            user_tasks[i].setName(name);
            break;
        }
    }
}

void User::start_task(const unsigned id)
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getID() == id)
        {
            user_tasks[i].setStatus(Status::IN_PROCESS);
            break;
        }
    }
}

void User::update_task_desc(const unsigned id, const MyString &desc)
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getID() == id)
        {
            user_tasks[i].setDesc(desc);
            break;
        }
    }
}

void User::delete_task(const unsigned id)
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getID() == id)
        {
            user_tasks.popAt(i);
            break;
        }
    }
}

void User::get_task(const unsigned id) const
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getID() == id)
        {
            user_tasks[i].list_task();
            break;
        }
    }
}

// fix for multiple names
void User::get_task(const MyString &name) const
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (name == user_tasks[i].getName())
        {
            user_tasks[i].list_task();
        }
    }
}

void User::list_completed() const
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getStatus() == Status::DONE)
        {
            user_tasks[i].list_task();
        }
    }
}

void User::finish_task(const unsigned id)
{
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (user_tasks[i].getID() == id)
        {
            user_tasks[i].setStatus(Status::DONE);
            break;
        }
    }
}

void User::list_tasks(const MyString &date) const
{
    Date toFind(date);
    for (size_t i = 0; i < user_tasks.getSize(); i++)
    {
        if (isSameDay(user_tasks[i].getDate(), toFind))
        {
            user_tasks[i].list_task();
            break;
        }
    }
}

// todo
void User::logout()
{
    // save to file
}

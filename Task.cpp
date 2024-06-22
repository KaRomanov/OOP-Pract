#include "./Headers/Task.h"
#include "util/String.h"
#include <exception>
#include <fstream>

std::ostream &operator<<(std::ostream &os, const Status &status)
{
    switch (status)
    {
    case Status::ON_HOLD:
        os << "ON_HOLD";
        break;
    case Status::DONE:
        os << "DONE";
        break;
    case Status::IN_PROCESS:
        os << "IN_PROCESS";
        break;
    case Status::OVERDUE:
        os << "OVERDUE";
        break;
    default:
        os << "UNKNOWN";
        break;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Status &status)
{
    MyString input;
    is >> input;
    if (input == MyString("ON_HOLD"))
    {
        status = Status::ON_HOLD;
    }
    else if (input == MyString("IN_PROCESS"))
    {
        status = Status::IN_PROCESS;
    }
    else if (input == MyString("DONE"))
    {
        status = Status::DONE;
    }
    else if (input == MyString("OVERDUE"))
    {
        status = Status::OVERDUE;
    }
    return is;
}

// fix task_id

Task::Task(const MyString &name, const MyString &due_date, const MyString &description)
{
    task_id = id_count++;

    this->name = name;
    this->due_date = Date(due_date);

    this->description = description;
}

void Task::list_task() const
{
    std::cout << '\n';
    std::cout << "Task id: " << task_id << '\n';
    std::cout << "Task name: " << name << '\n';
    std::cout << "Description: " << description << '\n';
    std::cout << "Status: " << task_status << '\n';
    std::cout << "Due date: ";
    due_date.print();
    std::cout << '\n';
}

const Date &Task::getDate() const
{
    return due_date;
}

const unsigned Task::getID() const
{
    return task_id;
}

const MyString &Task::getName() const
{
    return name;
}

const Status Task::getStatus() const
{
    return task_status;
}

void Task::setName(const MyString &name)
{
    this->name = name;
}

void Task::setStatus(const Status newStatus)
{
    task_status = newStatus;
}

// fix writing and reading

// void Task::writeToFile(std::ofstream &out) const {
//   out << task_id << name << task_status << description << due_date;
// }

// void Task::readFromFile(std::ifstream &in) {
//   in >> task_id >> name >> task_status >> description >> due_date;
// }

void Task::setDesc(const MyString &newDesc)
{
    description = newDesc;
}

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

Task::Task(const MyString &name, const MyString &due_date, const MyString &description, const unsigned id)
{
    task_id = id;

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

void Task::writeToFile(std::ofstream &out) const
{
    out.write((const char *)&task_id, sizeof(task_id));
    unsigned nameSize = name.length();
    out.write((const char *)&nameSize, sizeof(nameSize));
    out.write(name.c_str(), nameSize + 1);
    unsigned descSize = description.length();
    out.write((const char *)&descSize, sizeof(descSize));
    out.write(description.c_str(), descSize + 1);
    long unixTime = due_date.getUnixTime();
    out.write((const char *)&unixTime, sizeof(unixTime));
    int status = static_cast<int>(task_status);
    out.write((const char *)&status, sizeof(status));
}

void Task::readFromFile(std::ifstream &in)
{
    in.read((char *)&task_id, sizeof(task_id));
    unsigned nameSize;
    in.read((char *)&nameSize, sizeof(nameSize));
    nameSize++;
    char *tempName = new char[nameSize];
    in.read(tempName, nameSize);
    name = MyString(tempName);
    free(tempName);

    unsigned descSize;
    in.read((char *)&descSize, sizeof(descSize));
    descSize++;
    char *newDesc = new char[descSize];
    in.read(newDesc, descSize);
    description = MyString(newDesc);
    free(newDesc);

    long unixTime;
    in.read((char *)&unixTime, sizeof(unixTime));
    due_date = Date(unixTime);
    in.read((char *)&task_status, sizeof(task_status));
}

void Task::setDesc(const MyString &newDesc)
{
    description = newDesc;
}

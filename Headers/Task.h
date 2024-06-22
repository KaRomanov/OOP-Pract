#include "../util/String.h"
#include "./Date.h"
#include <fstream>
#include <iomanip>

enum class Status
{
    ON_HOLD,
    IN_PROCESS,
    DONE,
    OVERDUE
};

static unsigned id_count = 1;

class Task
{
  private:
    unsigned task_id;
    MyString name;
    Date due_date;
    Status task_status = Status::ON_HOLD;
    MyString description;

  public:
    Task(){}
    Task(const MyString &name, const MyString &due_date, const MyString &description);
    void list_task() const;

    const unsigned getID() const;
    const Date &getDate() const;
    const MyString &getName() const;
    const Status getStatus() const;

    void setName(const MyString &newName);
    void setStatus(const Status newStatus);
    void setDesc(const MyString &newDesc);

    void writeToFile(std::ofstream &out) const;
    void readFromFile(std::ifstream &in);
};
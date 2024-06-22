#include "../util/String.h"
#include "../util/Vector.hpp"
#include "./Date.h"
#include "./Task.h"

class User
{
  private:
    MyString username;
    MyString password;

    Date login_time;
    Vector<Task> user_tasks;

  public:
    User(const MyString &name, const MyString &pass);

    bool registration(const MyString &name, const MyString &pass);
    void add_task(const MyString &name, const MyString &date, const MyString &desc);
    void update_task_name(const unsigned id, const MyString &name);
    void start_task(const unsigned id);
    void update_task_desc(const unsigned id, const MyString &desc);
    void delete_task(const unsigned id);
    void get_task(const MyString &name) const;
    void get_task(const unsigned id) const;
    void list_tasks(const MyString &date) const;
    void list_completed() const;
    void finish_task(const unsigned id);
    void logout();
};
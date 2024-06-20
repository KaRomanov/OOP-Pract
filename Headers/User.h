#include "../util/String.h"
#include "../util/Vector.hpp"
#include "./Date.h"
#include "./Task.h"

class User {
private:
  MyString username;
  MyString password;

  Date login_time;
  Vector<Task> user_tasks;

public:
  User(const char *name, const char *pass) {}

  void registration(const char *name, const char *pass);
  void add_task(const char *name, const char *due_date, const char *desc);
  void update_task_name(const unsigned id, const char *name);
  void start_task(const unsigned id);
  void update_task_desc(const unsigned id, const char *desc);
  void delete_task(const unsigned id);
  void get_task(const char *name) const;
  void get_task(const unsigned id) const;
  void list_tasks(const char *date) const;
  void list_completed() const;
  void finish_task(const unsigned id);
  void logout();
};
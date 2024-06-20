#include "../util/String.h"
#include"./Date.h"
#include <iomanip>

enum class Status { ON_HOLD, IN_PROCESS, DONE, OVERDUE };

static unsigned id_count = 1;

class Task {
private:
  unsigned task_id;
  MyString name;
  Date due_date;
  Status task_status = Status::ON_HOLD;
  MyString description;

public:
  Task() {}
  Task(const char *name, const char *due_date, const char *description);
  void list_task(const unsigned id) const;
  void list_task(const char *name) const;
  void list_task_date(const char *date) const;
};
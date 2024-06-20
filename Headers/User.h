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



};
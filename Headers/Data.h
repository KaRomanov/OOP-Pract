#include "../util/Vector.hpp"
#include "Collab.h"
#include "User.h"
#include <fstream>

static const char *TasksFile = "../data_files/tasks.bin";
static const char *UsersFile = "../data_files/users.bin";
static const char *CollabsFile = "../data_files/collaborations.bin";

class Data
{
  private:
    Vector<Task> tasks;
    Vector<User> users;
    Vector<Collab> collaborations;
    Vector<unsigned> dashboard;

    unsigned current_user = 0;

    bool checkTaskId(const unsigned task_id) const;
    void loadDashboard();
    bool isUserInCollab(unsigned collab_ind) const;
    unsigned getUserID(const MyString &name) const;

  public:
    Data();

    void registration(const MyString &name, const MyString &pass, const unsigned id);
    void login(const unsigned newUser);

    void update_task_name(const unsigned task_id, const MyString &name);
    void start_task(const unsigned task_id);
    void update_task_desc(const unsigned task_id, const MyString &desc);
    void get_task(const unsigned task_id) const;
    void get_task(const MyString &name) const;
    void list_tasks() const;
    void list_tasks(const Date &day) const;
    void list_completed() const;
    void finish_task(const unsigned id);

    void add_task(const MyString &name, const MyString &due_date, const MyString &description, const unsigned task_id);
    void remove_task(const unsigned id);

    void remove_from_dashboard(const unsigned id);
    void add_to_dashboard(const unsigned id);
    void list_dashboard() const;

    void add_collab(const MyString &name, unsigned collab_id);
    void delete_collab(const MyString &name);
    void list_collabs() const;
    void add_user_collab(const MyString &name, unsigned id);
    void list_tasks_collab(const MyString &name) const;
    void assign_task(const MyString &collab, const MyString &username, const Task &task);

    void writeDataToFile() const;
    void readDataFromFile();

    void logout();
};
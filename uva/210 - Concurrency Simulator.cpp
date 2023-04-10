#include <iostream>
#include <cstdio>
#include <deque>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Command {
public:
  string cmd;
  string var;
  int value;
  Command() {}
  Command(string& line) {
    stringstream ss(line);
    ss >> cmd;
    if (cmd != "lock" && cmd != "unlock" && cmd != "end") {
      if (cmd == "print") {
        ss >> var;
      } else {
        var = cmd;
        ss >> cmd >> value;
      }
    }
  }
};

class VarPool {
private:
  const int NO_LOCK = -1;
  map<string, int> vars;
  int lock_by = NO_LOCK;
public:
  bool lock(int id) {
    if (lock_by == NO_LOCK) {
      lock_by = id;
      return true;
    }
    return false;
  }
  bool unlock(int id) {
    if (lock_by == id) {
      lock_by = NO_LOCK;
      return true;
    }
    return false;
  }
  bool print(int& id, string var) {
    if (vars.count(var)) {
      printf("%d: %d\n", id, vars[var]);
    } else {
      printf("%d: %d\n", id, 0);
    }
    return true;
  }
  bool equal(int& id, string var, int value) {
    vars[var] = value;
    return true;
  }
};

class Program {
private:
  int id;
  queue<Command> commands;
public:
  bool stopped = false;
  Program() {}
  Program(int i, istream& in) {
    id = i;
    string s;
    while (getline(in, s)) {
      if (s == "") {
        continue;
      }
      Command command(s);
      commands.push(command);
      if (command.cmd == "end") {
        break;
      }
    }
  }
  bool next_command(Command* command) {
    if (commands.empty()) {
      return false;
    }
    *command = commands.front();
    return true;
  }
  int do_exec_next_command(VarPool& var_pool) {
    Command command = commands.front();
    if (command.cmd == "print") {
      return var_pool.print(id, command.var) ? 1 : 0;
    } else if (command.cmd == "=") {
      return var_pool.equal(id, command.var, command.value) ? 1 : 0;
    } else if (command.cmd == "lock") {
      return var_pool.lock(id) ? 1 : 0;
    } else if (command.cmd == "unlock") {
      return var_pool.unlock(id) ? 2 : 0;
    }
    return 1;
  }
  int exec_next_command(VarPool& var_pool) {
    int status = do_exec_next_command(var_pool);
    if (status != 0) {
      commands.pop();
    } else {
      stopped = true;
    }
    return status;
  }
};


int main() {

  int n, q, t1, t2, t3, t4, t5;
  cin >> n >> q >> t1 >> t2 >> t3 >> t4 >> t5;

  deque<Program> programs;
  deque<Program> stopped_programs;
  for (int i = 1; i <= n; ++i) {
    programs.push_back(Program(i, cin));
  }

  int used_time = 0;
  bool run_first = true;
  VarPool var_pool;
  Command command;
  Program program;
  map<string, int> time_map;
  time_map["="] = t1;
  time_map["print"] = t2;
  time_map["lock"] = t3;
  time_map["unlock"] = t4;
  time_map["end"] = t5;

  while (!programs.empty() || !stopped_programs.empty()) {
    if (programs.empty()) {
      while (!stopped_programs.empty()) {
        programs.push_front(stopped_programs.back());
        programs.front().stopped = false;
        stopped_programs.pop_back();
      }
    }
    program = programs.front();
    programs.pop_front();
    used_time = 0;
    bool is_continue = false;
    while (used_time < q) {
      if (!program.next_command(&command)) {
        is_continue = true;
        break;
      }
      int status = program.exec_next_command(var_pool);
      if (program.stopped) {
        is_continue = true;
        stopped_programs.push_back(program);
        break;
      } else if (status == 2) {
        is_continue = true;
        programs.push_front(program);
        while (!stopped_programs.empty()) {
          programs.push_front(stopped_programs.back());
          programs.front().stopped = false;
          stopped_programs.pop_back();
        }
        break;
      }
      used_time += time_map[command.cmd];
    }
    if (!is_continue) {
      programs.push_back(program);
    }
  }
  return 0;
}

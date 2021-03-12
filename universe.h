#ifndef Universe_H_
#define Universe_H_
#include "world.h"
#include "ant.h"
class Universe {
public:
  Universe(const int x, const int y, const int steps);
  void run_simulation(void);
 private:
  void process_step(void);
  void print_world(void);
  World world_;
  Ant ant_;
  int steps_;
};

#endif //Universe_H_
class Ant;
#ifndef Ant_H_
#define Ant_H_
#include "world.h"

enum Colour { WHITE, BLACK, RED};

struct Position {
  int x;
  int y;
};

enum Orientation { NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST , NORTH_WEST};

class Ant {
 public:
  Ant(void);
  Ant(const int& rows, const int& cols);
  Position get_position(void);
  int get_orientation(void);
  void set_orientation(const int& orientation);
  void change_orientation(const int& current_cell_colour);
  void move_fordward();
  void set_position_x(const int& x);
  void set_position_y(const int& y);
  void print_ant(void);
 private:
  Position position_;
  int orientation_;
};


#endif //Ant_H_
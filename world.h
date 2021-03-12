class World;
#ifndef World_H_
#define World_H_

#include "vector_t.h"
#include "ant.h"
class World {
 public:
  World(const int x_ini = 2, const int y_ini = 2);
  int get_rows_min(void);
  int get_rows_max(void);
  int get_cols_min(void);
  int get_cols_max(void);

  int get_cell_colour(const int x, const int y);
  void change_cell_colour(const int x, const int y);
  void print_cell(const int& i, const int& j);

  void resize(const int x_min, const int y_min, const int x_max, const int y_max);
 private:
  int min_x_;
  int min_y_;
  int max_x_;
  int max_y_;
  Vector_t<Vector_t<int>> board_;
};



#endif //World_H_
#include "universe.h"

Universe::Universe(const int x, const int y, const int steps) {
  steps_ = steps;
  world_.resize(-x,-y,x,y);
}

void Universe::run_simulation(void) {
  int i = 0;
  while(i <= steps_) {
    if (i == 0) {
      std::cout << "Estado inicial" << std::endl;
    } else {
      std::cout << "Iteración numero " << i << std::endl;
    }
    process_step();
    i++;
  }
}

void Universe::process_step(void) {
  print_world();
  ant_.change_orientation(world_.get_cell_colour(ant_.get_position().x, ant_.get_position().y));
  world_.change_cell_colour(ant_.get_position().x, ant_.get_position().y);
  ant_.move_fordward();
  std::cout << std::endl;
  
  if((ant_.get_position().x < world_.get_rows_min()) || (ant_.get_position().x >= world_.get_rows_max())) {
    if(ant_.get_position().x < world_.get_rows_min()) {
      world_.resize(world_.get_rows_min() - 1, world_.get_cols_min(), world_.get_rows_max(), world_.get_cols_max());
    } else {
      world_.resize(world_.get_rows_min(), world_.get_cols_min(), world_.get_rows_max() + 1, world_.get_cols_max());
    }
  }

  if((ant_.get_position().y < world_.get_cols_min()) || (ant_.get_position().y >= world_.get_cols_max())) {
    if(ant_.get_position().y < world_.get_cols_min()) {
      world_.resize(world_.get_rows_min(), world_.get_cols_min() - 1, world_.get_rows_max(), world_.get_cols_max());
    } else {
      world_.resize(world_.get_rows_min(), world_.get_cols_min(), world_.get_rows_max(), world_.get_cols_max() + 1);
    }
  }
}

void Universe::print_world(void) {
  for (int i = world_.get_rows_min(); i < world_.get_rows_max(); i++) {
    std::cout << "\n";
    for (int j = world_.get_cols_min(); j < world_.get_cols_max(); j++) {
      if ((i == ant_.get_position().x) && (j == ant_.get_position().y )) {
        ant_.print_ant();
        } else {
          world_.print_cell(i,j);
        }
      }
  }
}
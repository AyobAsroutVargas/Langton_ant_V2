#include "world.h"

World::World(const int x_ini, const int y_ini) {
  min_x_ = -x_ini;
  max_x_ = x_ini;
  min_y_ = -y_ini;
  max_y_ = y_ini;
  board_.resize(min_x_, max_x_);
  for (int i = min_x_; i < max_x_; i++) {
    board_.at(i).resize(min_y_, max_y_);
  }

  //Inicializamos el tablero a 0
  for (int i = min_x_; i < max_x_; i++) {
    for (int j = min_y_; j < max_y_; j++) {
      board_.at(i).at(j) = 0;
    }
  }
}

int World::get_cols_max() {
  return max_y_;
}

int World::get_cols_min() {
  return min_y_;
}

int World::get_rows_max() {
  return max_x_;
}

int World::get_rows_min() {
 return min_x_; 
}

int World::get_cell_colour(const int x, const int y) {
  return board_.at(x).at(y);
}

void World::change_cell_colour(const int x, const int y) {
  if (board_[x][y] == WHITE) {
    board_[x][y] = BLACK;
  } else if(board_[x][y] == BLACK){
    board_[x][y] = WHITE;
  }
}

void World::resize(const int x_min, const int y_min, const int x_max, const int y_max) {
  std::cout << "Redimensionando..., pasando de eje x:" << min_x_ << "," << max_x_ << " ejey: " << min_y_ << "," << max_y_ << " a " << "eje x:" << x_min << "," << x_max << " eje y: " << y_min << "," << y_max << std::endl;
  //Creamos nuevo tablero con tamaño deseado
  Vector_t<Vector_t<int>> new_board(x_min, x_max);
  for (int i = x_min; i < x_max; i++) {
    new_board.at(i).resize(y_min, y_max);
  }

  //inicializamos el nuevo tablero
  for (int i = x_min; i < x_max; i++) {
    for (int j = y_min; j < y_max; j++) {
      new_board.at(i).at(j) = 0;
    }
  }

  //copiamos los valores del tablero actual al nuevo
  for (int i = min_x_; i < max_x_; i++) {
    for(int j = min_y_; j < max_y_; j++) {
      new_board.at(i).at(j) = board_.at(i).at(j);
    }
  }

  //actualizamos los atributos del mundo
  min_x_ = x_min;
  max_x_ = x_max;
  min_y_ = y_min;
  max_y_ = y_max;

  //redimensionamos nuestro tablero a las dimensiones deseadas
  board_.resize(min_x_, max_x_);
  for (int i = min_x_; i < max_x_; i++) {
    board_.at(i).resize(min_y_, max_y_);
  }

  //Volvemos a copiar los valores a nuestro tablero
  for (int i = min_x_; i < max_x_; i++) {
    for(int j = min_y_; j < max_y_; j++) {
      board_.at(i).at(j) = new_board.at(i).at(j);
    }
  }
}

void World::print_cell(const int& i, const int& j) {
  int cell_colour;
  cell_colour = get_cell_colour(i,j);
  switch (cell_colour) {
    case WHITE:
      std::cout << ' ';
      break;
    case BLACK:
      std::cout << 'X';
      break;  
  }
}
#include "universe.h"

int main (void) {
  int rows, cols, steps, i;
  std::cout << "En esta simulación se representan las casillas del mundo como ' '(balncas)\n"
  << "'X'(negras), las orientaciones de la hormiga son '^'(norte), '/'(noreste), '>'(este),\n" 
  << " ';'(sureste), 'v'(sur), ','(suroeste), '<'(oeste), '`'(noroeste)\n";
  std::cout << "Introduzca las dimensiones del mundo\nfilas:";
  std::cin >> rows;
  std::cout << "columnas:";
  std::cin >> cols;
  std::cout << "Numero de pasos:";
  std::cin >> steps;
  std::cout << "\n\n";

  Universe universe(rows, cols, steps);
  universe.run_simulation();

  return 0;
}
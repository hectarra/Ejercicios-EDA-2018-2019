#include <iostream>
#include <string>
#include <stdio.h>

std::string operator+ (const std::string& lhs, char rhs);
//std::string operator+ (char lhs, const std::string& rhs);
std::string DecimalABinarioNoFinal (int n);
std::string DecimalABinarioFinal (int n, std::string nf);

int main() {
  std::string nf;
  std::cout << DecimalABinarioFinal(13, nf);
  getchar();
  return 0;
}

std::string DecimalABinarioNoFinal (int n) {
  if (n == 0) return "0";
  if (n == 1) return "1";
  else return DecimalABinarioNoFinal(n/2) + char('0'+n%2);
}

std::string DecimalABinarioFinal (int n, std::string nf) {
  if (n == 0) return '0' + nf;
  if (n == 1) return '1' + nf;
  else return DecimalABinarioFinal(n/2, char('0'+n%2)+nf);
}

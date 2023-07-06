#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {
  for (int i = 0; i < 500; i++) {
    std::cout << "Barak The King" << i << "\n";
    std::cerr << "This is some Text " << i << "\n";
    this_thread::sleep_for(chrono::milliseconds(1500));
  }

  return 0;
}

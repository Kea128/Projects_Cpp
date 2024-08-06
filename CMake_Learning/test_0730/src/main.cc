#include <gflags/gflags.h>
#include <glog/logging.h>

#include <iostream>

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, true);

  std::cout << "hello" << std::endl;
  return 0;
}

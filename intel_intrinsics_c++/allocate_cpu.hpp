
#pragma once
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/syscall.h>
#include <sys/types.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <signal.h>

#include "date_time.hpp"
#include "CPUAffinity.hpp"
#include "perishable_string_tokenizer.hpp"

namespace HFSAT {

class AllocateCPUUtils {
 public:
  static AllocateCPUUtils& GetUniqueInstance();
  static void ResetUniqueInstance();

  /* It will try to allocate CPU. If it fails to do so, it will raise SIGINT */
  void AllocateCPUOrExit(std::string thread_name);

 private:
  AllocateCPUUtils();
  ~AllocateCPUUtils();

  int AllocateCPU(std::string thread_name);

  static AllocateCPUUtils* unique_ptr;
};
}
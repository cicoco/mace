// Copyright 2019 The MACE Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mace/port/darwin/env.h"

#include <execinfo.h>
#include <sys/time.h>

#include <cstddef>
#include <string>
#include <vector>

#include "mace/port/posix/backtrace.h"
#include "mace/port/posix/file_system.h"
#include "mace/port/posix/time.h"

namespace mace {
namespace port {

int64_t DarwinEnv::NowMicros() {
  return mace::port::posix::NowMicros();
}

FileSystem *DarwinEnv::GetFileSystem() {
  return &posix_file_system_;
}

LogWriter *DarwinEnv::GetLogWriter() {
  return &log_writer_;
}

std::vector<std::string> DarwinEnv::GetBackTraceUnsafe(int max_steps) {
  return mace::port::posix::GetBackTraceUnsafe(max_steps);
}

Env *Env::Default() {
  static DarwinEnv darwin_env;
  return &darwin_env;
}

}  // namespace port
}  // namespace mace

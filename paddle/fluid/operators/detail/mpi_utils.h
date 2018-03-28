/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once
#include <mpi.h>
#include <map>
#include <string>
#include <vector>

namespace paddle {
namespace operators {
namespace detail {
class MPIUtils {
 public:
  MPIUtils(const std::string& worker_name);
  const int GetRankID(const std::string& task_id);

 private:
  void InitMPI();
  std::map<std::string, int> name_id_map;
};

class MPIIsend {
 public:
  MPIIsend(int dst, const char* buf);
  bool IsFinished();
  void Send();
  ~MPIIsend();

 private:
  int done1;
  int length;
  char* req;
  MPI_Request msg1_;
};

class MPIIrecv {
 public:
MPIIrecv();
bool IsFinished();
  void Recv();
  ~MPIIrecv();
};

}  // namespace detail
}  // namespace operators
}  // namespace paddle

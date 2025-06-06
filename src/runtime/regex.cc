/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
 * \file src/runtime/regex.cc
 * \brief Exposes calls to python's `re` library.
 */

#include "./regex.h"

#include <tvm/runtime/registry.h>

namespace tvm {
namespace runtime {

bool regex_match(const std::string& match_against, const std::string& regex_pattern) {
  const auto regex_match_func = tvm::ffi::Function::GetGlobal("tvm.runtime.regex_match");
  CHECK(regex_match_func.has_value())
      << "RuntimeError: "
      << "The ffi::Function 'tvm.runtime.regex_match' has not been registered.  "
      << "This can occur if the TVM Python library has not yet been imported.";
  return (*regex_match_func)(regex_pattern, match_against).cast<bool>();
}

}  // namespace runtime
}  // namespace tvm

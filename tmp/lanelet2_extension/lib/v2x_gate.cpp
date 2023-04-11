// Copyright 2023 The Autoware Contributors
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

// NOLINTBEGIN(readability-identifier-naming)

#include "lanelet2_extension/regulatory_elements/v2x_gate.hpp"

#include <lanelet2_core/primitives/RegulatoryElement.h>

#include <string>
#include <vector>

namespace lanelet::autoware
{

V2xGate::V2xGate(const RegulatoryElementDataPtr & data) : RegulatoryElement(data)
{
  for (const std::string role : {"acquire_line", "release_line"}) {
    if (getParameters<ConstLineString3d>(role).size() == 0) {
      throw InvalidInputError("There must be at least one " + role);
    }
  }
}

std::string V2xGate::getCategory() const
{
  return attributeOr<std::string>("category", "");
}

std::vector<ConstLineString3d> V2xGate::getAcquireLines() const
{
  return getParameters<ConstLineString3d>("acquire_line");
}

std::vector<ConstLineString3d> V2xGate::getReleaseLines() const
{
  return getParameters<ConstLineString3d>("release_line");
}

}  // namespace lanelet::autoware

// NOLINTEND(readability-identifier-naming)

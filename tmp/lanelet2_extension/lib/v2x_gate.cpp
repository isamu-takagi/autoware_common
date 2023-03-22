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

#include <boost/variant.hpp>

#include <lanelet2_core/primitives/RegulatoryElement.h>

#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

namespace lanelet::autoware
{
namespace
{

/*
RegulatoryElementDataPtr constructV2xGateData(
  Id id, const AttributeMap & attributes, const LineString3d & road_marking)
{
  RuleParameterMap rpm;
  RuleParameters rule_parameters = {road_marking};
  rpm.insert(std::make_pair(RoleNameString::Refers, rule_parameters));

  auto data = std::make_shared<RegulatoryElementData>(id, rpm, attributes);
  data->attributes[AttributeName::Type] = AttributeValueString::RegulatoryElement;
  data->attributes[AttributeName::Subtype] = "road_marking";
  return data;
}
*/
}  // namespace

V2xGate::V2xGate(const RegulatoryElementDataPtr & data) : RegulatoryElement(data)
{
  /*
  if (getParameters<ConstLineString3d>(RoleName::Refers).size() != 1) {
    throw InvalidInputError("There must be exactly one road marking defined!");
  }
  */
}

std::vector<ConstLineString3d> V2xGate::getAcquireLines() const
{
  return getParameters<ConstLineString3d>("acquire_line");
}

std::vector<ConstLineString3d> V2xGate::getReleaseLines() const
{
  return getParameters<ConstLineString3d>("release_line");
}

/*
V2xGate::V2xGate(Id id, const AttributeMap & attributes, const LineString3d & road_marking)
: V2xGate(constructV2xGateData(id, attributes, road_marking))
{
}

ConstLineString3d V2xGate::V2xGate() const
{
  return getParameters<ConstLineString3d>(RoleName::Refers).front();
}

LineString3d V2xGate::V2xGate()
{
  return getParameters<LineString3d>(RoleName::Refers).front();
}

void V2xGate::setV2xGate(const LineString3d & road_marking)
{
  parameters()[RoleName::Refers] = {road_marking};
}

void V2xGate::removeV2xGate() { parameters()[RoleName::Refers] = {}; }
*/

}  // namespace lanelet::autoware

// NOLINTEND(readability-identifier-naming)

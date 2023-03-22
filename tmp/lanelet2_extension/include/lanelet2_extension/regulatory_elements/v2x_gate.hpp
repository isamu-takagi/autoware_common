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

#ifndef LANELET2_EXTENSION__REGULATORY_ELEMENTS__V2X_GATE_HPP_
#define LANELET2_EXTENSION__REGULATORY_ELEMENTS__V2X_GATE_HPP_

// NOLINTBEGIN(readability-identifier-naming)

#include <lanelet2_core/primitives/BasicRegulatoryElements.h>
#include <lanelet2_core/primitives/LineString.h>

#include <memory>
#include <vector>

namespace lanelet::autoware
{

class V2xGate : public lanelet::RegulatoryElement
{
public:
  using ConstPtr = std::shared_ptr<const V2xGate>;
  using Ptr = std::shared_ptr<V2xGate>;
  static constexpr char RuleName[] = "v2x_gate";

  //! Directly construct a stop line from its required rule parameters.
  //! Might modify the input data in order to get correct tags.
  static Ptr make(Id id, const AttributeMap & attributes, const LineString3d & road_marking)
  {
    return Ptr{new V2xGate(id, attributes, road_marking)};
  }

  std::vector<ConstLineString3d> getAcquireLines() const;
  std::vector<ConstLineString3d> getReleaseLines() const;

  /**
   * @brief get the relevant road marking
   * @return road marking
   */
  // [[nodiscard]] ConstLineString3d V2xGate() const;
  // [[nodiscard]] LineString3d V2xGate();

  /**
   * @brief add a new road marking
   * @param primitive road marking to add
   */
  // void setV2xGate(const LineString3d & road_marking);

  /**
   * @brief remove a road marking
   */
  // void removeV2xGate();

private:
  // the following lines are required so that lanelet2 can create this object
  // when loading a map with this regulatory element
  friend class lanelet::RegisterRegulatoryElement<V2xGate>;
  V2xGate(Id id, const AttributeMap & attributes, const LineString3d & temp);
  explicit V2xGate(const lanelet::RegulatoryElementDataPtr & data);
};

static lanelet::RegisterRegulatoryElement<V2xGate> reg_v2x_gate;

}  // namespace lanelet::autoware

// NOLINTEND(readability-identifier-naming)

#endif  // LANELET2_EXTENSION__REGULATORY_ELEMENTS__V2X_GATE_HPP_

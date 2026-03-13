/**
 * @file FederatedTrainer.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_DISTRIBUTED_FEDERATED_TRAINER_HPP
#define VIX_AI_DISTRIBUTED_FEDERATED_TRAINER_HPP

#include <cstddef>

namespace vix::ai::distributed
{

  struct FederatedTrainer
  {
    std::size_t round{0};
    void step() { ++round; } // simulate one FL round
    std::size_t current_round() const { return round; }
  };

} // namespace vix::ai::distributed

#endif

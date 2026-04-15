/**
 *
 *  @file Peer.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/vixcpp/vix
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 */
#ifndef VIX_AI_DISTRIBUTED_PEER_HPP
#define VIX_AI_DISTRIBUTED_PEER_HPP

#include <string>
#include <utility>

namespace vix::ai::distributed
{
  struct Peer
  {
    std::string id{"peer-0"};
    explicit Peer(std::string pid = "peer-0") : id(std::move(pid)) {}
    const std::string &name() const noexcept { return id; }
    bool operator==(const Peer &other) const noexcept { return id == other.id; }
    bool operator!=(const Peer &other) const noexcept { return !(*this == other); }
  };

} // namespace vix::ai::distributed

#endif

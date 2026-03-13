/**
 * @file SyncManager.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_DISTRIBUTED_SYNC_MANAGER_HPP
#define VIX_AI_DISTRIBUTED_SYNC_MANAGER_HPP

#include <cstddef>
#include <vector>
#include <string>
#include <vix/ai/distributed/Peer.hpp>

namespace vix::ai::distributed
{
  struct SyncManager
  {
    std::vector<Peer> peers{};
    std::size_t sync_count{0};

    void add_peer(const Peer &p) { peers.push_back(p); }
    std::size_t size() const noexcept { return peers.size(); }

    std::size_t sync()
    {
      // simulate a sync pass
      sync_count += peers.size();
      return peers.size();
    }
    std::size_t total_synced() const noexcept { return sync_count; }
  };

} // namespace vix::ai::distributed

#endif

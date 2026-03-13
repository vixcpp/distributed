/**
 * @file SecureChannel.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_DISTRIBUTED_SECURE_CHANNEL_HPP
#define VIX_AI_DISTRIBUTED_SECURE_CHANNEL_HPP

#include <string>

namespace vix::ai::distributed
{
  struct SecureChannel
  {
    bool established{false};

    bool handshake(const std::string &remote_id)
    {
      established = !remote_id.empty();
      return established;
    }
    bool is_established() const noexcept { return established; }
  };

} // namespace vix::ai::distributed

#endif

/* -*-mode:c++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#pragma once

#include <string>

namespace gg {

class GoogleStorageCredentials
{
private:
  std::string access_key_;
  std::string secret_key_;

public:
  GoogleStorageCredentials();
  GoogleStorageCredentials( const std::string& access_key,
                            const std::string& secret_key );

  const std::string& access_key() const { return access_key_; }
  const std::string& secret_key() const { return secret_key_; }
};

} // namespace gg

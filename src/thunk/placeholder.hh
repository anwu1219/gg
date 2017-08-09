/* -*-mode:c++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#ifndef PLACEHOLDER_HH
#define PLACEHOLDER_HH

#include <sys/types.h>
#include <string>

#include "optional.hh"

class ThunkPlaceholder
{
private:
  std::string content_hash_;
  size_t order_;
  off_t size_;

  bool execute_after_force_;

public:
  ThunkPlaceholder( const std::string & content_hash,
                    const size_t order,
                    const off_t size,
                    const bool execute_after_force );

  std::string content_hash() const { return content_hash_; }
  size_t order() const { return order_; }
  off_t size() const { return size_; }
  bool execute_after_force() const { return execute_after_force_; }

  void write( const std::string & filename ) const;
  static Optional<ThunkPlaceholder> read( const std::string & filename );
};

#endif /* PLACEHOLDER_HH */

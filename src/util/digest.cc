/* -*-mode:c++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include "digest.hh"

#include <crypto++/base64.h>
#include <crypto++/hex.h>
#include <crypto++/sha.h>

using namespace std;
using namespace gg;
using namespace CryptoPP;

string digest::sha256( const string& input )
{
  SHA256 hash_function;
  string ret;

  /* Each stage of the Crypto++ pipeline will delete the pointer it owns
     (https://www.cryptopp.com/wiki/Pipelining) */

  StringSource s(
    input,
    true,
    new HashFilter( hash_function,
                    new Base64URLEncoder( new StringSink( ret ), false ) ) );

  return ret;
}

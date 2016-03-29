/* Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PI_SRC_UTILS_UTILS_H_
#define PI_SRC_UTILS_UTILS_H_

#include <arpa/inet.h>

inline uint64_t htonll(uint64_t n) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return n;
#else
  return (((uint64_t)htonl(n)) << 32) + htonl(n >> 32);
#endif
}

inline uint64_t ntohll(uint64_t n) {
#if __BYTE_ORDER__ == __BIG_ENDIAN__
  return n;
#else
  return (((uint64_t)ntohl(n)) << 32) + ntohl(n >> 32);
#endif
}

char *read_file(const char *path);

#endif  // pi_p4info_field_next
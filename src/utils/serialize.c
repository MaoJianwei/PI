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

#include "PI/pi_base.h"
#include "PI/pi_tables.h"

#include <stdint.h>
#include <string.h>

size_t emit_uint32(char *dst, uint32_t v) {
  memcpy(dst, &v, sizeof(v));
  return sizeof(v);
}

size_t emit_uint64(char *dst, uint64_t v) {
  memcpy(dst, &v, sizeof(v));
  return sizeof(v);
}

size_t emit_p4_id(char *dst, pi_p4_id_t v) {
  return emit_uint32(dst, v);
}

size_t emit_entry_handle(char *dst, pi_entry_handle_t v) {
  return emit_uint64(dst, v);
}

size_t emit_dev_id(char *dst, pi_dev_id_t v) {
  // TODO(antonin): change to uint16?
  return emit_uint32(dst, v);
}

size_t emit_dev_tgt(char *dst, pi_dev_tgt_t v) {
  size_t s = 0;
  s += emit_dev_id(dst, v.dev_id);
  s += emit_uint32(dst + s, v.dev_pipe_mask);
  return s;
}

size_t emit_status(char *dst, pi_status_t v) {
  return emit_uint32(dst, v);
}

size_t retrieve_uint32(const char *src, uint32_t *v) {
  memcpy(v, src, sizeof(*v));
  return sizeof(*v);
}

size_t retrieve_uint64(const char *src, uint64_t *v) {
  memcpy(v, src, sizeof(*v));
  return sizeof(*v);
}

size_t retrieve_p4_id(const char *src, pi_p4_id_t *v) {
  return retrieve_uint32(src, v);
}

size_t retrieve_entry_handle(const char *src, pi_entry_handle_t *v) {
  return retrieve_uint64(src, v);
}

size_t retrieve_dev_id(const char *src, pi_dev_id_t *v) {
  uint32_t tmp32;
  size_t s = retrieve_uint32(src, &tmp32);
  *v = tmp32;
  return s;
}

size_t retrieve_dev_tgt(const char *src, pi_dev_tgt_t *v) {
  size_t s = 0;
  s += retrieve_dev_id(src, &v->dev_id);
  uint32_t tmp32;
  s += retrieve_uint32(src + s, &tmp32);
  v->dev_pipe_mask = tmp32;
  return s;
}

size_t retrieve_status(const char *src, pi_status_t *v) {
  return retrieve_uint32(src, v);
}

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

/*
 * Jianwei Mao (maojianwei2012@126.com)
 *
 */

//! @file

#ifndef PI_INC_PI_PI_REGISTER_H_
#define PI_INC_PI_PI_REGISTER_H_

#include <PI/pi_base.h>
#include <PI/pi_tables.h>

#include <string>


#ifdef __cplusplus
extern "C" {
#endif

// enum RegisterDataCase {
//   kBitstring = 1,
//   kBool = 2,
//   kTuple = 3,
//   kStruct = 4,
//   kHeader = 5,
//   kHeaderUnion = 6,
//   kHeaderStack = 7,
//   kHeaderUnionStack = 8,
//   kEnum = 9,
//   kError = 10,
//   DATA_NOT_SET = 0,
// };
typedef uint64_t RegisterDataCase;



typedef struct {

  RegisterDataCase data_case;

  union RegisterDataUnion {
    ::std::string bitstring_;
    // char * bitstring_;


    // bool bool_;
    // ::p4::P4StructLike* tuple_;
    // ::p4::P4StructLike* struct__;
    // ::p4::P4Header* header_;
    // ::p4::P4HeaderUnion* header_union_;
    // ::p4::P4HeaderStack* header_stack_;
    // ::p4::P4HeaderUnionStack* header_union_stack_;
    // ::google::protobuf::internal::ArenaStringPtr enum__;
    // ::google::protobuf::internal::ArenaStringPtr error_;
  } data_;

} pi_register_data_t;

RegisterDataCase get_data_case(pi_register_data_t* register_data);
::std::string get_data_bitstring(pi_register_data_t* register_data);
// bool get_data_bool(pi_register_data_t* register_data);


// #define PI_COUNTER_FLAGS_NONE 0
// // do a sync with the hw when reading a counter
// #define PI_COUNTER_FLAGS_HW_SYNC (1 << 0)

//! Mao: Reads a cell of a register. ???->at the given \p index.
pi_status_t pi_register_read(pi_session_handle_t session_handle,
                            pi_dev_tgt_t dev_tgt, pi_p4_id_t register_id,
                            size_t index,// int flags,
                            pi_register_data_t *register_data);

// //! Writes an indirect counter at the given \p index.
// pi_status_t pi_counter_write(pi_session_handle_t session_handle,
//                              pi_dev_tgt_t dev_tgt, pi_p4_id_t counter_id,
//                              size_t index,
//                              const pi_counter_data_t *counter_data);

// //! Callback type for hw sync
// typedef void (*PICounterHwSyncCb)(pi_dev_id_t dev_id, pi_p4_id_t counter_id,
//                                   void *cb_cookie);

// //! Sync all counter array entries with hardware. Use NULL for \p cb for
// //! blocking call.
// pi_status_t pi_counter_hw_sync(pi_session_handle_t session_handle,
//                                pi_dev_tgt_t dev_tgt, pi_p4_id_t counter_id,
//                                PICounterHwSyncCb cb, void *cb_cookie);

#ifdef __cplusplus
}
#endif

#endif  // PI_INC_PI_PI_REGISTER_H_

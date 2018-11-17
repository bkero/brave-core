/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include <string>

#include "catalog_type_info.h"
#include "catalog_payload_info.h"

namespace ads {

struct CreativeInfo {
  CreativeInfo() :
      creative_instance_id(""),
      type(TypeInfo()),
      payload(PayloadInfo()) {}

  explicit CreativeInfo(const CreativeInfo& info) :
      creative_instance_id(info.creative_instance_id),
      type(info.type),
      payload(info.payload) {}

  ~CreativeInfo() {}

  std::string creative_instance_id;
  TypeInfo type;
  PayloadInfo payload;
};

}  // namespace ads

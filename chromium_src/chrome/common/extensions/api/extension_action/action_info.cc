/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

// This may seem strange to not have a pdfjs manifest .cc file, but the
// reason is because ActionInfoData is defined in the action_info.cc.
// I could do a patch, or just include the pdfjs code in the override .cc file.
// So we avoid a patch by doing it this way!
#include "../../../../../../../chrome/common/extensions/api/extension_action/action_info.cc"

#include "brave/common/extensions/extension_constants.h"
#include "brave/common/extensions/manifest_handlers/pdfjs_manifest_override.h"

namespace extensions {

PDFJSOverridesHandler::PDFJSOverridesHandler() {}

PDFJSOverridesHandler::~PDFJSOverridesHandler() {}

bool PDFJSOverridesHandler::Parse(Extension* extension,
                                  base::string16* error) {
  LOG(ERROR) << "PDFJSOverridesHandler::Parse---1";

  if (extension && extension->id() == pdfjs_extension_id) {
//    ActionInfo::SetPageActionInfo(extension, nullptr);
    /*
    ActionInfo::SetExtensionActionInfo(extension, nullptr);

    ActionInfoData* data = static_cast<ActionInfoData*>(
        extension->GetManifestData(manifest_keys::kPageAction));
    if (data) {
      data->action_info.reset();
      LOG(ERROR) << "!!!!!resetting! " << extension->id();
    } else {
      LOG(ERROR) << "!!!!!NOT resetting1 !" << extension->id();
    }
  } else {
      LOG(ERROR) << "!!!!!NOT resetting2 !";
  */
  }
  return true;
}

const std::vector<std::string> PDFJSOverridesHandler::Keys() const {
  return SingleKey(manifest_keys::kPageAction);
}

}  // namespace extensions

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMMON_EXTENSIONS_MANIFEST_HANDLERS_PDFJS_OVERRIDES_HANDLER_H_
#define BRAVE_COMMON_EXTENSIONS_MANIFEST_HANDLERS_PDFJS_OVERRIDES_HANDLER_H_

#include <memory>

#include "base/macros.h"
#include "extensions/common/extension.h"
#include "extensions/common/manifest_handler.h"

namespace extensions {

// We want PDFJS, but we don't want the PDFJS page action
class PDFJSOverridesHandler : public ManifestHandler {
 public:
  PDFJSOverridesHandler();
  ~PDFJSOverridesHandler() override;

  bool Parse(Extension* extension, base::string16* error) override;

 private:
  const std::vector<std::string> Keys() const override;

  DISALLOW_COPY_AND_ASSIGN(PDFJSOverridesHandler);
};

}  // namespace extensions
#endif  // BRAVE_COMMON_EXTENSIONS_MANIFEST_HANDLERS_PDFJS_OVERRIDES_HANDLER_H_

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/extensions/brave_extension_management.h"

#include "brave/extensions/browser/brave_extension_provider.h"
#include "components/prefs/pref_service.h"

#include "brave/common/extensions/extension_constants.h"
#include "chrome/browser/extensions/external_policy_loader.h"
#include "components/component_updater/component_updater_url_constants.h"
#include "extensions/browser/pref_names.h"


namespace extensions {

BraveExtensionManagement::BraveExtensionManagement(
    PrefService* pref_service,
    bool is_signin_profile)
    : ExtensionManagement(pref_service, is_signin_profile) {
  providers_.push_back(
      std::make_unique<BraveExtensionProvider>());

  LOG(ERROR) << "BraveExtensionManagement cstr: Setting pref for install force list!";
  base::DictionaryValue forced_list_pref;

  base::ListValue allowed_types;
  allowed_types.AppendString("extension");
  allowed_types.AppendString("theme");
  allowed_types.AppendString("user_script");
  allowed_types.AppendString("hosted_app");
  allowed_types.AppendString("platform_app");
  pref_service->Set(extensions::pref_names::kAllowedTypes, std::move(allowed_types));

  extensions::ExternalPolicyLoader::AddExtension(
      &forced_list_pref, pdfjs_extension_id, /*component_updater::kUpdaterDefaultUrl*/"https://clients2.google.com/service/update2/crx");
  pref_service->Set(extensions::pref_names::kInstallForceList, std::move(forced_list_pref));

}

BraveExtensionManagement::~BraveExtensionManagement() {
}

}  // namespace extensions

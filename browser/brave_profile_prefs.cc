/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/brave_profile_prefs.h"

#include "brave/common/extensions/extension_constants.h"
#include "brave/components/brave_shields/browser/brave_shields_web_contents_observer.h"
#include "chrome/browser/prefs/session_startup_pref.h"
#include "chrome/browser/extensions/external_policy_loader.h"
#include "chrome/common/pref_names.h"
#include "components/component_updater/component_updater_url_constants.h"
#include "components/content_settings/core/common/pref_names.h"
#include "components/pref_registry/pref_registry_syncable.h"
#include "components/signin/core/browser/signin_pref_names.h"
#include "extensions/browser/pref_names.h"

namespace brave {

void RegisterProfilePrefs(user_prefs::PrefRegistrySyncable* registry) {
  brave_shields::BraveShieldsWebContentsObserver::RegisterProfilePrefs(registry);

  // No sign into Bravea functionality
  registry->SetDefaultPrefValue(prefs::kSigninAllowed, base::Value(false));

  // Restore last profile on restart
  registry->SetDefaultPrefValue(prefs::kRestoreOnStartup,
      base::Value(SessionStartupPref::kPrefValueLast));

  LOG(ERROR) << "RegisterProfilePrefs:: Adding forced list pref for pdfjs";
  // Include the following extensions by default:
  // - PDF.js
  /*
  base::DictionaryValue forced_list_pref;
  extensions::ExternalPolicyLoader::AddExtension(
      &forced_list_pref, pdfjs_extension_id, component_updater::kUpdaterDefaultUrl);
  registry->SetDefaultPrefValue(extensions::pref_names::kInstallForceList, std::move(forced_list_pref));
  */
}

}  // namespace brave

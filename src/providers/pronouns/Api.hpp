#pragma once

#ifdef CHATTERINO_HAVE_PLUGINS
#include <QString>


#include <functional>
#include <memory>
#include <vector>

namespace chatterino::pronouns {

using ResultCallback = std::function<void(const QString &)>;
using ErrorCallback = std::function<void()>;

/**
 * @brief Loads pronouns for user provided
 *
 * @param userName Name of Twitch User
 * @param onLoaded Callback taking the pronouns of the user
 * @param onError Callback called when the network request fails
 */
void fetchPronounsForUser(const QString &userName,
          ResultCallback onLoaded, ErrorCallback onError);


}  // namespace chatterino::recentmessages
#endif
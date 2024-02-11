#ifdef CHATTERINO_HAVE_PLUGINS
#include "Api.hpp"

#include "common/NetworkRequest.hpp"
#include "common/NetworkResult.hpp"
#include "common/Outcome.hpp"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

namespace chatterino::pronouns {

    void fetchPronounsForUser(const QString &userName,
          ResultCallback onLoaded, ErrorCallback onError)
    {

        NetworkRequest("https://pronouns.alejo.io/api/users/" + userName)
                .timeout(5 * 1000)
                .header("Accept", "application/json")
            .onSuccess([onLoaded, onError](auto result) -> Outcome {
                auto data = result.parseJsonArray();
                QString pronoun("None");

                if (!data.isEmpty())
                {
                    pronoun = data[0].toObject().value("pronoun_id").toString();
                }

                onLoaded(pronoun);

                return Success;
            })
            .onError([onError](auto /* result */) {
                // TODO: make better xd

                onError();
            })
            .execute();
    }

}  // namespace chatterino::pronouns
#endif
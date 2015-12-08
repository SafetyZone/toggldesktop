// Copyright 2015 Toggl Desktop developers.

#ifndef SRC_ANALYTICS_H_
#define SRC_ANALYTICS_H_

#include <string>

#include "Poco/Task.h"
#include "Poco/TaskManager.h"

namespace toggl {

class Analytics : public Poco::TaskManager {
 public:
    void Track(
        const std::string client_id,
        const std::string category,
        const std::string action);

    void TrackAutocompleteUsage(
        const std::string client_id,
        const bool was_using_autocomplete);
};

class GoogleAnalyticsEvent : public Poco::Task {
 public:
    GoogleAnalyticsEvent(
        const std::string client_id,
        const std::string category,
        const std::string action,
        const std::string opt_label,
        const int opt_value)
        : Poco::Task("GoogleAnalyticsEvent")
    , client_id_(client_id)
    , category_(category)
    , action_(action)
    , opt_label_(opt_label)
    , opt_value_(opt_value) {}
    void runTask();

 private:
    std::string client_id_;
    std::string category_;
    std::string action_;
    std::string opt_label_;
    int opt_value_;

    const std::string relativeURL();
};

}  // namespace toggl

#endif  // SRC_ANALYTICS_H_

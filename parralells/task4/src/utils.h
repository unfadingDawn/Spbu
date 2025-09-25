#pragma once
#include "logger.h"
#include "message.h"

namespace utils {
void log_message(utils::Message const& message, logger::Logger* logger);

void log_message_with_queue(utils::Message const& message, logger::Logger* logger);

void log_message_without_condition(utils::Message const& message, logger::Logger* logger);

void log_message_with_queue_without_condition(utils::Message const& message,
                                              logger::Logger* logger);
}  // namespace utils

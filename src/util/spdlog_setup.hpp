#pragma once

#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

inline void spdlog_setup() {
    auto console_sink =
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
            "logs/app_log.txt");
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto MyLogger = std::make_shared<spdlog::logger>(
            "MyLogger", sinks.begin(), sinks.end());

#ifndef NDEBUG
    MyLogger->set_level(spdlog::level::trace);
#else
    MyLogger->set_level(spdlog::level::info);
#endif
    spdlog::set_default_logger(MyLogger);
}

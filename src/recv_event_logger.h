#include <string>
#include <chrono>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h"

class RecvEventLogger {
public:
    RecvEventLogger(std::string logger_name, std::string log_path) {
        async_logger = spdlog::basic_logger_mt<spdlog::async_factory>(logger_name, log_path);
        spdlog::flush_every(std::chrono::seconds(3));
        async_logger->set_pattern("%v");
    }

    void LogEvent(bool is_start, bool is_push, bool is_req, uint64_t tid, int sender, int recver) {
        auto now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
        async_logger->info("{} {} {} {} {} {} {}", std::to_string(now.count()), is_start, is_push, is_req, tid, sender, recver);
    }

private:
    std::shared_ptr<spdlog::logger> async_logger;
};
#include <string>
#include <chrono>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h"

class RecvEventLogger {
public:
    RecvEventLogger() {};

    RecvEventLogger(std::string logger_name, std::string log_path) {
        Init(logger_name, log_path);
    }

    void Init(std::string logger_name, std::string log_path) {
        async_logger_ = spdlog::basic_logger_mt<spdlog::async_factory>(logger_name, log_path);
        spdlog::flush_every(std::chrono::seconds(3));
        async_logger_->set_pattern("%v");
    }

    void LogEvent(bool is_start, bool is_push, bool is_req, uint64_t tid, int sender, int recver) {
        auto now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
        async_logger_->info("{} {} {} {} {} {} {}", std::to_string(now.count()), is_start, is_push, is_req, tid, sender, recver);
    }

    void LogString(std::string s) {
        async_logger_->info("{}", s);
    }

private:
    std::shared_ptr<spdlog::logger> async_logger_ = nullptr;
};
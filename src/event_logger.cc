#include <string>
#include <chrono>
#include <stdlib.h>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>

#include "ps/event_logger.h"

namespace BPSLogger
{

static size_t start_identifier_size = 3 * sizeof(int) + 4 + sizeof(uint64_t); 
static size_t end_identifier_size = 2*sizeof(int) + 4 + sizeof(uint64_t); 

RecvEventLogger::RecvEventLogger() {
    char* log_path_from_env = std::getenv("PSLITE_TIMESTAMP_PATH");
    std::string log_path;
    if (log_path_from_env) {
        log_path = log_path_from_env;
    } else {
        log_path = "./pslite_recv_timestamp.log";
    }
    Init("PSLITE_TIMESTAMP_PATH", log_path);
}

RecvEventLogger& RecvEventLogger::GetLogger() {
    static RecvEventLogger recv_event_logger;
    return recv_event_logger;
}

void RecvEventLogger::Init(std::string logger_name, std::string log_path) {
    async_logger_ = spdlog::basic_logger_mt<spdlog::async_factory>(logger_name, log_path);
    spdlog::flush_every(std::chrono::seconds(3));
    async_logger_->set_pattern("%v");
    inited_ = true;
}

void RecvEventLogger::LogEvent(bool is_start, bool is_push, bool is_req, uint64_t tid, int sender, int recver) {
    auto now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
    async_logger_->info("{} {} {} {} {} {} {}", std::to_string(now.count()), is_start, is_push, is_req, tid, sender, recver);
}

void RecvEventLogger::LogString(std::string s) {
    async_logger_->info("{}", s);
}

void DeserializeUInt64(uint64_t* integer, char* buf) {
  *integer = 0;
  for(int byte_index=0; byte_index<sizeof(uint64_t); byte_index++) {
    *integer += (unsigned char)buf[byte_index] << byte_index * 8;
  }
}

void DeserializeInt(int* integer, char* buf) {
  *integer = 0;
  for(int byte_index=0; byte_index<sizeof(int); byte_index++) {
    *integer += buf[byte_index] << byte_index * 8;
  }
}

} // namespace BPSLogger
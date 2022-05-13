

#ifndef HTTP_REQUEST_PARSER_HPP
#define HTTP_REQUEST_PARSER_HPP

#include <tuple>
#include <iostream>
namespace http {
namespace AsyncServer {

struct HttpRequest;

/// Parser for incoming requests.
class RequestParser {
public:
    RequestParser();

    /// Reset to initial parser state.
    void reset();

    /// Result of parse.
    enum result_type { good, bad, indeterminate };

    /// Parse some data. The enum return value is good when a complete request has
    /// been parsed, bad if the data is invalid, indeterminate when more data is
    /// required.
    template <typename InputIterator>
    std::tuple<result_type, InputIterator> parse(HttpRequest& req,
        InputIterator begin, InputIterator end) {
        while (begin != end) {
            result_type result = Consume(req, *begin++);

            if (result == good || result == bad) {
                return std::make_tuple(result, begin);
            }

        }
        return std::make_tuple(indeterminate, begin);
    }

private:
    /// Handle the next character of input.
    result_type Consume(HttpRequest& req, char input);

    static bool IsSymbol(int c);

    static bool IsTspecial(int c);

    /// The current state of the parser.
    enum State {
        method_start,
        method,
        uri,
        http_version_h,
        http_version_t_1,
        http_version_t_2,
        http_version_p,
        http_version_slash,
        http_version_major_start,
        http_version_major,
        http_version_minor_start,
        http_version_minor,
        expecting_newline_1,
        header_line_start,
        header_lws,
        header_name,
        space_before_header_value,
        header_value,
        expecting_newline_2,
        expecting_newline_3,
        content_value,
        expecting_newline_4,
    } state_;
};

} // namespace AsyncServer
} // namespace http

#endif // HTTP_REQUEST_PARSER_HPP
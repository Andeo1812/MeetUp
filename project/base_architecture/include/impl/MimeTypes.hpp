

#ifndef HTTP_MIME_TYPES_HPP
#define HTTP_MIME_TYPES_HPP

#include <string>

namespace http {
namespace AsyncServer {
namespace MimeTypes {

/// Convert a file extension into a MIME type.
std::string extension_to_type(const std::string& extension);

} // namespace MimeTypes
} // namespace AsyncServer
} // namespace http

#endif // HTTP_MIME_TYPES_HPP


#include "MimeTypes.hpp"

namespace http {
namespace AsyncServer {
namespace MimeTypes {

struct Mapping {
    const char* extension;
    const char* mime_type;
} mappings[] =
                {
                  { "gif", "image/gif" },
                  { "htm", "text/html" },
                  { "html", "text/html" },
                  { "jpg", "image/jpeg" },
                  { "png", "image/png" }
                };

std::string extension_to_type(const std::string& extension) {
    for (Mapping m: mappings) {
        if (m.extension == extension) {
            return m.mime_type;
        }
    }

    return "text/plain";
}

} // namespace MimeTypes
} // namespace AsyncServer
} // namespace http
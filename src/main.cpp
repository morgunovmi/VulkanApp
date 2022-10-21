#include <stdexcept>

#include "util/spdlog_setup.hpp"
#include "vulkan_app.hpp"

int main() {
    spdlog_setup();
    spdlog::debug("Vulkan tut launch");

    VulkanApp app;

    try {
        app.run();
    } catch (const std::exception& e) {
        spdlog::error(e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

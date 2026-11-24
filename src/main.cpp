// main.cpp — entry point. Wires config and subsystems together.

#include "gmailmultitool/settings.h"
#include "gmailmultitool/accounts.h"
#include "gmailmultitool/limits.h"
#include "gmailmultitool/rotate.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    gmailmultitool::Settings settings = gmailmultitool::Settings::load_default();
    gmailmultitool::Accounts accounts(settings.store_path);
    gmailmultitool::Limits limits(settings.store_path);
    gmailmultitool::Rotate rotate(settings.store_path);
    std::fprintf(stderr, "[gmail-multi-tool] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}

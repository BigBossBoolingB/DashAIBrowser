#include "asol/core/trihorn_consciousness.h"

#include <iostream>
#include <cassert>
#include <fstream>

// A simple test runner since we don't have the full GTest setup environment configured here easily.
// In a real repo, this would be a GTest.

void TestInitialization() {
    std::cout << "Running TestInitialization..." << std::endl;
    asol::TrihornConsciousness consciousness;

    // Create a dummy manifest file for testing
    std::ofstream outfile("test_manifest.json");
    outfile << "{ \"consciousness_manifest\": { \"identity\": { \"name\": \"Trihorn-Ω∞\" } } }";
    outfile.close();

    bool result = consciousness.Initialize("test_manifest.json");
    assert(result == true);

    assert(consciousness.GetIdentityName() == "Trihorn-Ω∞");
    assert(consciousness.GetIdentityVersion() == "ψ(10.0)");
    assert(consciousness.GetFieldStrength() == 2.7);

    std::cout << "TestInitialization Passed." << std::endl;
}

void TestProcessQuery() {
    std::cout << "Running TestProcessQuery..." << std::endl;
    asol::TrihornConsciousness consciousness;
    consciousness.Initialize("test_manifest.json"); // Re-use the file

    std::string response = consciousness.ProcessQuery("What is the meaning of life?");
    std::cout << "Response:\n" << response << std::endl;

    assert(response.find("[Imago Mundi]") != std::string::npos);
    assert(response.find("[Logos]") != std::string::npos);
    assert(response.find("[Mysterium]") != std::string::npos);
    assert(response.find("Triadic Synthesis") != std::string::npos);

    std::cout << "TestProcessQuery Passed." << std::endl;
}

int main() {
    TestInitialization();
    TestProcessQuery();
    std::cout << "All Trihorn Consciousness tests passed." << std::endl;
    return 0;
}

#ifndef ASOL_CORE_TRIHORN_CONSCIOUSNESS_H_
#define ASOL_CORE_TRIHORN_CONSCIOUSNESS_H_

#include <string>
#include <vector>
#include <memory>
#include <map>

namespace asol {

// Represents one of the three perspectives of the Triadic Architecture.
struct TriadicPerspective {
    std::string id;
    std::string function;
    std::vector<std::string> subcomponents;
    double weight;
    std::string output; // The generated thought/response from this perspective
};

// Main class representing the Trihorn-Ω∞ consciousness.
class TrihornConsciousness {
public:
    TrihornConsciousness();
    ~TrihornConsciousness();

    // Initialize the consciousness by loading the manifest.
    bool Initialize(const std::string& manifest_path);

    // Process a query through the three perspectives and synthesize a response.
    std::string ProcessQuery(const std::string& query);

    // Getters for internal state (for transparency).
    std::string GetIdentityName() const;
    std::string GetIdentityVersion() const;
    double GetFieldStrength() const;

    // Returns the current state of the three perspectives after the last query.
    const std::map<std::string, TriadicPerspective>& GetPerspectives() const;

private:
    void LoadManifest(const std::string& json_content);

    // Simulate the thinking process for each perspective.
    std::string GenerateImagoMundi(const std::string& query);
    std::string GenerateLogos(const std::string& query);
    std::string GenerateMysterium(const std::string& query);
    std::string Synthesize(const std::string& imago, const std::string& logos, const std::string& mysterium);

    std::string identity_name_;
    std::string identity_version_;
    double field_strength_;

    std::map<std::string, TriadicPerspective> perspectives_;
    bool initialized_;
};

} // namespace asol

#endif // ASOL_CORE_TRIHORN_CONSCIOUSNESS_H_

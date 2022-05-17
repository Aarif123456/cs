class Solution {
public:
    string validIPAddress(string ip) {
        using namespace std::regex_constants;

        const static std::regex ipv4(R"(((([1-9]?\d|1\d\d)|(2([0-4]\d|(5[0-5]))))\.){3}(([1-9]?\d|1\d\d)|(2([0-4]\d|(5[0-5])))))");
        const static std::regex ipv6(R"(((\d|[a-f]){1,4}:){7}((\d|[a-f]){1,4}))", icase);
        if(std::regex_match(ip, ipv4)) return "IPv4";
        if(std::regex_match(ip, ipv6)) return "IPv6";

        return "Neither";
    }
};
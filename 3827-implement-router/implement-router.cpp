#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    int MAX_SIZE;  // memory limit
    unordered_map<string, vector<int>> packetStore;  // key -> packet [source, dest, timestamp]
    unordered_map<int, vector<int>> destTimestamps;  // destination -> sorted timestamps
    queue<string> que;  // FIFO order

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packetStore.find(key) != packetStore.end()) {
            return false;  // duplicate
        }

        if ((int)packetStore.size() >= MAX_SIZE) { // remove the oldest packet
            forwardPacket();
        }

        packetStore[key] = {source, destination, timestamp};
        que.push(key);

        // insert timestamp in sorted order
        auto &vec = destTimestamps[destination];
        auto pos = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(pos, timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {}; // If there are no packets to forward, return an empty array.

        string key = que.front(); 
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        int timestamp = packet[2];

        // remove this timestamp from destTimestamps[dest]
        auto &vec = destTimestamps[dest];
        auto pos = lower_bound(vec.begin(), vec.end(), timestamp);
        if (pos != vec.end() && *pos == timestamp) {
            vec.erase(pos);
        }

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        const auto &vec = it->second;

        int i = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin(); // first ≥ start
        int j = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();   // first > end

        return j - i;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end()); // Lexicographic sort
        vector<string> result;

        for (const string& path : folder) {
            if (result.empty() || path.find(result.back() + "/") != 0) {
                result.push_back(path); // Not a subfolder
            }
        }

        return result;
    }
};

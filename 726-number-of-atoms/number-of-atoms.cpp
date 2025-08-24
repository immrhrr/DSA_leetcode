// Using stack to parse chemical formula
// Time Complexity: O(n^2) (because of map merging)
// Space Complexity: O(n) (stack of maps for nested groups)

class Solution {
public:
    // Alias for convenience: a map storing atom -> count
    typedef unordered_map<string, int> MAP;

    string countOfAtoms(string formula) {
        int n = formula.length();
        
        // Stack to handle nested parentheses
        // Each level of parentheses will have its own atom-count map
        stack<MAP> st;
        st.push(MAP()); // push an empty map for global scope

        int i = 0; // pointer for formula traversal

        while (i < n) {
            if (formula[i] == '(') {
                // Case 1: Opening bracket → start a new scope
                st.push(MAP());
                i++;

            } else if (formula[i] == ')') {
                // Case 2: Closing bracket → pop current scope, multiply counts, and merge with previous

                MAP currMap = st.top(); // get counts inside current brackets
                st.pop();
                i++;

                // Parse number after ')', which is the multiplier
                string multiplier;
                while (i < formula.length() && isdigit(formula[i])) {
                    multiplier += formula[i];
                    i++;
                }

                // Apply multiplier if it exists
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                // Merge multiplied counts into the previous scope
                for (auto& [atom, count] : currMap) {
                    st.top()[atom] += count;
                }

            } else {
                // Case 3: Parse an atom name + optional count

                string currAtom;
                currAtom += formula[i]; // First letter (always uppercase)
                i++;

                // Collect lowercase letters (e.g., "Mg" or "Na")
                while (i < formula.length() && islower(formula[i])) {
                    currAtom += formula[i];
                    i++;
                }

                // Collect digits for count (e.g., H2 -> count=2)
                string currCount;
                while (i < formula.length() && isdigit(formula[i])) {
                    currCount += formula[i];
                    i++;
                }

                // If no count given, default is 1
                int count = currCount.empty() ? 1 : stoi(currCount);

                // Add atom count to current scope (top of stack)
                st.top()[currAtom] += count;
            }
        }
        
        // Sort atoms lexicographically using ordered map
        map<string, int> sortedMap(begin(st.top()), end(st.top()));

        // Build final result string
        string result;
        for (auto& [atom, count] : sortedMap) {
            result += atom;            // Add atom name
            if (count > 1) {           // Append count only if > 1
                result += to_string(count);
            }
        }

        return result;
    }
};

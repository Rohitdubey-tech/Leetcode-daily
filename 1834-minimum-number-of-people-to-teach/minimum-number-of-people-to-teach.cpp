class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    vector<unordered_set<int>> languageSets;
    unordered_set<int> needTeach;
    unordered_map<int, int> languageCount;

    for (const vector<int>& language : languages)
      languageSets.push_back({language.begin(), language.end()});

    for (const vector<int>& friendship : friendships) {
      const int u = friendship[0] - 1;
      const int v = friendship[1] - 1;
      if (cantTalk(languageSets, u, v)) {
        needTeach.insert(u);
        needTeach.insert(v);
      }
    }
    for (const int u : needTeach)
      for (const int language : languageSets[u])
        ++languageCount[language];
    int maxCount = 0;
    for (const auto& [_, freq] : languageCount)
      maxCount = max(maxCount, freq);

    return needTeach.size() - maxCount;
  }

 private:
  bool cantTalk(const vector<unordered_set<int>>& languageSets, int u, int v) {
    for (const int language : languageSets[u])
      if (languageSets[v].contains(language))
        return false;
    return true;
  }
};

template <typename T>
vector<int> prefix_function(const T &s) {
    int n = (int) s.size();
    vector<int> lps(n, 0);
    lps[0] = 0;
    int matched = 0;
    for(int pos = 1; pos < n; ++pos){
        while(matched > 0 && s[pos] != s[matched])matched = lps[matched-1];
        if(s[pos] == s[matched])matched++;
        lps[pos] = matched;
    }
    return lps;
}
template <typename T>
vector<int> kmp(const T &text, const T &pattern) {
    int n = (int) text.size();
    int m = (int) pattern.size();
    vector<int> lcp = prefix_function(pattern);
    vector<int> occurrences;
    int matched = 0;
    for(int idx = 0; idx < n; ++idx){
        while(matched > 0 && text[idx] != pattern[matched])matched = lcp[matched-1];
        if(text[idx] == pattern[matched])matched++;
        if(matched == m) {
            occurrences.push_back(idx-matched+1);
            matched = lcp[matched-1];
        }
    }
    return occurrences;
}
template <typename T>
vector<int> search_pattern(const T &text, const T &pattern) {
    return kmp(text, pattern);
}
// Usage:
//   string txt = "ABABABABC";
//   string pat = "ABA";
//   vector<int> ans = search_pattern(txt, pat); {0, 2, 4}

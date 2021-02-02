// Question Link: https://leetcode.com/problems/online-election/

class TopVotedCandidate {
private:
    unordered_map<int, unordered_map<int, int>> timeVoteMap; // {time, {person, votes}}
    map<int, vector<int>> maxVotedPersonAtTimeTMap; // {time, {MaxVotedperson, TotalVotes}}
    int size;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        size = times.size();
        // Save first person for first time only to accumulate map later on
        timeVoteMap[times[0]][persons[0]]++;
        // Keep track of the max voted person so far
        maxVotedPersonAtTimeTMap.insert({times[0], {persons[0], 1}});
        // Calculate the votes for ith person at time ith
        for (int i = 1; i < size; i++) {
            // Copy previous records to current map entry
            timeVoteMap[times[i]] = timeVoteMap[times[i - 1]];
            // Update current entry
            timeVoteMap[times[i]][persons[i]]++;
            // Check if updated person is a new maxVoted person
            if (timeVoteMap[times[i]][persons[i]] >= maxVotedPersonAtTimeTMap[times[i - 1]][1]) {
                maxVotedPersonAtTimeTMap.insert({times[i], {persons[i], timeVoteMap[times[i]][persons[i]]}});
            } else {
                maxVotedPersonAtTimeTMap[times[i]] = maxVotedPersonAtTimeTMap[times[i - 1]];
            }
        }
    }
    
    int q(int t) {
        auto it = maxVotedPersonAtTimeTMap.lower_bound(t);
        if (it->first == t) {
            return it->second[0];
        }
        if (it != maxVotedPersonAtTimeTMap.begin()) {
            it--;
        }
        return it->second[0];
    }
};

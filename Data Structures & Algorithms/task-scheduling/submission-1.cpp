class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_freq(26);

        for (char task : tasks)
        {
            task_freq[task - 'A']++;
        }


        priority_queue<int> most_freq_task;
        for (int count : task_freq)
        {
            if (count > 0)
                most_freq_task.emplace(count);
        }

        int time = 0;
        queue<pair<int, int>> tasks_on_cooldown;

        while (!most_freq_task.empty() || !tasks_on_cooldown.empty())
        {
            time++;

            if (!most_freq_task.empty())
            {
                int count = most_freq_task.top() - 1; most_freq_task.pop();
                if (count > 0)
                    tasks_on_cooldown.emplace(count, time + n);
            }
            else
            {
                time = tasks_on_cooldown.front().second;
            }

            if (!tasks_on_cooldown.empty() && time == tasks_on_cooldown.front().second)
            {
                most_freq_task.emplace(tasks_on_cooldown.front().first);
                tasks_on_cooldown.pop();
            }
        }

        return time;


    }
};

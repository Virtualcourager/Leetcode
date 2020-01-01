         unordered_map<int, int> mp;
         vector<int> result;
         for (int i = 0; i < nums.size(); i++)
         {
             mp[nums[i]] = i;
         }
 
         for (int i = 0; i < nums.size(); i++)
         {
             const int gap = target - nums[i];
             if (mp.find(gap) != mp.end() && mp[gap] > i)
             {
                 result.push_back(i);
                 result.push_back(mp[gap]);
                 break;
             }
         }
         return result;

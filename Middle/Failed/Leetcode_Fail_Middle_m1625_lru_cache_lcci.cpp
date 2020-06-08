/* 
   Leecode 93 LRU Cache Lcci(Can't compelet) 
   Level: Middle

   Source: https://leetcode-cn.com/problems/lru-cache-lcci/solution/da-qia-2020-05-25-by-pemona/
   通过哈希表完成
    744ms    5.26%
    39.3mb   100%

   Date: 8, June, 2020
*/


class LRUCache {
private:
	int cap;
	list<int> buffer;
	map<int, int> hash;
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		list<int>::iterator it = find(buffer.begin(), buffer.end(), key);
		if (it==buffer.end()) {
			return -1;
		}
		else {
			int x = *it;
			buffer.erase(it);
			buffer.push_back(x);

			return hash[x];
		}
	}

	void put(int key, int value) {
		if (hash.find(key) != hash.end()) {
			hash[key] = value;
			list<int>::iterator it=find(buffer.begin(), buffer.end(), key);
			int x = *it;
			buffer.erase(it);
			buffer.push_back(x);
		}
		else {
			if (hash.size() < cap) {
				hash[key] = value;
				buffer.push_back(key);//模拟队列 
			}
			else {
				int x = buffer.front();
				buffer.erase(buffer.begin());
				hash.erase(hash.find(x));

				hash[key] = value;
				buffer.push_back(key);
			}
		
		}
		
	}
};

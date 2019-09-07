
import java.util.ArrayList;
import java.util.HashMap;

public class Solution {
	public boolean isIsomorphic(String s, String t) {

		if (s.length() == t.length() && s.length() == 0)
			return true;

		ArrayList<Integer> patterns = generate(s);
		ArrayList<Integer> patternt = generate(t);
		HashMap<Integer, Integer> pool = new HashMap<>();
		for (int i = 0; i < patterns.size(); ++i) {
			Integer key = patterns.get(i);
			Integer value = patternt.get(i);
			Integer cur = pool.get(key);
			if (cur != null) {
				if (cur != value)
					return false;
			} else {
				if (pool.containsValue(value))
					return false;
				pool.put(key, value);
			}
		}
		return true;
	}

	private ArrayList<Integer> generate(String s) {
		ArrayList<Integer> ret = new ArrayList<>();
		for (int i = 0; i < s.length(); ++i) {
			ret.add(s.charAt(i) - 'a');
		}
		return ret;
	}

	static void test() {
		Solution s = new Solution();
		System.err.println(s.isIsomorphic("egg", "add") ? "true" : "false");
		System.err.println(s.isIsomorphic("foo", "bar") ? "true" : "false");
		System.err.println(s.isIsomorphic("paper", "title") ? "true" : "false");
		System.err.println(s.isIsomorphic("ab", "aa") ? "true" : "false");
	}
}


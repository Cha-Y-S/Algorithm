import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.HashMap;

class Solution {
  public int[] solution(int[] fees, String[] records) {
    Map<String, Integer> enter = new HashMap<>();
    Map<String, Integer> parking = new TreeMap<>();
    StringTokenizer st;

    for(int i = 0 ; i < records.length; i++){
      String t, n, info;
      int hour, minute;
      st = new StringTokenizer(records[i]);

      t = st.nextToken();
      n = st.nextToken();
      info = st.nextToken();

      hour = Integer.parseInt(t.substring(0, 2));
      minute = Integer.parseInt(t.substring(3));

      if(info.compareTo("IN") == 0){
        enter.put(n, hour * 60 + minute);
      } else {
        if(parking.containsKey(n)){
          parking.put(n, parking.get(n) + ((hour * 60 + minute) - enter.get(n)));
        } else {
          parking.put(n, (hour * 60 + minute) - enter.get(n));
        }
        enter.remove(n);
      }
    }

    for(Map.Entry<String, Integer> entry : enter.entrySet()){
      String n = entry.getKey();
      int t = entry.getValue();

      if(parking.containsKey(n)){
        parking.put(n, parking.get(n) + ((23 * 60 + 59) - t));
      } else {
        parking.put(n, (23 * 60 + 59) - enter.get(n));
      }
    }

    int[] answer = new int[parking.size()];
    int idx = 0;

    for(Map.Entry<String, Integer> entry : parking.entrySet()){
      String n = entry.getKey();
      int t = entry.getValue();
      int fee;

      if(t < fees[0]){
        fee = fees[1];
      } else {
        fee = fees[1] + (int)Math.ceil((double)(t - fees[0]) / fees[2]) * fees[3];
      }

      answer[idx++] = fee;
    }

    return answer;
  }
}
  #include <iostream>
  #include <queue>
  #include <vector>
  using namespace std;
  long long w[10005];
  priority_queue<int, vector<int>,greater<int> > pq;
  int main() {
      long long n, ans = 0;
      cin >> n;
      for (int i = 0; i < n; i++) {
          cin >> w[i];
      }
      for(int i=0;i<n;i++){
          pq.push(w[i]);
      }
      while(pq.size()>1){
          int x=pq.top();
          pq.pop();
          x+=pq.top();
          pq.pop();
          ans+=x;
          pq.push(x);
      }
      cout << ans << endl;
      return 0;
  }

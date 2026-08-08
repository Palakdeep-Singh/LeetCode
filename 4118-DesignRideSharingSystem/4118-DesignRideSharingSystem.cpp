// Last updated: 8/8/2026, 3:42:53 PM
class RideSharingSystem {
public:
    queue <int> riders,drivers;
    unordered_set <int> waiting, cancelled;
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        riders.push(riderId);
        waiting.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
      
      while(!riders.empty() && cancelled.count(riders.front())){
        int r = riders.front();
        riders.pop();
        cancelled.erase(r);
        waiting.erase(r);
      } 

      if(!riders.empty() && !drivers.empty()){
        int d = drivers.front();
        drivers.pop();
        int r = riders.front();
        riders.pop();
        waiting.erase(r);
        return {d,r};
      }
      return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if (waiting.count(riderId)){
            cancelled.insert(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
class BusBooking {
vector<vector<int>>bus;
int time = 0;
int allA = 0;
int allB = 0;
int allC = 0;
int allD = 0;
public:
    BusBooking(int n) {
        bus.assign(n+1,vector<int>(4,0));
    }
    
    void toggle(string seat) {
        int ch = seat[0]-'A';
        seat.erase(0, 1);
        int num = stoi(seat);
        if(bus[num][ch]!=0){
            if(ch==0) allA--;
            if(ch==1) allB--;
            if(ch==2) allC--;
            if(ch==3) allD--;
            time -= bus[num][ch];
            bus[num][ch] = 0;
        }
        else{
            if(ch==0){
                if(bus[num][ch+1]!=0){
                    time+=3;
                    bus[num][ch] = 3;
                }
                else{
                    bus[num][ch] = 1;
                    time+=1;
                }
                allA++;
            }
            if(ch==1){
                time+=1;
                bus[num][ch] = 1;
                allB++;
            }
            if(ch==2){
                time+=1;
                bus[num][ch] = 1;
                allC++;
            }
            if(ch==3){
                if(bus[num][ch-1]==1){
                    time+=3;
                    bus[num][ch] = 3;
                }
                else{
                    time+=1;
                    bus[num][ch] = 1;
                }
                allD++;
            }
        }
    }
    
    int getTotalTime() {
        return time;
    }
    
    int getMinTime() {
        return allA+allB+allC+allD;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
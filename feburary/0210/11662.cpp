//삼분 탐색 내용은 다음 블로그 참조  https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=221432986308&proxyReferer=https:%2F%2Fwww.google.com%2F

#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<iomanip>
using namespace std;

vector<pair<double,double>> p1;   // point a, point b
vector<pair<double,double>> p2;   // point c, point d

double dist(double t){  //calculate distance at time t
    double x1 = p1[0].first + t*(p1[1].first - p1[0].first);
    double y1 = p1[0].second + t*(p1[1].second - p1[0].second);
    double x2 = p2[0].first + t*(p2[1].first - p2[0].first);
    double y2 = p2[0].second + t*(p2[1].second - p2[0].second);
    double result = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ax,ay,bx,by,cx,cy,dx,dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    p1.push_back(make_pair(ax,ay));
    p1.push_back(make_pair(bx,by));
    p2.push_back(make_pair(cx,cy));
    p2.push_back(make_pair(dx,dy));
    double left = 0.0;  double right = 1.0;
    double ans;
    double p,q;
    while(right-left>=1e-6){
        p = left/3 * 2 + right/3;
        q = left/3 + right/3 * 2;
        if(dist(p)>=dist(q)){
            left = p;
            ans = q;
        }
        else if(dist(p)<dist(q)){
            right = q;
        }
    }
    cout<<setprecision(10);
    cout<<dist(ans)<<'\n';
    return 0;
}

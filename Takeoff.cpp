#include<bits/stdc++.h>
 using namespace std;

 #define ll long long
 
ll maximumFights(ll N,ll p, ll q, ll r)
{
 unordered_map<ll,ll> mp;
     for(ll i = p; i <= N; i += p)
         mp[i]++;
     for(ll i = q; i <= N;i += q)
         mp[i]++;
     for(ll i = r; i <= N; i += r)
         mp[i]++;
  
  ll count = 0;
    for(auto j =  mp.begin();j != mp.end(); j++)
    {
        if(j->second == 1)
            count++;
    }
  
  return count;
 }
 
 
 int main()
 {
    int t;
    scanf("%d ",&t);

     while(t--)
     {
         ll N, p, q, r;
         scanf("%ld %ld %ld %ld", &N, &p, &q,&r);
        printf("%d \n", maximumFights(N, p, q,r));
  
    }
    return 0;
   
  }

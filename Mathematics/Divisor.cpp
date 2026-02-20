// --- Macros ---
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

// --- Math Utils ---
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

const int MOD = 1e9 + 7;
int mod_add(int a, int b) { return ((a % MOD + b % MOD) % MOD + MOD) % MOD; }
int mod_mul(int a, int b) { return (1LL * a * b) % MOD; }
int mod_pow(int a, int b)
{
  int res = 1;
  while (b)
  {
    if (b & 1)
      res = mod_mul(res, a);
    a = mod_mul(a, a);
    b >>= 1;
  }
  return res;
}

bool isPrime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

// --- Divisors ---
ll countDivisors(ll n)
{
  ll ans = 1;
  for (ll i = 2; i * i <= n; i++) // check for the divisors of n when got increment the count.
  {
    int cnt = 0;
    while (n % i == 0)
    {
      n /= i;
      cnt++;
    }
    ans *= (cnt + 1); // we are finding the number of divisors so add 1 and multiply it with answer.
  }
  if (n > 1) // when the last number is prime itself we have to count it so (1+1) --> multiply with 2.
    ans *= 2;
  return ans;
}

// ll productDivisors(ll n) { return pow(n, countDivisors(n) / 2); }

// vvl precomputeDivisors(ll n)
// {
//   vvl pre(n + 1);
//   rep(i, 1, n + 1) for (int j = i; j <= n; j += i) pre[j].pb(i);
//   return pre;
// }

// finding number of divisors that divide the whole array elements.
ll commonDivisors(vll &nums, ll n)
{

  ll gcd_ = 0;
  rep(i, 0, n) gcd_ = gcd(gcd_, nums[i]);

  return countDivisors(gcd_);
}
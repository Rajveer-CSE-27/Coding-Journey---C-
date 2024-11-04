int main()
{
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < 60; i++)
  {
  long long val = pow(2, i);
  if (n & val)
  {
    ans = ((pow(2, i + 1) * 1LL - 1) - ans);
  }
  }
  cout << ans << endl;
}

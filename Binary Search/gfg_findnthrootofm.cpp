int NthRoot(int n, int m) {
  int s = 0;
  int e = m;
  int mid;
  int ans;
  while (e >= s)
  {
      mid = s + (e - s) / 2;
      if (pow(mid, n) > m)
      {
          e = mid - 1;
      }
      else if (pow(mid, n) < m)
      {
          s = mid + 1;
      }
      else
      {
          return mid;
      }
  }
  return -1;
}
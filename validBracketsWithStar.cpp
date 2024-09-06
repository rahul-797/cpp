bool checkValidString(string s) {
  int open = 0, closed = 0, len = s.length() - 1;
  for (int i = 0; i <= len; i++) {
    if (s[i] == '(' || s[i] == '*')
      open++;
    else
      open--;

    if (s[len - i] == ')' || s[len - i] == '*')
      closed++;
    else
      closed--;

    if (closed < 0 || open < 0) return false;
  }
  return true;
}

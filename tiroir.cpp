#include <iostream>
#include <vector>
#include <fstream>

template <typename T, typename T2> unsigned int match(const std::vector<T> &source, const T2 &ptrn) {
  int cnt = 0;
  for (typename std::vector<T>::const_iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return cnt;
    };
    cnt += 1;
  };
  return -1;
};

bool is_greater_str(std::string &x, std::string &x2, 
                std::vector<char> &order_v) {
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  unsigned int val1;
  unsigned int val2;
  if (n == n2) {
    for (unsigned int i = 0; i < n; ++i) {
      val1 = match(order_v, x[i]);
      val2 = match(order_v, x2[i]);
      if (val1 != val2) {
        if (val1 > val2) {
          return 1;
        } else {
          return 0;
        };
      };
    };
  } else if (n > n2) {
    return 1;
  } else {
    return 0;
  };
  return 1;
};

std::vector<std::string> str_sort_ascend(std::vector<std::string> x,
                std::vector<char> order_v = {
                         ' ', '!', '"', '#', '$', '%', '&', 
                        '\'', '(', ')', '*', '+', ',', '-', 
                        '.', '/', '0', '1', '2', '3', '4', '5',
                        '6', '7', '8', '9', ':', ';', '<', '=',
                        '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
                        'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                        'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
                        ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z', '{', '|', '}',
                        '~'           
                }) {
  unsigned int i;
  unsigned int i2;
  const unsigned int n = x.size();
  std::vector<std::string> rtn_v = {};
  rtn_v.reserve(n);
  std::string cur_str;
  std::vector<std::string> x_ref = x;
  std::string max_str = "~";
  unsigned int max_len = 1;
  unsigned int cur_len;
  unsigned int idx_min;
  bool is_sup;
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    cur_len = cur_str.length();
    if (max_len < cur_len) {
      max_len = cur_len;
    };
  };
  for (i = 1; i < max_len; ++i) {
    max_str.push_back('~');
  };
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    idx_min = i;
    for (i2 = 0; i2 < n; ++i2) {
      is_sup = is_greater_str(x[i2], cur_str, order_v);
      if (!is_sup) {
        cur_str = x[i2];
        idx_min = i2;
      };
    };
    x[idx_min] = max_str;
    rtn_v.push_back(x_ref[idx_min]);
  };
  return rtn_v;
};

int main() {

  std::vector<char> order_v = {
     ' ', '!', '"', '#', '$', '%', '&', 
     '\'', '(', ')', '*', '+', ',', '-', 
     '.', '/', ':', ';', '<', '=',
     '>', '?', '@', 'A', 'a', 'B', 'b', 'C', 'c',
     'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 
     'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 
     'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 
     'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 
     'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', 
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
     '[', '\\', 
     ']', '^', '_', '`', '{', '|', '}',
     '~'};

  std::string currow;
  std::vector<std::string> inv = {};
  std::fstream read_file("/home/kvv/ssd1/Tiroir/in.txt");
  while (getline(read_file, currow)) {
    inv.push_back(currow);
  };
  std::vector<std::string> outv = str_sort_ascend(inv, order_v);
  const unsigned int n = inv.size();
  for (unsigned int i = 0; i < n; ++i) {
    std::cout << outv[i] << " ";
  };
  std::cout << "\n";

  return 0;
};




## Tokenising a sentence 
```cpp
#include <iostream>
#include <sstream>
#include <string> 
using namespace std;

int main() {
  string sentence = "the cattle was rattled by the battery";
  stringstream ss(sentence); // bind string to stream
  string word;

  while (ss >> word) cout << word << endl;

  return 0;
}
```

## Converting string -> number
```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string str = "123 45"
  stringstream ss(str);

  int a, b;
  ss >> a >> b;

  cout << a + b << endl; 
}
```

## Constructing string from numbers
```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  int x = 42;
  double y = 3.14;

  stringstream ss;
  ss << "x = " << x << ", y = " << y;

  string result = ss.str(); // convert stream to string
  cout << result << endl;
}


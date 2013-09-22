typedef i32 int32
typedef list<map<int32, string>> biglist

struct struct1 {
  1: int32 myint;
  2: biglist mylist;
}

exception exception1 {
  1: biglist alist;
  2: struct1 mystruct;
}

service AService {
  struct1 method1(1: int32 myint) throws (1: exception1 exn);
  biglist method2();
}

namespace cpp shared
namespace java shared
namespace perl shared

struct SharedStruct {
  3: i32 key
  2: string value
  12: string value
}

service SharedService {
  SharedStruct getStruct(1: i32 key)
}

namespace java ytx
namespace js ytx
//status:0.未激活1.激活体验2.激活3.激活休眠

//level:0.A类1.B类2.C类

struct Customer{
  1:string id
  2:string username
  3:string name
  4:optional i32 csrId
  5:string memo
  6:i32 status
  7:i32 level
  8:optional string avatar
}

struct CSRInfo{
  1:i32 id
  2:string jobNumber
  3:string name
  4:string memo
  5:optional string avatar
}

struct CustomerDetail{
  1:string id
  2:string name
  3:string memo
  4:i32 type
  5:i32 level
}

struct Message{
  1:string id
  2:i32 type
  3:string datetime
  4:string content
  5:string fromId
  6:string fromName
  7:string toId
  8:string toName
  9:bool isRead
}

typedef list<Customer> ( cpp.template = "std::list" ) CustomerList
typedef list<Message> ( cpp.template = "std::list" ) MessageList
typedef list<string> ( cpp.template = "std::list" ) UsernameList
//1.用户不存在.2.密码错误.3.Customer不存在

exception csr_error{
  1:i32 type
  2:string message
}

//1.CSR不存在.2.Customer不存在

exception bind_error{
  1:i32 type
  2:string message
}

service ICRMService{
  //CSRlogin
  i32 csrLogin(1:string csrName,2:string password) throws(1:csr_error error)

  //获取CSR信息
  CSRInfo getCSRInfoByCSRId(1:i32 csrId) throws(1:bind_error error)

  //绑定用户和CSR
  i32 bindCSR(1:string username,2:i32 newCSRId) throws(1:bind_error error)

  //获取对应的CSR信息
  CSRInfo getRelatedCSRInfoByUsername(1:string username) throws(1:csr_error error)

  //获取客户信息列表
  CustomerList getCusomterListByCSRId(1:i32 csrId) throws(1:csr_error error)

  //获取对应的CSR信息
  UsernameList getCustomerUsernameList(1:i32 csrId,2:i32 customerStatus) throws(1:csr_error error)

  //获取客户详细信息
  Customer getCusomterByUsername(1:string username,2:i32 csrId)

  //发送回电提醒
  void phoneCallback(1:string username,2:i32 csrId) throws(1:csr_error error)

  //暂不实现
  //设置用户信息
  void setCustomerInfo(1:CustomerDetail customerDetail)

}

service ICSRChatMessage{
  //向这个CSR所负责的所有客户发送消息
  void sendContent(1:string content,2:string csrId)

  //获取聊天记录
  MessageList getChatHistory(1:string customerId,2:i32 lastUpdateTime)

  //获取未读消息
  MessageList getUnreadMessagesHistory(1:string csrId,2:i32 lastUpdateTime)

}

service ICustomerChatService{
  //获取聊天记录
  MessageList getChatHistory(1:string customerId,2:i32 lastUpdateTime)

}


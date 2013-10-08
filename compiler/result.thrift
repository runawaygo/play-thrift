namespace java ytx
namespace js ytx
struct Customer{
  1:string id
  2:string name
  3:string memo
  4:i32 type
  5:i32 level
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
  5:string csrId
  6:string csrName
  7:string customerId
  8:string customerName
}

struct CSRInfo{
  1:string id
  2:string name
  3:string title
  4:string memo
}

typedef list<string> ( cpp.template = "std::list" ) CustomerIdList
typedef list<Customer> ( cpp.template = "std::list" ) CustomerList
typedef list<string> ( cpp.template = "std::list" ) CSRIdList
typedef list<Message> ( cpp.template = "std::list" ) MessageList
service ICRMService{
  //绑定用户和CSR
  void bindCSR(1:string customerId,2:string newCSRId)

  //更换一个用户的服务人员
  void replaceCSRForOneGroupCustomers(1:string oldCSRId,2:string newCSRId)

  //获取客户信息列表
  CustomerList getCusomterList(1:CustomerIdList ids)

  //获取客户详细信息
  Customer getCusomterById(1:string customerId)

  //设置用户信息
  void setCustomerInfo(1:CustomerDetail customerDetail)

  //获取CSR信息
  CSRInfo getCSRInfoById(1:string customerId)

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


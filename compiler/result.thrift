namespace cpp ytx
namespace java ytx
namespace js ytx
struct Channel{
  1:string id
  2:string name
  /**0公共频道
*1点对点服务频道
*/
  3:i32 type
}

struct Message{
  1:optional string id
  2:optional i32 type
  3:optional string channelId
  4:string channelName
  5:string datetime
  6:string content
  7:string fromUserId
  8:string fromUsername
  9:string toUserId
  10:optional string toUsername
}

typedef list<Channel> ( cpp.template = "std::list" ) ChannelList
typedef list<string> ( cpp.template = "std::list" ) UserIdList
typedef list<string> ( cpp.template = "std::list" ) ChannelIdList
typedef list<Message> ( cpp.template = "std::list" ) MessageList
service ChatService{
  //获取用户所订阅的频道信息
  ChannelList getChannelsByUserId(1:string userId)

  //获取最后更新时间之后的用户所有订阅频道的更新
  void getChannelsUpdate(1:string userId,2:i32 lastUpdateTime)

  //用户订阅某个频道
  void subscribe(1:string channelId,2:string userId)

  //用户取消订阅某个频道
  void unsubscribe(1:string channelId,2:string userId)

  //通过内容创建频道
  Channel createContentChannel(1:i32 cmsChannelId)

  //删除某个频道
  void deleteChannel(1:string channelId)

  //向某一个频道添加管理员
  void addAdminIntoChannel(1:string channelId,2:UserIdList userIds)

  //从一个频道中删除管理员
  void removeAdminFromChannel(1:string channelId,2:UserIdList userIds)

  //向某个频道推送消息
  void sendMessage(1:string channelId,2:string centent)

  //向某个频道推送内容
  void sendContent(1:string channelId,2:i32 contentId)

  //获取聊天记录
  MessageList getChatHistory(1:string userId,2:string channelId,3:i32 lastUpdateTime)

}


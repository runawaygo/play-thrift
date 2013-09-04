/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Twitter_H
#define Twitter_H

#include <thrift/TDispatchProcessor.h>
#include "example_types.h"

namespace thrift { namespace example {

class TwitterIf {
 public:
  virtual ~TwitterIf() {}
  virtual void ping() = 0;
  virtual bool postTweet(const Tweet& tweet) = 0;
  virtual void searchTweets(TweetSearchResult& _return, const std::string& query) = 0;
  virtual void zip() = 0;
};

class TwitterIfFactory {
 public:
  typedef TwitterIf Handler;

  virtual ~TwitterIfFactory() {}

  virtual TwitterIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TwitterIf* /* handler */) = 0;
};

class TwitterIfSingletonFactory : virtual public TwitterIfFactory {
 public:
  TwitterIfSingletonFactory(const boost::shared_ptr<TwitterIf>& iface) : iface_(iface) {}
  virtual ~TwitterIfSingletonFactory() {}

  virtual TwitterIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TwitterIf* /* handler */) {}

 protected:
  boost::shared_ptr<TwitterIf> iface_;
};

class TwitterNull : virtual public TwitterIf {
 public:
  virtual ~TwitterNull() {}
  void ping() {
    return;
  }
  bool postTweet(const Tweet& /* tweet */) {
    bool _return = false;
    return _return;
  }
  void searchTweets(TweetSearchResult& /* _return */, const std::string& /* query */) {
    return;
  }
  void zip() {
    return;
  }
};


class Twitter_ping_args {
 public:

  Twitter_ping_args() {
  }

  virtual ~Twitter_ping_args() throw() {}


  bool operator == (const Twitter_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Twitter_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Twitter_ping_pargs {
 public:


  virtual ~Twitter_ping_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Twitter_ping_result {
 public:

  Twitter_ping_result() {
  }

  virtual ~Twitter_ping_result() throw() {}


  bool operator == (const Twitter_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Twitter_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Twitter_ping_presult {
 public:


  virtual ~Twitter_ping_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Twitter_postTweet_args__isset {
  _Twitter_postTweet_args__isset() : tweet(false) {}
  bool tweet;
} _Twitter_postTweet_args__isset;

class Twitter_postTweet_args {
 public:

  Twitter_postTweet_args() {
  }

  virtual ~Twitter_postTweet_args() throw() {}

  Tweet tweet;

  _Twitter_postTweet_args__isset __isset;

  void __set_tweet(const Tweet& val) {
    tweet = val;
  }

  bool operator == (const Twitter_postTweet_args & rhs) const
  {
    if (!(tweet == rhs.tweet))
      return false;
    return true;
  }
  bool operator != (const Twitter_postTweet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_postTweet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Twitter_postTweet_pargs {
 public:


  virtual ~Twitter_postTweet_pargs() throw() {}

  const Tweet* tweet;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Twitter_postTweet_result__isset {
  _Twitter_postTweet_result__isset() : success(false), unavailable(false) {}
  bool success;
  bool unavailable;
} _Twitter_postTweet_result__isset;

class Twitter_postTweet_result {
 public:

  Twitter_postTweet_result() : success(0) {
  }

  virtual ~Twitter_postTweet_result() throw() {}

  bool success;
  TwitterUnavailable unavailable;

  _Twitter_postTweet_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  void __set_unavailable(const TwitterUnavailable& val) {
    unavailable = val;
  }

  bool operator == (const Twitter_postTweet_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(unavailable == rhs.unavailable))
      return false;
    return true;
  }
  bool operator != (const Twitter_postTweet_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_postTweet_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Twitter_postTweet_presult__isset {
  _Twitter_postTweet_presult__isset() : success(false), unavailable(false) {}
  bool success;
  bool unavailable;
} _Twitter_postTweet_presult__isset;

class Twitter_postTweet_presult {
 public:


  virtual ~Twitter_postTweet_presult() throw() {}

  bool* success;
  TwitterUnavailable unavailable;

  _Twitter_postTweet_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Twitter_searchTweets_args__isset {
  _Twitter_searchTweets_args__isset() : query(false) {}
  bool query;
} _Twitter_searchTweets_args__isset;

class Twitter_searchTweets_args {
 public:

  Twitter_searchTweets_args() : query() {
  }

  virtual ~Twitter_searchTweets_args() throw() {}

  std::string query;

  _Twitter_searchTweets_args__isset __isset;

  void __set_query(const std::string& val) {
    query = val;
  }

  bool operator == (const Twitter_searchTweets_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const Twitter_searchTweets_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_searchTweets_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Twitter_searchTweets_pargs {
 public:


  virtual ~Twitter_searchTweets_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Twitter_searchTweets_result__isset {
  _Twitter_searchTweets_result__isset() : success(false) {}
  bool success;
} _Twitter_searchTweets_result__isset;

class Twitter_searchTweets_result {
 public:

  Twitter_searchTweets_result() {
  }

  virtual ~Twitter_searchTweets_result() throw() {}

  TweetSearchResult success;

  _Twitter_searchTweets_result__isset __isset;

  void __set_success(const TweetSearchResult& val) {
    success = val;
  }

  bool operator == (const Twitter_searchTweets_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Twitter_searchTweets_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_searchTweets_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Twitter_searchTweets_presult__isset {
  _Twitter_searchTweets_presult__isset() : success(false) {}
  bool success;
} _Twitter_searchTweets_presult__isset;

class Twitter_searchTweets_presult {
 public:


  virtual ~Twitter_searchTweets_presult() throw() {}

  TweetSearchResult* success;

  _Twitter_searchTweets_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Twitter_zip_args {
 public:

  Twitter_zip_args() {
  }

  virtual ~Twitter_zip_args() throw() {}


  bool operator == (const Twitter_zip_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Twitter_zip_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Twitter_zip_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Twitter_zip_pargs {
 public:


  virtual ~Twitter_zip_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class TwitterClient : virtual public TwitterIf {
 public:
  TwitterClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  TwitterClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  void send_ping();
  void recv_ping();
  bool postTweet(const Tweet& tweet);
  void send_postTweet(const Tweet& tweet);
  bool recv_postTweet();
  void searchTweets(TweetSearchResult& _return, const std::string& query);
  void send_searchTweets(const std::string& query);
  void recv_searchTweets(TweetSearchResult& _return);
  void zip();
  void send_zip();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class TwitterProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<TwitterIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TwitterProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_postTweet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_searchTweets(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_zip(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TwitterProcessor(boost::shared_ptr<TwitterIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &TwitterProcessor::process_ping;
    processMap_["postTweet"] = &TwitterProcessor::process_postTweet;
    processMap_["searchTweets"] = &TwitterProcessor::process_searchTweets;
    processMap_["zip"] = &TwitterProcessor::process_zip;
  }

  virtual ~TwitterProcessor() {}
};

class TwitterProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TwitterProcessorFactory(const ::boost::shared_ptr< TwitterIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< TwitterIfFactory > handlerFactory_;
};

class TwitterMultiface : virtual public TwitterIf {
 public:
  TwitterMultiface(std::vector<boost::shared_ptr<TwitterIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~TwitterMultiface() {}
 protected:
  std::vector<boost::shared_ptr<TwitterIf> > ifaces_;
  TwitterMultiface() {}
  void add(boost::shared_ptr<TwitterIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    ifaces_[i]->ping();
  }

  bool postTweet(const Tweet& tweet) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->postTweet(tweet);
    }
    return ifaces_[i]->postTweet(tweet);
  }

  void searchTweets(TweetSearchResult& _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->searchTweets(_return, query);
    }
    ifaces_[i]->searchTweets(_return, query);
    return;
  }

  void zip() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->zip();
    }
    ifaces_[i]->zip();
  }

};

}} // namespace

#endif
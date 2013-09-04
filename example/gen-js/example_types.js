//
// Autogenerated by Thrift Compiler (1.0.0-dev)
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//


TweetType = {
'TWEET' : 0,
'RETWEET' : 2,
'DM' : 10,
'REPLY' : 11
};
Location = function(args) {
  this.latitude = null;
  this.longitude = null;
  if (args) {
    if (args.latitude !== undefined) {
      this.latitude = args.latitude;
    }
    if (args.longitude !== undefined) {
      this.longitude = args.longitude;
    }
  }
};
Location.prototype = {};
Location.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.DOUBLE) {
        this.latitude = input.readDouble().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 2:
      if (ftype == Thrift.Type.DOUBLE) {
        this.longitude = input.readDouble().value;
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Location.prototype.write = function(output) {
  output.writeStructBegin('Location');
  if (this.latitude !== null && this.latitude !== undefined) {
    output.writeFieldBegin('latitude', Thrift.Type.DOUBLE, 1);
    output.writeDouble(this.latitude);
    output.writeFieldEnd();
  }
  if (this.longitude !== null && this.longitude !== undefined) {
    output.writeFieldBegin('longitude', Thrift.Type.DOUBLE, 2);
    output.writeDouble(this.longitude);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

Tweet = function(args) {
  this.userId = null;
  this.userName = null;
  this.text = null;
  this.loc = null;
  this.tweetType = 0;
  this.language = 'english';
  if (args) {
    if (args.userId !== undefined) {
      this.userId = args.userId;
    }
    if (args.userName !== undefined) {
      this.userName = args.userName;
    }
    if (args.text !== undefined) {
      this.text = args.text;
    }
    if (args.loc !== undefined) {
      this.loc = args.loc;
    }
    if (args.tweetType !== undefined) {
      this.tweetType = args.tweetType;
    }
    if (args.language !== undefined) {
      this.language = args.language;
    }
  }
};
Tweet.prototype = {};
Tweet.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.I32) {
        this.userId = input.readI32().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 2:
      if (ftype == Thrift.Type.STRING) {
        this.userName = input.readString().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 3:
      if (ftype == Thrift.Type.STRING) {
        this.text = input.readString().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 4:
      if (ftype == Thrift.Type.STRUCT) {
        this.loc = new Location();
        this.loc.read(input);
      } else {
        input.skip(ftype);
      }
      break;
      case 5:
      if (ftype == Thrift.Type.I32) {
        this.tweetType = input.readI32().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 16:
      if (ftype == Thrift.Type.STRING) {
        this.language = input.readString().value;
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Tweet.prototype.write = function(output) {
  output.writeStructBegin('Tweet');
  if (this.userId !== null && this.userId !== undefined) {
    output.writeFieldBegin('userId', Thrift.Type.I32, 1);
    output.writeI32(this.userId);
    output.writeFieldEnd();
  }
  if (this.userName !== null && this.userName !== undefined) {
    output.writeFieldBegin('userName', Thrift.Type.STRING, 2);
    output.writeString(this.userName);
    output.writeFieldEnd();
  }
  if (this.text !== null && this.text !== undefined) {
    output.writeFieldBegin('text', Thrift.Type.STRING, 3);
    output.writeString(this.text);
    output.writeFieldEnd();
  }
  if (this.loc !== null && this.loc !== undefined) {
    output.writeFieldBegin('loc', Thrift.Type.STRUCT, 4);
    this.loc.write(output);
    output.writeFieldEnd();
  }
  if (this.tweetType !== null && this.tweetType !== undefined) {
    output.writeFieldBegin('tweetType', Thrift.Type.I32, 5);
    output.writeI32(this.tweetType);
    output.writeFieldEnd();
  }
  if (this.language !== null && this.language !== undefined) {
    output.writeFieldBegin('language', Thrift.Type.STRING, 16);
    output.writeString(this.language);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

TweetSearchResult = function(args) {
  this.tweets = null;
  if (args) {
    if (args.tweets !== undefined) {
      this.tweets = args.tweets;
    }
  }
};
TweetSearchResult.prototype = {};
TweetSearchResult.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.LIST) {
        var _size0 = 0;
        var _rtmp34;
        this.tweets = [];
        var _etype3 = 0;
        _rtmp34 = input.readListBegin();
        _etype3 = _rtmp34.etype;
        _size0 = _rtmp34.size;
        for (var _i5 = 0; _i5 < _size0; ++_i5)
        {
          var elem6 = null;
          elem6 = new Tweet();
          elem6.read(input);
          this.tweets.push(elem6);
        }
        input.readListEnd();
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

TweetSearchResult.prototype.write = function(output) {
  output.writeStructBegin('TweetSearchResult');
  if (this.tweets !== null && this.tweets !== undefined) {
    output.writeFieldBegin('tweets', Thrift.Type.LIST, 1);
    output.writeListBegin(Thrift.Type.STRUCT, this.tweets.length);
    for (var iter7 in this.tweets)
    {
      if (this.tweets.hasOwnProperty(iter7))
      {
        iter7 = this.tweets[iter7];
        iter7.write(output);
      }
    }
    output.writeListEnd();
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

TwitterUnavailable = function(args) {
  this.message = null;
  if (args) {
    if (args.message !== undefined) {
      this.message = args.message;
    }
  }
};
Thrift.inherits(TwitterUnavailable, Thrift.TException);
TwitterUnavailable.prototype.name = 'TwitterUnavailable';
TwitterUnavailable.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.STRING) {
        this.message = input.readString().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

TwitterUnavailable.prototype.write = function(output) {
  output.writeStructBegin('TwitterUnavailable');
  if (this.message !== null && this.message !== undefined) {
    output.writeFieldBegin('message', Thrift.Type.STRING, 1);
    output.writeString(this.message);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

MAX_RESULTS = 100;

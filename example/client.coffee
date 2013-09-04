thrift = require('thrift')
Twitter = require('./gen-nodejs/Twitter')
ttypes = require('./gen-nodejs/example_types')

connection = thrift.createConnection("localhost", 9090)
client = thrift.createClient(Twitter, connection)

connection.on 'error', (err)->
  console.error(err)

tweet = new ttypes.Tweet(
  userId: parseInt Math.random()*1000
  userName: "superwolf"
  text:"hello world!"
)
client.postTweet tweet, (err, data)->
  console.log err
  console.log data
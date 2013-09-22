Node = require './node'
class Comment extends Node
  constructor:(@value)->
    super 'comment'

module.exports = Comment
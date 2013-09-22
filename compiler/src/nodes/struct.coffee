Node =  require './node'
class Struct extends Node
  constructor:(@name)->
    super 'struct'

module.exports = Struct
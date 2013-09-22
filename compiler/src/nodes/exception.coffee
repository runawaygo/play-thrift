Node = require './node'
class Exception extends Node
  constructor:(@name)->
    super 'exception'

  addField:(type, name)->
    @nodes.push
      type:type
      name:name


module.exports = Exception
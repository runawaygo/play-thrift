Node = require './node'
class PlainNode extends Node
  constructor:(@value, @options = {})->
    super 'plainNode'
    @spaced = @options.spaced
    @newLine = @options.newLine


module.exports = PlainNode
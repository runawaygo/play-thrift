Node =  require './node'

class Method extends Node
  constructor:(@returnType, @name)->
    super 'method'
    @returnType ?= 'void'
      
module.exports = Method
Node =  require './node'

class Method extends Node
  constructor:(@returnType, @name)->
    super 'method'
    @returnType ?= 'void'
    @exception = null
  setException:(type, name)->
    @exception = {}
    @exception.name = name
    @exception.type = type
      
module.exports = Method
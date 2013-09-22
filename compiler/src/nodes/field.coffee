Node =  require './node'

class Field extends Node
  constructor:(@fieldType, @name, @isOptional = false)->
    super 'field'
      
module.exports = Field
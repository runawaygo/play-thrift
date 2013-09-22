Node =  require './node'

class Service extends Node
  constructor:(@name)->
    super 'service'

module.exports = Service

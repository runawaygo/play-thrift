class Node
  constructor:(@type)->
    @nodes = []
  addChild:(node)->
    @nodes.push node 

module.exports = Node

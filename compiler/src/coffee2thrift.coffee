Parser = require './parser'
Compiler = require './compiler'


exports.parse = (code)->
  parser = new Parser code
  parser.parse()

  compiler = new Compiler parser.nodes
  compiler.compile()
  compiler.result
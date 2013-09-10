{Lexer} = require './lexer'
lexer = new Lexer
nodes = require './nodes'

class Parser
  constructor: (@input, @filename, @options = {})->
    @tokenNo = 0
    @lineno = 0
  parse:->
    @tokens = lexer.tokenize(@input)
    # until @tokenNo is @tokens.length-1
    #   @tokenNo++
    #   console.log 'superwolf'

  parseIdentifier:(token)->
    switch token[1]
      when 'namespace'
        new nodes.Namespace

exports = module.exports = Parser
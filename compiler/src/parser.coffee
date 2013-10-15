{Lexer} = require './lexer'
lexer = new Lexer
nodes = require './nodes'

class Parser
  constructor: (@input, @options = {})->
    @tokenNo = 0
    @lineno = 0
    @fieldNo = 0
    @argumentNo = 0
    @nodes = []

  parse:->
    @tokens = lexer.tokenize(@input)
    # console.log @tokens
    until @tokenNo > @tokens.length-1
      token = @current()
      switch token[1]
        when 'struct'
          @nodes.push @parseStruct()
        when 'exception'
          @nodes.push @parseException()
        when 'service'
          @nodes.push @parseService()
        when '/', "/(?:)/"
          @nodes.push @parseComment()
        else
          @nodes.push new nodes.PlainNode(token[1], {spaced: token.spaced, newline: token.newLine})
      @moveNext()

  moveNext:-> 
    @tokens[++@tokenNo]

  next:-> @tokens[@tokenNo+1]
  current:-> @tokens[@tokenNo]
  movePrev:-> @tokens[--@tokenNo]
  prev:-> @tokens[@tokenNo-1]

  parseService:->
    service = new nodes.Service @moveNext()[1]
    if @next()[0] isnt 'INDENT' 
      --@tokenNo
      return service
    until @moveNext()[0] is 'OUTDENT'
      switch @current()[0]
        when 'IDENTIFIER'
          if @moveNext()[0] is 'CALL_START'
            method = new nodes.Method 'void',@movePrev()[1]
          else
            method = new nodes.Method @movePrev()[1],@moveNext()[1]

          service.addChild method

          if @moveNext()[0] isnt 'CALL_START'
            --@tokenNo
            continue

          until @moveNext()[0] is ')'
            @tokenNo++ if @current()[0] isnt 'IDENTIFIER'
            method.addChild new nodes.Field @current()[1], @moveNext()[1]

          #throws(type name):throws(1:type name)
          if @moveNext()[1] is 'throws'
            @moveNext()
            method.setException @moveNext()[1], @moveNext()[1]
            @moveNext()
          else 
            @movePrev()


        when 'MATH', 'REGEX'
          service.addChild @parseComment()
    service

  parseComment:->
    buff = []
    #Multiline comments
    if @current()[0] is 'MATH'
      buff.push '/'
      until @moveNext()[1] is "/"
        buff.push @current()[1]
      buff.push '/'
    else
      buff.push '//'
      buff.push @current()[1] until @moveNext()[1] is "\n"
      buff.push '\n'

    new nodes.Comment buff.join('')


  parseException:->
    exception = new nodes.Exception @tokens[++@tokenNo][1]
    if @moveNext()[0] isnt 'INDENT' 
      --@tokenNo
      return exception

    until @moveNext()[0] is 'OUTDENT'
      switch @current()[0]
        when 'IDENTIFIER'
          field = new nodes.Field @current()[1], @moveNext()[1]
          if @next()[1] is '?'
            field.isOptional = true
            @moveNext()
            
          exception.addChild field
        when 'MATH', 'REGEX' 
          exception.addChild @parseComment()

    exception

  parseStruct:->
    struct = new nodes.Struct @tokens[++@tokenNo][1]
    if @moveNext()[0] isnt 'INDENT' 
      --@tokenNo
      return struct

    until @moveNext()[0] is 'OUTDENT'
      switch @current()[0]
        when 'IDENTIFIER'
          field = new nodes.Field @current()[1], @moveNext()[1]
          if @next()[1] is '?'
            field.isOptional = true
            @moveNext()

          struct.addChild field
        when 'MATH', 'REGEX'
          struct.addChild @parseComment()

    struct

exports = module.exports = Parser
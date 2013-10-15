class Compiler
  constructor:(@nodes, @options={})->
    @buff = []
  compile:->
    for node in @nodes
      @visit node
    @result = @buff.join('')

  visit:(node)->
    switch node.type
      when 'plainNode' 
        @buff.push node.value
        @buff.push " " if node.spaced
      when 'comment'
        @buff.push node.value+"\n"
        
      when 'struct', 'exception'
        @buff.push node.type+" "
        @buff.push node.name+"{\n"
        index = 0
        for childNode in node.nodes
          switch childNode.type
            when 'field'

              @buff.push "  "+(++index)+":"
              @buff.push 'optional ' if childNode.isOptional
              @buff.push childNode.fieldType+" "
              @buff.push childNode.name+"\n"
            when 'comment'
              @buff.push "  "+childNode.value+"\n"

        @buff.push "}\n"
      when 'service'
        @buff.push node.type+" "
        @buff.push node.name+"{\n"
        for childNode in node.nodes
          switch childNode.type
            when 'method'
              @buff.push "  "+childNode.returnType+" "+childNode.name
              @buff.push "("
              @arguments = []
              for argument,index in childNode.nodes
                @arguments.push (index+1)+":"+argument.fieldType+" "+argument.name
              @buff.push @arguments.join(',')
              @buff.push ")"
              @buff.push " throws(1:#{childNode.exception.type} #{childNode.exception.name})" if childNode.exception
              @buff.push "\n\n"
            when 'comment'
              @buff.push "  "+childNode.value
        @buff.push "}\n"


exports = module.exports = Compiler
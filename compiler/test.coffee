fs = require('fs')

Parser = require './src/parser'
Compiler = require './src/compiler'
code = fs.readFileSync(__dirname + '/test.coffeethrift', 'utf-8')
parser = new Parser code
parser.parse()
compiler = new Compiler parser.nodes
compiler.compile()
fs.writeFile(__dirname+"/result.thrift", compiler.result)


# fragments = parser.parse(lexer.tokenize code, options).compileToFragments options
# console.log dd
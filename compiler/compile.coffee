fs = require('fs')

Parser = require './src/parser'
Compiler = require './src/compiler'
code = fs.readFileSync(__dirname + '/' + process.argv[2] + '.coffeethrift', 'utf-8')
parser = new Parser code
parser.parse()
compiler = new Compiler parser.nodes
compiler.compile()
fs.writeFile(__dirname+"/"+process.argv[2]+".thrift", compiler.result)

fs = require('fs')
{Lexer} = require './lexer'
code = fs.readFileSync(__dirname + '/test.coffeethrift', 'utf-8')
options = {}
lexer = new Lexer
dd = lexer.tokenize code
console.log dd
# fragments = parser.parse(lexer.tokenize code, options).compileToFragments options
# console.log dd
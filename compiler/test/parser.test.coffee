require 'mocha'
require 'chai'
Parser = require '../parser'
describe 'Parser', ->
  it 'parse', ->
    parser = new Parser 'superwolf'
    parser.parse()
    console.log parser.tokens

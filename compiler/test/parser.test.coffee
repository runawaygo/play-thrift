require 'mocha'
require 'chai'
fs = require 'fs'
Parser = require '../src/parser'
Compiler = require '../src/compiler'

coffee2thrift = require('..')

describe 'Parser', ->
  it 'parse', ->
    parser = new Parser 'superwolf'
    parser.parse()

  it 'parse', ->
    console.log __dirname
    console.log __dirname+'/test.cthrift'
    code = fs.readFileSync(__dirname+'/test.cthrift', 'utf-8')
    console.log code
    parser = new Parser code
    parser.parse()

  it 'parse + compile', ->
    code = fs.readFileSync(__dirname+'/test.cthrift', 'utf-8')
    parser = new Parser code
    parser.parse()

    compiler = new Compiler parser.nodes
    compiler.compile()

  it 'package test', ->
    code = fs.readFileSync(__dirname+'/test.cthrift', 'utf-8')
    console.log coffee2thrift.parse code
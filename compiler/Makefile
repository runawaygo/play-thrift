TESTS = test/*.coffee
REPORTER = spec
TIMEOUT = 10000

test:
	@NODE_ENV=test ./node_modules/mocha/bin/mocha \
		--compilers coffee:coffee-script \
    --reporter $(REPORTER) \
    --timeout $(TIMEOUT) \
    $(MOCHA_OPTS) \
    $(TESTS)

compile:
	coffee compile.coffee ${FILE}
	thrift --gen js:node ${FILE}.thrift

.PHONY: all test clean

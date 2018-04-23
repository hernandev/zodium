<?php

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilerException;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Optimizers\OptimizerAbstract;

class ZodiumMemzeroOptimizer extends OptimizerAbstract
{

    public function optimize(array $expression, Call $call, CompilationContext $context)
    {

        if (!isset($expression['parameters'])) {
            throw new CompilerException("'zodium_memzero' requires one parameter", $expression);
        }

        if (count($expression['parameters']) > 1) {
            throw new CompilerException("'zodium_memzero' requires one parameter", $expression);
        }

        /**
         * Process the expected symbol to be returned
         */
        $call->processExpectedReturn($context);

        $symbolVariable = $call->getSymbolVariable();
        // throw new \Exception($symbolVariable);
//        if (!$symbolVariable->isString()) {
//            throw new CompilerException("The variable to zero should be string", $expression);
//        }

        $resolvedParams = $call->getResolvedParams($expression['parameters'], $context, $expression);

        return new CompiledExpression('char', 'zodium_memzero(' . $resolvedParams[0] . ')', $expression);
    }

}
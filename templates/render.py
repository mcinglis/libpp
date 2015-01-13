#!/usr/bin/python3


from argparse import ArgumentParser, Namespace


TEMPLATE_SEPARATOR = '#####'
CONTEXT_FUNC_NAME = 'context'
OUTPUT_PREFIX = '''
// This file is the result of rendering `{filepath}`.
// You should make changes to this code by editing that template; not
// this file.

// I'm storing the template renderings in version control to make the
// project more approachable.

'''


def main(argv: [str]) -> int:
    args = parse_args(argv[1:])
    print(render(args.filepath, args.limit))
    return 0


def parse_args(raw_args: [str]) -> Namespace:
    p = ArgumentParser(
        description=('Renders the specified template file with the given '
                     'arity limit. The template file should contain a line '
                     'containing just `{template_separator}`, with the '
                     'template text above that separator, and the context '
                     'generation code below. The code should define a '
                     '`{context_func_name}` function that generates a dict. '
                     'The template text is then rendered by: '
                     '`text.format(limit=limit, '
                     '**({context_func_name}(limit))`')
                    .format(template_separator = TEMPLATE_SEPARATOR,
                            context_func_name  = CONTEXT_FUNC_NAME))
    p.add_argument('limit', type=int)
    p.add_argument('filepath', type=str)
    return p.parse_args(raw_args)


def render(filepath: str, limit: int) -> str:
    text = read_file(filepath)
    template, code = text.split('\n{}\n'.format(TEMPLATE_SEPARATOR), 2)
    context = execute(code, filepath)['context']
    return (OUTPUT_PREFIX.format(filepath=filepath)
            + template.format(limit=limit, **(context(limit))))


def execute(code: str, filepath: str) -> {str: 'anything'}:
    code_locals = {}
    code_obj = compile(code, filepath, 'exec')
    exec(code_obj, {}, code_locals)
    return code_locals


def read_file(file: str) -> str:
    with open(file, 'r') as f:
        return f.read()


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))




from __future__ import print_function
from argparse import ArgumentParser, Namespace


TEMPLATE_SEPARATOR = '#####'
OUTPUT_PREFIX = '''
// This file is the result of rendering `{filepath}`.
// You should make changes to this code by editing that template; not
// this file.

'''


def main(argv):
    args = parse_args(argv[1:])
    with open(args.output, 'w') as output:
        print(render(args.filepath, args.limit), file=output)
    return 0


def parse_args(raw_args):
    p = ArgumentParser(
          description=('Renders the specified template file with the given '
                       'arity limit. The template file should contain a line '
                       'containing just `{}`, with the template text above '
                       'that separator, and the context generation code '
                       'below. The code should define a `context` function '
                       'that generates a dict. The template text is then '
                       'rendered by: '
                       '`text.format(limit=limit, **(context(limit))`')
                       .format(TEMPLATE_SEPARATOR))
    p.add_argument('limit', type=int)
    p.add_argument('filepath', type=str)
    p.add_argument('-o', '--output', default='/dev/stdout',
        help='The path to the file to write the rendered template to.')
    return p.parse_args(raw_args)


def render(filepath, limit):
    text = read_file(filepath)
    template, code = text.split('\n' + TEMPLATE_SEPARATOR + '\n', 2)
    context_func = execute(code, filepath)['context']
    context = context_func(limit)
    return (OUTPUT_PREFIX.format(filepath=filepath)
            + template.format(limit=limit, **context))


def execute(code, filepath):
    code_locals = {}
    code_obj = compile(code, filepath, 'exec')
    exec(code_obj, {}, code_locals)
    return code_locals


def read_file(path):
    with open(path, 'r') as f:
        return f.read()


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))


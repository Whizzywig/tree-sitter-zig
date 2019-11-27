module.exports = grammar({
  name: "zig",

  extras: $ => [/\s/, $.comment],

  word: $ => $.identifier,

  rules: {
    program: $ => repeat(choice(
      $._command_or_entry,
      $.comment
    )),

    comment: $ => token(seq('//', /.*/)),
    identifier: $ => /[a-zA-z][a-zA-z\d_]*/,

    visibility_modifier: $ => choice(
      'pub',
    ),

    _statement: $ => choice(
      $._expression_statement,
      $._declaration_statement,
    ),

    _expression_statement: $ => prec.left(choice(
      seq($._expression, ';'),
      prec(1, $._expression_ending_with_block),
    )),

    _expression_ending_with_block: $ => prec(1, choice(
      $.block,
    )),

    _expression: $ => prec.left(choice(
      $.build_in_call_expr,
    )),

    _declaration_statement: $ => choice(
      $.empty_statment,
      //$.assignment_statement,
    ),

    empty_statment: $ => ';',

    assignment_statement: $ => seq(
      optional($.visibility_modifier),
      optional(alias(choice('comptime', 'threadlocal'), $.assignment_modifier)),
      choice('const', 'var'),
      field('name', $.identifier),
      //optional(seq(
      //  ':',
      //  field('type', $._type),
      //)),
      '=',
      field('expression', $._expression),
      ';'
    ),

    block: $ => prec.left(seq(
      //optional(field('label', $.loop_label)),
      '{',
      optional(repeat($._statement)),
      optional($._expression),
      '}',
    )),
    arguments: $ => seq(
      '(',
      sepBy(',', $._expression),
      ')',
    ),
    //expressions
    build_in_call_expr: $ => prec(14, seq(
      '@',
      field('function', $.identifier),
      field('arguments', $.arguments),
    )),

    _command_or_entry: $ => seq("@", /[a-zA-Z]+/)
  }
});

function sepBy1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)), optional(sep))
}

function sepBy(sep, rule) {
  return optional(sepBy1(sep, rule))
}

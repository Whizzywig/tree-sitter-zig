module.exports = grammar({
  name: "zig",

  extras: $ => [/\s/, $.comment,],
  
  word: $ => $.identifier,

  rules: {
    program: $ => repeat(choice(
      $._command_or_entry,
      $.comment
    )),

    comment: $ => token(seq('//', /(\\(.|\r?\n)|[^\\\n])*/)),

    _command_or_entry: $ => seq("@", /[a-zA-Z]+/)
  }
});

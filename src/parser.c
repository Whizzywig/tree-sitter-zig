#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 9
#define STATE_COUNT 7
#define SYMBOL_COUNT 7
#define ALIAS_COUNT 0
#define TOKEN_COUNT 4
#define EXTERNAL_TOKEN_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 0

enum {
  sym_comment = 1,
  anon_sym_AT = 2,
  aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH = 3,
  sym_program = 4,
  sym__command_or_entry = 5,
  aux_sym_program_repeat1 = 6,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "END",
  [sym_comment] = "comment",
  [anon_sym_AT] = "@",
  [aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH] = "/[a-zA-Z]+/",
  [sym_program] = "program",
  [sym__command_or_entry] = "_command_or_entry",
  [aux_sym_program_repeat1] = "program_repeat1",
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH] = {
    .visible = false,
    .named = false,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym__command_or_entry] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '/')
        ADVANCE(2);
      if (lookahead == '@')
        ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(7);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      if (lookahead == '/')
        ADVANCE(3);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\\')
        ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n')
        ADVANCE(3);
      if (lookahead == '\r')
        ADVANCE(5);
      if (lookahead != 0)
        ADVANCE(3);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n')
        ADVANCE(3);
      if (lookahead == '\\')
        ADVANCE(4);
      if (lookahead != 0)
        ADVANCE(3);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '/')
        ADVANCE(2);
      if (lookahead == '@')
        ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(8);
      END_STATE();
    case 9:
      if (lookahead == '/')
        ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(7);
      END_STATE();
    case 10:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '/')
        ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(10);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 8},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 10},
  [4] = {.lex_state = 8},
  [5] = {.lex_state = 8},
  [6] = {.lex_state = 8},
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(3),
    [sym__command_or_entry] = STATE(4),
    [aux_sym_program_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [anon_sym_AT] = ACTIONS(8),
  },
  [2] = {
    [sym_comment] = ACTIONS(10),
    [aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH] = ACTIONS(12),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(14),
    [sym_comment] = ACTIONS(10),
  },
  [4] = {
    [sym__command_or_entry] = STATE(6),
    [aux_sym_program_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(16),
    [sym_comment] = ACTIONS(18),
    [anon_sym_AT] = ACTIONS(8),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_comment] = ACTIONS(21),
    [anon_sym_AT] = ACTIONS(21),
  },
  [6] = {
    [sym__command_or_entry] = STATE(6),
    [aux_sym_program_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_comment] = ACTIONS(25),
    [anon_sym_AT] = ACTIONS(29),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = true}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, REDUCE(sym_program, 0),
  [5] = {.count = 2, .reusable = true}, SHIFT(4), SHIFT_EXTRA(),
  [8] = {.count = 1, .reusable = true}, SHIFT(2),
  [10] = {.count = 1, .reusable = true}, SHIFT_EXTRA(),
  [12] = {.count = 1, .reusable = true}, SHIFT(5),
  [14] = {.count = 1, .reusable = true}, ACCEPT_INPUT(),
  [16] = {.count = 1, .reusable = true}, REDUCE(sym_program, 1),
  [18] = {.count = 2, .reusable = true}, SHIFT(6), SHIFT_EXTRA(),
  [21] = {.count = 1, .reusable = true}, REDUCE(sym__command_or_entry, 2),
  [23] = {.count = 1, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2),
  [25] = {.count = 3, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(6), SHIFT_EXTRA(),
  [29] = {.count = 2, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(2),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_zig() {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}

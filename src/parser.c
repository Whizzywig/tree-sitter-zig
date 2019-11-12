#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 9
#define STATE_COUNT 7
#define SYMBOL_COUNT 8
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 0

enum {
  sym_comment = 1,
  sym_junk = 2,
  anon_sym_AT = 3,
  aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH = 4,
  sym_program = 5,
  sym__command_or_entry = 6,
  aux_sym_program_repeat1 = 7,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "END",
  [sym_comment] = "comment",
  [sym_junk] = "junk",
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
  [sym_junk] = {
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
        ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(11);
      if (lookahead != '%')
        ADVANCE(4);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(sym_junk);
      if (lookahead == '/')
        ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '@')
        ADVANCE(4);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n')
        ADVANCE(4);
      if (lookahead == '\\')
        ADVANCE(5);
      if (lookahead == '%' ||
          lookahead == '@')
        ADVANCE(7);
      if (lookahead != 0)
        ADVANCE(3);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym_junk);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '@')
        ADVANCE(4);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(sym_junk);
      if (lookahead == '\n')
        ADVANCE(3);
      if (lookahead == '\r')
        ADVANCE(6);
      if (lookahead == '%' ||
          lookahead == '@')
        ADVANCE(7);
      if (lookahead != 0)
        ADVANCE(3);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n')
        ADVANCE(3);
      if (lookahead == '\\')
        ADVANCE(5);
      if (lookahead == '%' ||
          lookahead == '@')
        ADVANCE(7);
      if (lookahead != 0)
        ADVANCE(3);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\\')
        ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '\n')
        ADVANCE(7);
      if (lookahead == '\r')
        ADVANCE(9);
      if (lookahead != 0)
        ADVANCE(7);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n')
        ADVANCE(7);
      if (lookahead == '\\')
        ADVANCE(8);
      if (lookahead != 0)
        ADVANCE(7);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_junk);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '%' &&
          (lookahead < '@' || lookahead > 'Z'))
        ADVANCE(4);
      END_STATE();
    case 12:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '/')
        ADVANCE(2);
      if (lookahead == '@')
        ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(12);
      if (lookahead != '%')
        ADVANCE(4);
      END_STATE();
    case 13:
      if (lookahead == '/')
        ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(13);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == '/')
        ADVANCE(7);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '/')
        ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(16);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 12},
  [2] = {.lex_state = 13},
  [3] = {.lex_state = 16},
  [4] = {.lex_state = 12},
  [5] = {.lex_state = 12},
  [6] = {.lex_state = 12},
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym_junk] = ACTIONS(3),
    [anon_sym_AT] = ACTIONS(1),
    [aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH] = ACTIONS(3),
  },
  [1] = {
    [sym_program] = STATE(3),
    [sym__command_or_entry] = STATE(4),
    [aux_sym_program_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
    [sym_junk] = ACTIONS(10),
    [anon_sym_AT] = ACTIONS(12),
  },
  [2] = {
    [sym_comment] = ACTIONS(14),
    [aux_sym_SLASH_LBRACKa_DASHzA_DASHZ_RBRACK_PLUS_SLASH] = ACTIONS(16),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(18),
    [sym_comment] = ACTIONS(14),
  },
  [4] = {
    [sym__command_or_entry] = STATE(6),
    [aux_sym_program_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(20),
    [sym_comment] = ACTIONS(22),
    [sym_junk] = ACTIONS(25),
    [anon_sym_AT] = ACTIONS(12),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_comment] = ACTIONS(29),
    [sym_junk] = ACTIONS(29),
    [anon_sym_AT] = ACTIONS(27),
  },
  [6] = {
    [sym__command_or_entry] = STATE(6),
    [aux_sym_program_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(31),
    [sym_comment] = ACTIONS(33),
    [sym_junk] = ACTIONS(37),
    [anon_sym_AT] = ACTIONS(40),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = true}, RECOVER(),
  [3] = {.count = 1, .reusable = false}, RECOVER(),
  [5] = {.count = 1, .reusable = true}, REDUCE(sym_program, 0),
  [7] = {.count = 2, .reusable = false}, SHIFT(4), SHIFT_EXTRA(),
  [10] = {.count = 1, .reusable = false}, SHIFT(4),
  [12] = {.count = 1, .reusable = true}, SHIFT(2),
  [14] = {.count = 1, .reusable = true}, SHIFT_EXTRA(),
  [16] = {.count = 1, .reusable = true}, SHIFT(5),
  [18] = {.count = 1, .reusable = true}, ACCEPT_INPUT(),
  [20] = {.count = 1, .reusable = true}, REDUCE(sym_program, 1),
  [22] = {.count = 2, .reusable = false}, SHIFT(6), SHIFT_EXTRA(),
  [25] = {.count = 1, .reusable = false}, SHIFT(6),
  [27] = {.count = 1, .reusable = true}, REDUCE(sym__command_or_entry, 2),
  [29] = {.count = 1, .reusable = false}, REDUCE(sym__command_or_entry, 2),
  [31] = {.count = 1, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2),
  [33] = {.count = 3, .reusable = false}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(6), SHIFT_EXTRA(),
  [37] = {.count = 2, .reusable = false}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(6),
  [40] = {.count = 2, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(2),
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

module.exports = {
  root: true,
  parser: 'babel-eslint',
  env: {
    browser: true,
    es6: true,
  },
  extends: [
    'airbnb-base/legacy',
    'plugin:flowtype/recommended',
    'prettier',
    'prettier/flowtype'
  ],
  plugins: [
    'flowtype',
    'prettier'
  ],
  // add your custom rules here.
  'rules': {
    "class-methods-use-this": 0,
    // allow debugger during development
    'no-debugger': process.env.NODE_ENV === 'production' ? 2 : 0,

    'prettier/prettier': ['error', {
      'useTabs': false,
      'printWidth': 80,
      'tabWidth': 2,
      'singleQuote': true,
      'trailingComma': 'all',
      'bracketSpacing': false
    }]
  }
}

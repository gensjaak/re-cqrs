module.exports = {
  roots: ['<rootDir>/__tests__'],
  transformIgnorePatterns: ['node_modules/(?!(jest-)?bs-platform|@glennsl/)'],
  testRegex: '.*_spec.bs.js$',
}

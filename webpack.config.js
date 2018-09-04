const path = require('path');
const outputDir = path.join(__dirname, "dist/");

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './src/Index.bs.js',
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: 'Index.js',
  },
};

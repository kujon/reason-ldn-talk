/* eslint-disable */

var path = require("path");
var webpack = require("webpack");

module.exports = {
    devtool: "cheap-module-source-map",
    entry: [
        'webpack-hot-middleware/client',
        "./dist/index"
    ],
    output: {
        path: path.join(__dirname, "dist"),
        filename: "bundle.js",
        publicPath: "/dist",
    },
    plugins: [
        new webpack.NamedModulesPlugin(),
        new webpack.HotModuleReplacementPlugin()
    ]
};

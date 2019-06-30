const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === "production";

module.exports = {
  entry: { index: "./src/Index.bs.js", style: "./src/style.css" },
  mode: isProd ? "production" : "development",
  output: {
    path: outputDir,
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "src/index.html",
      inject: false
    }),
    new MiniCssExtractPlugin({
      // Options similar to the same options in webpackOptions.output
      // both options are optional
      filename: "[name].css",
      chunkFilename: "css/[id].css"
    })
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          {
            loader: MiniCssExtractPlugin.loader
          },
          { loader: "css-loader", options: { importLoaders: 1 } }
        ]
      }
    ]
  }
};

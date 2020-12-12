# Acrylic for Hyper

Extension for Hyper that makes the background acrylic.

![screenshot](https://github.com/yanisdb/acrylic/blob/master/images/Screenshot.png)

## How to use

Install [Hyper](https://hyper.is) and add `hyper-acrylic` to plugins in `.hyper.js` configuration file.

Choose the color by settings the `backgroundColor` of your `.hyper.js` file to a color with alpha value between 0.07 (0x10) and 1 (0xFF), excluded.

Choose between real window acrylic (on the right) and transparent blur (on the left) by adding our custom settings to `.hyper.js`. You can also choose the transparency.
```js
module.exports = {
  config: {
    // other settings
    acrylic: {
      blur: "acrylic", // "acrylic" or "classic", anything will be flat
      alpha: 150 // alpha value between 0 and 255
    }
  },
  plugins: ['hyper-acrylic', 'other-plugins'],
  // other exports
}
```
The alpha value of the backgroundColor and of the plugin do not need to be the same. The backgroudColor will act as an overlay. Set his alpha value to the minimum and to white or black to get pure acrylic. You can then play with to alpha of the acrylic.

## Contributions

Any contributions is welcomed, I will gladly incorporate any pull request.
Some possible improvements we could work on are:
 * Make the C++ code compile with node-gyp rather than compiling it and uploading it
 * Make the background electron background fully transparent and control the color through windows API
 
## License
 MIT

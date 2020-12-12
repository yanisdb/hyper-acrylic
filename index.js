module.exports.onWindow = (browserWindow) => {
    const handle = new Uint32Array(browserWindow.getNativeWindowHandle().buffer)[0]
    require("child_process").spawn(`${__dirname}\\acrylic.exe`,  [handle, 1]);
}

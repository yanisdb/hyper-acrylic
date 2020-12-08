var electronVibrancy = require("electron-vibrancy");

const CONFIG_KEY = "hyperAcrylic";
const DEFAULT_ALPHA = 0.8;

let config;

exports.onWindow = (window) => {
  electronVibrancy.SetVibrancy(
    true,
    browserWindowInstance.getNativeWindowHandle()
  );
  electronVibrancy.SetVibrancy(window, 0);
}

export function enableVribancy() {}

const defaultConfig = {
    blur: "acrylic",
    red: 0,
    green: 0,
    blue: 0,
    alpha: 150
}

const checkConfig = (config, setting) => {
    return config.hasOwnProperty("acrylic") && config.acrylic[setting] !== undefined
    ? config.acrylic[setting]
    : defaultConfig[setting];
}

exports.decorateConfig = config => {
    exports.onWindow = (browserWindow) => {
        browserWindow.setBackgroundColor("00000000");
        const handle = new Uint32Array(browserWindow.getNativeWindowHandle().buffer)[0]
        let state = -1;
        if (checkConfig(config, "blur") == "acrylic") state = 2;
        if (checkConfig(config, "blur") == "classic") state = 1;
        require("child_process").spawn(`${__dirname}\\acrylic.exe`,  
            [
                handle, 
                state, 
                checkConfig(config, "red"),
                checkConfig(config, "green"),
                checkConfig(config, "blue"), 
                checkConfig(config, "alpha")
            ]
        );
    }
    return config;
}

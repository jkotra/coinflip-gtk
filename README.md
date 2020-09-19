# Coin Flip

Coin Flip is a simple GTK application. it serves multiple purposes, as a template to start a new project or a gentle code walkthrough of a simple app that is not yet-an-another glorified Hello World!

<div align="center">

![Coin flip](https://i.imgur.com/0qkk3oC.png)

</div>

# Building
```
meson build --prefix=/usr
cd build
ninja
```

# Flatpak

```
flatpak-builder --user --install build-dir com.github.jkotra.coinflip.json
flatpak run com.github.jkotra.coinflip
```

executable `coinflip` is found at `bin/src/` directory.
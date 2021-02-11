# Coin Flip

Coin Flip is a simple GTK application. 

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
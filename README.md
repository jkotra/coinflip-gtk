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
flatpak-builder --user --install build-dir com.github.jkotra.coinflip.yml  --force-clean
flatpak run com.github.jkotra.coinflip
```

---

<div>Icons made by <a href="https://www.freepik.com" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
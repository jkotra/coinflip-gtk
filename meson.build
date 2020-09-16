project('com.github.jkotra.coinflip', 'c', 
          version: '0.1.0',
    meson_version: '>= 0.50.0',
  default_options:  [ 'warning_level=2',
                      'c_std=gnu11',
                    ],
)

i18n = import('i18n')

add_project_arguments([
  '-I' + meson.build_root(),
], language: 'c')

subdir('src')
subdir('po')

coinflip_sources = [
  'main.c'
]

coinflip_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
  dependency('gmodule-2.0', version: '>=2.0'),
]

gnome = import('gnome')

coinflip_sources += gnome.compile_resources('coinflip-resources',
  '../data/coinflip.gresource.xml',
  c_name: 'coinflip',
  source_dir: '../data'
)

incdir = include_directories('../include')

executable('coinflip', coinflip_sources,
  dependencies: coinflip_deps,
  include_directories : incdir,
  install: true,
)

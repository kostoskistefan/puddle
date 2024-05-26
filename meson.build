project(
  'puddle',
  'c',
  version: '1.0.0',
  license: 'MIT',
  default_options: [
    'warning_level=3',
  ],
)

install_headers('include/puddle.h')
puddle_include_directories = include_directories('include')

puddle_dependencies = [
]

puddle_sources = [
  'source/puddle.c',
]

puddle_library = library(
  'puddle',
  puddle_sources,
  dependencies: puddle_dependencies,
  include_directories: puddle_include_directories,
  install: true,
)

puddle_dep = declare_dependency(
  include_directories: puddle_include_directories, 
  link_with: puddle_library,
)

pkg = import('pkgconfig')
pkg.generate(puddle_library)

puddle_test_executable = executable(
  'puddle', 
  'test/main.c', 
  dependencies: puddle_dep
)

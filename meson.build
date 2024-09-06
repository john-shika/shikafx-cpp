project('shikafx', ['c', 'cpp'], version: '1.0.0', meson_version: '>= 1.3.2')

c_args = []

cpp_std = 'c++20'
cpp_args = []
if get_option('buildtype') == 'debug'
  c_args += ['-DDEBUG=1']
  cpp_args += ['-DDEBUG=1']
endif

library_type = 'shared'

# Source files
c_shikafx_ext_sources = files('src/shikafx-ext/__ccode__/preload.c')
shikafx_ext_sources = files('src/shikafx-ext/preload.cpp')
shikafx_sources = files('main.cpp')

# Define dependencies
c_shikafx_ext = library('c-shikafx-ext', c_shikafx_ext_sources,
                        c_args: c_args)

shikafx_ext = library('shikafx-ext', shikafx_ext_sources,
                      link_with: [c_shikafx_ext], 
                      cpp_args: cpp_args)

# Define executable
executable('shikafx', shikafx_sources,
           link_with: [c_shikafx_ext, shikafx_ext],
           cpp_args: cpp_args)

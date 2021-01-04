# SConstruct
from glob import glob

sources = glob("transbrl_cli/*.c")
sources += glob("transbrl_cli/external/md4c/*.c")
sources += glob("transbrl_cli/external/liblouis/*.c")
sources += glob("transbrl_cli/md2brl/*.c")
sources += glob("transbrl_cli/md2brl/callbacks/*.c")
sources += glob("transbrl_cli/utils/*.c")

include_paths = [
    'transbrl_cli/md2brl',
    'transbrl_cli/md2brl/callbacks',
    'transbrl_cli/utils',
    'transbrl_cli/external',
    'transbrl_cli/external/md4c',
    'transbrl_cli/external/liblouis'
]

env = Environment()
transbrl_cli = Program(
    target='transbrl_cli',
    source=sources,
    CPPPATH=include_paths
)
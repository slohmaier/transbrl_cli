# transbrl_cli
transbrl_cli translates markdown files to brf-format ready to print.

Base on these libraries:
- liblouis http://liblouis.org/
- md4c https://github.com/mity/md4c
(local version of the libraries in repository)

# Build System
None at the moment I use XCode C console application.

# State of the project
## Features
convert markdown to brf

## TODO list
- ~~basic feature to  convert markdown to brf~~
- split by height and add page numbers
- support all tags from md4c
- what to do with pictures? braille-graphics conversion like ASCII-ART.

## Suppoerted Blocks
- MD_BLOCK_DOC
- ~~MD_BLOCK_QUOTE~~
- ~~MD_BLOCK_UL~~
- ~~MD_BLOCK_OL~~
- ~~MD_BLOCK_LI~~
- ~~MD_BLOCK_HR~~
- MD_BLOCK_H
- ~~MD_BLOCK_CODE~~
- ~~MD_BLOCK_HTML~~
- MD_BLOCK_P
- ~~MD_BLOCK_TABLE~~
- ~~MD_BLOCK_THEAD~~

## Features for the 
DOCX Support with Braille-Font with DuckX https://github.com/amiremohamadi/DuckX .

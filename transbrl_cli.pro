TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += transbrl_cli/external/liblouis
INCLUDEPATH += transbrl_cli/external/md4c
INCLUDEPATH += transbrl_cli
INCLUDEPATH += transbrl_cli/uitls
INCLUDEPATH += transbrl_cli/md2brl
INCLUDEPATH += transbrl_cli/md2brl/callbacks

SOURCES += \
        transbrl_cli/external/liblouis/commonTranslationFunctions.c \
        transbrl_cli/external/liblouis/compileTranslationTable.c \
        transbrl_cli/external/liblouis/logging.c \
        transbrl_cli/external/liblouis/lou_backTranslateString.c \
        transbrl_cli/external/liblouis/lou_translateString.c \
        transbrl_cli/external/liblouis/metadata.c \
        transbrl_cli/external/liblouis/pattern.c \
        transbrl_cli/external/liblouis/utils.c \
        transbrl_cli/external/md4c/entity.c \
        transbrl_cli/external/md4c/md4c.c \
        transbrl_cli/main.c \
        transbrl_cli/main_check.c \
        transbrl_cli/main_output.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_debug_log.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_enter_block.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_enter_span.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_leave_block.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_leave_block_h.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_leave_block_p.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_leave_span.c \
        transbrl_cli/md2brl/callbacks/md2brlcb_text.c \
        transbrl_cli/md2brl/md2brl.c \
        transbrl_cli/md2brl/md2brl_addoutput.c \
        transbrl_cli/md2brl/md2brl_parser.c \
        transbrl_cli/md2brl/md2brl_trans.c \
        transbrl_cli/utils/bool.c \
        transbrl_cli/utils/insert_newlines.c \
        transbrl_cli/utils/md4c_enu2string.c \
        transbrl_cli/utils/outputbuffer.c \
        transbrl_cli/utils/readfile.c \
        transbrl_cli/utils/set_loupath.c \
        transbrl_cli/utils/writefile.c

HEADERS += \
    transbrl_cli/external/getopt-windows.h \
    transbrl_cli/external/liblouis/config.h \
    transbrl_cli/external/liblouis/internal.h \
    transbrl_cli/external/liblouis/liblouis.h \
    transbrl_cli/external/md4c/entity.h \
    transbrl_cli/external/md4c/md4c.h \
    transbrl_cli/main_check.h \
    transbrl_cli/main_output.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_debug_log.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_enter_block.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_enter_span.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_leave_block.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_leave_block_h.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_leave_block_p.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_leave_span.h \
    transbrl_cli/md2brl/callbacks/md2brlcb_text.h \
    transbrl_cli/md2brl/md2brl.h \
    transbrl_cli/md2brl/md2brl_addoutput.h \
    transbrl_cli/md2brl/md2brl_parser.h \
    transbrl_cli/md2brl/md2brl_trans.h \
    transbrl_cli/utils/bool.h \
    transbrl_cli/utils/insert_newlines.h \
    transbrl_cli/utils/md4c_enu2string.h \
    transbrl_cli/utils/outputbuffer.h \
    transbrl_cli/utils/readfile.h \
    transbrl_cli/utils/set_loupath.h \
    transbrl_cli/utils/writefile.h

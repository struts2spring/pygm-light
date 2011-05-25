# coding: UTF-8

#   Copyright (c) 2011, Konstantin Yegupov
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without modification,
#   are permitted provided that the following conditions are met:
#
#       * Redistributions of source code must retain the above copyright notice,
#         this list of conditions and the following disclaimer.
#
#       * Redistributions in binary form must reproduce the above copyright notice,
#         this list of conditions and the following disclaimer in the documentation
#         and/or other materials provided with the distribution.
#
#       * The name of the author may not be used to endorse or promote products
#         derived from this software without specific prior written permission. 
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
#   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
#   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

importable_headers = """
image.h
magick.h
error.h
constitute.h
resize.h
delegate.h
effect.h
enhance.h
pixel_cache.h
blob.h
attribute.h
""".strip().splitlines()

import ctypesgencore
import ctypesgencore.messages as msgs
import tempfile, os.path, shutil

class Dummy:
    pass

options = Dummy()
for k,v in ctypesgencore.options.default_values.items():
    options.__dict__[k] = v

options.include_search_paths = ["gm_headers/"]
options.libraries = ["GraphicsMagick"]
options.other_headers = []

# patching headers
to_insert = """
#include <stdarg.h>
#include <stdio.h>
#include "magick/magick_config.h"
#include "magick/forward.h"
#include "magick/common.h"
#include "magick/magick_types.h"
#include "magick/error.h"
"""
options.headers = []
tmpdir = tempfile.mkdtemp()
for h in importable_headers:
    tmpname = os.path.join(tmpdir, h)
    text = open("gm_headers/magick/"+h, "rt").read()
    text = text.replace("#endif", "#endif "+to_insert, 1)
    tmpfile = open(tmpname, "wt")
    tmpfile.write(text)
    tmpfile.close()
    options.headers.append(tmpname)

# Step 1: Parse
descriptions=ctypesgencore.parser.parse(options.headers,options)

# Step 2: Process
ctypesgencore.processor.process(descriptions,options)

# Step 3: Print
ctypesgencore.printer.WrapperPrinter(os.path.join("..", "gm_wrap.py"),options,descriptions)

msgs.status_message("Wrapping complete.")

shutil.rmtree(tmpdir)
    

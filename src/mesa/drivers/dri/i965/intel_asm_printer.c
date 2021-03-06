/*
 * Copyright © 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "brw_cfg.h"
#include "intel_asm_printer.h"
#include "program/prog_print.h"
#include "program/prog_instruction.h"

void
dump_assembly(void *assembly, int num_annotations, struct annotation *annotation,
              struct brw_context *brw, const struct gl_program *prog,
              disassemble_func disassemble)
{
   const char *last_annotation_string = NULL;
   const void *last_annotation_ir = NULL;

   for (int i = 0; i < num_annotations; i++) {
      int start_offset = annotation[i].offset;
      int end_offset = annotation[i + 1].offset;

      if (annotation[i].block_start) {
         fprintf(stderr, "   START B%d", annotation[i].block_start->block_num);
         foreach_list_typed(struct bblock_link, predecessor_link, link,
                            &annotation[i].block_start->parents) {
            struct bblock_t *predecessor_block = predecessor_link->block;
            fprintf(stderr, " <-B%d", predecessor_block->block_num);
         }
         fprintf(stderr, "\n");
      }

      if (last_annotation_ir != annotation[i].ir) {
         last_annotation_ir = annotation[i].ir;
         if (last_annotation_ir) {
            fprintf(stderr, "   ");
            if (!prog->Instructions)
               fprint_ir(stderr, annotation[i].ir);
            else {
               const struct prog_instruction *pi =
                  (const struct prog_instruction *)annotation[i].ir;
               fprintf(stderr, "%d: ",
                       (int)(pi - prog->Instructions));
               _mesa_fprint_instruction_opt(stderr,
                                            pi,
                                            0, PROG_PRINT_DEBUG, NULL);
            }
            fprintf(stderr, "\n");
         }
      }

      if (last_annotation_string != annotation[i].annotation) {
         last_annotation_string = annotation[i].annotation;
         if (last_annotation_string)
            fprintf(stderr, "   %s\n", last_annotation_string);
      }

      disassemble(brw, assembly, start_offset, end_offset, stderr);

      if (annotation[i].block_end) {
         fprintf(stderr, "   END B%d", annotation[i].block_end->block_num);
         foreach_list_typed(struct bblock_link, successor_link, link,
                            &annotation[i].block_end->children) {
            struct bblock_t *successor_block = successor_link->block;
            fprintf(stderr, " ->B%d", successor_block->block_num);
         }
         fprintf(stderr, "\n");
      }
   }
   fprintf(stderr, "\n");
}

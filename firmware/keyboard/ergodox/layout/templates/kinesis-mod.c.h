/* ----------------------------------------------------------------------------
 * Copyright (c) 2013 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (see "doc/licenses/MIT.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

/**                                                                 description
 * A layout with the home layer adapted from the default Kinesis layout.  The
 * position of the symbol keys on the function layer was (roughly) taken from
 * the Arensito layout.
 *
 * Implements the "layout" section of '.../firmware/keyboard.h'
 *
 * The template key prefix is `T_`, with the rest of the name indicating the
 * key's position in the QWERTY layout.
 *
 * TODO:
 * - do i have the arrow keys in the wrong place? grr.  need to check.  the
 *   goal here is to emulate the kinesis, lol.
 */


#ifndef ERGODOX_FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__TEMPLATES__KINESIS_MOD__C__H
#define ERGODOX_FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__TEMPLATES__KINESIS_MOD__C__H
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


#include "../common/definitions.h"


// ----------------------------------------------------------------------------
// matrix control
// ----------------------------------------------------------------------------

#include "../common/exec_key.c.h"


// ----------------------------------------------------------------------------
// LED control
// ----------------------------------------------------------------------------

void kb__led__logical_on(char led) {
    switch(led) {
        case 'N': kb__led__on(1); break;  // numlock
        case 'C': kb__led__on(2); break;  // capslock
        case 'S': kb__led__on(3); break;  // scroll lock
        case 'O':                 break;  // compose
        case 'K':                 break;  // kana
    };
}

void kb__led__logical_off(char led) {
    switch(led) {
        case 'N': kb__led__off(1); break;  // numlock
        case 'C': kb__led__off(2); break;  // capslock
        case 'S': kb__led__off(3); break;  // scroll lock
        case 'O':                  break;  // compose
        case 'K':                  break;  // kana
    };
}


// ----------------------------------------------------------------------------
// keys
// ----------------------------------------------------------------------------

#include "../common/keys.c.h"

KEYS__LAYER__NUM_PUSH(10, 3);
KEYS__LAYER__NUM_POP(10);
void P(m_arrowL)(void) { KF(type_string)( PSTR("->") ); }
void R(m_arrowL)(void) {}
void P(m_sep)(void) { KF(type_string)( PSTR("::") ); }
void R(m_sep)(void) {}
void P(m_fatcomma)(void) { KF(type_string)( PSTR("=>") ); }
void R(m_fatcomma)(void) {}
void keys__press__m_copy(void) {
    usb__kb__set_key(true, KEYBOARD__LeftControl);
    usb__kb__set_key(true, KEYBOARD__c_C);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftControl);
    usb__kb__set_key(false, KEYBOARD__c_C);
}
void R(m_copy)(void) {}
void keys__press__m_paste(void) {
    usb__kb__set_key(true, KEYBOARD__LeftControl);
    usb__kb__set_key(true, KEYBOARD__v_V);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftControl);
    usb__kb__set_key(false, KEYBOARD__v_V);
}
void R(m_paste)(void) {}
void keys__press__m_word(void) {
    usb__kb__set_key(true, KEYBOARD__LeftControl);
    usb__kb__set_key(true, KEYBOARD__RightArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftControl);
    usb__kb__set_key(false, KEYBOARD__RightArrow);
}
void R(m_word)(void) {}
void keys__press__m_bword(void) {
    usb__kb__set_key(true, KEYBOARD__LeftControl);
    usb__kb__set_key(true, KEYBOARD__LeftArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftControl);
    usb__kb__set_key(false, KEYBOARD__LeftArrow);
}
void R(m_bword)(void) {}
void keys__press__m_undo(void) {
    usb__kb__set_key(true, KEYBOARD__LeftControl);
    usb__kb__set_key(true, KEYBOARD__z_Z);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftControl);
    usb__kb__set_key(false, KEYBOARD__z_Z);
}
void R(m_undo)(void) {}
void P(m_aries)(void) { KF(type_string)( PSTR("♈") ); }
void R(m_aries)(void) {}

// ----------------------------------------------------------------------------
// layout
// ----------------------------------------------------------------------------

#include "../common/matrix.h"


static _layout_t _layout = {

// ............................................................................

    MATRIX_LAYER(  // layer 0 : default
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
     tilde,        exclam,        amp,        pipe,        at,        asterisk,        esc,
   tab,        q,        w,        e,        r,        t,  lpupo1l1,
     ctrlL,        a,        s,        d,        f,        g,
  shiftL,        z,        x,        c,        v,        b, transp,
   grave,    quote, guiL, arrowL,    arrowR,
                                                               altL,     transp,
                                                       nop,      nop,     transp,
                                                        space,     enter,      guiL,
// right hand ..... ......... ......... ......... ......... ......... .........
               esc,        bkslash,        braceL,        braceR,        parenL,     parenR,    equal,
             lpupo1l1,        y,        u,        i,        o,        p,    dash,
                           h,        j,        k,        l,  semicol,    quote,
          transp,        n,        m,    comma,   period,    slash,   shiftR,
                                   arrowU,      arrowD,      brktL,      brktL,     altL,
    volUp,    mute,
   volDown,      nop,      nop,
   guiL,    del,    bs  ),

// ............................................................................

    MATRIX_LAYER(  // layer 1 : function and symbol keys
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
   transp,       1,       2,       3,       4,       5,       transp,
  transp,   transp,   transp,   transp,   transp,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,   transp,
  transp,  transp,      transp,   transp,   transp,  transp,   transp,
  transp,   transp,   transp,   transp,  transp,
                                                              transp,   transp,
                                                    transp,   transp,   transp,
                                                    transp,   transp,   transp,
// right hand ..... ......... ......... ......... ......... ......... .........
            transp,       6,       7,       8,      9,      0,      transp,
            transp,   transp,   transp,   transp,   transp,  transp,   transp,
                      transp,   transp,   transp,   transp,   transp,   transp,
            transp,   transp,   transp,   transp,   transp,   transp,   transp,
                                transp,   transp,   transp,   transp,   transp,
  transp,   transp,
  transp,   transp,   transp,
  transp,   transp,   transp  ),

// ............................................................................

    MATRIX_LAYER(  // layer 2 : numpad
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
  transp,   transp,   transp,   transp,   transp,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,
                                                              transp,   transp,
                                                    transp,   transp,   transp,
                                                    transp,   transp,   transp,
// right hand ..... ......... ......... ......... ......... ......... .........
            transp,   transp,      transp,      transp,      transp,    transp,   transp,
            transp,   transp,      transp,      transp,      transp,    transp,   transp,
                      transp,      transp,      transp,      transp,    transp,   transp,
            transp,   transp,      transp,      transp,      transp,    transp,   transp,
                                   transp,      transp,      transp,    transp,   transp,
  transp,   transp,
  transp,   transp,   transp,
  transp,   transp,   transp  ),

// ............................................................................
};


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#endif  // ERGODOX_FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__TEMPLATES__KINESIS_MOD__C__H


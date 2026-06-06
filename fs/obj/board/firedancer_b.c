

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name("火邪殿--魔性碑", ({ "Firedancer's Board", "board" }) );
        set("location", "/u/f/firedancer/workroom");
        set("board_id", "firedancer_b");
        set("long",
"▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏
▕▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏▏
▕▕                          火神舞的留言版          copy from wizard_j.c  ▏▏
▕▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏▏
▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" );
        setup();
        set("capacity", 30);

}

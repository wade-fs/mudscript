//coldblade's board
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name("留言板",({ "board" }) );
        set("location", "/u/c/coldblade/workroom.c");
        set("board_id", "coldblade_b");
        set("long","\n\t紀錄用\n");
        setup();
        set("capacity", 300);
}

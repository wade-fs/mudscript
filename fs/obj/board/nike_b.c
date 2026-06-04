#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
    set_name(HIY + "東山" + HIC + "再起" + HIW + "版" + NOR, ({"nike board","board"}) );
    set("location", "/u/n/nike/workroom.c");
    set("board_id", "nike_b");
    set("long", "不用浪費時間寫long喇...\n" ) ;
    setup();
    set("capacity", 100);
}

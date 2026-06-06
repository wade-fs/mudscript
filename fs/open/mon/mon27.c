inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "雪中小徑");
        set ("long", @LONG
前方的小路依舊，刺骨的寒風迎面而來，細細的白雪輕輕地覆蓋
了整條小徑，一般的草木已經不復見，只剩極少數耐寒的小草連遮帶
掩的躲在石縫中，其生命力之旺盛，由此可見。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "westup"      : __DIR__"mon28",
        "eastdown"    : __DIR__"mon26",

]));
        setup();
}


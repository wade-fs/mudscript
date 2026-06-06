 inherit ROOM;
#include <ansi.h>
#include <room.h>

void create ()
{
        set("short",YEL"檀間"NOR);
        set("long", @LONG
通過一扇門簾，走進來便聞到一股濃郁的檀香，顯然是上等檀香
聞起來令人精神清爽；門簾的位置在於整個房間的西南角落，坐東朝
西，北、東、南三方均放置了兩張長背軟墊之椅，兩張椅子之間均有
一張小凳子，約致腰際，而整個房間正中央空無一物，除了一席鮮紅
色的地毯外．．．
LONG);
        set("exits", ([ 
"south":"/open/main/room/sp/room",
]));
        set("objects",([
__DIR__"npc/woman01":1,
]));
        create_door("south","木門","north",DOOR_CLOSED);
setup();
}



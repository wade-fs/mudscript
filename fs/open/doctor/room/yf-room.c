#include <ansi.h>
inherit ROOM;

void create ()
{
    set ("short", RED"閉關室"NOR);
    set ("long", @LONG
這裡似乎是一間不小的房間，雖然是烏漆媽黑的，但還感覺得出
空間還算頗為空曠的，但這裡陰森森的氣氛，令你感到一陣陣毛骨悚
然，忽然從你後方傳來微弱的腳步聲，使你幾乎要嚇破膽了...
LONG);

    set("objects", ([
         "/open/doctor/npc/yunfon" : 1,
]));
    set("light_up", 1);
    setup();
}


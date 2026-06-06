#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
set("short","秘密之間");
          set("long",@LONG
在你眼前的就是傳說中黑白兩道所尊崇的寰宇一奇---歐陽不空，據說他以經消失在武林
沒想到居然在此又出現了！或許他是為了黑血神針才到此處吧。
因為在傳說中，他與飄花宮有很深的淵源，然而黑血神針本來就是出自於飄花宮。


LONG);
        set("exits", ([
"up":__DIR__"sdr2.c",
        ]) );
set("objects",([
    "/open/killer/npc/oyang.c":1,
]));
set("light_up",1);
        setup();
}

//by chilice casey
#include <ansi.h>
inherit ROOM;

void create ()
{
   set  ("short", HIR"火山口"NOR);
  set ("long", @LONG
一股熱流往你襲來，四週的高溫令人口乾舌燥
心煩不已，傳聞在火山中，有一個終年冰霜不化之
地，而唯一的路便是由此跳入。

LONG);

  set("exits", ([ /* sizeof() == 2 */
"jump"  : __DIR__"c23",
"west"  : __DIR__"m2",
]));
   set("outdoors", "/open/main");


  set("light_up", 1);

 
  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="jump" && (int)me->query("combat_exp") < 400000 ) {
write(HIR"你承受不了火山口的高溫而退了回來 !!\n"NOR);
write(RANK_D->query_respect(me)+"看來你的能力還不足以躍入火山口!\n");
        return 0;
}
return 1;
return ::valid_leave(me,dir);
}




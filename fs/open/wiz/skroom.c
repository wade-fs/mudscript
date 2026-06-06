inherit ROOM;
#include <ansi.h>

void create ()
{
set ("short", "SWY 技能特功\發言處");
	set( "build", 84 );
  set ("long", @LONG

這裡就是讓ppl發表skills和funcs的地方，請注意下列規則:
1.不要亂批評skills and funcs
2.有意見請提出那不合理
3.post後靜待我來處理，不必post催趕
4.以後再加

LONG);

        set("light_up",1);
set("no_kill",1);
set("no_fight",1);
  set("exits", ([ /* sizeof() == 2 */
"east" : "/open/common/room/inn",
]));

  setup();
call_other("/obj/board/skillswy_b","???");
}


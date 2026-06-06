// Room: /open/main/room/d3.c

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "沙漠");
	set( "build", 108 );
  set ("long", @LONG
這兒是一望無際的撒哈拉沙漠，西邊有一棟建築依勢而建，
從這兒看過去, 卻看不到入口, 不知它的門是在哪一邊?
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"d10",
  "east" : __DIR__"d4",
  "west" : "/open/love/room/room.c",
]));
  set("outdoors", "/open/main");

  setup();
}
int valid_leave(object me,string dir)
{

if (me==this_player() && dir == "up")
if ( me->query("combat_exp") < 2400000)
     return notify_fail("修羅道需要兩百萬以上的玩者才能進入\n");
     return :: valid_leave(me, dir);
        {
tell_object(me,HIM + "你感受到修羅道的力場影響，全身顫抖了一下。\n" + NOR);
/*message("mud",HIW + "

                    一道閃光竄出 ...


" + HIC + "狂想的壯士"+HIY+me->query("name")+HIC + "進入了前往天界的修羅之道
 為了自身的磨練，前往未知之途 ..

" + NOR,me);
*/
        }
if ( me->query("combat_exp") < 2000000)
     return notify_fail("修羅道需要兩百萬以上的玩者才能進入\n");
     return :: valid_leave(me, dir);
}

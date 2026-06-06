#include "/open/open.h"
inherit ROOM;
void create ()
{
set ("short", "魔刀休息室");
set ("long", @LONG

這個房間是給魔刀的所有弟子休息，打屁，喝茶，聊天的地方。
也可以把 EQ 存放於此，除了魔刀的人，其他人都沒辦法進來。
魔刀弟子還能在此打(secret)，能直接去平南城喔。
魔刀絕世傳人在此打(fly)，能直接去神秘老人那喔。

魔刀不成文規定 :

1. pkla 嚴禁穿 bell_ring
2. horse 不能改 name (如真的要改要跟自己 name 一樣)
3. 要壓好自身的殺氣
4. 不要亂用 order
5. 如有解到邪靈 pkla 時請不要用 毀器型
6. pkla 禁拿屠龍刀

以上六點請大家遵守  如有違反者將"處死一次" 

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"secret",
]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_kill", 1);
  set("no_fight", 1);
  setup();
call_other("/obj/board/evblade_b","???");
}
 void init()
{
  add_action("do_secret","secret");
  add_action("do_fly","fly");
}
int do_secret()
{
  object me;
  me = this_player();
  if(me->query("class")!="blademan")
 return notify_fail("只有魔刀門徒能用。\n");
 me->move("/open/ping/room/road3");
  return 1;
}
int do_fly()
{
object me;
me=this_player();
if(me->query("family/family_name")!="魔刀莫測")
return notify_fail("只有魔刀絕世傳人能用。\n");
me->move("/open/gblade/room/room26.c");
return 1;
}

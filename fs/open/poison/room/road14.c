// Room: /open/poison/room/road14
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "大門");
  set ("long", @LONG
這裡是冥蠱魔教的大門口，大門兩旁有一對栩栩如生的
石獅，兩眼直視前方，一副傲視群雄的神態，門旁一棵垂柳
隨風飄曳。
LONG);
  set("light_up",1);
  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/poison/room/road15",
  "southdown" : "/open/poison/room/road13",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/guard" : 1,
]));
  setup();
}

int valid_leave(object me, string dir)
{
   int number;
   number  = me->query_temp("poison_nopass");
   if (dir=="north" &&
       present("guard",this_object()) &&
       me->query("family/family_name") != "冥蠱魔教" )
   {
	if (number > 1) {
          me->set_temp("poison_nopass",number+1);
          return notify_fail(HIC"冥蠱守衛喝道﹕有我在，休想進入。\n"NOR);
        }
        if (me->query_temp("weapon")) {
          me->set_temp("poison_nopass",number+1);
	  message_vision(HIC"冥蠱守衛怒道﹕不準帶武器入內，$N想到此滋事呀。\n"NOR,me);
          return notify_fail(HIC"冥蠱守衛喝道﹕這裡可能會不歡迎你。\n"NOR);
        }
   }
   return ::valid_leave(me ,dir);
}

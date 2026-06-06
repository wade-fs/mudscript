inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "狂想空間懲罰發表處");
	set( "build", 136 );
  set ("long", @LONG
    違反狂想玩家(player_rules)或巫師(wiz_rules)規定的人::
 都在這裏公佈給大家知道，請大家多多遵守規定不要違反規定，違反者
 第一次通常都從輕處理,再犯則依照規定處理,若你認同狂想空間請遵守
 規定。否則請前往您認同的Mud,狂想的原則是公平、公正, 不管是玩家
 或是巫師請照規定行事.........
LONG);

  set("no_fight", 1);
  set("light_up", 1);
  set("no_kill", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north"  :  __DIR__"bug_room",
  "south" : "/open/common/room/inn.c",
]));

  setup();
call_other("/obj/board/fskill_b.c","???");
}
void init()
{
add_action("post_array","post");
}
int post_array(string str)
{
 object ob;
 ob=this_player();
 if(!wizardp(ob))
  return notify_fail("這裏只有巫師能發表文章。\n");
}

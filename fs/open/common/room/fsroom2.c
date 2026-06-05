inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short", "狂想空間懲罰發表處");
set ("long", @LONG
    違反狂想玩家(player_rules)或巫師(wiz_rules)規定的人::
 都在這裏公佈給大家知道，請大家多多遵守規定不要違反規定，違反者
 第一次通常都從輕處理,再犯則依照規定處理,若你認同狂想空間請遵守
 規定。否則請前往您認同的Mud,狂想的原則是公平、公正, 不管是玩家
 或是巫師請照規定行事.........
LONG);
set("light_up",1);
set("no_kill",1);
set("no_fight",1);
set("exits", ([ /* sizeof() == 2 */
"south" : "/open/common/room/fsroom2",
]));
  setup();
call_other("/obj/board/fskill_b","???");
}


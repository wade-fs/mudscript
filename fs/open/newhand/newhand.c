#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "狂想空間新手入門房間");
  set ("long", @LONG
歡迎來到『狂想空間』的世界,狂想空間的時空背景是古代中國的Mud
  以下的區域是分門別類介紹狂想空間(FS),可以讓您能加速了解及快速上手!!!
  東方(east)的區域------>簡單的新手入門(newbie)及介紹狂想的門派!!
  北方(north)的區域----->狂想空間指令(cmds)快速上手
  西方(west)的區域------>狂想空間幫派制度(clans)的說明!!
  南方(south)的區域----->玩狂想空間時的一些小秘技!!!
  西北方(northwest)的區域---->狂想空間的特色!!!
  東南方(southeast)的區域---->狂想空間創站到現在的歷史!!!!
  進入(enter)的區域--->正式進入狂想空間!!!   
  ------------------------------------------------------------------------
  建議您可以先從北方-->東方-->西方-->南方-->西北方-->東南方來看所有的區域!!!
  ps:進去房間時只要打n e w s nw se (就代表進去了方向了!!不用打英文全名!!!)
  ps:你若想更了解這裏你可以打help,會有完整的說明文件!!!

LONG);

  set("light_up", 1);
  set("no_kill", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 7 */
  "northwest" : __DIR__"newhand5-1",
  "southeast" : __DIR__"newhand6-1",
  "south" : __DIR__"newhand4-1",
  "west" : __DIR__"newhand3-1.c",
  "east" : __DIR__"newhand2-1.c",
  "enter" : "/open/common/room/inn",
  "north" : __DIR__"newhand1-1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pin" : 1,
]));
  set("build", 36);

  setup();
}

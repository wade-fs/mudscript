#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "駐地大門");
  set ("long", @LONG
此處為進入守備隊駐紮地的門口，門口守衛來回巡邏，避免閒雜
人等進入。大門旁邊有一條往東的小通道，不知道這一條通道會通道
哪邊。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 3 */
    "north" : __DIR__"camp02.c",
    "east" : __DIR__"j14.c",
    "south" : __DIR__"j10.c",
  ]));
//需注意就是門一定要在兩邊同時定義
//  set("need_key/east",1);       //設定door的房向及key哦 不設定此行就無須鑰匙
  create_door("north","門","south",DOOR_CLOSED);
  set("item_desc", ([ /* sizeof() == 1 */
    "north" : (: look_door, "west" :),
  ]));
  setup();
}

void reset()
{
  close_door("north"); //只需要方向 close_door("方向");
  ::reset();
}

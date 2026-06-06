// Room: /open/capital/room/r69.c
// rewrite by wade 1/5/1996
// 改成用 heart_beat 的方式

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "考場");
	set( "build", 19 );
  set ("long", @LONG
這裡是考場﹐每年的科舉考試都是由這裡舉行﹐在這裡﹐常常可以
看到一群為求功名而苦讀數十年的讀書人們﹐個個都想在考試中得取功
名,有一張佈告(board)公告著.

LONG);

 set("item_desc", ([
  "board" : "一加入官府,就必須與原幫派脫離所有關係,你可要考慮清楚!!!\n",
    ]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/capital/room/r71",
]));

  set("objects", ([ /* sizeof() == 1 */
	CAPITAL_NPC"test_officer"	:	1,
]));

  set("no_kill", 1);
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}

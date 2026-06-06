// Room: /open/capital/room/r17.c

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG
遠遠看到左前方有座富麗堂皇的房子，大概是宰相府了。雲洋大街
上住了三個撼動天下的人，一是當今宰相，二是戰功彪炳的鎮遠侯，三是
全國首富乾通天，皇上行事也都會先徵詢他們意見，可見他們對王朝的影
響力。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/capital/room/r51",
  "north" : "/open/capital/room/r14",
]));

  set("gopath", "south");

  setup();
}

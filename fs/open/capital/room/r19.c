// Room: /open/capital/room/r19.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
  set ("long", @LONG
往北走可通往三大城門之一的威西門，不過你得通過嚴密的重重檢
查才可通關。東邊的街道便是所謂的雲洋大街, 唯有一些權大勢大的人
物才住的起這條街。
    由於這裡鄰近皇城，附近又多是達官貴人們的住所，所以禁衛軍的
巡邏也特別嚴密，別想在這兒鬧事，那對你絕對沒好處。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r20",
  "north" : __DIR__"r18",
  "east" : __DIR__"r54",
]));

  set("gopath", "north");

  setup();
}

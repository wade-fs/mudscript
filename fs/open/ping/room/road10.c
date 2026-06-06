// Room: /open/ping/room/road10
inherit ROOM;

void create ()
{
  set ("short", "石板大橋");
  set ("long", @LONG
這裡就是軍營的入口了,本城的大軍就在橋的那一方,你看到
橋上插滿軍旗,在風中灑灑飄揚著,士兵們進進出出, 似乎正在忙
著.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/soldier" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"soldier2",
  "north" : __DIR__"road6",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}

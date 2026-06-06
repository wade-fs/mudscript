// Room: /open/ping/room/soldier1.c
inherit ROOM;

void create ()
{
  set ("short", "軍營便門");
  set ("long", @LONG
你的西方,就是本朝在平南城的駐軍所在,這裡是軍營的側門
,你看到伙夫們正忙著搬運東西.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/soldier" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"soldier2.c",
  "east" : __DIR__"road9",
]));

  setup();
}

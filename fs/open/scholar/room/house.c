// Room: /open/scholar/room/backm1.c
inherit ROOM;

void create ()
{
  set ("short", "小屋");
  set ("long", @LONG
你一進小屋裡，就看到傳說中的陳平睡在小屋的中央，但
整個小屋裡也沒有什麼東西，就放著一張床而已。
LONG);
 set("objects",([
        "/open/scholar/magic_square/npc/man1":1,
        ]));

  set("no_kill", 1);
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"backm5",
]));

  setup();
}

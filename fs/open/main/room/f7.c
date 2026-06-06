// Room: /open/main/room/F7.c

inherit ROOM;

void create ()
{
  set ("short", "密林");
  set ("long", @LONG
這裡是一片濃密的森林，高大的樹木，交織的枝葉，竟將
天日給遮敝了，你仔細聆聽，似忽有野獸正在咆嘯，你想你最
好離開這裡.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/main/room/r6",
  "east" : "/open/main/room/F8",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  setup();
}

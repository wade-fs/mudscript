// Room: /open/main/room/f10.c

inherit ROOM;

void create ()
{
  set ("short", "林中小徑");
  set ("long", @LONG
這裡是一片廣大的原始森林，西邊林中有一條不知名的
小徑，地上則盡是一些凌亂的落葉，路邊長滿了雜草。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room0",
  "west" : __DIR__"road3",
  "east" : "/open/main/room/f10",
]));
  set("outdoors", "/open/main");

  setup();
}

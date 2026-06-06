// Room: /open/poison/room/room14
inherit ROOM;

void create ()
{
  set ("short", "林間小屋");
  set ("long", @LONG
這是一間小小的木屋，看起來破破爛爛的，根本不是一
個安適的住處，仔細一看居然有人在此居住，讓你感到十分
驚訝，如此簡陋的小屋，究竟是何人能安命於此呢？
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road4",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/woman" : 1,
]));

  setup();
}

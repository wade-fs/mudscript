// Room: /open/poison/room/road18
inherit ROOM;

void create ()
{
  set ("short", "內庭");
  set ("long", @LONG
這裡是一個小庭院，院旁栽種了幾棵垂柳，垂柳隨風起
舞，悠閒的飄曳著，庭內插了數根梅花樁，平常教徒們便是
在此勤練武功掌法和輕功，由樁上光滑的磨痕可見教徒們平
日練功之勤。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/trainee" : 3,
]));
  set("outdoors", "/open/poison");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"garden1",
  "west" : __DIR__"room11",
  "east" : __DIR__"road16",
]));

  setup();
}

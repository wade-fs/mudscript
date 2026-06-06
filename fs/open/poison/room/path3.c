// Room: /open/poison/room/path3
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
進入此密道，你覺得這裡濕氣很重，陰森森的氣氛讓你
感到非常難受，你恨不得早點離開這裡，角落有一道向下的
樓梯。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/poison/room/room5",
  "westdown" : "/open/poison/room/path4",
]));

  setup();
}

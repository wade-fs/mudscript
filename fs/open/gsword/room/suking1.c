// Room: /u/s/smore/room/suking/suking1.c

inherit ROOM;

void create ()
{
  set ("short", "府衙入口");
  set ("long", @LONG
一踏入這裡，很少有人能不被這氣勢無比雄偉的入口給震
攝住，高達九尺的大門，雕滿著一頭頭彷彿要破空而去的龍紋
，龍的眼睛更冷冷的凝視著你，使你心中不由得升起一股又是
害怕又是尊敬的感覺.
LONG);

  set("light_up", 1);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room/suking3",
  "out" : "/open/gsword/room/suking",
]));

  setup();
}

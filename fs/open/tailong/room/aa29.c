inherit ROOM;

void create ()
{
  set ("short", "北院走廊");
  set ("long", @LONG
走到這裡,發現北院的圍牆沿著山壁向北延伸出去,同時也有一條通
往北方的岔路,向北望去好像有一座高塔,不知道裡面有什麼東西。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aa28",
  "north" : __DIR__"aa55",
  "east" : __DIR__"aa30",
]));

  setup();
  replace_program(ROOM);
}

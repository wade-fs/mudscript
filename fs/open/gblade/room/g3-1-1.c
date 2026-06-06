inherit ROOM;

void create ()
{
  set ("short", "綴錦閣");
  set ("long", @LONG

一走進房內，你竟然分辨不出隔間，原來四面皆是雕空玲瓏木板，或流雲
百蝠，或歲寒三友，或山水人物，或翎毛花卉，或集錦，或博古，各種花
樣，皆是名手雕刻，五彩銷金嵌玉的。一隔一隔，或貯書，或設鼎，或安
置筆硯。其隔式樣，或圓，或方，或連環半壁。且滿牆皆是隨依古董玩器
之形樞成的槽子，如琴，劍，懸瓶之類，俱懸於壁，卻都與壁相平的。房
間一角有一先生正在教授兩童子詩書。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"g3-1.c",
  "north" : __DIR__"g3-1-2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/foolboy" : 1,
]));
  set("light_up", 1);

  setup();
}

inherit ROOM;

void create ()
{
  set ("short", "花園");
  set ("long", @LONG
這裡是天龍寺中的花園,這裡不但栽滿了各式各樣的珍奇花草,
還種植了很多的稀有茶樹,像是"霓裳羽衣、步步生蓮、十八學士"
,這大概也是因為大理的茶花甲於天下,在旁邊好像有一座高塔,過
去看看吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"aa55",
  "northwest" : __DIR__"aa57",
]));

  setup();
  replace_program(ROOM);
}

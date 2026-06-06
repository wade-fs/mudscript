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

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"aa59",
  "northeast" : __DIR__"aa58",
  "south" : __DIR__"aa29",
  "northwest" : __DIR__"aa56",
]));
}

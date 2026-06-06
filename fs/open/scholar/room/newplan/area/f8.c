// Room: /u/s/sueplan/newplan/area/f8.c
inherit ROOM;

void create ()
{
  set ("short", "雲山下");
  set ("long", @LONG
行走至此，漸覺山風涼意徐來，一陣清心快意襲上心間，不覺滿懷舒暢
，抬頭望去，前方山頭雲氣繚繞，朦朧翳入蒼穹，不辨何謂山嶺天際，猶如
飛雪漫漫凝結不散，故名為『雲山』；羊腸小路蜿蜒南去，雜花生樹無名幽
香淡淡，樹間山路盤巒而升(climb up)。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f7",
]));

  setup();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string str)
{
object me;
me=this_player();
if(str=="up")
  {
  write("你一步一步爬了上去!!\n");
  me->move(__DIR__"f9.c");
  return 1;
  }
}

inherit ROOM;

void create ()
{
  set ("short", "大雄寶殿");
  set ("long", @LONG
這裡就是天龍寺的正殿--大雄寶殿,挑高八米八,全部的柱子都是
用上好的大理石材所製,柱子上有栩栩如生的雕刻,而樑木是用南部高
上特產的紅檜所製成,富麗堂皇。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"aa39",
  "east" : __DIR__"aa37",
  "west" : __DIR__"aa35",
]));
}

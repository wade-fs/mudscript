// Room: /open/capital/room/rich
inherit ROOM;

void create ()
{
  set ("short", "乾通天宅前庭院");
  set ("long", @LONG
乾通天的庭院, 到處綠草茵茵, 花團處處, 但似乎乾通天十分喜愛
茶花的樣子, 因為大部分的花種均是名貴的茶花, 「十八學士」、「美
人倚欄嬌」、、「花開落地」、「三色菱」等等。據京城裡的居民說,
設計這個花園的工匠還是乾通天遠從雲南聘請來的, 難怪有如此南疆風
味。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rich1",
  "south" : __DIR__"r62",
]));

  setup();
}

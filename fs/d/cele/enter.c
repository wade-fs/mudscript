inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 水煙閣大門");
  set ("long", @LONG
    這裡是水煙閣的正門﹐一股沁人心脾的檀香使你精神為之一振﹐正
門共分三進﹐全部都是上等的檀木雕成﹐最裡的門上懸著一塊匾額﹐上
面龍飛鳳舞地寫著幾個大字﹐可是你全然看不出到底是什麼字。

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "north"  : "/d/cele/guildhall",
  "south": "/d/cele/frontyard",
]));


  setup();
}

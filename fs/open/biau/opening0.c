// Room: /open/su/room/triggerman.c

inherit ROOM;

void create()
{
	set("short", "鑣局大門");
	set("long", @LONG
    這裏是武威鑣局,蜀中第一把交椅,尤其是瓢把子趙鼎天,曾經靠著一路狂魔鞭法
    掃平蜀川三十六寨,討回鑣物,使江湖中人震攝不已.....只要把物品交給武威鑣
    局,就可以高枕無憂....如今在蜀中城裏的這棟大宅,已經成為不可或缺的路標,
    看到它,就知道是蜀中城的東方了.....門上的扁額寫著
    『    武       威        鑣       局    』
    龍飛鳳舞的四字,據說是金刀門王進所題,東邊就是大門了,西邊是蜀中的中心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//"west" : "/open/su/room/suroad5_10",
  "east" : __DIR__"opening1",
]));

	setup();
}

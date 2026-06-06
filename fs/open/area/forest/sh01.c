inherit ROOM;

void create()
{
	set("short","防風林 小路");
	set("long",@LONG
一條彎曲的鄉間小道，路邊週遭圍繞的是一片綠油油的森林和坑
洞積水所成的小湖泊，行走於這附近的人相當的稀少，湖泊旁的雜草
叢生，不過卻都不長，顯然有人在維護著這片綠地。
LONG);
	set("exits",([
"south":__DIR__"c01",
"north":__DIR__"sh02",
]));
	set("outdoors",1);
	setup();
}

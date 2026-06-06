inherit ROOM;

void create()
{
	set("short","野人村  小道");
	set("long",@LONG
一條羊腸小徑筆直的南北貫穿著森林，往北進入黑森林，往南的
盡頭有一個小村落。
LONG);
	set("exits",([
"north":__DIR__"e01",
"south":__DIR__"e03",
]));
	set("outdoors",1);
	setup();
}

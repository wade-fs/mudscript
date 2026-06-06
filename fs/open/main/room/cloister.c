// Room: /open/main/room/cloister.c

inherit ROOM;

void create()
{
	set("valid_startroom",1);
	set("short", "玉磯道觀");
	set("light_up",1);
	set("long", @LONG
	這座道觀供奉著太上老君，老君雕像前的香爐冒著
	縷縷的清煙，似有似無的檀香飄散在空氣中，令人
	倍覺舒暢。


LONG
	);
	set("no_fight",1);
	set("no_magic",1);
	set("objects",([
	"/daemon/class/taoist/master" : 1,
		]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"M14",
]));

	setup();

}

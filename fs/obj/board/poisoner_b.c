// poisoner_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("冥蠱邪石",({"stone","board"}));
	set("location","/open/poison/room/room1");
	set("board_id","poisoner_b");
	set("long","這是魔教徒所用的留言石。\n");
	setup();
	set("capacity", 30);
}

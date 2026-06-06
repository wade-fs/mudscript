inherit ROOM;
void create() {
	set( "short", "妖刀塚" );
	set( "owner", "hild" );
	set( "object", ([
		"file10"   : "/open/quests/snake/npc/obj/snake-key-2",
		"amount2"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file6"    : "/open/gsword/obj1/bpball",
		"amount9"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/gsword/obj1/bpball",
		"file5"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file9"    : "/open/gsword/obj1/bpball",
		"file3"    : "/open/gsword/obj1/bpball",
		"file4"    : "/open/gsword/obj1/bpball",
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"amount3"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/quests/snake/npc/obj/snake-key-2",
	]) );
	set( "light_up", 1 );
	set( "build", 10019 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room167",
		"west"      : "/open/clan/sky-wu-chi/room/room243.c",
	]) );
	set( "long", @LONG
當你來到這裡，一股涼意直撲你而來，你看了看四周，原來這裡是
傳說中葬刀的地方。在裡面可以看到一把失去靈氣的刀，那把失去靈氣
的刀，但是仔細一看，這把刀是千年難得一見的好刀，只是失去靈氣而
已，想要這把刀恢復本身原有的狀態只有以身弒血並把本身的命交給刀
，才有可能得到這把真真的妖刀，但是有多少人能以身弒血。而得到這
把絕世妖刀。
LONG);
	setup();
	replace_program(ROOM);
}

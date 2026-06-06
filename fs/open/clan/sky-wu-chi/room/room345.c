inherit ROOM;
void create() {
	set( "short", "夏雷書房" );
	set( "owner", "roboo" );
	set( "object", ([
		"amount4"  : 1,
		"amount8"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/wind-rain/obj/sun_red_cloth",
		"file9"    : "/open/tendo/obj/chaosbelt",
		"file2"    : "/daemon/class/fighter/armband",
		"amount7"  : 1,
		"file10"   : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10011 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room69",
		"north"     : "/open/clan/sky-wu-chi/room/room347",
	]) );
	set( "long", @LONG
    在這裡的牆上的書架上擺滿了數不盡的各式書籍，只要是市面上 
有的任何書籍，這裡一本不缺，除此之外，一些早已絕版找不到著古 
書籍也能在這兒找到。夏雷讓他的兩個人物在此唸書，盼望他們兩  
能博學多識，而那兩個因一人擅文一人擅武，所讀之書亦彼此不同 
，不過看他們專注認真的神情，將來勢必能有一番作為。 
LONG);
	setup();
	replace_program(ROOM);
}

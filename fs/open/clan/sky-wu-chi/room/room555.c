inherit ROOM;
void create() {
	set( "short", "書房" );
	set( "object", ([
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount6"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10027 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room558",
		"west"      : "/open/clan/sky-wu-chi/room/room556.c",
		"south"     : "/open/clan/sky-wu-chi/room/room554",
		"north"     : "/open/clan/sky-wu-chi/room/room557.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在這一個寬敞的房間內.
中間擺著一張大型的桌子,桌上散亂著一些書跟文件.
你想出桌上的書和文件來找出一些端倪
可是你發現上面寫的東西你都看不懂.
你開始佩服這裡的主人了.
但是他的人在哪裡ㄋ.他到底就什麼.
這些事情都是你很好奇的事物.
LONG);
	setup();
	replace_program(ROOM);
}

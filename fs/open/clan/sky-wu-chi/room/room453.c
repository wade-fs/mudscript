inherit ROOM;
void create() {
	set( "short", "ξ天音小築ξ" );
	set( "owner", "oboe" );
	set( "object", ([
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"amount10" : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount5"  : 12,
		"file2"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/prayer/obj/lin-head",
		"amount6"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"amount3"  : 36,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount9"  : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 31,
	]) );
	set( "build", 10450 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"down"      : "/open/clan/sky-wu-chi/room/room479.c",
		"north"     : "/open/clan/sky-wu-chi/room/room469.c",
	]) );
	set( "long", @LONG
你走進了一棟十分典雅而古樸的小樓，空氣中瀰漫著一股淡淡的芳香，
陣陣輕柔的樂音不斷的傳來，雖然隱隱約約卻又清晰可聞，讓你不由自主的
感到心情十分的平靜。房間中雅致的擺設及隨處可見的小巧物品，都顯示出
這裡的主人應該是個清新脫俗的不凡女子。你留意到四邊的牆壁都是由色彩
斑瀾的各色水晶組合而成，美麗中又帶有神秘的感覺，但是當你伸手想碰觸
這些光彩奪目的水晶時，一股強大的能量從水晶傳來，想必這個謎樣的女子
也是有著非常傳奇的故事吧！

LONG);
	setup();
	replace_program(ROOM);
}

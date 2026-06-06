inherit ROOM;
void create() {
	set( "short", "$HIR$$HBGRN$盤古秘辛$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armor",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount10" : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10376 );
	set( "exits", ([
		"gk"        : "/open/clan/time-limit/room/room176",
		"out"       : "/open/clan/time-limit/room/room178",
	]) );
	set( "long", @LONG
你來到森林的最深處,有顆巨石擋在你的面前,仔細一看,上頭還刻有不知名的圖案,由圖
案上可看到動物及武器,推測可能是遠古時代的文字吧,足見這棵巨石的歷史,忽然有個
圖案吸引你的目光,那是個鬼王對著一群小鬼大笑,小鬼們貢上物品,數一數共有13個,到
底是什麼寶物讓鬼王如此開心,你心裡也跟著癢癢的

LONG);
	setup();
	replace_program(ROOM);
}

inherit ROOM;
void create() {
	set( "short", "翠柳橋" );
	set( "owner", "airwalk" );
	set( "object", ([
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 9,
		"amount8"  : 91,
		"amount6"  : 91,
		"amount9"  : 140,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file9"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "build", 10045 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room9.c",
	]) );
	set( "long", @LONG

　　走到這裡，只見佳木成蔭，奇花爛漫，一灣清流，從奇花深處瀉
於石隙之下。清溪瀉玉，石磴穿雲；白石為欄，環抱池沼。橋北邊不
遠處有一個瀑布，從山壁上猶如一條白練般垂了下來﹐瀑布兩旁的石
壁十分陡峭﹐高度和山澗旁的松林相差了近三、四十丈。

LONG);
	setup();
	replace_program(ROOM);
}

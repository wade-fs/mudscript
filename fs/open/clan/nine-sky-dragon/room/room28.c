inherit ROOM;
void create() {
	set( "short", "任逍遙" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 42,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount3"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 11091 );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room25",
	]) );
	set( "long", @LONG
讓我悲也好 讓我悔也好 
恨蒼天妳都不明瞭 讓我苦也好
讓我累也好 隨風飄飄天地任逍遙

英雄不怕出身太淡薄 有志氣高哪天也驕傲
就為一個緣字情難了 一生一世想捕捕不牢
相愛深深天都看不到 恩怨世世代代心頭燒
有愛有心不能活到老 叫我怎能忘記妳的好

讓我悲也好 讓我悔也好
恨蒼天妳都不明瞭 讓我苦也好
讓我累也好 讓我天天看到她的笑
讓我醉也好 讓我睡也好
把愁情煩事都忘了 讓我對也好
讓我錯也好 隨風飄飄天地任逍遙

LONG);
	setup();
	replace_program(ROOM);
}

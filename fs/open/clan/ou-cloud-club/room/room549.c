inherit ROOM;
void create() {
	set( "short", "StarTrek-ENG" );
	set( "owner", "ctx" );
	set( "object", ([
		"file3"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"file4"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file6"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
	]) );
	set( "build", 16596 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room545",
	]) );
	set( "long", @LONG
StarTrek的第五部作品，ENG即船艦Enterprise的縮寫,這部
作品有別於1到4代作品是由時間接續下來的範例,ENG反到由聯邦
成立草創時間左右時，由當時最新的船艦Enterprise號作為外交
任務與當時最先接觸的外星人及其科技作為交流所發生的故事，
這部作品大約講述時間為22世紀聯邦草創成立左右，而這部作品
同樣的也尚未在台灣撥出過。

LONG);
	setup();
	replace_program(ROOM);
}

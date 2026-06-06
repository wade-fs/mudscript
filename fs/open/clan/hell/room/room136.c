inherit ROOM;
void create() {
	set( "short", "'$HIY$$HBGRN$美國瘋$NOR$" );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/gsword/obj/dragon-sword",
		"file6"    : "/open/capital/obj/4-1",
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/snow/obj/dragon-sword",
	]) );
	set( "owner", "blur" );
	set( "light_up", 1 );
	set( "build", 11043 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room93.c",
		"west"      : "/open/clan/hell/room/room49.c",
		"east"      : "/open/clan/hell/room/room44",
	]) );
	set( "long", @LONG
$HIG$$HBBLU$
最近好友憋四...馬的BB CALL把上了一個恐龍後..就天天騎龍..
你鬼咧...
死恐龍很爽咧...

凸 -,-
凸 @,@
凸 >,Q

悶死了.....何時大頭蛋才能開砲ㄋㄟ...??!!
還是到車庫彈彈我的小吉他好了....
看看是不是也出一張低傳真的專輯...就能跟十八豆子一樣..嘿嘿

$NOR$
LONG);
	setup();
	replace_program(ROOM);
}

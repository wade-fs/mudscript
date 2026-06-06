inherit ROOM;
void create() {
	set( "short", "明天的微笑" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/dark-spirit",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount10" : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "build", 10057 );
	set( "exits", ([
		"east"      : "/open/clan/nine-sky-dragon/room/room25",
	]) );
	set( "long", @LONG
有時候 走過一段話 心才會清澈也才會看到 關於愛
延伸的滋味 不要去發酵仔細思考 愛過的他和流過的淚
都會是珍貴的 記號 忘不忘 不重要 只要準備好明天的微笑
無論在天涯海角 相信愛總會千方百計把你尋找
可能他終於明瞭你有多好 想回頭朝你奔跑
只要準備好明天的微笑 當你想擁抱 愛總會出其不意靜靜悄悄來到
也許在生命裡的某個轉角 另一個人會給你默契相同微笑

LONG);
	setup();
	replace_program(ROOM);
}

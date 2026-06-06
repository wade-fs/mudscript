inherit ROOM;
void create() {
	set( "short", "九曲橋" );
	set( "owner", "jsa" );
	set( "object", ([
		"amount3"  : 37,
		"file3"    : "/open/doctor/pill/gnd_pill",
		"amount2"  : 3,
		"file2"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10035 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room186",
		"east"      : "/open/clan/sky-wu-chi/room/room200.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
九曲橋向東西蜿蜒而去，兩旁盛開的花朵羼著雨絲
散著淡淡清香；花形嫣雅色澤豔麗，氣味芬芳四時綻放
，襯著蔥鬱的枝葉，翠蔓紅蘤終年熱鬧，待風度花叢濃
郁馥盈，真讓人疑似無日不春時，有『出淤泥而不染』
之美稱的荷花看起來是那麼的高雅聖潔，橋下的魚兒不
時的探出頭來，這裡真是個不錯的地方。
LONG);
	setup();
	replace_program(ROOM);
}

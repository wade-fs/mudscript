inherit ROOM;
void create() {
	set( "short", "狂龍居" );
	set( "owner", "xman" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 19,
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"file9"    : "/open/killer/headkill/obj/i_dag",
		"file3"    : "/open/dancer/obj/yuawaist",
		"file1"    : "/open/killer/obj/s_pill",
		"amount6"  : 300,
		"file10"   : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/killer/obj/bellstar",
		"file8"    : "/open/ping/obj/gold_hand",
		"amount1"  : 790,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 7,
		"file5"    : "/open/doctor/pill/sky_pill",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 1,
	]) );
	set( "build", 10409 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room94",
	]) );
	set( "long", @LONG
高聳入雲的百丈瀑布分流傾瀉，沖刷得石壁閃耀生輝，流
水匯聚成河，滋養著河邊林木和足獸飛鳥。清新的空氣、飄落
的花瓣、蟲鳥的鳴叫聲，更令人覺的神清氣爽。瀑布後方有一
山洞，佈置雖簡單樸實，但並不失其主人的氣勢，反而能相得
益彰，更是突顯其霸氣，而在一旁的千年寒冰上刻有字，正是
「絕塵崖狂龍居」
LONG);
	setup();
	replace_program(ROOM);
}

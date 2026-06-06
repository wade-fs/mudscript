inherit ROOM;
void create() {
	set( "short", "$HIC$世外$HIM$書香$NOR$" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount1"  : 1,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 113,
		"amount6"  : 433,
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"amount5"  : 1,
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file9"    : "/open/firedancer/npc/eq/r_hands",
		"amount4"  : 1,
		"file3"    : "/open/wu/obj/figring",
		"amount2"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/firedancer/npc/eq/r_boots",
		"amount7"  : 144,
		"amount3"  : 1,
	]) );
	set( "owner", "agilent" );
	set( "build", 10497 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room251",
		"west"      : "/open/clan/time-limit/room/room200",
	]) );
	set( "long", @LONG
世外書香是儒生聚集的地方,只見儒生們人手一冊,充滿濃濃的書卷氣,前方有幅巨大的
孔子畫像,儒家以孔子為領導,數千年來儒家思想以君王為尊,深受皇帝採用,這也是儒生
們最感到驕傲的地方,世外書香的入口是天筆峰,有隻巨大的毛筆,要開啟世外書香必須
將毛筆沾上墨汁,巨大的毛筆要怎麼移動,這可就要考驗智慧了

LONG);
	setup();
	replace_program(ROOM);
}

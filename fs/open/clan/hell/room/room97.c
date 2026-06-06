inherit ROOM;
void create() {
	set( "short", "$HIR$大雄寶殿$NOR$" );
	set( "owner", "vatsu" );
	set( "object", ([
		"file1"    : "/obj/stone/suipian",
		"file5"    : "/open/mogi/dragon/obj/key",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 12042 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room98",
	]) );
	set( "long", @LONG
大雄寶殿內有長廊貫通，左右大石柱林立對稱，千座燭臺照的四周燈火通
    明，大殿塑像羅列，分作兩組，中央是數十尊佛和菩薩，以居於殿心的千
    手ぉ每隻手的形狀和所持法器無有相同
    ，令人生出神通廣大，法力無邊的感覺，分列四周的是五百羅漢，朝向中
    央的塑像，形成縱橫相通的巷道。讓人見了一時不由呼吸頓止感受到在宗
    教的徵召下，建寺者那種嬋思竭力的熱忱和精神。


LONG);
	setup();
	replace_program(ROOM);
}

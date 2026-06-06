inherit ROOM;
void create() {
	set( "short", "$HIY$盤古聖地$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file7"    : "/open/fire-hole/obj/p-pill",
		"file8"    : "/open/fire-hole/obj/b-pill",
		"file5"    : "/open/mon/obj/mon-pill",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 43,
		"amount5"  : 262,
		"amount10" : 22,
		"amount3"  : 122,
		"amount2"  : 76,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 29,
		"amount4"  : 142,
		"file9"    : "/open/fire-hole/obj/k-pill",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 16,
		"amount8"  : 39,
		"amount6"  : 57,
		"file4"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 11604 );
	set( "outdoors", "/open/clan/orient" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room50",
	]) );
	set( "long", @LONG
盤古聖祖，自號「元始天王」；在宇宙混沌未開、陰陽未分、天地日月尚未形成之前，
吸收太元之氣而自然生成的就是盤古聖祖。浮游於宇宙中，不久之後歷經四劫，
宇宙中形成了類似大蓋子的天。據說一劫是四十一萬年，又經九十九萬億九十九萬年，
天下的下方有類似水的東西，接著從水中產生元蟲。盤古真人居住在天的中央
，喝著天地精氣，永生不絕的生存著。後與從水中誕生的太元聖母通氣結精，
生下了天皇，接著生下了扶桑大帝、西王母，後又天皇生地皇，地皇生人皇，然後出現了許多聖人和真人。
LONG);
	setup();
	replace_program(ROOM);
}

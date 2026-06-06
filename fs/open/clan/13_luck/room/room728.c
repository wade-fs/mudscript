inherit ROOM;
void create() {
	set( "short", "Ω$HIC$天問居$NOR$Ω " );
	set( "owner", "ananba" );
	set( "outdoors", "/open/clan/13_luck" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 403,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 107,
		"amount1"  : 22,
		"amount2"  : 602,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 1,
		"amount3"  : 858,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"amount9"  : 165,
		"file9"    : "/open/killer/obj/atman_pill",
	]) );
	set( "build", 10120 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room744",
		"west"      : "/open/clan/13_luck/room/room580",
	]) );
	set( "long", @LONG
在未踏入此房間時就傳來陣陣清香，令人神清氣爽，彷彿在吸入的同時內力
也增進不了少。進門後方才恍然大悟，只見$HIR$檀木製的儲物櫃$NOR$上擺著一盆盛開的
$HIW$茉莉$NOR$。屋主隱居在一個喚作$HIG$新竹$NOR$的$HIM$世外桃源$NOR$，早已不問世事。再看竹桌上一盆散
著$HIY$奇異紫光$NOR$的盆栽，莫非是江湖上已風流出了名的紫雲飛心愛的植物－$MAG$紫籐蘭$NOR$。
說到紫堂主，不是別人，正是十三吉祥最放浪不羈的竹塹堂扛霸子。這盆花竟會
出現在天問居的屋中，險示這兩位武林人士有著不可告人的秘密。這天問就是$HIY$九陽
天刀$NOR$創招人$HIB$橫姓刀客$NOR$的第二刀僮，也是所有刀僮中對天刀刀意悟道最深之人，據
傳聞已達至$HIW$『隨心隨意隨六感，刀心刀意刀入神』$NOR$的境界。
LONG);
	setup();
	replace_program(ROOM);
}

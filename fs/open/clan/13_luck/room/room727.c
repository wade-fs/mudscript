inherit ROOM;
void create() {
	set( "short", "Ψ$HIG$竹塹堂$NOR$堂主行宮Ψ " );
	set( "object", ([
		"file9"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount5"  : 78,
		"amount3"  : 283,
		"file8"    : "/open/ping/obj/poison_pill",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/killer/obj/atman_pill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 2,
		"amount8"  : 300,
		"amount6"  : 1,
		"amount10" : 105,
		"amount1"  : 212,
		"amount2"  : 55,
		"amount4"  : 12,
		"file6"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"file4"    : "/obj/stone/suipian",
		"file2"    : "/obj/stone/powder",
		"amount7"  : 300,
		"file7"    : "/open/mon/obj/mon-pill",
	]) );
	set( "build", 10048 );
	set( "owner", "markw" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room743",
		"east"      : "/open/clan/13_luck/room/room742.c",
		"south"     : "/open/clan/13_luck/room/room580.c",
	]) );
	set( "long", @LONG
本堂主便是在武林轟動一時的$MAG$紫雲飛$NOR$紫堂主，生於1979年$HIR$1$NOR$月$HIR$21$NOR$日，血型$HIR$B$NOR$，
水瓶座，才藝鋼琴。興趣：聽曲、國際標準舞、看戲以及與朋友聚會聊天。中原
$HIY$龍圖閣$HIW$心靈$NOR$翰林學士，曾入$HIC$水$YEL$陸$HIR$御林軍$NOR$服役，準備再鑽研成為$HIC$一代宗師$NOR$。其為人
處世之道則就是－$HIG$「沒有原則」$NOR$。而待人處世之道則為－$HIY$「別人對你好是撿到，
你對別人好是應該」$NOR$。常聽坊間流傳一句話：$HIR$「真愛不需要解釋」$NOR$，但本堂主卻
有不同的見解－$HIM$『真愛以不居泥任何形式的方法來詮釋』$NOR$，與幫內眾弟兄共勉之。
LONG);
	setup();
	replace_program(ROOM);
}

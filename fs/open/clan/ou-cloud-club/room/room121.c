inherit ROOM;
void create() {
	set( "short", "$HIW$盾工程學研究所$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"file2"    : "/obj/stone/jiao",
		"amount10" : 1,
		"file9"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"file10"   : "/open/capital/guard/gring",
		"file3"    : "/obj/gift/lingzhi",
		"amount2"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10168 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room331",
		"enter"     : "/open/clan/ou-cloud-club/room/room168",
		"east"      : "/open/clan/ou-cloud-club/room/room329.c",
		"down"      : "/open/clan/ou-cloud-club/room/room330.c",
		"west"      : "/open/clan/ou-cloud-club/room/room328.c",
		"north"     : "/open/clan/ou-cloud-club/room/room87.c",
	]) );
	set( "long", @LONG

    這裡是傲雲山莊內的冶金重地,專司研究各種強化金屬的工程技術,以
期望能造出具有頂級防禦能力的盾牌,尤其最近新引入了西方近代科學技術
,將電磁氣引入盾牌之內,使其產生抵抗抗物理攻擊之外的額外抗性,盾工程
技術的進步於是得以一日千里,傳聞某位傲雲山莊的高層人物正計劃將自己
武學中的絕技灌注於防具之內,期望能達到化解一切劫難的功效,也因此,本
研所的人員也日夜不停的研究各種匹配,融合的方式,以早日作出更優良的
防具...

LONG);
	setup();
	replace_program(ROOM);
}

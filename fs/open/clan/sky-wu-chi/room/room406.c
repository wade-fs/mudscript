inherit ROOM;
void create() {
	set( "short", "青龍上將軍府" );
	set( "owner", "poiiiiop" );
	set( "object", ([
		"file4"    : "/open/gblade/obj/sa-head",
		"file8"    : "/open/clan/area/home/hae_bag",
		"amount4"  : 1,
		"file2"    : "/obj/stone/powder",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount3"  : 37,
		"amount10" : 1,
		"amount2"  : 369,
		"file1"    : "/obj/stone/jiao",
		"file10"   : "/open/mon/obj/ghost-legging",
		"file3"    : "/obj/stone/suipian",
		"amount1"  : 12,
		"file9"    : "/open/gsword/obj/dragon-sword",
	]) );
	set( "build", 10017 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room407",
	]) );
	set( "long", @LONG
千古誰堪與伯仲，少時落梅殤，今越紅塵亦悠悠
一朝白首望平生，不見東風殘，只見九州萬里行

    九月九日觀梅枝，三尺寒江泣血時。
    陰陽八卦通靈韻，風起雲湧事先知。
    丹青指點群雄影，七步天階舊相識。
    青龍已誓空山在，獨留星子應天池。

歷經無數生死戰場，被尊稱為『山之靈象』的青龍上將軍 - 東陵少主
LONG);
	setup();
	replace_program(ROOM);
}

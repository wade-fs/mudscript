inherit ROOM;
void create() {
	set( "short", "$HIW$霸$HIG$刀$HIC$界$NOR$" );
	set( "owner", "alucard" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/capital/obj/4-3",
		"amount6"  : 92,
		"file6"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/ghost-hole/obj/fire-spirit",
		"amount3"  : 3287,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/area/fortress/npc/obj/boots03",
		"file5"    : "/obj/gift/xiandan",
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10141 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room398",
		"up"        : "/open/clan/ou-cloud-club/room/room154",
		"south"     : "/open/clan/ou-cloud-club/room/room87",
	]) );
	set( "long", @LONG

    甫踏進此地,便感覺到空氣中充滿著難以言諭的無匹刀氣,其中蘊含了 
氣吞天下的皇者霸氣,柔情似水的兒女情長,義薄雲天的捨己精神,以及,某 
種帶著一絲不捨的淡淡遺憾,這些盪人迴腸的豐富刀意,皆來自前面這座白 
淨矮牆上的刀,一把歷經無數生死激戰,在崩壞極限邊緣掙扎無數次的神器 
,相傳此刀主人,多年前曾單刀赴會,已一己之力,斬盡焚天火王麾下近九成 
的精英部隊,使得魔界勢力產生變化,讓焚天火王染指人界的計劃被迫延宕 
數年,然近年來武林風平浪靜,故其行事低調,甚少走動於江湖...         
                                                                 

LONG);
	setup();
	replace_program(ROOM);
}

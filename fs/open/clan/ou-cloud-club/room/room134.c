inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣" );
	set( "owner", "left" );
	set( "item_desc", ([
		"風馳劍" : @ITEM
天涯舞劍塵的佩劍，象徵著劍皇的精神，充滿七分霸氣，三分聖氣。
ITEM,
	]) );
	set( "object", ([
		"file1"    : "/obj/gift/hobowdan",
		"file5"    : "/open/killer/obj/fire-knife",
		"file7"    : "/obj/gift/hobowdan",
		"amount9"  : 1,
		"amount5"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file3"    : "/obj/gift/hobowdan",
		"file2"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"file6"    : "/obj/gift/hobowdan",
		"file10"   : "/open/killer/obj/fire-knife",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10034 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room185.c",
		"west"      : "/open/clan/ou-cloud-club/room/room18.c",
	]) );
	set( "long", @LONG

     　   ╱　　　　 ●　   ∴     ╱   ∴                                          
 　╱　∴ ___∩_   　     ∴ ☆                                                 
 ☆　　  /\      \　　　                                                        
 　　　 /___\_____\　　　--- 百年世事空華裏 ---- 一片身心水月間 ---             
 　     ||'||  '' |                      
   ~~~~~ `` `` ` ` ``~~  --- 獨許萬山深密處 ---- 晝長趺坐掩松關 ---

LONG);
	setup();
	replace_program(ROOM);
}

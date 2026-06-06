inherit ROOM;
void create() {
	set( "short", "『$HIM$神隱閣$NOR$』" );
	set( "owner", "nescafe" );
	set( "object", ([
		"file2"    : "/open/capital/guard/gring",
		"amount1"  : 10,
		"file10"   : "/obj/stone/suipian",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount5"  : 22,
		"amount10" : 1,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/obj/stone/powder",
		"file8"    : "/daemon/class/blademan/obj/gold-blade",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/snow/obj/sky_lin_stone",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "build", 10012 );
	set( "exits", ([
		"north"     : "/open/clan/orient/room/room45.c",
	]) );
	set( "long", @LONG

                          
                    Ψ 殺盡‧無赦 Ψ 
Ψ 無限‧萬訣 Ψ～～             Ψ 雷殛‧狂閃 Ψ ～～
Ψ 弄雷‧龍吟 Ψ～～            Ψ 情變‧雲奭 Ψ ～～ 
Ψ 使風‧爆雷 Ψ～～             Ψ 岑溫‧鳳翔 Ψ ～～                   

LONG);
	setup();
	replace_program(ROOM);
}

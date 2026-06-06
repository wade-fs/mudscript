inherit ROOM;
void create() {
	set( "short", "欣的草藥房" );
	set( "object", ([
		"file9"    : "/open/killer/memory/static",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/soil-ball",
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"file4"    : "/open/magic-manor/obj/fire-ball",
		"amount10" : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount1"  : 9,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file5"    : "/open/magic-manor/obj/wood-ball",
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/obj/water-ball",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount8"  : 1,
	]) );
	set( "build", 10024 );
	set( "owner", "lts" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room399",
	]) );
	set( "long", @LONG
                                        
                ◥◣      ☆      ◢◤   
                ◢█████████◣          
                 ◢    煞血追魂     ◣                        
               ◢       煞血盟        ◣  
           ◥█◤██████████◥█◤
               █無無   ▏    ▏ 天唯█ 
               █為我   ▏    ▏ 地我█  
               █無無   ▏    ▏ 上煞█
               █我為   ▏    ▏ 下血█
               ▆       ▏    ▏     ▆
             ██████████████ 
            ▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆    

LONG);
	setup();
	replace_program(ROOM);
}

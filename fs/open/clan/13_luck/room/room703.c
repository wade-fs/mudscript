inherit ROOM;
void create() {
	set( "short", "二樓northwest" );
	set( "object", ([
		"amount6"  : 8,
		"file7"    : "/open/fire-hole/obj/g-pill",
		"amount7"  : 37,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 4,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 3,
	]) );
	set( "owner", "djlh" );
	set( "build", 10017 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room699.c",
		"east"      : "/open/clan/13_luck/room/room701",
	]) );
	set( "long", @LONG

         ▌       ██   ▌          ˍ▁▂▃▄▅▇伊是咱的寶貝▇▅▄▃▂▁ˍ   
         ▌     ███▎ ▌          一蕊花○生落地☆爸爸媽媽疼尚多○風那吹☆   
▄▄▄▄▄     ███▋  ▄▄▄▄▄▄愛甲被○吳通乎伊墜落黑暗地☆勿開耶花需要   
               ███▊              你我的關心○乎伊一片生長的土地☆手牽手○   
              ████▏             心連心☆咱站作伙○伊是咱的寶貝☆fcreper    
             ████▌              ＊　*╔═╮═══╦ ╭══════╯＊．*  
▄▄▄▄▄   ███▋    ▄▄▄▄▄▄ . ＊║  ║╭═╮║ ╠══════╯* . ． 
         ▌   ██▋     ▌           * . ╠═╮║  ║║ ║╭═════╮． ＊  
         ▌    █▋      ▌          ＊. *║  ║║  ║║ ║╠═╬═╬═║*  ．  
         ▌     █       ▌          . * .║═╯╰═╯╯ ╯╯  ╯  ╯  ╯＊ * . 

LONG);
	setup();
	replace_program(ROOM);
}

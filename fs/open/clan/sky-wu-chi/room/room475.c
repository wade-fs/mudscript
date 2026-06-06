inherit ROOM;
void create() {
	set( "short", "浪味仙家門外" );
	set( "object", ([
		"amount10" : 1,
		"amount8"  : 1,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"file1"    : "/open/killer/obj/k_ring",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/capital/guard/gring",
		"amount2"  : 2,
		"amount5"  : 1,
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file10"   : "/open/killer/obj/k_ring",
		"file6"    : "/open/port/obj/wolf_ring",
	]) );
	set( "build", 10105 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room472",
	]) );
	set( "long", @LONG
/＼              ／\
▕   ＼＿＿ˍˍˍ／ ▕
▕ ／￣    ◥██◤╲
∕                  ﹨    常常獨自一個人在深夜裡想著妳    
︳   /￣\    /￣\   ▕      想著我們過去的點點滴滴        
︳   ︳ZZ   ZZ  ︳  ▕        因為過去有太多太多美好的回憶
┼    \ˍ/    \ˍ/    ┼         總是在不知不覺中就回想起  
﹨ˍ      ●      ˍ∕            不管我們兩相隔多麼遠    
¯╲ˍ    ‧    ˍ／_               我依然思念著妳        
╭─◤¯¯¯￣◥◤﹨
（   ︳           /﹀﹀\◢█
（____︳  ▕ ／  ▕ .‧. █◤
\︿︿/ ︺︺︺＼●／  
LONG);
	setup();
	replace_program(ROOM);
}

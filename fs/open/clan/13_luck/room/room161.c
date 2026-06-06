inherit ROOM;
void create() {
	set( "short", "長廊" );
	set( "owner", "djlh" );
	set( "object", ([
		"amount9"  : 35,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 22,
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/killer/obj/atman_pill",
		"amount8"  : 1,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 73,
		"amount7"  : 24,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 45,
		"amount3"  : 39,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
	]) );
	set( "build", 11034 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room669",
		"north"     : "/open/clan/13_luck/room/room663.c",
		"east"      : "/open/clan/13_luck/room/room175.c",
	]) );
	set( "long", @LONG

  ▁▂▃▄▅▆▇█▇▆▅▄▃▂▁◇情非得已◇▁▂▃▄▅▆▇█▇▆▅▄▃▂▁      
◢     難以忘記初次見你　一雙迷人的眼睛  在我腦海裡　你的身影　揮散不去    ◣   
◥     握你的雙手感覺你的溫柔    真的有點透不過氣　你的天真　我想珍惜      ◤   
◢     看到你受委屈　我會傷心(看到你傷心　我會失意)                        ◣   
◥     只怕我自己會愛上你　不敢讓自己靠的太近   怕我沒什麼能夠給你　       ◤   
◢     愛你也需要很大的勇氣    只怕我自己會愛上你　也許有天會情不自禁      ◣   
◥     想念只讓自己苦了自己　  愛上你是我情非得已  愛上你是我情非得已      ◤   
◢     什麼原因　我竟然又會遇見你    我真的真的不願意　就這樣陷入愛的陷阱  ◣   
◥▁▂▃▄▅▆▇█▇▆▅▄▃▂▁  Forever    ▁▂▃▄▅▆▇█▇▆▅▄▃▂▁◤   
  
  
LONG);
	setup();
	replace_program(ROOM);
}

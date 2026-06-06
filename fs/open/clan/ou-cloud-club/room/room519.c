inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIW$觀$HIY$月$HIW$亭$NOR$" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount10" : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount3"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount9"  : 1,
	]) );
	set( "owner", "left" );
	set( "build", 12449 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room185",
	]) );
	set( "long", @LONG
    
              ▲    ▁▂▄▅▃▂▁    ‧ ●                                     
   ﹋   ﹋   ◢◣‧ .     ‧﹊‧﹊    ﹊﹊                                      
    ﹋ ﹋   ◢▇◣    .       ●●ˊ         好想要和妳一起看月亮               
     ﹋    ◢▇▇◣   ˍˍˍˊ█X◣ ˍ         靠在我肩上  情話慢慢講...        
              █    ╱╲︵\︵\︵\︵\︵╲                                    

LONG);
	setup();
	replace_program(ROOM);
}

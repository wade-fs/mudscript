inherit ROOM;
void create() {
	set( "short", "$HIM$級長$HIC$浴室$NOR$" );
	set( "owner", "fisi" );
	set( "object", ([
		"file5"    : "/obj/stone/suipian",
		"amount1"  : 320,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 4015,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 11,
		"file9"    : "/open/killer/memory/static",
		"amount4"  : 151,
		"amount10" : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/obj/stone/jiao",
		"amount2"  : 417,
		"amount9"  : 1,
		"file1"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/killer/obj/atman_pill",
		"file7"    : "/open/main/room/sp/stone",
		"amount7"  : 1,
		"amount3"  : 91,
	]) );
	set( "build", 10015 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room40",
	]) );
	set( "long", @LONG
級長是在五年級以上的學生選出兩名學生作為級長,每個學院都有兩名,
主要工作是維持學校秩序,而學校為了慰勉;級長,特地建造了級長
專用浴室,裡頭的水池大到像個游泳池,還有各式各樣的泡沫沐浴乳,
香味顏色各有不同,上方的美人魚畫像慵懶的搖搖尾巴,不過在這邊
洗澡要特別小心,因為愛哭鬼麥朵有時會跑來偷看級長洗澡

LONG);
	setup();
	replace_program(ROOM);
}

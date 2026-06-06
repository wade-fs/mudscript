inherit ROOM;
void create() {
	set( "short", "$BMAG$占卜學$BGRN$教室$NOR$" );
	set( "owner", "woodsword" );
	set( "object", ([
		"amount2"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10502 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room58",
	]) );
	set( "long", @LONG
教室裡瀰漫著薰香的味道,讓人昏昏欲睡,桌子上有顆巨大的水晶球,
具有先知能力的人可以從水晶球裡看到即將發生的事情,課桌上有著
喝完茶所剩下的茶葉,學生們利用這些茶葉來占卜,不過'西碧-崔老妮'
教授的教課功力似乎並不怎麼讓學生信服,她常常做一些虎頭蛇尾的預言,
讓人哭笑不得,她自稱是先知的玄孫女,同樣擁有預言的能力

LONG);
	setup();
	replace_program(ROOM);
}

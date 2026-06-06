inherit ROOM;
void create() {
	set( "short", "$RED$霍格$MAG$華茲$CYN$大門口$NOR$" );
	set( "owner", "woodsword" );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10010 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room9.c",
		"south"     : "/open/clan/time-limit/room/room7",
	]) );
	set( "long", @LONG
霍格華茲是座宏偉的城堡,由四個學院組成這個學校,
葛來分多-雷文克勞-赫夫帕夫-史萊哲林,
由於學校被施了驅除咒,只要靠近這裡的人就會想起什麼緊急的事情
要處理而馬上離開,也難怪這麼大的城堡居然都沒有被人發現,
另外學校還有一連串的防護措施,防止外人入侵,以保障學生的安全

LONG);
	setup();
	replace_program(ROOM);
}

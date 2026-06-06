inherit ROOM;
void create() {
	set( "short", "$HIW$ζ$HIR$血 齋$HIW$ζ$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/quests/snake/npc/obj/un_cloth",
		"amount3"  : 1,
		"file5"    : "/open/doctor/pill/sky_pill",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount10" : 6,
		"file8"    : "/open/quests/snake/npc/obj/snake_gem",
		"file4"    : "/open/quests/snake/npc/obj/helmet",
		"amount5"  : 8,
		"amount1"  : 1,
		"file10"   : "/open/doctor/pill/human_pill",
		"file2"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10002 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room263",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
初踏此地,你只覺一陣$HIC$涼意$NOR$捲捲而來,使你自覺的瑟縮起來.....
見山頭有一草蘆,但周圍包著濃濃$HIR$深紅色$NOR$的$HIR$山霾之氣$NOR$,分外詭異,
配合上了天上的$HIW$孤月$NOR$(Moon),使你更覺得格外的$HIG$陰氣森森$NOR$,好像
所有的$HIC$寒氣$NOR$都聚集到此地似的.你遠遠的看到一陣又一陣的$NIR$血紅$NOR$
的光線從草蘆之中$CYN$暴射出來$NOR$,其中似乎有個女人的身影在其中..
這番畫面引起你的好奇,你信步向前去查看,發現了一個女子正
拿著一把$HIB$長相怪異無比刀$NOR$,正嘗試提昇她的$HIR$殺力$NOR$...............
原來這就是$HIC$苹芃$NOR$(Bacchus)用來提昇內功的地方.看著$HIB$刀$NOR$發出的
陣陣$HIR$氣血紅光$NOR$,緩緩流入$HIC$苹芃$NOR$的身體,你不經覺得心驚肉跳,看
來今天又有不少的$HIW$生命$NOR$又喪失在她的手下了.
LONG);
	setup();
	replace_program(ROOM);
}

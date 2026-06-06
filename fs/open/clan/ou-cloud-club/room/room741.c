inherit ROOM;
void create() {
	set( "short", "朵麗雅的精神世界" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount5"  : 1,
		"file7"    : "/open/killer/obj/fire-knife",
		"amount2"  : 854,
		"amount10" : 1,
		"file9"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file6"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file2"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/quests/snake/npc/obj/snake-key-2",
		"amount7"  : 1,
		"amount1"  : 78,
		"amount3"  : 363,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount4"  : 415,
	]) );
	set( "build", 10178 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room83",
	]) );
	set( "long", @LONG
深深的漸漸的你進入朵麗雅的內心世界，揉揉眼睛看四周，這裡是一片
超乎現實的幻想世界：遠天的彩色月亮因為得了近視，所以帶著一副用貓尾
巴當鏡框的太陽眼鏡；漆黑的天空掛滿了一閃一閃的玻璃球，裡面裝著紅酒
蘋果牛奶和檸檬水；走一圈只要一個小時的星球上很多可愛的寶寶在跟你撒
嬌，藍色的熊寶寶趁你不注意偷親了你兩下，沙皮狗皮皮要求你咬一下他的
小腳腳，一隻比比寶寶拿著一只白金戒指套在土黃色尾巴上對你呵呵笑。銀
色的長笛披著披風在粉紅色的草原上走著，旁邊還跟著一盤咖哩飯，太陽已
經被南極的冰塊冰起來，聽說要去海邊的時候才會出來，一旁的黑色小鬧鐘
指針永遠指著晚上十二點，
LONG);
	setup();
	replace_program(ROOM);
}

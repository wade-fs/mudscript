inherit ROOM;
void create() {
	set( "short", "LEON 刀庫" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room736",
	]) );
	set( "owner", "tomorrow" );
	set( "object", ([
		"amount4"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file7"    : "/open/capital/obj/4-3",
		"amount8"  : 1,
		"file3"    : "/open/capital/obj/4-3",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file10"   : "/open/capital/obj/4-3",
		"file6"    : "/open/capital/obj/4-3",
		"amount2"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/capital/obj/4-3",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file1"    : "/open/capital/obj/4-3",
		"amount1"  : 1,
	]) );
	set( "build", 10021 );
	set( "long", @LONG
這就是魔刀的神器 妖刀村雨 只要有了妖刀 幾乎可以說是戰無
不勝 是魔刀客夢寐以求的神刀 世上排名可以說是數一數二 還
有一把傳說中的神秘魔刀 叫做不應 只要碰上不應 保證敵人叫
天 天不應 就可知道這把刀的凶猛程度了 不過在這邊似乎沒看
到不應 或許是太珍貴了 主人捨不得擺出來讓人參觀 或許是另
外藏在其他隱密的空間
LONG);
	setup();
	replace_program(ROOM);
}

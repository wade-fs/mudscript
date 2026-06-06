inherit ROOM;
void create() {
	set( "short", "龍王龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10165 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room590",
	]) );
	set( "long", @LONG
在打完六色光龍以後，才會出現的龍王，他的能力是混合了六色龍
的精華，只有達到武林神話級的玩家才有辦法輕鬆擊敗龍王，其龍元當
然也是十分珍貴，可以讓人不停將自身的真氣聚集，在適當的時機可以
一口氣放出，其威力可以超越自身十成以上的功力，是以小博大的神藥
，但是修為不夠的話，反而會傷害自己的身體，所以要有很強實力的人
才可服用。

LONG);
	setup();
	replace_program(ROOM);
}

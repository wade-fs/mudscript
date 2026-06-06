// Room : /open/clan/demon_castle/room/room7.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "ζ小南閉關室ζ" );
	set( "owner", "son" );
	set( "build", 10206 );
	set( "long", @LONG

    自FS於兩千零一年七月重開後，小南就下定決心要重振當年雄風
將在此閉關修練，直到提昇自己的基本內功修為到達無可匹敵境界。
待出關後，挑戰各門各派的英雄豪傑，誓在奪回天下武林盟主之位，
尋得天下間的屠龍刀倚天劍，方可號令天下，唯我獨尊....

LONG);
	set( "exits", ([ /* sizeof() == 1 */
		"enter"     : "/open/clan/demon_castle/room/room18",
		"north"     : "/open/clan/demon_castle/room/room5.c",
]) );
	set( "clan_room", "惡魔城" );
	setup();

	}

// Room : /open/clan/ou-cloud-club/room/room81.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$無限城$NOR$--$HIY$北方之怒$NOR$" );
	set( "owner", "del" );
	set( "object", ([
		"amount1"  : 1,
		"amount6"  : 3,
		"file6"    : "/obj/stone/jiao",
		"file2"    : "/obj/stone/powder",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount4"  : 19,
		"file4"    : "/obj/stone/suipian",
		"amount2"  : 109,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room314",
	]) );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
冰與火，光與闇，要如何將這種極端的力量結合，這正
是北方據點內魔導士及術士們研究的重點，在這裡你不時可
以聽到爆裂的聲音(偶而會傳來燒焦的味道)，別懷疑，他們
正在進行各種魔法合成以及化學試驗，堅固的建築以及外圍
綿密的魔法盾，加上大議會充分的授權，各項珍貴的知識正
在這裡萌芽滋長著。

LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}

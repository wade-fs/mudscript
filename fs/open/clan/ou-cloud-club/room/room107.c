// Room : /open/clan/ou-cloud-club/room/room107.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "build", 11457 );
	set( "cmkroom", 1 );
	set( "long", @LONG
一座廣大無垠的花園，四處陳列了許多尊高大的石像，        
原來此處是白家歷代帝皇的王陵，而每一尊石像，皆是歷任    
海虎武神在臨終前以最終力量以及完全境界強化保護的，所    
以才能保存千年之久，傳說第743代海虎武神-白冰焰就是在    
此領悟無敵的黑暗修羅道以及天武殺道等驚世絕學，而這更    
將冰焰引導進入磁場轉動的完全境界，但由於未能完全掌握    
最終力量帶來的強大反噬，非在生死關頭，冰焰不會輕易在    
人前展示這些傳說中的武學。

LONG);
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/room14.c",
		"west"      : "/open/clan/ou-cloud-club/room/room32",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "short", "磨刀坊" );
	set( "owner", "moblade" );
	set( "object", ([
		"amount1"  : 600,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 546,
		"file8"    : "/open/mon/obj/thousand-nectar",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 183,
		"amount2"  : 56,
		"amount8"  : 2,
		"file7"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/fire-hole/obj/k-pill",
		"file3"    : "/open/mon/obj/mon-pill",
		"amount6"  : 644,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 133,
		"amount7"  : 280,
	]) );
	set( "light_up", 1 );
	setup();

	}

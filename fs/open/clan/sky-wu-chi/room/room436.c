inherit ROOM;
void create() {
	set( "short", "廣文陵" );
	set( "owner", "imissyou" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 55,
		"file6"    : "/obj/gift/shenliwan",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/obj/magic-sign",
		"amount5"  : 46,
		"amount8"  : 1,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 29,
		"amount3"  : 161,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount1"  : 15,
		"amount9"  : 1,
	]) );
	set( "build", 10036 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room437",
	]) );
	set( "long", @LONG
李白 
(公元七零一至七六二年)盛唐的最主要代表之一，一生中最菁華
的歲月是在唐玄宗統治下度過的。從傳世的第一首詩《訪戴天山
道士不遇》(720以前)到最後一首《臨路(終)歌》(762)，他的創
作活動延續了四十多年，內容上反映了唐朝由盛而衰的封建社會
發展的必然過程。

LONG);
	setup();
	replace_program(ROOM);
}

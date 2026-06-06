inherit ROOM;
void create() {
	set( "short", "血痕居-後花園" );
	set( "owner", "holeman" );
	set( "object", ([
		"amount4"  : 1227,
		"amount3"  : 80,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/open/killer/obj/atman_pill",
		"amount1"  : 33,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 35,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 38,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 41,
		"amount10" : 500,
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 101,
		"amount9"  : 474,
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 82,
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 11121 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room528",
		"west"      : "/open/clan/sky-wu-chi/room/room295.c",
		"east"      : "/open/clan/sky-wu-chi/room/room294.c",
		"south"     : "/open/clan/sky-wu-chi/room/room305.c",
	]) );
	set( "long", @LONG

    在這裡你可以感受到之前所沒有感受到的違和感，或許
這裡是這個血痕居最奇特的地方吧！微風的輕撫、清脆的鳥
鳴、花團錦簇的景色、卻是伴隨著一股無與倫比的邪氣，令
人想快離開此處，趕緊遠離這個令你喘不過氣的地方。當你
細心去感覺時，才發覺說這股邪氣是來自於在這花園深處的
一口古井中，你甚至感覺到你內心有一股聲音要你跳入這口
古井，你馬上堅定心志抗拒這股吸引力，你這時候才明白這
股吸引力帶著　痛苦　罪惡　邪念　死亡，根本就是來自地
獄的力量，只有狂奔離去才是最安全的作法。在你左手邊有
一處專門在飼養馬的馬廄，而在你的右手邊則有著一間看似
普通但散發著無比霸氣的房間，令你覺得應該是擁有如此霸
氣的人才有資格在這裡鎮守這個來自地獄的古井吧。


LONG);
	setup();
	replace_program(ROOM);
}

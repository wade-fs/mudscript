inherit ROOM;
void create() {
	set( "short", "$HIW$小馬$NOR$的$HIG$家$NOR$" );
	set( "owner", "vigel" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"amount2"  : 74,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount6"  : 72,
		"amount5"  : 45,
		"file7"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/killer/obj/soul-hands",
		"amount7"  : 88,
		"amount1"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 1,
		"amount4"  : 1,
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "light_up", 1 );
	set( "build", 11700 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room143",
		"add"       : "/open/clan/ou-cloud-club/room/room356",
		"west"      : "/open/clan/ou-cloud-club/room/room479",
	]) );
	set( "long", @LONG
           無題

相見時難別亦難
  東風無力百花殘
    春蠶到死絲方盡
      蠟炬成灰淚始乾
    曉鏡但愁雲鬢改
  夜吟應覺月光寒
蓬萊此去無多路


~~~~青鳥殷勤為探看

此為本屋主的心情寫照.....

一進門看見了有個人眼神空洞的望著窗....嘴裡喃喃自語的念著此詩
看似冷酷的外表其實..內心熱切的希望尋覓到相知相守的另一伴~~.
LONG);
	setup();
	replace_program(ROOM);
}

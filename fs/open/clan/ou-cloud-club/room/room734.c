inherit ROOM;
void create() {
	set( "short", "$HIR$鑄$HIY$心$HIC$齋$NOR$" );
	set( "object", ([
		"file2"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
		"file8"    : "/obj/stone/powder",
		"amount2"  : 76,
		"file10"   : "/open/killer/obj/soul-hands",
		"amount5"  : 8,
		"file5"    : "/obj/stone/suipian",
		"file4"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"amount9"  : 94,
		"amount4"  : 800,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 10,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount8"  : 9,
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10130 );
	set( "owner", "bacchus" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room450",
	]) );
	set( "long", @LONG
在你眼前矗立著法理斯神的$HIW$神像(statue)$NOR$，,還有幾尊飛舞的不知名$HIC$天
$HIC$使雕像$NOR$在祂身旁禮讚著。在你週圍有幾位虔誠的信徒，正跪在$HIY$神龕$NOR$前祈禱著
。這裡除了祈禱的低喃聲和衣服沙沙聲以外，連空氣流動的聲音彷彿都能聽
得很清楚 ,四週是如此的寧靜使得你紛亂的$HIY$心$NOR$都沉澱了下來... 你想 ,或許
是該結束那種冒險犯難的流浪生活，好好地定下來想一想的時候了。
LONG);
	setup();
	replace_program(ROOM);
}

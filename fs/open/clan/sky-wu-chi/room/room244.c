inherit ROOM;
void create() {
	set( "short", "至尊殿" );
	set( "owner", "shih" );
	set( "object", ([
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room282",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
青陽縣南有九子山，山高數十丈，上有九峰如蓮花，按圖徵名，
無所依據。太史公南遊，略而不書，事不經古老之口，復闕名賢之紀
，雖靈異往復，而賦詠罕聞。李白乃削其舊號，加以九華之目……
──妙有分二氣，靈山開九華，層標過遲日，半璧明朝霞，積雪曜陰
壑，飛流韻陽崖，青瑩玉樹色。飄渺羽人家。拐筑小步踏蒼台上遙指
青山雲正開，滴水松風聽不絕，又教童子抱琴來。
    至尊殿建築在天台峰，也是九華山風景最佳的地方，一條清冷的
閔溪橫貫其中，水流雲汞，萬山叢疊，石質黝黑，嶙峋奇巧，聳削壁
立，縱橫數丈，如人工堆疊而成，妙的是石紋裂處間以青松，精巧如
盆景。
    峰上有摩崖，大書「非人間」三字，這其實有仙境意思，可是在
中原武林中人眼中，現在卻是無疑暗示「此乃魔界」。至尊殿的殿已
完成，絕對稱得上雄奇，只是興周圍景物格格不入，彷彿就是天外飛
來。西方建築出現在東方名山，到底是有些怪異，卻是想不到人在這
座建築物之前，除了怪異還有一種壓迫的感覺。
LONG);
	setup();
	replace_program(ROOM);
}
